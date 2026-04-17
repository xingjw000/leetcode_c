#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <queue>
using namespace std;

// 示例 1：

// 输入：root = [1,2,3,null,5,null,4]

// 输出：[1,3,4]
// 输入：root = [1,2,3,4,null,null,null,5]

// 输出：[1,3,4,5]



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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        queue<TreeNode *> q;
        if (root == nullptr)
        {
            return {};
        }
        q.push(root);

        while(!q.empty()){
            int len = q.size();

            while(len--){
                auto node = q.front();
                if (len == 0)
                {
                    ret.push_back(node->val);
                }
                q.pop();

                if (node->left)
                {
                    q.push(node->left);
                }
                
                if (node->right)
                {
                    q.push(node->right);
                }
            }
        }

        return ret;
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
    TreeNode t1_node0(5);
    TreeNode t1_node1(2, nullptr, &t1_node0);
    TreeNode t1_node2(4);
    TreeNode t1_node3(3, nullptr, &t1_node2);
    TreeNode t1_node4(1, &t1_node1, &t1_node3);

    cout << "t1:";
    list_print(&t1_node4);
    cout << endl;

    Solution sol;
    auto ret = sol.rightSideView(&t1_node4);

    cout << "ret :";
    for (auto &v : ret)
    {
        cout << v << ",";
    }
    cout << endl;

    TreeNode t2_node0(5);
    TreeNode t2_node1(4, &t2_node0, nullptr);
    TreeNode t2_node2(2, &t2_node1, nullptr);
    TreeNode t2_node3(3);
    TreeNode t2_node4(1, &t2_node2, &t2_node3);

    cout << "t2:";
    list_print(&t2_node4);
    cout << endl;

    auto ret1 = sol.rightSideView(&t2_node4);

    cout << "ret1 :";
    for (auto &v : ret1)
    {
        cout << v << ",";
    }
    cout << endl;
    return 0;
}