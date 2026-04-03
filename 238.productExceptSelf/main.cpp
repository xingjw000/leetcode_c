#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

// 示例 1:

// 输入: nums = [1,2,3,4]
// 输出: [24,12,8,6]
// 1 1 2 6
// 1 4 12 24

// 示例 2:

// 输入: nums = [-1,1,0,-3,3]
// 输出: [0,0,9,0,0]


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        auto len = nums.size();
        int left_product = 1;
        int right_product = 1;
        vector<int> l_v;
        l_v.reserve(len);
        l_v.push_back(left_product);
        vector<int> r_v;
        r_v.reserve(len);
        r_v.push_back(right_product);

        for (size_t i = 0; i < len - 1; i++)
        {
            left_product *= nums[i];
            l_v.push_back(left_product);
            right_product *= nums[len - 1 - i];
            r_v.push_back(right_product);
        }

        vector<int> ret;
        ret.reserve(len);
        for (size_t i = 0; i < len; i++)
        {
            ret.push_back(l_v[i] * r_v[len - 1 - i]);
        }
        return ret;
        
    }
};

int main()
{
    vector<int> test1 = {1,2,3,4};
    Solution sol;
    auto ret = sol.productExceptSelf(test1);
    
    cout << "ret:";
    for (auto &v : ret)
    {
        cout << v << ",";
    }

    cout << endl;
    
    vector<int> test2 = {-1,1,0,-3,3};
    auto ret1 = sol.productExceptSelf(test2);
    
    cout << "ret1:";
    for (auto &v : ret1)
    {
        cout << v << ",";
    }

    cout << endl;     
    
    return 0;
}