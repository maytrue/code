//
// Created by zouguowei on 2019/7/23.
//

#include <iostream>
#include <vector>
#include <string>

#include "Common.hpp"

class Solution {
public:
    /**
     * @param root: the root of the binary tree
     * @return: all root-to-leaf paths
     */
    std::vector<std::string> binaryTreePaths(TreeNode * root) {
        // write your code here
        std::vector<std::string> paths;
        std::vector<int> path;
        helper(root, paths, path);
        return paths;
    }

    void helper(TreeNode * root, std::vector<std::string> &paths, std::vector<int>& path) {
        if (!root) {
            return;
        }
        path.push_back(root->val);
        if (!root->left && !root->right) {
            std::string value;
            for (int i = 0; i < path.size(); i++) {
                if (!value.empty()) {
                    value.append("->");
                }
                value.append(std::to_string(path[i]));
            }
            paths.push_back(value);
            path.pop_back();
            return;
        }
        if (root->left) {
            helper(root->left, paths, path);
        }
        if (root->right) {
            helper(root->right, paths, path);
        }
        path.pop_back();
    }
};

int main(int argc, char *argv[])
{

    {
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->right = new TreeNode(5);

        Solution solution;
        auto results = solution.binaryTreePaths(root);
        for (auto &result : results) {
            std::cout << result << std::endl;
        }
    }

    {
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        Solution solution;
        auto results = solution.binaryTreePaths(root);
        for (auto &result : results) {
            std::cout << result << std::endl;
        }
    }

    return 0;
}
