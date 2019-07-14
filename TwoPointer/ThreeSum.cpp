//
// Created by zouguowei on 2019-06-23.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#include "TwoPointers.hpp"

std::vector<std::vector<int>> ThreeSum::threeSum(std::vector<int> &numbers) {
    // write your code here
    std::vector<std::vector<int>> result;
    std::sort(numbers.begin(), numbers.end());
    std::set<std::pair<int, int>> uniquePairSet;

    if (numbers.size() >= 3) {

        int total = numbers.size();
        for (int index = 0; index <= total - 3; index++) {

            int start = index + 1;
            int end = numbers.size() - 1;

            while (start < end) {

                int sum = numbers[start] + numbers[end] + numbers[index];
                if (sum == 0) {
                    auto pair = std::make_pair(numbers[index], numbers[start]);
                    if (uniquePairSet.find(pair) == uniquePairSet.end()) {
                        auto three = std::vector<int>{numbers[index], numbers[start], numbers[end]};
                        result.push_back(three);
                        uniquePairSet.insert(pair);
                    }
                    start++;
                    end--;
                } else if (sum > 0) {
                    end--;
                } else {
                    start++;
                }
            }

        }
    }

    return result;
}

//class ThreeSum {
//public:
//    /**
//     * @param numbers: Give an array numbers of n integer
//     * @return: Find all unique triplets in the array which gives the sum of zero.
//     */
//    std::vector<std::vector<int>> threeSum(std::vector<int> &numbers) {
//        // write your code here
//        std::vector<std::vector<int>> result;
//        std::sort(numbers.begin(), numbers.end());
//        std::set<std::pair<int, int>> uniquePairSet;
//
//        if (numbers.size() >= 3) {
//
//            int total = numbers.size();
//            for (int index = 0; index <= total - 3; index++) {
//
//                int start = index + 1;
//                int end = numbers.size() - 1;
//
//                while (start < end) {
//
//                    int sum = numbers[start] + numbers[end] + numbers[index];
//                    if (sum == 0) {
//                        auto pair = std::make_pair(numbers[index], numbers[start]);
//                        if (uniquePairSet.find(pair) == uniquePairSet.end()) {
//                            auto three = std::vector<int>{numbers[index], numbers[start], numbers[end]};
//                            result.push_back(three);
//                            uniquePairSet.insert(pair);
//                        }
//                        start++;
//                        end--;
//                    } else if (sum > 0) {
//                        end--;
//                    } else {
//                        start++;
//                    }
//                }
//
//            }
//        }
//
//        return result;
//
//    }
//};

//int main(int argc, char *argv[])
//{
//
//    {
//        int array[] = {2, 7, 11, 15};
//        std::vector<int> input(std::begin(array), std::end(array));
//        ThreeSum solution;
//
//        auto results = solution.threeSum(input);
//
//        for (auto &result : results) {
//            for (auto &num : result) {
//                std::cout << num << "\t";
//            }
//            std::cout << std::endl;
//        }
//    }
//
//    {
//        int array[] = {-1, 0, 1, 2, -1, -4};
//        std::vector<int> input(std::begin(array), std::end(array));
//        ThreeSum solution;
//
//        auto results = solution.threeSum(input);
//
//        for (auto &result : results) {
//            for (auto &num : result) {
//                std::cout << num << "\t";
//            }
//            std::cout << std::endl;
//        }
//    }
//
//
//    return 0;
//}
