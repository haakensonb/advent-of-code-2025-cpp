#ifndef COMMON_H
#define COMMON_H
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

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

}

#endif
