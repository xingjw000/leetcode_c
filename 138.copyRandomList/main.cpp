#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

// 输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
// 输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
// 示例 2：
// 输入：head = [[1,1],[2,1]]
// 输出：[[1,1],[2,1]]
// 示例 3：
// 输入：head = [[3,null],[3,0],[3,null]]
// 输出：[[3,null],[3,0],[3,null]]


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

void list_print(Node *list);


class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* src_p = head;
        std::unordered_map<Node*, Node*> nodes;
        nodes.reserve(1000);
        while(src_p)
        {
            Node *p = new Node(src_p->val);
            nodes[src_p] = p;
            src_p = src_p->next;
        }

        src_p = head;
        while(src_p)
        {
            nodes[src_p]->next = nodes[src_p->next];
            nodes[src_p]->random = nodes[src_p->random];
            src_p = src_p->next;
        }

        return nodes[head];
    }
};

void list_print(Node *list){
    cout << "list:";
    while (list)
    {
       cout << list->val << "(" << (list->random ?  list->random->val : -1) << ")" << "->";
       list = list->next;
    }
    cout << "null" << endl;
    
}

int main()
{
    Node l1_node1(1);
    
    Node l1_node2(10);

    Node l1_node3(11);
    Node l1_node4(13);
    Node l1_node5(7);  
    
    l1_node1.random = &l1_node5;

    l1_node2.next = &l1_node1;
    l1_node2.random = &l1_node3;

    l1_node3.next = &l1_node2;
    l1_node3.random = &l1_node1;

    l1_node4.next = &l1_node3;
    l1_node4.random = &l1_node5;

    l1_node5.next = &l1_node4;

    list_print(&l1_node5);     

    Solution sol;
    auto result = sol.copyRandomList(&l1_node5);
    list_print(result);  

    return 0;
}