#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

// 输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
// 输出：true
// 输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
// 输出：false

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int x = 0;
        int y = n - 1;

        while(x < m && y >= 0)
        {
            if (matrix[x][y] == target)
            {
                return true;
            }else if(matrix[x][y] > target)
            {
                y--;
            }else{
                x++;
            }
            
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> test1 = {{1,4,7,11,15}, {2,5,8,12,19}, {3,6,9,16,22}, {10,13,14,17,24}, {18,21,23,26,30}};
    Solution sol;
    auto result = sol.searchMatrix(test1,5);
    cout << "result:" << result << endl;

    auto result1 = sol.searchMatrix(test1,20);
    cout << "result:" << result1 << endl; 
    return 0;
}