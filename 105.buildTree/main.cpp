#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stack>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
  
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMap;
        inorderMap.reserve(inorder.size());
        for (int i = 0; i < inorder.size(); i++)
        {
            inorderMap.emplace(inorder[i], i);
        }
        
        if (preorder.size() < 1)
        {
            return nullptr;
        }
        auto root = new TreeNode(preorder[0]);
        stack<TreeNode *> stack;
        stack.push(root);

        for (int i = 1; i < preorder.size(); i++)
        {
            auto node = new TreeNode(preorder[i]);
            auto preNode = stack.top();
            auto preNodeIndex = inorderMap[preNode->val];
            auto node_index = inorderMap[node->val];
            if (node_index < preNodeIndex)
            {
                preNode->left = node;
            }else{
                TreeNode* parent = nullptr;
                while(!stack.empty() && inorderMap[node->val] > inorderMap[stack.top()->val])
                {
                    parent = stack.top();
                    stack.pop();
                }
                parent->right = node;
            }
            stack.push(node);
        }
        return root;
    }
};

void list_print(TreeNode *root){
    if(root == NULL)
    {
        return;
    }
    cout << "->" << root->val;
    list_print(root->left);
    list_print(root->right);
}

int main()
{
    vector<int> preorder{3,9,20,15,7};
    vector<int> inorder{9,3,15,20,7};



    Solution sol;
    auto ret = sol.buildTree(preorder, inorder);

    cout << "t1:";
    list_print(ret);
    cout << endl;
    return 0;
}