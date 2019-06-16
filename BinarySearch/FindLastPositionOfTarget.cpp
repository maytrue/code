//
// Created by zouguowei on 2019-06-16.
//

#include <iostream>
#include <vector>

class Solution
{
    /**
   * @param nums: The integer array.
   * @param target: Target to find.
   * @return: The first position of target. Position starts from 0.
   */
public:
    int lastPosition(std::vector<int> &nums, int target) {
        // write your code here
        if (nums.size() == 0) {
            return -1;
        }

        int start = 0;
        int last = nums.size() - 1;
        int mid = start + (last - start) / 2;

        while (start + 1 < last) {
            mid = start + (last - start) / 2;
            if (nums[mid] == target) {
                start = mid;
            } else if (nums[mid] < target) {
                start = mid;
            } else {
                last = mid;
            }
        }

        if (nums[last] == target) {
            return last;
        }

        if (nums[mid] == target) {
            return mid;
        }

        if (nums[start] == target) {
            return start;
        }

        return -1;
    }
};

int main(int argc, char* argv[])
{

    {
        int array[] = {1, 2, 2, 4, 5, 5};
        std::vector<int> input(std::begin(array), std::end(array));
        Solution solution;
        std::cout << "last position of 2 is " << solution.lastPosition(input, 2) << std::endl;
    }

    {
        int array[] = {1, 2, 2, 4, 5, 5};
        std::vector<int> input(std::begin(array), std::end(array));
        Solution solution;
        std::cout << "last position of 6 is " << solution.lastPosition(input, 6) << std::endl;
    }

    {
        int array[] = {1, 2, 2, 4, 5, 5};
        std::vector<int> input(std::begin(array), std::end(array));
        Solution solution;
        std::cout << "last position of 5 is " << solution.lastPosition(input, 5) << std::endl;
    }

    return 0;
}
