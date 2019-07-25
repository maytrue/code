//
// Created by zouguowei on 2019/7/22.
//

#ifndef PROJECT_COMMON_HPP
#define PROJECT_COMMON_HPP

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = nullptr;
    }
};

#endif //PROJECT_COMMON_HPP
