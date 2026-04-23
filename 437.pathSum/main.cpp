#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <queue>
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
    int pathSum(TreeNode* root, int targetSum) {
        int cnt = 0;
        unordered_map<long long, int> prefix_sum;
        prefix_sum[0] = 1;
        
        auto backTrace = [&](auto &&self, TreeNode* root, long long currSum) -> int{
            if (root == nullptr)
            {
                return 0;
            }

            int ret = 0;
            currSum += root->val;
            if (prefix_sum.count(currSum - targetSum))
            {
                ret = prefix_sum[currSum - targetSum];
            }

            prefix_sum[currSum]++;
            ret += self(self, root->left, currSum);
            ret += self(self, root->right, currSum);

            prefix_sum[currSum]--;
            return ret;
        };
 
        return backTrace(backTrace, root, 0);
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
    TreeNode t1_node1(-2);
    TreeNode t1_node2(3, &t1_node0, &t1_node1);
    TreeNode t1_node3(1);
    TreeNode t1_node4(2, nullptr, &t1_node3);
    TreeNode t1_node5(5, &t1_node2, &t1_node4);
    TreeNode t1_node6(11);
    TreeNode t1_node7(-3, nullptr, &t1_node6);
    TreeNode t1_node8(10, &t1_node5, &t1_node7);

    cout << "t1:";
    list_print(&t1_node8);
    cout << endl;

    Solution sol;
    cout << sol.pathSum(&t1_node8, 8) << endl;

    return 0;
}