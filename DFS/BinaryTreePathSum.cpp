//
// Created by zouguowei on 2019/7/23.
//

#include <iostream>
#include <vector>

#include "Common.hpp"

class Solution {
public:
    /*
     * @param root: the root of binary tree
     * @param target: An integer
     * @return: all valid paths
     */
    std::vector<std::vector<int>> binaryTreePathSum(TreeNode * root, int target) {
        // write your code here
        std::vector<std::vector<int>> result;
        std::vector<int> path;
        helper(root, target, result, path);
        return result;
    }

    void helper(TreeNode *node, int target, std::vector<std::vector<int>>& result, std::vector<int>& path)
    {
        if (!node) {
            return;
        }

        if (!node->left && !node->right) {
            if (node->val == target) {
                path.push_back(node->val);
                result.push_back(path);
                path.pop_back();
            }
            return;
        }

        path.push_back(node->val);
        if (node->left) {
            helper(node->left, target - node->val, result, path);
        }
        if (node->right) {
            helper(node->right, target - node->val, result, path);
        }
        path.pop_back();
    }

};

int main(int argc, char *argv[])
{
    {
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(4);

        root->left->left = new TreeNode(2);
        root->left->right = new TreeNode(3);

        Solution solution;
        auto results = solution.binaryTreePathSum(root, 5);
        for (auto &path : results) {
            std::string value;
            for (auto &item : path) {
                if (!value.empty()) {
                    value.append(",");
                }
                value.append(std::to_string(item));
            }
            std::cout << value << std::endl;
        }
    }

    return 0;
}