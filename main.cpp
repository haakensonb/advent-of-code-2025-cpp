#include <iostream>
#include <string>
#include "day/day_1/day_1.h"
#include "common/common.h"

std::string sample_input = "L68\nL30\nR48\nL5\nR60\nL55\nL1\nL99\nR14\nL82";

int main() {
    auto files = Common::get_files_in_dir(PROJECT_ROOT "/puzzle_input");

    for (const auto& file : files) {
        auto& day = Common::input_to_day_map[file];
        std::cout << "File: " << file << std::endl;
        std::cout << "  Part 1: " << day->solve_part_1() << std::endl;
        std::cout << "  Part 2: " << day->solve_part_2() << std::endl;
    }

    return 0;
}