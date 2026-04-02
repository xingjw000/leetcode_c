#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

// 示例 1：

// 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
// 输出：[[1,6],[8,10],[15,18]]
// 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
// 示例 2：

// 输入：intervals = [[1,4],[4,5]]
// 输出：[[1,5]]
// 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
// 示例 3：

// 输入：intervals = [[4,7],[1,4]]
// 输出：[[1,7]]
// 解释：区间 [1,4] 和 [4,7] 可被视为重叠区间。

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        sort(intervals.begin(), intervals.end());
        size_t len = intervals.size();

        ret.push_back(intervals[0]);
        
        for (size_t i = 1; i < len; i++)
        {
            int first_r = ret.back()[1];
            int sencond_l = intervals[i][0];
            if (first_r >= sencond_l)
            {
               ret.back()[1] = max(ret.back()[1], intervals[i][1]);
            }else{
                ret.push_back(intervals[i]);
            }
        }
        return ret;
    }
};

int main()
{
    vector<vector<int>> test1 = {{1,3},{2,6},{8,10},{15,18}};
    Solution sol;
    auto result = sol.merge(test1);

    for(auto &v : result)
    {
        cout << v[0] << "-" << v[1] << endl;
    }

    return 0;
}