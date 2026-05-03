#include <vector>
#include <unordered_map>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

int main()
{

    vector<int> test1 = {3,2,3};
    Solution sol;
    auto result = sol.majorityElement(test1);

    cout << result << endl;

    vector<int> test2 = {2,2,1,1,1,2,2};
    auto result2 = sol.majorityElement(test2);

    cout << result2 << endl;    
    
    return 0;
}