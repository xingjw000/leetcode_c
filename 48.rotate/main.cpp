#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

// 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
// 输出：[[7,4,1],[8,5,2],[9,6,3]]
// 输入：matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
// 输出：[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

class Solution {
public:
    vector<int> rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> ans;
        ans.reserve(n*n);

        int left = 0, top = 0;
        int right = n - 1, bottom = n - 1;
        
        while(left < right)
        {
            for (int i = 0; i < n - 1 - left - top; i++)
            {
                int tmp = matrix[top][left + i];
                matrix[top][left + i] = matrix[bottom - i][left];
                matrix[bottom - i][left] = matrix[bottom][right - i];
                matrix[bottom][right - i] = matrix[top + i][right];
                matrix[top + i][right] = tmp;
            }
            left++;
            right--;
            top++;
            bottom--;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans.push_back(matrix[i][j]);
            }
            
        }
        

        return ans;
    }
};

int main()
{
    vector<vector<int>> test1 = {{1,2,3}, {4,5,6}, {7,8,9}};
    Solution sol;
    auto result = sol.rotate(test1);
    cout << "result:";
    for(auto &v : result)
    {
        cout << v << ",";
    }

    cout << endl;

    vector<vector<int>> test2 = {{5,1,9,11}, {2,4,8,10}, {13,3,6,7}, {15,14,12,16}};

    auto result1 = sol.rotate(test2);
    cout << "result1:";
    for(auto &v : result1)
    {
        cout << v << ",";
    }

    cout << endl;    
    return 0;
}