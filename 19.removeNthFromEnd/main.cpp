#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

// 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
// 输入：head = [1,2,3,4,5], n = 2
// 输出：[1,2,3,5]
// 示例 2：

// 输入：head = [1], n = 1
// 输出：[]
// 示例 3：

// 输入：head = [1,2], n = 1
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode new_head;
        new_head.next = head;
        ListNode *n_head = &new_head;
        ListNode *n_tail = &new_head;
        int n_div = 0;
        while(n_tail->next){
            if (n_div == n)
            {
                n_head = n_head->next;
            }else{      
                n_div++;
            }
            n_tail = n_tail->next;
        }

        // delete
        n_tail = n_head->next->next;
        n_head->next = n_tail;

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
    // ListNode l1_node1(5);
    // ListNode l1_node2(4, &l1_node1);
    // ListNode l1_node3(3, &l1_node2);
    // ListNode l1_node4(2, &l1_node3);
    // ListNode l1_node5(1, &l1_node4);

    ListNode l1_node1(5);
    ListNode l1_node2(4, &l1_node1);

    list_print(&l1_node2);   

    Solution sol;
    auto result = sol.removeNthFromEnd(&l1_node2, 1);
    list_print(result); 
    return 0;
}