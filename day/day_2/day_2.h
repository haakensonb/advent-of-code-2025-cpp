#ifndef DAY_2_H
#define DAY_2_H
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <functional>
#include "common/day.h"

struct InputRange {
  std::string start;
  std::string end;
  long start_num;
  long end_num;
};

class Day_2 : public Day {
    public:
        Day_2(std::string input): Day(input){
          load_input(_input);
        };

        std::string solve_part_1(){
          return solve(is_invalid_id);
        }

        std::string solve_part_2(){
          return solve(is_invalid_id_part_2);
        }

        std::string solve(std::function<bool(long)> is_invalid_id_func){
          long invalid_ids_sum = 0L;
          for (auto& input_range : _input_ranges){
            for (long i = input_range.start_num; i <= input_range.end_num; i++){
              if (is_invalid_id_func(i)){
                //std::cout << "invalid id: " << i << std::endl;
                invalid_ids_sum += i;
              }
            }
          }
          return std::to_string(invalid_ids_sum);
        }

        static bool is_invalid_id(long id){
          std::string id_str = std::to_string(id);
          int midpoint = id_str.length() / 2;
          std::string half_1 = id_str.substr(0, midpoint);
          std::string half_2 = id_str.substr(midpoint);
          if (half_1 == half_2)
            return true;
          return false;
        }

        // static bool is_invalid_id_part_2(long id){
        //   std::set<std::string> seen;
        //   // Generate all possible contiguous substrings
        //   std::string id_str = std::to_string(id);
        //   for (int i =0; i < id_str.length(); i++) {
        //     for (int len = 1; len <= id_str.length() - i; len++){
        //       std::string substring = id_str.substr(i, len);
        //       std::cout << "substring: " << substring << std::endl;
        //       if (seen.contains(substring)){
        //         std::cout << "in set: " << substring << std::endl;
        //         return true;
        //       } else {
        //         seen.insert(substring);
        //       }
        //
        //     }
        //   }
        //   return false;
        // }

        static bool is_invalid_id_part_2(long id){
          std::string id_str = std::to_string(id);

          // target_len / cur_len = num of times to multiply
          int target_len = id_str.length();
          int cur_len = 1;
          while (cur_len <= target_len / 2){
            int n = target_len / cur_len;
            std::string cur_substr = id_str.substr(0, cur_len);
            std::string new_str = repeated_str(cur_substr, n);
            if (new_str == id_str){
              return true;
            }
            cur_len += 1;
          }
          return false;

        }

        static std::string repeated_str(const std::string& str, int n){
          std::string result = "";
          for (int i = 0; i < n; i++){
            result += str;
          }
          return result;
        }

    private:
        std::vector<InputRange> _input_ranges;



        void load_input(std::string input){
          std::stringstream ss(input);
          std::string line;
          while(std::getline(ss, line, ',')){
            //std::cout << "line: " << line << std::endl;

            std::stringstream ss2(line);
            std::string token;
            std::vector<std::string> tokens;
            while(std::getline(ss2, token, '-')){
              //std::cout << "token: " << token << std::endl;
              tokens.push_back(token);
            }
            std::string start = tokens.at(0);
            std::string end = tokens.at(1);
            InputRange input_range = {start, end, std::stol(start), std::stol(end)};
            _input_ranges.push_back(input_range);
          }
        }

};

#endif
