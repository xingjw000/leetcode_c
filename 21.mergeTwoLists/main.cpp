#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

// 输入：l1 = [1,2,4], l2 = [1,3,4]
// 输出：[1,1,2,3,4,4]
// 示例 2：

// 输入：l1 = [], l2 = []
// 输出：[]
// 示例 3：

// 输入：l1 = [], l2 = [0]
// 输出：[0]


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
  
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode head;
        ListNode *p = &head;
        while(list1 != NULL && list2 != NULL){
            if (list1->val < list2->val)
            {
                p->next = list1;
                list1= list1->next;
            }else{
                p->next = list2;
                list2 = list2->next;
            }
            p = p->next;
        }

        if (list1 != NULL)
        {
            p->next = list1;
        }else{
            p->next = list2;
        }

        return head.next;
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
    ListNode l1_node2(2, &l1_node1);
    ListNode l1_node3(1, &l1_node2);

    list_print(&l1_node3);

    ListNode l2_node1(4);
    ListNode l2_node2(3, &l2_node1);
    ListNode l2_node3(1, &l2_node2);
    list_print(&l2_node3);    

    Solution sol;
    auto result = sol.mergeTwoLists(&l1_node3, &l2_node3);
    list_print(result); 
    return 0;
}