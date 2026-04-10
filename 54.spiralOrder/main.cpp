#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

// 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
// 输出：[1,2,3,6,9,8,7,4,5]
// 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// 输出：[1,2,3,4,8,12,11,10,9,5,6,7]

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        ans.reserve(m*n);

        auto dfs = [&](auto &&self, int m_start, int m, int n_start, int n){
            if (m_start >= m || n_start >= n)
            {
                return;
            }

            for (int i = n_start; i < n; i++)
            {
                ans.push_back(matrix[m_start][i]);
            }

            for (int i = m_start + 1; i < m; i++)
            {
                ans.push_back(matrix[i][n - 1]);
            }

            for (int i = n - 2; i >= n_start + 1; i--)
            {
                ans.push_back(matrix[m - 1][i]);
            }

            for (int i = m - 1; i >= m_start + 1; i--)
            {
                ans.push_back(matrix[i][n_start]);
            }
            
            self(self, m_start + 1, m - 1, n_start + 1, n - 1); 
        };

        dfs(dfs, 0, m, 0 , n);

        return ans;
    }
};

int main()
{
    vector<vector<int>> test1 = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    Solution sol;
    auto result = sol.spiralOrder(test1);
    cout << "result:";
    for(auto &v : result)
    {
        cout << v << ",";
    }

    cout << endl;

    vector<vector<int>> test2 = {{1,2,3}, {4,5,6}, {7,8,9}};

    auto result1 = sol.spiralOrder(test2);
    cout << "result1:";
    for(auto &v : result1)
    {
        cout << v << ",";
    }

    cout << endl;    
    return 0;
}