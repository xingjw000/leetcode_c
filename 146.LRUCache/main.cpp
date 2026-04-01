#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

// 请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
// 实现 LRUCache 类：
// LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
// void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
// 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。

struct CacheNode
{
    int key;
    int value;
    CacheNode *next;
    CacheNode *pre;
};


  
class LRUCache {
public:
    LRUCache(int capacity) {
        m_capacity = capacity;
        cacheIndexs.reserve(m_capacity);
        head.next = &head;
        head.pre = &head;
    }
    
    int get(int key) {
        auto it = cacheIndexs.find(key);
        if (it != cacheIndexs.end())
        {
            auto node = it->second;
            if (node)
            {
                if (head.pre != node)
                {
                    node->pre->next = node->next;
                    node->next->pre = node->pre;

                    list_append(&head, node);                    
                }
                
                return node->value;
            }  
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (m_capacity == 0)
        {
            return;
        }
        
        auto it = cacheIndexs.find(key);
        if (it != cacheIndexs.end())
        {
            auto node = it->second;
            node->value = value;
            
            node->pre->next = node->next;
            node->next->pre = node->pre;

            list_append(&head, node);


        }else{
            if (cacheIndexs.size() <  m_capacity)
            {
                auto new_node = new CacheNode();
                new_node->key = key;
                new_node->value = value;

                list_append(&head, new_node);
                cacheIndexs[key] = new_node;
            }else{
                CacheNode *oldest_node = list_delete_head(&head);
                int oldest_node_key = oldest_node->key;
                cacheIndexs.erase(oldest_node_key);

                oldest_node->key = key;
                oldest_node->value = value;
                list_append(&head, oldest_node);
                cacheIndexs[key] = oldest_node;
            }
            
        }
        
    }

    void list_append(CacheNode *head, CacheNode *node)
    {
        head->pre->next = node;
        node->pre = head->pre;
        head->pre = node;
        node->next = head;
    }

    CacheNode *list_delete_head(CacheNode *head)
    {
        if (head->next == head)
        {
            return nullptr;
        }
        CacheNode *d_node = head->next;
        head->next = d_node->next;
        d_node->next->pre = head;
        return d_node;
    }

private:
    unordered_map<int, CacheNode*> cacheIndexs;
    CacheNode head;
    int  m_capacity;   
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    LRUCache *lRUCache = new LRUCache(2);
    lRUCache->put(1, 1); // 缓存是 {1=1}
    lRUCache->put(2, 2); // 缓存是 {1=1, 2=2}
    cout << lRUCache->get(1) << endl;    // 返回 1
    lRUCache->put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    cout << lRUCache->get(2) << endl;   // 返回 -1 (未找到)
    lRUCache->put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    cout << lRUCache->get(1) << endl;   // 返回 -1 (未找到)
    cout << lRUCache->get(3) << endl;   // 返回 3
    cout << lRUCache->get(4) << endl;    // 返回 4
    return 0;
}