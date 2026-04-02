#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

// 示例 1：

// 输入：lists = [[1,4,5],[1,3,4],[2,6]]
// 输出：[1,1,2,3,4,4,5,6]
// 解释：链表数组如下：
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// 将它们合并到一个有序链表中得到。
// 1->1->2->3->4->4->5->6
// 示例 2：

// 输入：lists = []
// 输出：[]
// 示例 3：

// 输入：lists = [[]]
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
  
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k == 0)
        {
            return nullptr;
        }
        return merge2Lists(lists, 0, k - 1);
    }

    ListNode* merge2Lists(vector<ListNode*>& lists, int l, int r) {
        if (l == r)
        {
            return lists[l];
        }
        
        int mid = (l + r)/2;
        ListNode *list_l = merge2Lists(lists, l, mid);
        ListNode *list_r = merge2Lists(lists, mid + 1, r);
        return merge(list_l, list_r);
    }
    
    ListNode* merge(ListNode *list1, ListNode *list2)
    {
        ListNode dummy;
        ListNode *head = &dummy;
        while(list1 && list2)
        {
            if (list1->val < list2->val)
            {
                head->next = list1;
                list1 = list1->next;
            }else{
                head->next = list2;
                list2 = list2->next;
            }
            head = head->next;
        }

        head->next = list1 ? list1 : list2;
        return dummy.next;
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
    ListNode l1_node1(5);
    ListNode l1_node2(4, &l1_node1);
    ListNode l1_node3(1, &l1_node2);

    list_print(&l1_node3);

    ListNode l2_node1(4);
    ListNode l2_node2(3, &l2_node1);
    ListNode l2_node3(1, &l2_node2);
    list_print(&l2_node3);
    
    ListNode l3_node1(6);
    ListNode l3_node2(2, &l3_node1);
    list_print(&l3_node2);
    
    vector<ListNode*> lists;
    lists.push_back(&l1_node3);
    lists.push_back(&l2_node3);
    lists.push_back(&l3_node2);

    Solution sol;
    auto result = sol.mergeKLists(lists);
    list_print(result); 
    return 0;
}