#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

// 示例 1:

// 输入: s = "cbaebabacd", p = "abc"
// 输出: [0,6]
// 解释:
// 起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
// 起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
//  示例 2:

// 输入: s = "abab", p = "ab"
// 输出: [0,1,2]
// 解释:
// 起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
// 起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
// 起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> p_c_counts(26, 0);
        vector<int> s_c_counts(26, 0);
        vector<int> ans;
        int p_len = p.length();
        int s_len = s.length();
        if (s_len < p_len)
        {
            return {};
        }

        for (size_t i = 0; i < p_len; i++)
        {
            p_c_counts[p[i] - 'a']++;
            s_c_counts[s[i] - 'a']++;
        }

        int differ = 0;

        for (size_t i = 0; i < 26; i++)
        {
            if ( p_c_counts[i] != s_c_counts[i])
            {
                differ++;
            }
        }

        if (differ == 0)
        {
            ans.push_back(0);
        }

        for (size_t i = 0; i < s_len - p_len; i++)
        {
            if(s_c_counts[s[i] - 'a'] == p_c_counts[s[i] - 'a'])
            {
                differ++;
            }

            s_c_counts[s[i] - 'a']--;

            if(s_c_counts[s[i] - 'a'] == p_c_counts[s[i] - 'a'])
            {
                differ--;
            } 
            
            if (p_c_counts[s[i+p_len] - 'a'] == s_c_counts[s[i+p_len] - 'a'])
            {
                differ++;
            }            

            s_c_counts[s[i+p_len]  - 'a']++;

            if (p_c_counts[s[i+p_len] - 'a'] == s_c_counts[s[i+p_len] - 'a'])
            {
                differ--;
            }

            if (differ == 0)
            {
                ans.push_back(i + 1);
            }
            
        }
        
        return ans;
        
          
    }
};

int main()
{
    Solution sol;
    auto result = sol.findAnagrams("cbaebabacd", "abc");

    cout << "result:";
    for(auto &v : result)
    {
        cout << v << ",";
    }

    cout << endl;

    auto result1 = sol.findAnagrams("abab", "ab");

    cout << "result1:";
    for(auto &v : result1)
    {
        cout << v << ",";
    }

    cout << endl;    
    return 0;
}