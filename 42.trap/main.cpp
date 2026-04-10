#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

// 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
// 输出：6
// 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
// 示例 2：

// 输入：height = [4,2,0,3,2,5]
// 输出：9


class Solution {
public:
    int trap(vector<int>& height) {
        auto len = height.size();
        vector<int> left_max_heights(len, 0);
        vector<int> right_max_heights(len, 0);

        left_max_heights[0] = height[0];
        for (int i = 1; i < len; i++)
        {
            left_max_heights[i] = max(left_max_heights[i - 1], height[i]);
        }


        right_max_heights[len - 1] = height[len - 1];

        for (int i = len - 2; i >= 0; i--)
        {
            right_max_heights[i] = max(right_max_heights[i + 1], height[i]);
        }
        
        int rate_water = 0; 
        for (size_t i = 0; i < len; i++)
        {
            int a = min(left_max_heights[i], right_max_heights[i]);
            int b = a - height[i];
            if (b >= 0)
            {
                rate_water += b;
            }
            
        }
        
        return rate_water;
    }
};

int main()
{
    vector<int> test1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution sol;
    
    cout << sol.trap(test1) << endl;

    
    vector<int> test2 = {4,2,0,3,2,5};
    cout << sol.trap(test2) << endl;

    
    return 0;
}