#ifndef COMMON_H
#define COMMON_H
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <filesystem>
#include <map>
#include <memory>

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

    std::vector<std::string> get_files_in_dir(const std::string &dir_path)
    {
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

        return files;
    }

    std::map<std::string, std::unique_ptr<Day>> create_input_to_day_map() {
        std::map<std::string, std::unique_ptr<Day>> map;
        map[PROJECT_ROOT "/puzzle_input/input_1.txt"] = std::make_unique<Day_1>(read_file(PROJECT_ROOT "/puzzle_input/input_1.txt"));
        map[PROJECT_ROOT "/puzzle_input/input_2.txt"] = std::make_unique<Day_2>(read_file(PROJECT_ROOT "/puzzle_input/input_2.txt"));
        return map;
    }

    std::map<std::string, std::unique_ptr<Day>> input_to_day_map = create_input_to_day_map();

}

#endif
