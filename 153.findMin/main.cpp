#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;


class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        int l = 0;
        int r = len - 1;

        while(l <= r){
            if (nums[l] <= nums[r])
            {
                break;
            }else{
                int mid = (l + r) / 2;
                if (nums[mid] >= nums[l])
                {
                    l = mid + 1;
                }else{
                    r = mid;
                }
            }
        }
        return nums[l];
    }
};

int main()
{
    vector<int> test1 = {3,4,5,1,2};
    Solution sol;
    auto result = sol.findMin(test1);
    cout << "result:" << result << endl;

    // auto result1 = sol.search(test1,3);
    // cout << "result:" << result1 << endl;

    vector<int> test2 = {4,5,6,7,0,1,2};
    auto result2 = sol.findMin(test2);
    cout << "result:" << result2 << endl;

    vector<int> test3 = {11,13,15,17};
    auto result3 = sol.findMin(test3);
    cout << "result:" << result3 << endl;    
    return 0;
}