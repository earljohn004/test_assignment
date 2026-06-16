#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <cassert>

std::string reverse_words(const std::string& str){
    std::string result = str;
    std::size_t i = 0;

    while (i < result.size()){
        if (std::isalnum(static_cast<unsigned char>(result[i]))){
            std::size_t start = i;
            while (i < result.size() && std::isalnum(static_cast<unsigned char>(result[i]))){
                ++i;
            }
            std::reverse(result.begin() + start, result.begin() + i);
        }else{
            ++i;
        }
    }
    return result;
}

int main()

{

    std::vector<std::pair<std::string, std::string>> test_cases = { {"String; 2be reversed...", "gnirtS; eb2 desrever..."},{"Hello, world!", "olleH, dlrow!"},{"abc123 def456", "321cba 654fed"}, {"12345", "54321"},{"abc", "cba"}, {"a b c", "a b c"},
        {"ab cd ef", "ba dc fe"}, {"hello-world", "olleh-dlrow"}, {"hello.world", "olleh.dlrow"}, {"abc,,def", "cba,,fed"}, {"The quick brown fox", "ehT kciuq nworb xof"},{"!!!abc!!!", "!!!cba!!!"},{"123 abc 456", "321 cba 654"}, {"Test123!Data456?", "321tseT!654ataD?"} };

     for (const auto& [input, expected] : test_cases){
        const std::string actual = reverse_words(input);
        std::cout << "Testing: " << input << '\n';
        assert(actual == expected);
}

    std::cout << "\nAll tests passed!\n";

    return 0;

}