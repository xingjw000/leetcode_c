#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <limits>
using namespace std;

// 示例 1：

// 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
// 输出：[3,3,5,5,6,7]
// 解释：
// 滑动窗口的位置                最大值
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// 示例 2：

// 输入：nums = [1], k = 1
// 输出：[1]

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        int nums_len = nums.size();
        vector<int> ans;

        for (int i = 0; i < nums_len && i < k; i++)
        {
            pq.emplace(make_pair(nums[i], i));
            
        }
        
        ans.push_back(pq.top().first);

        if (nums_len <= k)
        {
            return ans;
        }

        for (int i = 1; i <= nums_len - k; i++)
        {
            pq.emplace(make_pair(nums[i+k-1], i+k-1));
            while(!pq.empty() && pq.top().second < i){
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
        
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    auto result = sol.maxSlidingWindow(nums, 3);

    cout << "result:";
    for(auto &v : result)
    {
        cout << v << ",";
    }

    cout << endl;

     vector<int> nums1 = {1};
    auto result1 = sol.maxSlidingWindow(nums1, 1);

    cout << "result1:";
    for(auto &v : result1)
    {
        cout << v << ",";
    }

    cout << endl;    
    return 0;
}