//
// Created by zouguowei on 2019-06-17.
//

#include <iostream>
#include <vector>

class Solution {
public:
    /**
     * @param A: an integer array
     * @param target: An integer
     * @param k: An integer
     * @return: an integer array
     */
    std::vector<int> kClosestNumbers(std::vector<int> &A, int target, int k) {
        // write your code here
        std::vector<int> result;
        if (A.size() == 0) {
            return result;
        }

        int start = 0;
        int end = A.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] == target) {
                end = mid;
            } else if (A[mid] < target) {
                start = mid;
            } else {
                end = mid;
            }
        }


        while (start >= 0 && end <= A.size() - 1 && k > 0) {
            if (abs(A[start] - target) <= abs(A[end] - target)) {
                result.push_back(A[start]);
                start--;
            } else {
                result.push_back(A[end]);
                end++;
            }
            k--;
        }

        while (start >= 0 && k > 0) {
            result.push_back(A[start]);
            start--;
            k--;
        }

        while (end <= A.size() - 1 && k > 0) {
            result.push_back(A[end]);
            end++;
            k--;
        }

        return  result;
    }
};

int main(int argc, char *argv[])
{

    {
        int array[] = {1, 2, 3};
        std::vector<int> input(std::begin(array), std::end(array));
        Solution solution;
        auto results = solution.kClosestNumbers(input, 2, 3);

        std::cout << "find kclose elements:";
        for (auto &item : results) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }

    {
        int array[] = {1, 4, 6, 8};
        std::vector<int> input(std::begin(array), std::end(array));
        Solution solution;
        auto results = solution.kClosestNumbers(input, 3, 3);

        std::cout << "find kclose elements:";
        for (auto &item : results) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}