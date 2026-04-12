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
    int maxDepth(TreeNode* root) {
        if (root == NULL)
        {
            return 0;
        }

        int leftMathDepth = maxDepth(root->left) + 1;
        int rightMathDepth = maxDepth(root->right) + 1;
        return leftMathDepth < rightMathDepth ? rightMathDepth : leftMathDepth;  
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
    TreeNode t1_node0(15);
    TreeNode t1_node1(7);
    TreeNode t1_node2(20, &t1_node0, &t1_node1);
    TreeNode t1_node3(9);
    TreeNode t1_node4(3, &t1_node3, &t1_node2);

    cout << "t1:";
    list_print(&t1_node4);
    cout << endl;

    Solution sol;
    cout << sol.maxDepth(&t1_node4) << endl;

    TreeNode t2_node0(2);
    TreeNode t2_node1(1, nullptr, &t2_node0);

    cout << "t2:";
    list_print(&t2_node1);
    cout << endl;
    cout << sol.maxDepth(&t2_node1) << endl;
    return 0;
}