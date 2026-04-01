#include <vector>
#include <unordered_map>
#include <iostream>
#include <functional>
using namespace std;

// 输入：head = [4,2,1,3]
// 输出：[1,2,3,4]

// 输入：head = [-1,5,3,4,0]
// 输出：[-1,0,3,4,5]

// 输入：head = []
// 输出：[]


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
    ListNode* sortList(ListNode* head) {
        if (!head)
        {
            return head;
        }
        


        function<ListNode *(ListNode *left, ListNode *right)> dfs;

        dfs = [&](ListNode *left, ListNode *right) -> ListNode *{
            if (left == nullptr)
            {
                return left;
            }

            if (left->next == right)
            {
                left->next = nullptr;
                return left;
            }
            

            ListNode *slow = left;
            ListNode *fast = left;
            
            while(fast != right)
            {
                slow = slow->next;
                fast = fast->next;
                if(fast != right){
                    fast = fast->next;
                }
            }

            ListNode *mid = slow;
            
            ListNode *list_l = dfs(left, mid);
            ListNode *list_r = dfs(mid, right);

            return megeList(list_l, list_r);
        };

        return dfs(head, nullptr); 
    }

    ListNode* megeList(ListNode* list1, ListNode* list2){
        ListNode dummyHead;
        ListNode *p = &dummyHead;
        ListNode *p1 = list1;
        ListNode *p2 = list2;
        while(p1 && p2){
            if (p1->val < p2->val)
            {
                p->next = p1;
                p1 = p1->next;
            }
            else{
                p->next = p2;
                p2 = p2->next;
            } 
            p = p->next;
        }

        if (p1)
        {
            p->next = p1;
        }else if(p2){
            p->next = p2;
        }
       return  dummyHead.next;
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
    ListNode l1_node1(0);
    ListNode l1_node2(4, &l1_node1);
    ListNode l1_node3(3, &l1_node2);
    ListNode l1_node4(5, &l1_node3);
    ListNode l1_node5(-1, &l1_node4);

    list_print(&l1_node5); 

    Solution sol;
    auto result = sol.sortList(&l1_node5);
    list_print(result); 
    return 0;
}