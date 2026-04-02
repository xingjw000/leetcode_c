#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

// 示例 1:

// 输入: nums = [1,2,3,4,5,6,7], k = 3
// 输出: [5,6,7,1,2,3,4]
// 解释:
// 向右轮转 1 步: [7,1,2,3,4,5,6]
// 向右轮转 2 步: [6,7,1,2,3,4,5]
// 向右轮转 3 步: [5,6,7,1,2,3,4]
// 示例 2:

// 输入：nums = [-1,-100,3,99], k = 2
// 输出：[3,99,-1,-100]
// 解释: 
// 向右轮转 1 步: [99,-1,-100,3]
// 向右轮转 2 步: [3,99,-1,-100]


class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        if (nums.size() <= 1)
        {
            return;
        }
        
        int tmp;
        k = k % nums.size();
        for (int i = 0; i < k; i++)
        {
            tmp = nums.back();

            for (int j = nums.size() - 2; j >= 0 ; j--)
            {
                nums[j+1] = nums[j];
            }
            nums[0] = tmp;
        }
    }
};

int main()
{
    vector<int> test1 = {1,2,3,4,5,6,7};
    Solution sol;
    sol.rotate(test1, 3);
    
    cout << "test1:";
    for (auto &v : test1)
    {
        cout << v << ",";
    }

    cout << endl;

    vector<int> test2 = {-1,-100,3,99};
    sol.rotate(test2, 2);
    
    cout << "test2:";
    for (auto &v : test2)
    {
        cout << v << ",";
    }

    cout << endl;    
    
    return 0;
}