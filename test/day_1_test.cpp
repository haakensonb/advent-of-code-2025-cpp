#include <gtest/gtest.h>
#include "day/day_1/day_1.h"

const std::string SAMPLE_INPUT = "L68\nL30\nR48\nL5\nR60\nL55\nL1\nL99\nR14\nL82";

TEST(Day1Test, SolvePart1) {
    Day_1 day(SAMPLE_INPUT);
    std::string result = day.solve_part_1();
    EXPECT_EQ(result, "3");
}

TEST(Day1Test, SolvePart2) {
    Day_1 day(SAMPLE_INPUT);
    std::string result = day.solve_part_2();
    EXPECT_EQ(result, "6");
}
