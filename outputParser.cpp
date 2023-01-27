#include <iostream>
#include <math.h>
#include <string>

std::string parseOutput(long double input, int max_length = 8) {

    std::string output{};

    if (input == 0) {
        return "0";  
    } else if (input < 0) {
        output += '-';
        max_length -= 1;
    }

    long double abs_input = abs(input);
    float magnitude = floor(log10(abs_input));

    if (magnitude < 0) {
        output += "0.";
        max_length -= 2;
    } else if (magnitude < max_length && floor(input) == input) {
        max_length = magnitude + 1;
    } else {
        max_length -= 1;
    }

    bool decimal_passed{false};
    float remainder{};
    int current_digit{};
    for (int i{}; i < max_length; i++) {
        if (magnitude - 1 == -1) {
            output += '.';
        }
        current_digit = floor((abs_input - remainder) / pow(10, (magnitude - i)));
        output += char(48 + current_digit);
        remainder += current_digit * pow(10, (magnitude - i));
    }
    
    return output;

}

std::string trailingZeroesToSpaces(std::string& input) {

    for (std::string::reverse_iterator it = input.rbegin(); it != input.rend(); it++) {
        if (*it == '0') {
            *it = ' ';
        } else {
            break;
        }
    }
    
    return input;

}

int main() {
    // int input{};
    // while (std::cin >> input) {
    //     std::cout << parseOutput(input) << '\n';
    // }
}