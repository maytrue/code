//
// Created by zouguowei on 2019-06-16.
//

#include <iostream>
#include <vector>

/**
Example 1:
	Input:  [1,4,4,5,7,7,8,9,9,10]，1
	Output: 0

	Explanation:
	the first index of  1 is 0.

Example 2:
	Input: [1, 2, 3, 3, 4, 5, 10]，3
	Output: 2

	Explanation:
	the first index of 3 is 2.

Example 3:
	Input: [1, 2, 3, 3, 4, 5, 10]，6
	Output: -1

	Explanation:
	Not exist 6 in array.
 */

class Solution
{
    /**
   * @param nums: The integer array.
   * @param target: Target to find.
   * @return: The first position of target. Position starts from 0.
   */
public:
    int binarySearch(std::vector<int> &nums, int target) {
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
                last = mid;
            } else if (nums[mid] < target) {
                start = mid;
            } else {
                last = mid;
            }
        }

        if (nums[start] == target) {
            return start;
        }

        if (nums[mid] == target) {
            return mid;
        }

        if (nums[last] == target) {
            return last;
        }

        return -1;
    }
};

int main(int argc, char* argv[])
{
    {
        int array[] = {1, 2, 3, 3, 4, 5, 10};
        std::vector<int> input(std::begin(array), std::end(array));
        Solution solution;
        std::cout << "first position of 3 is " << solution.binarySearch(input, 3) << std::endl;
    }

    {
        int array[] = {1, 4, 4, 5, 7, 7, 8, 9, 9, 10};
        std::vector<int> input(std::begin(array), std::end(array));
        Solution solution;
        std::cout << "first position of 1 is " << solution.binarySearch(input, 1) << std::endl;
    }

    {
        int array[] = {1, 2, 3, 3, 4, 5, 10};
        std::vector<int> input(std::begin(array), std::end(array));
        Solution solution;
        std::cout << "first position of 6 is " << solution.binarySearch(input, 6) << std::endl;
    }

    {
        int array[] = {1, 1, 2};
        std::vector<int> input(std::begin(array), std::end(array));
        Solution solution;
        std::cout << "first position of 1 is " << solution.binarySearch(input, 1) << std::endl;
    }

    return 0;
}