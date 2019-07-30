//
// Created by guowei on 2019/7/30.
//

#include <iostream>
#include <vector>
#include <Common.hpp>

class Solution
{
public:


    // pre order travel
    std::vector<TreeNode*> preOrder(TreeNode *root) {
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

            if (node->right) {
                queue.push_back(node->right);
            }

            if (node->left) {
                queue.push_back(node->left);
            }
        }
        return result;
    }



    std::vector<TreeNode*> inOrder(TreeNode *root)
    {
        std::vector<TreeNode*> result;
        if (!root) {
            return result;
        }

        std::vector<TreeNode*> queue;
        queue.push_back(root);

        while (!queue.empty()) {
            TreeNode* node = queue.back();
            if (node->left && !node->isLeftVisited) {
                node->isLeftVisited = 1;
                queue.push_back(node->left);
            } else if (node->isLeftVisited) {
                result.push_back(node);
                queue.pop_back();

                if (node->right) {
                    queue.push_back(node->right);
                }
            }
            if (!node->left) {
                result.push_back(node);
                queue.pop_back();

                if (node->right) {
                    queue.push_back(node->right);
                }
            }
        }
        return result;
    }

    std::vector<TreeNode*> postOrder(TreeNode *root)
    {
        std::vector<TreeNode*> result;
        return result;
    }

};




int main() {


    {
        TreeNode *root = new TreeNode(10);
        root->left = new TreeNode(1);
        root->left->right = new TreeNode(6);

        root->right = new TreeNode(11);
        root->right->right = new TreeNode(12);


        Solution solution;
        auto result = solution.preOrder(root);

        for (int i = 0; i < result.size(); i++) {
            if (i == 0) {
                std::cout << result[i]->val;
            } else {
                std::cout << "->" << result[i]->val;
            }
        }
        std::cout << std::endl;

    }

    {
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);

        Solution solution;
        auto result = solution.preOrder(root);

        for (int i = 0; i < result.size(); i++) {
            if (i == 0) {
                std::cout << result[i]->val;
            } else {
                std::cout << "->" << result[i]->val;
            }
        }
        std::cout << std::endl;
    }

    {
        TreeNode *root = new TreeNode(10);
        root->left = new TreeNode(1);
        root->left->right = new TreeNode(6);

        root->right = new TreeNode(11);
        root->right->right = new TreeNode(12);


        Solution solution;
        auto result = solution.inOrder(root);

        for (int i = 0; i < result.size(); i++) {
            if (i == 0) {
                std::cout << result[i]->val;
            } else {
                std::cout << "->" << result[i]->val;
            }
        }
        std::cout << std::endl;

    }


    return 0;
}