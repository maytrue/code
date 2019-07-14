//
// Created by zouguowei on 2019/7/14.
//

#include "BreadthFirst.hpp"
#include <deque>
#include <queue>

std::vector<std::vector<int>> BinaryTreeLevelTraversal::levelOrder(TreeNode * root)
{
    std::vector<std::vector<int>> results;
    std::deque<TreeNode*> queue;

    if (!root) {
        return results;
    }

    queue.push_back(root);
    int nodeCount = 1;
    while (!queue.empty()) {
        int index = 0;
        std::vector<int> result;
        while (index < nodeCount && !queue.empty()) {
            TreeNode *node = queue.front();
            queue.pop_front();
            if (node) {
                result.push_back(node->val);
                queue.push_back(node->left);
                queue.push_back(node->right);
            } else {
                queue.push_back(nullptr);
                queue.push_back(nullptr);
            }
            index ++;
        }

        nodeCount = nodeCount * 2;
        while (!queue.empty()) {
            TreeNode *node = queue.back();
            if (!node) {
                queue.pop_back();
                nodeCount = nodeCount - 1;
            } else {
                break;
            }
        }
        results.push_back(result);
    }
    return results;
}

std::vector<std::vector<int>> BinaryTreeLevelTraversal::levelOrderV2(TreeNode * root)
{
    std::vector<std::vector<int>> results;
    std::queue<TreeNode*> queue;

    if (!root) {
        return results;
    }

    queue.push(root);
    int nodeCount = 1;
    while (!queue.empty()) {
        int index = 0;
        std::vector<int> result;
        int size = queue.size();
        for (int index = 0; index < size; ++index) {
            TreeNode *node = queue.front();
            queue.pop();
            result.push_back(node->val);
            if (node->left) {
                queue.push(node->left);
            }
            if (node->right) {
                queue.push(node->right);
            }
        }
        results.push_back(result);
    }
    return results;
}
