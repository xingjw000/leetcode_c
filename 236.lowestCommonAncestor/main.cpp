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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool p_find = false;
        bool q_find = false;
        stack<TreeNode *> p_path;
        stack<TreeNode *> q_path;

        auto dfs = [&](auto &&self, TreeNode* root, TreeNode* p, TreeNode* q)
        {
            if (root == nullptr)
            {
                return;
            }

            if (!p_find)
            {
                p_path.push(root);
            }

            if (!q_find)
            {
                q_path.push(root);
            }


            if (root == p)
            {
                p_find = true;
            }
            
            if (root == q)
            {
                q_find = true;
            }

            if (!p_find || !q_find)
            {
                self(self, root->left, p ,q);
            }

            if (!p_find || !q_find)
            {
                self(self, root->right, p ,q);
            }            
            
            if (!p_find)
            {
                p_path.pop();
            }
            
            if (!q_find)
            {
                q_path.pop();
            }            
            
        };

        dfs(dfs, root, p, q);

        while (p_path.size() > q_path.size())
        {
            p_path.pop();
        }

        while (p_path.size() < q_path.size())
        {
            q_path.pop();
        }        
        
        while(!p_path.empty() && !q_path.empty())
        {
            if (p_path.top() == q_path.top())
            {
                return p_path.top();
            }
            p_path.pop();
            q_path.pop();
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
    TreeNode t1_node0(7);
    TreeNode t1_node1(4);
    TreeNode t1_node2(2, &t1_node0, &t1_node1);
    TreeNode t1_node3(6);
    TreeNode t1_node4(5, &t1_node3, &t1_node2);
    TreeNode t1_node5(0);
    TreeNode t1_node6(8);
    TreeNode t1_node7(1, &t1_node5, &t1_node6);
    TreeNode t1_node8(3, &t1_node4, &t1_node7);

    cout << "t1:";
    list_print(&t1_node8);
    cout << endl;

    Solution sol;
    cout << sol.lowestCommonAncestor(&t1_node8, &t1_node4, &t1_node1)->val << endl;

    return 0;
}