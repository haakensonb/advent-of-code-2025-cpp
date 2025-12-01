#include <iostream>
#include <string>
#include "day/day_1/dial.h"
#include "common/common.h"

std::string sample_input = "L68\nL30\nR48\nL5\nR60\nL55\nL1\nL99\nR14\nL82";

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::string input_file = "../puzzle_input/input_1.txt";
    auto input = Common::read_file(input_file);
    auto dial = Dial(input);
    int password = dial.get_password();
    std::cout << "Day 1, part 1: " << password << std::endl;
    return 0;
}