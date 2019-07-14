//
// Created by zouguowei on 2019-06-23.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class Solution {
public:
    /**
     * @param nums: an integer array
     * @param target: An integer
     * @return: the difference between the sum and the target
     */
    int twoSumClosest(std::vector<int> &nums, int target) {
        // write your code here
        std::sort(nums.begin(), nums.end());
        int delta = std::numeric_limits<int>::max();

        if (nums.size() >= 2) {
            int start = 0;
            int end = nums.size() - 1;

            while (start < end) {
                int sum = nums[start] + nums[end];
                int result = std::abs(sum - target);
                if (result <= delta) {
                    delta = result;
                    start++;
                    end--;
                } else if (result > delta) {

                }

            }

        }

        return delta;

    }
};

int main(int argc, char *argv[])
{

    return 0;
}
