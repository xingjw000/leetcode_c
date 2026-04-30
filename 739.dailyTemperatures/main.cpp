#include <vector>
#include <unordered_map>
#include <iostream>
#include <stack>
using namespace std;


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        vector<int> ret(len, 0);
        stack<int> toSure;

        for (int i = 0; i < len; i++)
        {
            while(!toSure.empty())
            {
                int idx = toSure.top();
                if (temperatures[i] > temperatures[idx])
                {
                    ret[idx] = i - idx;
                    toSure.pop();
                }else{
                    break;
                }
            }
            toSure.push(i);
        }
        

        return ret;
    }
};

int main()
{

    vector<int> test1 = {73,74,75,71,69,72,76,73};
    Solution sol;
    auto result = sol.dailyTemperatures(test1);

    cout << result.size() << ":"; 
    for (auto &i : result)
    {
        cout << i << ",";
    }
    cout << endl;
    
    return 0;
}