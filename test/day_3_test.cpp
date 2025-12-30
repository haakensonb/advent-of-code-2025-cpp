#include "day/day_3/day_3.h"

#include <gtest/gtest.h>

const std::string SAMPLE_INPUT = "987654321111111\n811111111111119\n234234234234278\n818181911112111";

TEST(Day3Test, SolvePart1) {
    Day_3 day(SAMPLE_INPUT);
    std::string result = day.solve_part_1();
    EXPECT_EQ(result, "357");
}
