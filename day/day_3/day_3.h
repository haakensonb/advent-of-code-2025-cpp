#ifndef DAY_3_H
#define DAY_3_H
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "common/day.h"

class BatteryBank {
   public:
    BatteryBank(std::string input_line) {
        for (auto ch : input_line) {
            int num = ch - '0';
            _bank.push_back(num);
        }
    };

    int get_max_joltage() {
        // Naive brute force
        int max_joltage = 0;
        for (size_t i = 0; i < _bank.size(); i++) {
            for (size_t j = i + 1; j < _bank.size(); j++) {
                auto num_1 = _bank[i];
                auto num_2 = _bank[j];
                auto num_str = std::to_string(num_1) + std::to_string(num_2);
                auto val = std::stoi(num_str);
                if (val > max_joltage) {
                    max_joltage = val;
                }
            }
        }
        return max_joltage;
    }

   private:
    std::vector<int> _bank;
};

class Day_3 : public Day {
   public:
    Day_3(std::string input) : Day(input) {
        load_input(input);
    };

    std::string solve_part_1() {
        int total_joltage = 0;
        for (auto& battery_bank : _battery_banks) {
            total_joltage += battery_bank.get_max_joltage();
        }
        return std::to_string(total_joltage);
    }

    std::string solve_part_2() {
        return "";
    }

   private:
    std::vector<BatteryBank> _battery_banks;

    void load_input(std::string input) {
        std::stringstream ss(input);
        std::string line;
        while (std::getline(ss, line)) {
            auto battery_bank = BatteryBank(line);
            _battery_banks.push_back(battery_bank);
        }
    }
};

#endif
