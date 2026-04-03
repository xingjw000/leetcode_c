#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

// 示例 1：

// 输入：nums = [1,2,0]
// 输出：3
// 解释：范围 [1,2] 中的数字都在数组中。
// 示例 2：

// 输入：nums = [3,4,-1,1]
// [3,4,5,1]
// [-3,4,-5,-1]
// 输出：2
// 解释：1 在数组中，但 2 没有。
// 示例 3：

// 输入：nums = [7,8,9,11,12]
// [7,8,9,11,12]
// 输出：1
// 解释：最小的正数 1 没有出现。


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        auto len = nums.size();
        for (size_t i = 0; i < len; i++)
        {
            if (nums[i] <= 0)
            {
                nums[i] = len + 1;
            } 
        }      

        for (size_t i = 0; i < len; i++)
        {
            int tmp = abs(nums[i]);
            if (tmp <= len)
            { 
                nums[tmp - 1] = -abs(nums[tmp - 1]);
            }
        }

        for (size_t i = 0; i < len; i++)
        {
            if (nums[i] > 0)
            {
                return i + 1;
            }
            
        }
        
        return len + 1;
    }
};

int main()
{
    vector<int> test1 = {1,2,0};
    Solution sol;
    
    cout << sol.firstMissingPositive(test1) << endl;

    
    vector<int> test2 = {3,4,-1,1};
    cout << sol.firstMissingPositive(test2) << endl;
   
    vector<int> test3 = {7,8,9,11,12};
    cout << sol.firstMissingPositive(test3) << endl;    
    
    return 0;
}