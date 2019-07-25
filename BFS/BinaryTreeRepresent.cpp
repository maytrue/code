//
// Created by zouguowei on 2019/7/14.
//

#include "BreadthFirst.hpp"
#include <deque>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>

std::string BinaryTreeRepresent::serialize(TreeNode * root)
{
    std::string result;
    std::stringstream stream;
    std::vector<TreeNode *> queue;
    if (!root) {
        return result;
    }
    queue.push_back(root);

    for (int i = 0; i < queue.size(); ++i) {
        TreeNode *node = queue[i];
        if (!node) {
            continue;
        }
        queue.push_back(node->left);
        queue.push_back(node->right);
    }

    while (queue.size() > 0 && !queue[queue.size() - 1]) {
        queue.pop_back();
    }

    if (queue.size() == 0) {
        return result;
    }

    std::stringstream ss;
    ss << "{" << queue[0]->val;
    for (int i = 1; i < queue.size(); i++) {
        if (queue[i] == NULL) {
            ss << ",#";
        } else {
            ss << "," << queue[i]->val;
        }
    }
    ss << "}";

    return ss.str();
}

TreeNode * BinaryTreeRepresent::deserialize(std::string &data)
{
    TreeNode* root = nullptr;
    std::vector<std::string> strings;
    std::istringstream stream(data);
    std::string item;
    while (std::getline(stream, item, ',')) {
        std::cout << item << std::endl;
        strings.push_back(item);
    }

    int size = strings.size();
    class NodeWithIndex
    {
    public:
        TreeNode *treeNode;
        int index;
    };

    if (size > 0) {
        std::string item = strings[0];
        int value = std::stoi(item);
        TreeNode *node = new TreeNode(value);
        if (!root) {
            root = node;
        }

        std::queue<NodeWithIndex> queue;
        NodeWithIndex nodeWithIndexRoot;
        nodeWithIndexRoot.treeNode = node;
        nodeWithIndexRoot.index = 0;
        queue.push(nodeWithIndexRoot);

        while (!queue.empty()) {
            NodeWithIndex nodeWithIndex = queue.front();
            queue.pop();
            node = nodeWithIndex.treeNode;
            int left = nodeWithIndex.index * 2 + 1;
            if (left < size) {
                item = strings[left];
                if (item.compare("#") == 0) {
                    node->left = nullptr;
                } else {
                    value = std::stoi(item);
                    node->left = new TreeNode(value);

                    NodeWithIndex nodeWithIndexLeft;
                    nodeWithIndexLeft.index = left;
                    nodeWithIndexLeft.treeNode = node->left;
                    queue.push(nodeWithIndexLeft);
                }
            }

            int right = nodeWithIndex.index * 2  + 2;
            if (right < size) {
                item = strings[right];
                if (item.compare("#") == 0) {
                    node->right = nullptr;
                } else {
                    value = std::stoi(item);
                    node->right = new TreeNode(value);
                    NodeWithIndex nodeWithIndexLeft;
                    nodeWithIndexLeft.index = right;
                    nodeWithIndexLeft.treeNode = node->right;
                    queue.push(nodeWithIndexLeft);
                }
            }
        }

    }
    return root;
}