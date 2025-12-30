#ifndef DAY_1_H
#define DAY_1_H
#include <string>

#include "common/day.h"
#include "day/day_1/dial.h"

class Day_1 : public Day {
   public:
    Day_1(std::string input) : Day(input){};

    std::string solve_part_1() {
        auto dial = Dial(_input);
        return std::to_string(dial.get_password());
    }

    std::string solve_part_2() {
        auto dial = Dial(_input);
        return std::to_string(dial.get_password_part_2());
    }
};

#endif
