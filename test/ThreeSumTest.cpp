//
// Created by zouguowei on 2019/7/14.
//

#include <gtest/gtest.h>
#include "TwoPointers.hpp"

TEST(TwoPointer, ThreeSum) {
    int array[] = {-1, 0, 1, 2, -1, -4};
    std::vector<int> input(std::begin(array), std::end(array));
    ThreeSum solution;

    auto results = solution.threeSum(input);
//    for (auto &result : results) {
//        for (auto &num : result) {
//            std::cout << num << "\t";
//        }
//        std::cout << std::endl;
//    }

//    std::cout << "test two pointer" << std::endl;
    ASSERT_EQ(results.size(), 2);

}