//
// Created by zouguowei on 2019/7/14.
//

#ifndef PROJECT_BREADTHFIRST_HPP
#define PROJECT_BREADTHFIRST_HPP

#include <vector>
#include <string>

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = nullptr;
    }
};

class BinaryTreeLevelTraversal
{
public:
    std::vector<std::vector<int>> levelOrder(TreeNode * root);

    std::vector<std::vector<int>> levelOrderV2(TreeNode * root);
};

class BinaryTreeRepresent
{
public:

    /**
 * This method will be invoked first, you should design your own algorithm
 * to serialize a binary tree which denote by a root node to a string which
 * can be easily deserialized by your own "deserialize" method later.
 */
    std::string serialize(TreeNode * root);

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in
     * "serialize" method.
     */
    TreeNode * deserialize(std::string &data);
};

#endif //PROJECT_BREADTHFIRST_HPP
