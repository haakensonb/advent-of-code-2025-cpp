#ifndef COMMON_H
#define COMMON_H
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "../day/day_1/day_1.h"
#include "../day/day_2/day_2.h"
#include "../day/day_3/day_3.h"
#include "day.h"

namespace Common {

std::string read_file(std::string path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << path << std::endl;
        return std::string();
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int extract_numeric_substring(const std::string &str) {
    // Extract number at the end of puzzle input filename
    char target_start = '_';
    char target_end = '.';
    auto start_index = str.find_last_of(target_start);
    auto end_index = str.find(target_end);
    if (start_index != std::string::npos && end_index != std::string::npos) {
        // Adjust offsets by 1 to exclude '_' and '.'
        auto substr_len = end_index - start_index - 1;
        auto substring = str.substr(start_index + 1, substr_len);
        return std::stoi(substring);
    }
    return 0;
}

std::vector<std::string> get_files_in_dir(const std::string &dir_path) {
    std::vector<std::string> files;
    try {
        for (const auto &entry : std::filesystem::directory_iterator(dir_path)) {
            if (std::filesystem::is_regular_file(entry.path())) {
                files.push_back(entry.path().string());
            }
        }
    } catch (const std::filesystem::filesystem_error &e) {
        std::cerr << "Filesystem error: " << e.what() << std::endl;
    }

    std::sort(files.begin(), files.end(), [](const std::string &a, const std::string &b) {
        int num_a = extract_numeric_substring(a);
        int num_b = extract_numeric_substring(b);
        // ascending order
        return num_a < num_b;
    });

    return files;
}

std::map<std::string, std::unique_ptr<Day>> create_input_to_day_map() {
    std::map<std::string, std::unique_ptr<Day>> map;
    map[PROJECT_ROOT "/puzzle_input/input_1.txt"] =
        std::make_unique<Day_1>(read_file(PROJECT_ROOT "/puzzle_input/input_1.txt"));
    map[PROJECT_ROOT "/puzzle_input/input_2.txt"] =
        std::make_unique<Day_2>(read_file(PROJECT_ROOT "/puzzle_input/input_2.txt"));
    map[PROJECT_ROOT "/puzzle_input/input_3.txt"] =
        std::make_unique<Day_3>(read_file(PROJECT_ROOT "/puzzle_input/input_3.txt"));

    return map;
}

std::map<std::string, std::unique_ptr<Day>> input_to_day_map = create_input_to_day_map();

}  // namespace Common

#endif
