#include <gtest/gtest.h>
#include "day/day_2/day_2.h"

const std::string SAMPLE_INPUT = "11-22,95-115,998-1012,1188511880-1188511890,222220-222224,1698522-1698528,446443-446449,38593856-38593862,565653-565659,824824821-824824827,2121212118-2121212124";

TEST(Day2Test, SolvePart1) {
    Day_2 day(SAMPLE_INPUT);
    std::string result = day.solve_part_1();
    EXPECT_EQ(result, "1227775554");
}

TEST(Day2Test, Input11) {
    Day_2 day(SAMPLE_INPUT);
    bool result = day.is_invalid_id(11L);
    EXPECT_EQ(result, true);
}

TEST(Day2Test, Input22) {
    Day_2 day(SAMPLE_INPUT);
    bool result = day.is_invalid_id(22L);
    EXPECT_EQ(result, true);
}

TEST(Day2Test, Input99) {
    Day_2 day(SAMPLE_INPUT);
    bool result = day.is_invalid_id(99L);
    EXPECT_EQ(result, true);
}

TEST(Day2Test, Input111) {
    Day_2 day(SAMPLE_INPUT);
    bool result = day.is_invalid_id(111L);
    EXPECT_EQ(result, false);
}
