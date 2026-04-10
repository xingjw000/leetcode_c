#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;

// 示例 1：

// 输入：s = "ADOBECODEBANC", t = "ABC"
// 输出："BANC"
// 解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
// 示例 2：

// 输入：s = "a", t = "a"
// 输出："a"
// 解释：整个字符串 s 是最小覆盖子串。
// 示例 3:

// 输入: s = "a", t = "aa"
// 输出: ""
// 解释: t 中两个字符 'a' 均应包含在 s 的子串中，
// 因此没有符合条件的子字符串，返回空字符串。

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128,0);
        vector<int> window(128,0);

        int diff = 0;
        for (size_t i = 0; i < t.size(); i++)
        {
            need[t[i]]++;
            if (need[t[i]] == 1)
            {
                diff++;
            }
            
        }
        
        int right = 0;
        int left = 0;

        int start = 0;
        int len = INT_MAX;
        while(right < s.size())
        {
            char c = s[right];
            if (need[c] > 0)
            {
                window[c]++;
                if (need[c] == window[c])
                {
                    diff--;
                }
                
                while(diff == 0)
                {
                    if(right - left + 1 < len)
                    {
                        start = left;
                        len = right - left + 1;
                    }
                    char l_c = s[left];
                    
                    if (need[l_c] > 0)
                    {
                        if (window[l_c] == need[l_c])
                        {
                            diff++;
                        }
                        window[l_c]--;
                    }
                    
                    left++;

                }
            }

            right++;
            
        }

        return len == INT_MAX ? "": s.substr(start, len);
        
    }
};

int main()
{
    Solution sol;
    auto result = sol.minWindow("ADOBECODEBANC", "ABC");

    cout << "result:" << result << endl;

    auto result1 = sol.minWindow("a", "a");

    cout << "result1:" << result1 <<  endl; 
    
    auto result2 = sol.minWindow("a", "aa");

    cout << "result2:" << result2 <<  endl;       
    return 0;
}