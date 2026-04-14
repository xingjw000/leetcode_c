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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      

        auto dfs = [&](auto &&self, int left, int right) -> TreeNode* {
            if (left > right)
            {
                return nullptr;
            }
            
            int mid = (left + right)/2;
            TreeNode *node = new TreeNode(nums[mid]);
            node->left = self(self, left, mid - 1);
            node->right = self(self, mid + 1, right);
            return node;
        };

        return dfs(dfs, 0, nums.size() - 1);
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



    vector<int> nums{-10,-3,0,5,9};
    Solution sol;
    auto t1 = sol.sortedArrayToBST(nums);

    cout << "t1:";
    list_print(t1);
    cout << endl;    

    vector<int> nums1{1,3};
    auto t2 = sol.sortedArrayToBST(nums1);

    cout << "t2:";
    list_print(t2);
    cout << endl;
    return 0;
}