#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

// 输入：l1 = [2,4,3], l2 = [5,6,4]
// 输出：[7,0,8]
// 解释：342 + 465 = 807.
// 示例 2：

// 输入：l1 = [0], l2 = [0]
// 输出：[0]
// 示例 3：

// 输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// 输出：[8,9,9,9,0,0,0,1]


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool isCarry = false;
        ListNode head;
        ListNode *p = &head;
        while(l1 && l2)
        {
            p->next = l1;
            int sum = l1->val + l2->val + (isCarry ? 1 : 0);
            int singleDigit = sum - 10;
            if (singleDigit >= 0)
            {
                isCarry = true;
            }
            else
            {
                isCarry = false;
            }
            p->next->val = isCarry ? singleDigit : sum;

            l1 = l1->next;
            l2 = l2->next;
            p = p->next; 
        }

        if(l1)
        {
            p->next = l1;
        }else {
            p->next = l2;
        }       

        if (!isCarry)
        {

            return head.next;
        }
        else
        {
            ListNode *pre_p = p;
            p = p->next;

            while(p)
            {
                int sum = p->val + (isCarry ? 1 : 0);
                int singleDigit = sum - 10;
                if (singleDigit >= 0)
                {
                    isCarry = true;
                }
                else{
                    isCarry = false;
                }

                p->val = isCarry ? singleDigit : sum;
                pre_p = p;
                p = p->next;
            }

            if (isCarry)
            {
                pre_p->next = new ListNode(1);
            }
            
            return head.next; 
        }       
        
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
    // ListNode l1_node1(2);
    // ListNode l1_node2(4, &l1_node1);
    // ListNode l1_node3(3, &l1_node2);

    // list_print(&l1_node3);

    // ListNode l2_node1(5);
    // ListNode l2_node2(6, &l2_node1);
    // ListNode l2_node3(4, &l2_node2);
    // list_print(&l2_node3); 
    
    // ListNode l1_node1(0);


    // list_print(&l1_node1);

    // ListNode l2_node1(0);

    // list_print(&l2_node1);
    
    // ListNode l1_node1(9);
    // ListNode l1_node2(9, &l1_node1);
    // ListNode l1_node3(9, &l1_node2);
    // ListNode l1_node4(9, &l1_node3);
    // ListNode l1_node5(9, &l1_node4);
    // ListNode l1_node6(9, &l1_node5);
    // ListNode l1_node7(9, &l1_node6);

    // list_print(&l1_node7);

    // ListNode l2_node1(9);
    // ListNode l2_node2(9, &l2_node1);
    // ListNode l2_node3(9, &l2_node2);
    // ListNode l2_node4(9, &l2_node3);
    // list_print(&l2_node4); 
    
    ListNode l1_node1(9);
    ListNode l1_node2(9, &l1_node1);
    ListNode l1_node3(9, &l1_node2);
    ListNode l1_node4(8, &l1_node3);
    ListNode l1_node5(9, &l1_node4);
    ListNode l1_node6(9, &l1_node5);
    ListNode l1_node7(9, &l1_node6);
    ListNode l1_node8(9, &l1_node7);
    ListNode l1_node9(9, &l1_node8);
    ListNode l1_node10(1, &l1_node9);

    list_print(&l1_node10);

    ListNode l2_node1(9);
    list_print(&l2_node1);     

    Solution sol;
    auto result = sol.addTwoNumbers(&l1_node10, &l2_node1);
    list_print(result); 
    return 0;
}