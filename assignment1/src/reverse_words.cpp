#include "reverse_words.h"

#include <algorithm>
#include <cctype>

std::string reverse_words(const std::string& str) {
    std::string result = str;
    std::size_t i = 0;

    while (i < result.size()) {
        if (std::isalnum(static_cast<unsigned char>(result[i]))) {
            std::size_t start = i;
            while (i < result.size() &&
                   std::isalnum(static_cast<unsigned char>(result[i]))) {
                ++i;
            }
            std::reverse(result.begin() + start, result.begin() + i);
        } else {
            ++i;
        }
    }
    return result;
}
