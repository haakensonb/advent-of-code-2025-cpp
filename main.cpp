#include <iostream>
#include <string>

#include "common/common.h"
#include "day/day_1/day_1.h"
#include "day/day_2/day_2.h"

int main() {
    auto files = Common::get_files_in_dir(PROJECT_ROOT "/puzzle_input");

    for (const auto& file : files) {
        if (Common::input_to_day_map.contains(file)) {
            auto& day = Common::input_to_day_map[file];
            std::cout << "File: " << file << std::endl;
            std::cout << "\tPart 1: " << day->solve_part_1() << std::endl;
            std::cout << "\tPart 2: " << day->solve_part_2() << std::endl;
        } else {
            std::cout << "No implementation for file: " << file << std::endl;
        }
    }

    return 0;
}
