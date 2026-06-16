import os
import tempfile
import shutil

import pytest

from src.update_build_version import update_file, validate_environment


class TestUpdateFile:
    def test_replaces_pattern_in_file(self, tmp_path):
        f = tmp_path / "VERSION"
        f.write_text("ADLMSDK_VERSION_POINT=123")

        update_file(
            str(f), r"ADLMSDK_VERSION_POINT\s*=\s*\d+", "ADLMSDK_VERSION_POINT=456"
        )

        assert f.read_text() == "ADLMSDK_VERSION_POINT=456"

    def test_replaces_sconstruct_point(self, tmp_path):
        f = tmp_path / "SConstruct"
        f.write_text(
            "config.version = Version(\nmajor=15,\nminor=0,\npoint=123,\npatch=0\n)"
        )

        update_file(str(f), r"point\s*=\s*\d+", "point=999")

        assert "point=999" in f.read_text()

    def test_raises_when_pattern_not_found(self, tmp_path):
        f = tmp_path / "empty.txt"
        f.write_text("no match here")

        with pytest.raises(ValueError, match="Pattern not found"):
            update_file(str(f), r"MISSING_PATTERN=\d+", "MISSING_PATTERN=1")


class TestValidateEnvironment:
    def test_valid_environment(self, monkeypatch):
        monkeypatch.setenv("SourcePath", "/some/path")
        monkeypatch.setenv("BuildNum", "456")

        source_path, build_num = validate_environment()

        assert source_path == "/some/path"
        assert build_num == "456"

    def test_missing_source_path(self, monkeypatch):
        monkeypatch.delenv("SourcePath", raising=False)
        monkeypatch.setenv("BuildNum", "123")

        with pytest.raises(EnvironmentError):
            validate_environment()

    def test_missing_build_num(self, monkeypatch):
        monkeypatch.setenv("SourcePath", "/some/path")
        monkeypatch.delenv("BuildNum", raising=False)

        with pytest.raises(EnvironmentError):
            validate_environment()

    def test_non_numeric_build_num(self, monkeypatch):
        monkeypatch.setenv("SourcePath", "/some/path")
        monkeypatch.setenv("BuildNum", "abc")

        with pytest.raises(ValueError, match="BuildNum must be numeric"):
            validate_environment()
