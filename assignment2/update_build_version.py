import os
import re


def update_file(file_path, pattern, replacement):
    with open(file_path, "r", encoding="utf-8") as file:
        content = file.read()

    updated_content, count = re.subn(
        pattern,
        replacement,
        content
    )

    if count == 0:
        raise ValueError(
            f"Pattern not found in {file_path}"
        )

    with open(file_path, "w", encoding="utf-8") as file:
        file.write(updated_content)


def validate_environment():
    source_path = os.environ.get("SourcePath")
    build_num = os.environ.get("BuildNum")

    if not source_path:
        raise EnvironmentError(
            "SourcePath environment variable not set"
        )

    if not build_num:
        raise EnvironmentError(
            "BuildNum environment variable not set"
        )

    if not build_num.isdigit():
        raise ValueError(
            "BuildNum must be numeric"
        )

    return source_path, build_num


def main():
    source_path, build_num = validate_environment()

    src_dir = os.path.join(
        source_path,
        "develop",
        "global",
        "src"
    )
    
    print("Updating SConstruct...")
    update_file(
        os.path.join(src_dir, "SConstruct"),
        r"point\s*=\s*\d+",
        f"point={build_num}"
    )
    
    print("Updating VERSION...")
    update_file(
        os.path.join(src_dir, "VERSION"),
        r"ADLMSDK_VERSION_POINT\s*=\s*\d+",
        f"ADLMSDK_VERSION_POINT={build_num}"
    )

    print("Build version updated successfully!")


if __name__ == "__main__":
    main()