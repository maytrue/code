//
// Created by zouguowei on 2019/7/14.
//

#include <gtest/gtest.h>
#include "BreadthFirst.hpp"

TEST(BFS, BinaryTreeLevel) {
//    {
//        TreeNode *node = new TreeNode(1);
//        TreeNode *left = new TreeNode(2);
//        TreeNode *right = new TreeNode(3);
//        node->left = left;
//        node->right = right;
//
//        BinaryTreeLevelTraversal solution;
//        auto results = solution.levelOrderV2(node);
//        for (auto &result : results) {
//            for (auto &item : result) {
//                std::cout << item << " ";
//            }
//            std::cout << std::endl;
//        }
//    }
//
//    {
//        TreeNode *node = new TreeNode(1);
//        TreeNode *right = new TreeNode(2);
//        node->left = nullptr;
//        node->right = right;
//
//        right->left = nullptr;
//        right->right = new TreeNode(3);
//
//        BinaryTreeLevelTraversal solution;
//        auto results = solution.levelOrderV2(node);
//        for (auto &result : results) {
//            for (auto &item : result) {
//                std::cout << item << " ";
//            }
//            std::cout << std::endl;
//        }
//    }
//
//    {
//        TreeNode *node = new TreeNode(1);
//        TreeNode *left = new TreeNode(2);
//        node->left = left;
//        node->right = nullptr;
//
//        left->left = new TreeNode(3);
//        left->right = nullptr;
//
//        BinaryTreeLevelTraversal solution;
//        auto results = solution.levelOrderV2(node);
//        for (auto &result : results) {
//            for (auto &item : result) {
//                std::cout << item << " ";
//            }
//            std::cout << std::endl;
//        }
//    }
}

TEST(BFS, BinaryTreeRepresent) {

    {
        TreeNode *node = new TreeNode(3);
        TreeNode *left = new TreeNode(9);
        TreeNode *right = new TreeNode(20);
        node->left = left;
        node->right = right;

        node->left->left = nullptr;
        node->left->right = nullptr;

        node->right->left = new TreeNode(15);
        node->right->right = new TreeNode(7);

        BinaryTreeRepresent solution;
        auto result = solution.serialize(node);
        std::cout << result << std::endl;
    }

    {
        TreeNode *node = new TreeNode(1);
        TreeNode *left = new TreeNode(2);
        node->left = left;
        node->right = nullptr;

        node->left->left = new TreeNode(3);
        node->left->right = new TreeNode(4);

        BinaryTreeRepresent solution;
        auto result = solution.serialize(node);
        std::cout << result << std::endl;
    }

    {
        std::string input = "3,9,20,#,#,15,7";
        BinaryTreeRepresent solution;
        solution.deserialize(input);
    }

}