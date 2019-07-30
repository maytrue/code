//
// Created by guowei on 2019/7/30.
//

#include <iostream>
#include <vector>

class TreeNode {
public:
    TreeNode(int value) {
        left_ = nullptr;
        right_ = nullptr;
        value_ = value;
    }

    TreeNode *left_;
    TreeNode *right_;
    int value_;
};


class Solution
{
public:


    // pre order travel
    std::vector<TreeNode*> preorder(TreeNode *root) {
        std::vector<TreeNode*> result;
        if (!root) {
            return result;
        }

        std::vector<TreeNode*> queue;
        queue.push_back(root);

        while (!queue.empty()) {

            TreeNode *node = queue.back();
            queue.pop_back();
            result.push_back(node);

            if (node->right_) {
                queue.push_back(node->right_);
            }

            if (node->left_) {
                queue.push_back(node->left_);
            }
        }
        return result;
    }

    std::vector<TreeNode*> inorder(TreeNode *root)
    {

    }

};




int main() {


    {
        TreeNode *root = new TreeNode(10);
        root->left_ = new TreeNode(1);
        root->left_->right_ = new TreeNode(6);

        root->right_ = new TreeNode(11);
        root->right_->right_ = new TreeNode(12);


        Solution solution;
        auto result = solution.preorder(root);

        for (int i = 0; i < result.size(); i++) {
            if (i == 0) {
                std::cout << result[i]->value_;
            } else {
                std::cout << "->" << result[i]->value_;
            }
        }
        std::cout << std::endl;

    }

    {
        TreeNode *root = new TreeNode(1);
        root->left_ = new TreeNode(2);
        root->right_ = new TreeNode(3);

        Solution solution;
        auto result = solution.preorder(root);

        for (int i = 0; i < result.size(); i++) {
            if (i == 0) {
                std::cout << result[i]->value_;
            } else {
                std::cout << "->" << result[i]->value_;
            }
        }
        std::cout << std::endl;

    }


    return 0;
}