#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#include "../src/reverse_words.h"

int main() {
    struct TestCase {
        std::string input;
        std::string expected;
    };

    std::vector<TestCase> test_cases = {
        {"String; 2be reversed...", "gnirtS; eb2 desrever..."},
        {"Hello, world!", "olleH, dlrow!"},
        {"abc123 def456", "321cba 654fed"},
        {"12345", "54321"},
        {"abc", "cba"},
        {"a b c", "a b c"},
        {"ab cd ef", "ba dc fe"},
        {"hello-world", "olleh-dlrow"},
        {"hello.world", "olleh.dlrow"},
        {"abc,,def", "cba,,fed"},
        {"The quick brown fox", "ehT kciuq nworb xof"},
        {"!!!abc!!!", "!!!cba!!!"},
        {"123 abc 456", "321 cba 654"},
        {"Test123!Data456?", "321tseT!654ataD?"},
    };

    int passed = 0;
    int failed = 0;

    for (const auto& tc : test_cases) {
        std::string actual = reverse_words(tc.input);
        if (actual == tc.expected) {
            ++passed;
        } else {
            ++failed;
            std::cerr << "FAIL: reverse_words(\"" << tc.input << "\")\n"
                      << "  Expected: \"" << tc.expected << "\"\n"
                      << "  Actual:   \"" << actual << "\"\n";
        }
    }

    std::cout << passed << "/" << (passed + failed) << " tests passed.\n";
    assert(failed == 0 && "Some tests failed");

    return 0;
}
