#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

// 输入：root = [2,1,3]
// 输出：true

// 输入：root = [5,1,4,null,null,3,6]
// 输出：false
// 解释：根节点的值是 5 ，但是右子节点的值是 4 。



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
    bool isValidBST(TreeNode* root) {
        
        auto bfs = [&](auto &&self, TreeNode* root, int &min_value, int &max_value) -> bool{
            if (root != nullptr && root->left == nullptr && root->right == nullptr)
            {
                min_value = root->val;
                max_value = root->val;
                return true;
            }
            

            int left_min_value;
            int left_max_value;
            bool leftIsValidBST = true;
            bool isLeftMaxSmall = true;
            if (root->left != nullptr)
            {
                leftIsValidBST = self(self, root->left, left_min_value, left_max_value);
                isLeftMaxSmall = left_max_value < root->val ? true : false;
                
            }else{
                left_min_value = root->val;
                left_max_value = root->val;
            }
            min_value = left_min_value;
            
            

            int right_min_value;
            int right_max_value;
            bool rightIsValidBST = true;
            bool isRightMinBiger = true;
            if (root->right != nullptr)
            {
                rightIsValidBST = self(self, root->right, right_min_value, right_max_value);
                isRightMinBiger =  root->val < right_min_value ? true : false;
                
            }else{
                right_min_value = root->val;
                right_max_value = root->val;
            }
            max_value = right_max_value; 

            return leftIsValidBST && rightIsValidBST && isLeftMaxSmall && isRightMinBiger;
        };

        int min_value;
        int max_value;
        return bfs(bfs, root, min_value, max_value);
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
    TreeNode t1_node1(6);
    TreeNode t1_node2(4, &t1_node0, &t1_node1);
    TreeNode t1_node3(1);
    TreeNode t1_node4(5, &t1_node3, &t1_node2);

    cout << "t1:";
    list_print(&t1_node4);
    cout << endl;

    Solution sol;
    cout << sol.isValidBST(&t1_node4) << endl;

    TreeNode t2_node0(1);
    TreeNode t2_node1(3);
    TreeNode t2_node2(2, &t2_node0, &t2_node1);

    cout << "t2:";
    list_print(&t2_node2);
    cout << endl;
    cout << sol.isValidBST(&t2_node2) << endl;

    TreeNode t3_node0(-1);
    TreeNode t3_node1(0, &t3_node0, nullptr);

    cout << "t3:";
    list_print(&t3_node1);
    cout << endl;
    cout << sol.isValidBST(&t3_node1) << endl;    
    return 0;
}