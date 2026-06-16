BUILD_DIR := build
BIN_DIR := bin

.PHONY: build clean lint lint-fix

build:
	@mkdir -p $(BUILD_DIR)
	@cd $(BUILD_DIR) && cmake .. && cmake --build .

lint:
	@clang-format --dry-run --Werror src/*.cpp src/*.h test/*.cpp

lint-fix:
	@clang-format -i src/*.cpp src/*.h test/*.cpp

clean:
	@rm -rf $(BUILD_DIR) $(BIN_DIR)
