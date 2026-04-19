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
    void flatten(TreeNode* root) {
        //dfs 1
        // TreeNode dummy;
        // TreeNode *p = &dummy;
        // if (root == nullptr)
        // {
        //     return;
        // }

        // auto dfs = [&](auto &&self, TreeNode* root) -> void {
        //     if (root == nullptr)
        //     {
        //         return;
        //     }
            
        //     TreeNode *node = new TreeNode();
        //     node->val = root->val;
        //     p->right = node;
        //     p = p->right;

        //     self(self, root->left);
        //     self(self, root->right);
        // };

        // dfs(dfs, root);
        // root->right = dummy.right->right;
        // root->left = nullptr;

        // if (root == nullptr)
        // {
        //     return;
        // }

        // dfs 2
        // flatten(root->right);
        // flatten(root->left);
        // root->left = nullptr;
        // root->right = preNode;
        // preNode = root;

        // return;

        //o(1)
        
        auto curr = root;
        while(curr != nullptr){
            if (curr->left != nullptr)
            {
                auto next = curr->left;
                auto pre = next;
                while(pre->right != nullptr)
                {
                    pre = pre->right;
                }
                pre->right = curr->right;

                curr->left = nullptr;
                curr->right = next;
            }
            curr = curr->right;
        }

    }

private:
    TreeNode *preNode = nullptr;
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

void list_print1(TreeNode *root){
    if(root == NULL)
    {
        return;
    }
    cout << "->" << root->val;
    list_print(root->right);
}

int main()
{
    TreeNode t1_node0(3);
    TreeNode t1_node1(4);
    TreeNode t1_node2(2, &t1_node0, &t1_node1);
    TreeNode t1_node3(6);
    TreeNode t1_node4(5, nullptr, &t1_node3);
    TreeNode t1_node5(1, &t1_node2, &t1_node4);

    cout << "t1:";
    list_print(&t1_node5);
    cout << endl;

    Solution sol;
    sol.flatten(&t1_node5);

    cout << "t1_after:";
    list_print1(&t1_node5);
    cout << endl;
    return 0;
}