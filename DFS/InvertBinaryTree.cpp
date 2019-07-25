//
// Created by zouguowei on 2019/7/22.
//

#include <iostream>
#include <queue>
#include "Common.hpp"

class Solution
{
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode * root) {
        // write your code here
        if (!root) {
            return;
        }
        TreeNode *node = root->left;
        root->left = root->right;
        root->right = node;
        invertBinaryTree(root->left);
        invertBinaryTree(root->right);
    }

    void printBinaryTree(TreeNode *root) {
        std::queue<TreeNode *> queue;
        if (root) {
            queue.push(root);
        }

        while (!queue.empty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = queue.front();
                queue.pop();
                std::cout << node->val;
                if (i < size - 1) {
                    std::cout << ", ";
                }
                if (node->left) {
                    queue.push(node->left);
                }
                if (node->right) {
                    queue.push(node->right);
                }
            }
            std::cout << std::endl;
        }
    }
};

int main(int argc, char *argv[])
{
    TreeNode *node = new TreeNode(1);
    node->left = new TreeNode(2);
    node->right = new TreeNode(3);
    node->right->left = new TreeNode(4);

    Solution solution;
    solution.printBinaryTree(node);

    solution.invertBinaryTree(node);
    solution.printBinaryTree(node);


    return 0;
}