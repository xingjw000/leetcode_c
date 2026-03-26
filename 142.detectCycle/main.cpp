#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

// 输入：head = [3,2,0,-4], pos = 1
// 输出：返回索引为 1 的链表节点
// 解释：链表中有一个环，其尾部连接到第二个节点。

// 输入：head = [1,2], pos = 0
// 输出：返回索引为 0 的链表节点
// 解释：链表中有一个环，其尾部连接到第一个节点。

// 输入：head = [1], pos = -1
// 输出：返回 null
// 解释：链表中没有环。



struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
  
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL)
        {
            return NULL;
        }
        
        ListNode *fast = head;
        ListNode *slow = head;
        std::unordered_set<ListNode *> slow_set;

        do
        {
            slow_set.insert(slow);
            slow = slow->next;
            fast = fast->next;
            if (fast)
            {
                auto it = slow_set.find(fast);
                if (it != slow_set.end())
                {
                    return *it;
                }                
                fast = fast->next;
                it = slow_set.find(fast);
                if (it != slow_set.end())
                {
                    return *it;
                }                  
                
            }else{
                return NULL;
            }
        }while(fast && slow && fast != slow);
        
        return fast;
    }
};

void list_print(ListNode *list, int n){
    cout << "list:";
    while (list && n >0)
    {
       cout << list->val << "->";
       list = list->next;
       n--;
    }
    cout << "null" << endl;
    
}

int main()
{
    ListNode l1_node0(5);
    ListNode l1_node1(-4,&l1_node0);
    ListNode l1_node2(0, &l1_node1);
    ListNode l1_node3(2, &l1_node2);
    ListNode l1_node4(3, &l1_node3);
    l1_node0.next = &l1_node3;

    list_print(&l1_node4, 5);

    // ListNode l1_node0(2);
    // ListNode l1_node1(1,&l1_node0); 
    // l1_node0.next = &l1_node1;
    // list_print(&l1_node1, 2);   

    // ListNode l2_node1(4);
    // ListNode l2_node2(3, &l2_node1);
    // ListNode l2_node3(1, &l2_node2);
    // list_print(&l2_node3);    

    Solution sol;
    auto result = sol.detectCycle(&l1_node4);
    cout << result->val << endl;
    return 0;
}