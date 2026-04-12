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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
        {
            return true;
        }

        auto dfs_left = [&](auto &&self, TreeNode* root) -> TreeNode* {
            if (root == nullptr)
            {
                return root;
            }
            
            TreeNode* tmp = self(self, root->left);
            root->left = self(self, root->right);
            root->right = tmp;
            return root;
        };
        
        dfs_left(dfs_left, root->left);

        auto dfs_right = [&](auto &&self, TreeNode* root1, TreeNode* root2) -> bool {
            if (root1 == nullptr && root2 == nullptr)
            {
                return true;
            }else if (root1 != nullptr && root2 == nullptr || root1 == nullptr && root2 != nullptr)
            {
                return false;
            }
        
            return root1->val == root2->val && self(self, root1->left, root2->left) && self(self, root1->right, root2->right);
        };

        return dfs_right(dfs_right, root->right, root->left);
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
    TreeNode t1_node0(3);
    TreeNode t1_node1(4);
    TreeNode t1_node2(2, &t1_node0, &t1_node1);
    TreeNode t1_node3(4);
    TreeNode t1_node4(3);
    TreeNode t1_node5(2, &t1_node3, &t1_node4);
    TreeNode t1_node6(1, &t1_node2, &t1_node5);

    cout << "t1:";
    list_print(&t1_node6);
    cout << endl;

    Solution sol;
    auto ret1 = sol.isSymmetric(&t1_node6);
    cout << "ret1:" << ret1 << endl;

    cout << "t1 invertTree:";
    list_print(&t1_node6);
    cout << endl;


    TreeNode t2_node1(3);
    TreeNode t2_node2(2, nullptr, &t2_node1);

    TreeNode t2_node4(3);
    TreeNode t2_node5(2, nullptr, &t2_node4);
    TreeNode t2_node6(1, &t2_node2, &t2_node5);

    cout << "t2:";
    list_print(&t2_node6);
    cout << endl;

    auto ret2 = sol.isSymmetric(&t2_node6);
    cout << "ret2:" << ret2 << endl;

    cout << "t2 invertTree:";
    list_print(&t2_node6);
    cout << endl;
    return 0;
}