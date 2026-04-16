#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stack>
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
    int kthSmallest(TreeNode* root, int k) {

        // int ret;
        // int count = k;
        
        // auto helper = [&](auto &&self, TreeNode* root) -> bool{
        //     if (root == nullptr)
        //     {
        //         return false;
        //     }

        //     if(self(self, root->left))
        //     {
        //         return true;
        //     }
        //     count--;
        //     //cout << "k:" << count << "value :" << root->val << endl;
        //     if (count == 0)
        //     {
        //         ret = root->val;
        //         return true;
        //     }
            
        //     if(self(self, root->right)){
        //         return true;
        //     }
        //     return false;
        // };
        
        // helper(helper, root);
        // return ret;

        stack<TreeNode *> s;

        while(root != nullptr || !s.empty()){
            while(root != nullptr){
                s.push(root);
                root = root->left;
            }
            
            root = s.top();
            s.pop();
            k--;
            if(k == 0){
                break;
            }

            root = root->right;
        }

        return root->val;
    }
};

void list_print(TreeNode *root){
    if(root == NULL)
    {
        return;
    }
    
    list_print(root->left);
    cout << "->" << root->val;    
    list_print(root->right);
}

int main()
{
    TreeNode t1_node0(2);
    TreeNode t1_node1(1, nullptr, &t1_node0);
    TreeNode t1_node2(4);
    TreeNode t1_node3(3, &t1_node1, &t1_node2);

    cout << "t1:";
    list_print(&t1_node3);
    cout << endl;

    Solution sol;
    cout << sol.kthSmallest(&t1_node3, 1) << endl;

    TreeNode t2_node0(1);
    TreeNode t2_node1(2, &t2_node0, nullptr);
    TreeNode t2_node2(4);
    TreeNode t2_node3(3, &t2_node1, &t2_node2);
    TreeNode t2_node4(6);
    TreeNode t2_node5(5, &t2_node3, &t2_node4);

    cout << "t2:";
    list_print(&t2_node5);
    cout << endl;
    cout << sol.kthSmallest(&t2_node5, 3) << endl;
    return 0;
}