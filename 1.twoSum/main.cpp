#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len  = nums.size();
        unordered_map<int, int> hash_map;
        for(int i = 0; i < len; i++)
        {
            auto it = hash_map.find(target - nums[i]);
            if(it != hash_map.end())
            {
                return {it->second, i};
            }
            else
            {
                hash_map[nums[i]] = i;
            }
        }
        return {};
    }
};

int main()
{
    vector<int> test1 = {2, 7, 11, 15};
    int target1 = 9;
    Solution sol;
    auto result = sol.twoSum(test1, target1);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}