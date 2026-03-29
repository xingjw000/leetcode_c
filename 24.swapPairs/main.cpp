#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

// 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
// 输入：head = [1,2,3,4]
// 输出：[2,1,4,3]
// 示例 2：

// 输入：head = []
// 输出：[]
// 示例 3：

// 输入：head = [1]
// 输出：[1]


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
    ListNode* swapPairs(ListNode* head) {
        ListNode new_head;
        ListNode *p1 = &new_head;
        new_head.next = head;
        while(p1->next)
        {
            ListNode *p2 = p1->next;
            if (p2 == NULL)
            {
                break;
            }
            ListNode *p3 = p2->next;
            if (p3 == NULL)
            {
                break;
            }
            
            p1->next = p3;
            p2->next = p3->next;
            p3->next = p2;
            p1 = p2;
        }

        return new_head.next;
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
    ListNode l1_node1(4);
    ListNode l1_node2(3, &l1_node1);
    ListNode l1_node3(2, &l1_node2);
    ListNode l1_node4(1, &l1_node3);

    list_print(&l1_node4);     

    Solution sol;
    auto result = sol.swapPairs(&l1_node4);
    list_print(result);  

    list_print(sol.swapPairs(NULL));     

    ListNode l2_node1(1);
    list_print(sol.swapPairs(&l2_node1)); 
    return 0;
}