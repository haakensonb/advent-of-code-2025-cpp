#ifndef DIAL_H
#define DIAL_H
#include <vector>
#include <string>
#include <sstream>

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

        int get_password() {
            for (auto instruction : _instruction_set) {
                _process_instruction(instruction);
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
            const int turn = _dial_val + (dir_modifier * instruction.value);

            // Assume that dial is a circle numbered from 0-99
            if (turn < 0) {
                _dial_val = (_dial_max_val + 1) + turn;
            } else if (turn > _dial_max_val) {
                _dial_val = turn % (_dial_max_val + 1);
            } else {
                _dial_val = turn;
            }

            if (_dial_val == 0)
                _num_of_times_dial_is_at_zero += 1;
        }
};

#endif