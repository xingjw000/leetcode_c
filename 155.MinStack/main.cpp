#include <vector>
#include <unordered_map>
#include <iostream>
#include <stack>
#include <limits.h>
using namespace std;


class MinStack {
public:
    MinStack() {
        m_stack.emplace(0, INT_MAX);
    }
    
    void push(int val) {
        m_stack.emplace(val, min(m_stack.top().second, val));
    }
    
    void pop() {
        m_stack.pop();
    }
    
    int top() {
        return m_stack.top().first;
    }
    
    int getMin() {
        return m_stack.top().second;
    }

private:
    stack<pair<int, int>> m_stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    MinStack *minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    cout << minStack->getMin() << endl;
    minStack->pop();
    cout << minStack->top() << endl;
    cout << minStack->getMin() << endl;
    return 0;
}