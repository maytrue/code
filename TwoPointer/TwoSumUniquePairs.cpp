//
// Created by zouguowei on 2019-06-21.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: An integer
     * @return: An integer
     */
    int twoSum6(std::vector<int> &nums, int target) {
        // write your code here
        int result = 0;
        // sort vector
        std::sort(nums.begin(), nums.end());
        std::set<int> firstNum;
        int start = 0;
        int end = nums.size() - 1;

        while (start < end) {
            int sum = nums[start] + nums[end];
            if (sum == target) {
                if (firstNum.find(nums[start]) == firstNum.end()) {
                    firstNum.insert(nums[start]);
                }
                start ++;
                end --;
            } else if (sum < target) {
                start++;
            } else {
                end--;
            }
        }

        result = static_cast<int>(firstNum.size());
        return result;
    }
};

int main(int argc, char *argv[])
{

    {
        int array[] = {1, 1, 2, 45, 46, 46};
        std::vector<int> input(std::begin(array), std::end(array));

        Solution solution;
        std::cout << "pair number : " << solution.twoSum6(input, 47) << std::endl;
    }
    return 0;
}
