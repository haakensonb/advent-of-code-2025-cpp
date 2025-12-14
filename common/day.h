#ifndef DAY_H
#define DAY_H
#include <string>

class Day {
    public:
        Day(std::string input){
            _input = input;
        };
        virtual std::string solve_part_1() { return ""; };
        virtual std::string solve_part_2() { return ""; };
        virtual ~Day() = default;
    
    protected:
        std::string _input;
};

#endif