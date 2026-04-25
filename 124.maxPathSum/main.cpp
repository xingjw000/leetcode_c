#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <queue>
#include <stack>
#include "limits.h"
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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        auto maxGrain = [&](auto &&self, TreeNode *root) -> int{
            if (root == nullptr)
            {
                return 0;
            }

            int leftMaxGrain = max(self(self, root->left), 0);
            int rightMaxGrain = max(self(self, root->right), 0);
            
            maxSum = max(maxSum, root->val + leftMaxGrain + rightMaxGrain);
            return max(leftMaxGrain, rightMaxGrain) + root->val;
        };
        maxGrain(maxGrain, root);
        return maxSum;
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
    TreeNode t1_node4(-10, &t1_node3, &t1_node2);

    cout << "t1:";
    list_print(&t1_node4);
    cout << endl;

    Solution sol;
    cout << sol.maxPathSum(&t1_node4) << endl;

    return 0;
}