#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

// 给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。

// k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

// 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

// 输入：head = [1,2,3,4,5], k = 2
// 输出：[2,1,4,3,5]

// 输入：head = [1,2,3,4,5], k = 3
// 输出：[3,2,1,4,5]


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void list_print(ListNode *list);
  
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        auto dfs = [&](auto &&self, ListNode* head, int k, int k_level, bool &isReverse) -> ListNode* {
            bool next_isReverse = false;
            if (head == NULL)
            {
                isReverse = false;

                return head;
            }

            if (k_level == 1 && k > 1)
            {
                isReverse = true;

            }

            ListNode *ret = self(self, head->next, k, k_level == 1 ? k:(k_level - 1), next_isReverse);
      
            if (next_isReverse)
            {
                ListNode *next = head->next;
                head->next = next->next;
                next->next = head;

                if (k_level != k)
                {
                    isReverse = true;
                }      
                
            }else{  
                if (k_level == 1)
                {
                    head->next = ret;
                }
                 
                ret = head;
            }

            return ret;
            
        };

        bool next_isReverse = false;
        return dfs(dfs, head, k, k, next_isReverse);
        
    }
};

void list_print(ListNode *list){
    cout << "list:";
    while (list)
    {
       cout << list->val << "->";
       list = list->next;
    }
    cout << "null" << endl;
    
}

int main()
{
    ListNode l1_node1(11);
    ListNode l1_node2(10, &l1_node1);
    ListNode l1_node3(9, &l1_node2);
    ListNode l1_node4(8, &l1_node3);
    ListNode l1_node5(7, &l1_node4);
    ListNode l1_node6(6, &l1_node5);
    ListNode l1_node7(5, &l1_node6);
    ListNode l1_node8(4, &l1_node7);
    ListNode l1_node9(3, &l1_node8);
    ListNode l1_node10(2, &l1_node9);
    ListNode l1_node11(1, &l1_node10);         

    list_print(&l1_node11);     

    Solution sol;
    auto result = sol.reverseKGroup(&l1_node11, 3);
    list_print(result);  

    // list_print(sol.swapPairs(NULL));     

    // ListNode l2_node1(1);
    // list_print(sol.swapPairs(&l2_node1)); 
    return 0;
}