#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m * n - 1;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            int i = mid / n;
            int j = mid % n;
            if (matrix[i][j] == target)
            {
                return true;
            }else if (matrix[i][j] < target)
            {
                left = mid + 1;     
            }else{
                right = mid - 1;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> test1 = {{1,3,5,7}, {10,11,16,20}, {23,30,34,60}};
    Solution sol;
    auto result = sol.searchMatrix(test1,3);
    cout << "result:" << result << endl;

    auto result1 = sol.searchMatrix(test1,13);
    cout << "result:" << result1 << endl; 
    return 0;
}