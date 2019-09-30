#pragma once

#include "Solution.h"

/* #94  
* Given a binary tree, return the inorder traversal of its nodes' values.
*/
class InorderTraversal : public Solution
{
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;

        if (root == nullptr)
        {
            return vec;
        }

        stack<TreeNode*> ptrs;
        stack<bool> flags;
        ptrs.push(root);
        flags.push(false);

        while (!ptrs.empty())
        {
            auto ptr = ptrs.top();
            auto flag = flags.top();
            ptrs.pop();
            flags.pop();

            if (!flag)
            {
                if (ptr->right != nullptr)
                {
                    ptrs.push(ptr->right);
                    flags.push(false);
                }
                ptrs.push(ptr);
                flags.push(true);
                if (ptr->left != nullptr)
                {
                    ptrs.push(ptr->left);
                    flags.push(false);
                }
            }
            else
            {
                vec.push_back(ptr->val);
            }
        }

        return vec;
    }

    /*vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;

        if (root == nullptr)
        {
            return vec;
        }

        traverse(root, vec);
        return vec;
    }*/

    void traverse(TreeNode* root, vector<int>& vec)
    {
        if (root->left != nullptr)
        {
            traverse(root->left, vec);
        }

        vec.push_back(root->val);

        if (root->right != nullptr)
        {
            traverse(root->right, vec);
        }
    }

    virtual void Run()
    {

    }
};

/* #144
Given a binary tree, return the preorder traversal of its nodes' values.
*/
class PreorderTraversal : public Solution
{
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;

        if (root == nullptr)
        {
            return vec;
        }

        stack<TreeNode*> ptrs;
        ptrs.push(root);

        while (!ptrs.empty())
        {
            auto ptr = ptrs.top();
            ptrs.pop();

            vec.push_back(ptr->val);
            if (ptr->right != nullptr)
            {
                ptrs.push(ptr->right);
            }
            if (ptr->left != nullptr)
            {
                ptrs.push(ptr->left);
            }
        }

        return vec;
    }

    /*vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;

        if (root == nullptr)
        {
            return vec;
        }

        traverse(root, vec);
        return vec;
    }*/

    void traverse(TreeNode* root, vector<int>& vec)
    {
        vec.push_back(root->val);

        if (root->left != nullptr)
        {
            traverse(root->left, vec);
        }

        if (root->right != nullptr)
        {
            traverse(root->right, vec);
        }
    }

    virtual void Run()
    {

    }
};

/* #145
Given a binary tree, return the postorder traversal of its nodes' values.
*/
class PostorderTraversal : public Solution
{
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vec;

        if (root == nullptr)
        {
            return vec;
        }

        stack<TreeNode*> ptrs;
        stack<bool> flags;
        ptrs.push(root);
        flags.push(false);

        while (!ptrs.empty())
        {
            auto ptr = ptrs.top();
            auto flag = flags.top();
            ptrs.pop();
            flags.pop();

            if (!flag)
            {
                ptrs.push(ptr);
                flags.push(true);
                if (ptr->right != nullptr)
                {
                    ptrs.push(ptr->right);
                    flags.push(false);
                }
                if (ptr->left != nullptr)
                {
                    ptrs.push(ptr->left);
                    flags.push(false);
                }
            }
            else
            {
                vec.push_back(ptr->val);
            }
        }

        return vec;
    }

    /*vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vec;

        if (root == nullptr)
        {
            return vec;
        }

        traverse(root, vec);
        return vec;
    }*/

    void traverse(TreeNode* root, vector<int>& vec)
    {
        if (root->left != nullptr)
        {
            traverse(root->left, vec);
        }

        if (root->right != nullptr)
        {
            traverse(root->right, vec);
        }

        vec.push_back(root->val);
    }

    virtual void Run()
    {

    }
};

/* #98
*Given a binary tree, determine if it is a valid binary search tree (BST).
*/
class IsValidBST : public Solution
{
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }

    bool isValidBST(TreeNode* root, long min, long max)
    {
        if (root == NULL)
        {
            return true;
        }

        return (root->val > min) && (root->val < max) &&
            isValidBST(root->left, min, root->val) &&
            isValidBST(root->right, root->val, max);
    }

    virtual void Run()
    {

    }
};