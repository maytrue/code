//
// Created by zouguowei on 2019/7/14.
//

#ifndef PROJECT_BREADTHFIRST_HPP
#define PROJECT_BREADTHFIRST_HPP

#include <vector>


class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class BinaryTreeLevelTraversal
{
public:
    std::vector<std::vector<int>> levelOrder(TreeNode * root);

    std::vector<std::vector<int>> levelOrderV2(TreeNode * root);
};

#endif //PROJECT_BREADTHFIRST_HPP
