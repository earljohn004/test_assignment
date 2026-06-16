#include <iostream>

#include "reverse_words.h"

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);
    std::cout << "Reversed: " << reverse_words(input) << '\n';
    return 0;
}
