#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

// 输入：root = [3,9,20,null,null,15,7]
// 输出：3
// 示例 2：

// 输入：root = [1,null,2]
// 输出：2



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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
        {
            return root;
        }

        TreeNode* tmp = invertTree(root->left);
        root->left = invertTree(root->right);
        root->right = tmp;
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
    TreeNode t1_node0(1);
    TreeNode t1_node1(3);
    TreeNode t1_node2(2, &t1_node0, &t1_node1);
    TreeNode t1_node3(6);
    TreeNode t1_node4(9);
    TreeNode t1_node5(7, &t1_node3, &t1_node4);
    TreeNode t1_node6(4, &t1_node2, &t1_node5);

    cout << "t1:";
    list_print(&t1_node6);
    cout << endl;

    Solution sol;
    auto ret1 = sol.invertTree(&t1_node6);

    cout << "t1 invertTree:";
    list_print(ret1);
    cout << endl;

    TreeNode t2_node0(1);
    TreeNode t2_node1(3);
    TreeNode t2_node2(2, &t2_node0, &t2_node1);

    cout << "t2:";
    list_print(&t2_node2);
    cout << endl;
    auto ret2 = sol.invertTree(&t2_node2);

    cout << "t2 invertTree:";
    list_print(ret2);
    cout << endl;
    return 0;
}