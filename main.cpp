#include <iostream>
#include <string>
#include "day/day_1/day_1.h"
#include "common/common.h"

std::string sample_input = "L68\nL30\nR48\nL5\nR60\nL55\nL1\nL99\nR14\nL82";

int main() {
    std::string input_file = "../puzzle_input/input_1.txt";
    auto input = Common::read_file(input_file);
    Day_1 day_1 = Day_1(input);
    std::cout << "Day 1, part 1: " << day_1.solve_part_1() << std::endl;
    std::cout << "Day 1, part 2: " << day_1.solve_part_2() << std::endl;
    return 0;
}