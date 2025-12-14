#ifndef DIAL_H
#define DIAL_H
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

enum Direction {Left, Right};

struct DialInstruction {
    const Direction direction;
    const int value;
};

class Dial {
    public:
        explicit Dial(const std::string &input) {
            _read_input(input);
        }

        void reset(){
            _dial_val = 50;
            _dial_max_val = 99;
            _num_of_times_dial_is_at_zero = 0;
        }

        int get_password() {
            reset();
            for (auto instruction : _instruction_set) {
                _process_instruction(instruction);
            }
            return _num_of_times_dial_is_at_zero;
        }

        int get_password_part_2() {
            reset();
            for (auto instruction : _instruction_set) {
                _process_instruction_part_2(instruction);
            }
            return _num_of_times_dial_is_at_zero;
        }

    private:
        std::vector<DialInstruction> _instruction_set;
        int _dial_val = 50;
        int _dial_max_val = 99;
        int _num_of_times_dial_is_at_zero = 0;

        void _read_input(const std::string &input) {
            std::stringstream ss(input);
            std::string line;
            while (std::getline(ss, line)) {
                const Direction direction = line.front() == 'L' ? Left: Right;
                const int value = std::stoi(line.substr(1));
                DialInstruction instruction = {direction, value};
                _instruction_set.push_back(instruction);
            }
        }

        void _process_instruction(const DialInstruction &instruction) {
            const int dir_modifier = instruction.direction == Left ? -1 : 1;
            const int turn_amount = dir_modifier * instruction.value;
            _dial_val = (_dial_val + turn_amount) % (_dial_max_val + 1);
            if (_dial_val == 0)
                _num_of_times_dial_is_at_zero += 1;
        }

        void _process_instruction_part_2(const DialInstruction &instruction) {
            // Brute force solution, couldn't get the math to work on real data.
            int turn = instruction.direction == Left ? -1 : 1;
            for (int i = 0; i < instruction.value; i++){
                _dial_val = (_dial_val + turn) % (_dial_max_val + 1);

                if (_dial_val == 0)
                    _num_of_times_dial_is_at_zero += 1;
            }
        }
};

#endif