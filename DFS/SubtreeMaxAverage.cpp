//
// Created by zouguowei on 2019/7/22.
//

#include <iostream>
#include <numeric>

#include "Common.hpp"

class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: the root of the maximum average of subtree
     */
    TreeNode * findSubtree2(TreeNode * root) {
        // write your code here
        TreeNode *maxNode = nullptr;
        int maxAverage = std::numeric_limits<int>::min();




        return maxNode;
    }

    int findMaxAverage(TreeNode *node, int& sum, int& num) {

        if (!node) {
            return 0;
        }

        if (!node->left && !node->right) {

        }

        int leftSum = 0;
        int leftNum = 0;
        int left = findMaxAverage(node->left, leftNum, leftNum);

        int rightSum = 0;
        int rightNum = 0;
        int right = findMaxAverage(node->right, rightSum, ri);
        int rootAverage = findMaxAverage(node);

    }




};

int main(int argc, char *argv[])
{


    return 0;
}
