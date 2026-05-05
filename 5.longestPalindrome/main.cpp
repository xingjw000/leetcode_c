#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        if (n == 1)
        {
            return s;
        }
        

        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
        }
        int maxLen = 1;
        int begin = 0;

        for (int L = 2; L <= n; L++)
        {
            for (int i = 0; i < n; i++)
            {
                int j = i + L - 1;
                if (j >= n)
                {
                    break;
                }

                if (s[i] != s[j])
                {
                    dp[i][j] = false;
                }else{
                    if (j - i < 2)
                    {
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = dp[i+1][j-1];
                    }
                    
                }

                if (dp[i][j] && L > maxLen)
                {
                    begin = i;
                    maxLen = L;
                }
                
            }
            
        }

        return s.substr(begin, maxLen);
    }
};

int main()
{
    Solution sol;
    cout << sol.longestPalindrome("babad") << endl;
    cout << sol.longestPalindrome("cddb") << endl;
    return 0;
}