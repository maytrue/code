//
// Created by zouguowei on 2019-06-18.
//

#include <iostream>
#include <vector>

class Solution {
public:

    /**
    * @param nums: a rotated sorted array
    * @return: the minimum number in the array
    */
    int findMin(std::vector<int> &nums) {
        // write your code here
        if (nums.size() == 0) {
            return -1;
        }

        int start = 0;
        int end = nums.size() - 1;
        int last = nums[end];

        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] <= last) {
                end = mid;
            } else {
                start = mid;
            }
        }
        if (nums[start] <= last) {
            return nums[start];
        }
        if (nums[end] <= last) {
            return nums[end];
        }
        return -1;
    }
};

int main(int argc, char *argv[]) {

    {
        int array[] = {4, 5, 6, 7, 0, 1, 2};
        std::vector<int> input(std::begin(array), std::end(array));
        Solution solution;
        int index = solution.findMin(input);
        std::cout << "minimum data is " << index << std::endl;
    }

    {
        int array[] = {2, 1};
        std::vector<int> input(std::begin(array), std::end(array));
        Solution solution;
        int index = solution.findMin(input);
        std::cout << "minimum data is " << index << std::endl;
    }

    return 0;
}