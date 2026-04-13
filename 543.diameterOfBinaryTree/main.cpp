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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }

        int maxDiameter = 0;
        auto maxDeth = [&](auto &&self, TreeNode* root) -> int{
            if (root == nullptr)
            {
                return 0;
            }
            
            int leftMax = self(self, root->left);
            int rightMax = self(self, root->right);
            int currDiameter =  leftMax + rightMax;
            if (maxDiameter < currDiameter)
            {
                maxDiameter = currDiameter;
            }
            
            return max(leftMax, rightMax) + 1;  
        };
        maxDeth(maxDeth, root);

        return maxDiameter;
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
    TreeNode t1_node0(4);
    TreeNode t1_node1(5);
    TreeNode t1_node2(2, &t1_node0, &t1_node1);
    TreeNode t1_node3(3);
    TreeNode t1_node4(1, &t1_node2, &t1_node3);

    cout << "t1:";
    list_print(&t1_node4);
    cout << endl;

    Solution sol;
    cout << sol.diameterOfBinaryTree(&t1_node4) << endl;

    TreeNode t2_node0(2);
    TreeNode t2_node1(1, nullptr, &t2_node0);

    cout << "t2:";
    list_print(&t2_node1);
    cout << endl;
    cout << sol.diameterOfBinaryTree(&t2_node1) << endl;
    return 0;
}