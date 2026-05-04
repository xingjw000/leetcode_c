#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i - 1 < 0 && j - 1 < 0)
                {
                    dp[i][j] = grid[i][j];
                }else if (i - 1 < 0)
                {
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                }else if (j - 1 < 0)
                {
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                }else{
                    dp[i][j] = min(dp[i - 1][j], dp[i][j-1]) + grid[i][j];
                }
                
                                
                //cout << i << "," << j << ":" << dp[i][j] << endl;
            }
        }
        
        return dp[m-1][n-1];
        
    }
};

int main()
{
    vector<vector<int>> test1 = {{1,3,1},{1,5,1},{4,2,1}};
    Solution sol;
        
    cout << sol.minPathSum(test1) << endl;

    vector<vector<int>> test2 = {{1,2,3},{4,5,6}};
        
    cout << sol.minPathSum(test2) << endl;    
    
    return 0;
}