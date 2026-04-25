#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        
        while(l <= r){
            int mid = (l + r)/2;
            if (nums[mid] == target)
            {
                return mid;
            }
            
            if (nums[l] > nums[r])
            {
                if (nums[l] <= nums[mid])
                {
                    if (target < nums[mid] && target >= nums[l])
                    {
                        r = mid - 1;
                    }else{
                        l = mid + 1;
                    }
                }else{
                    if (target < nums[mid])
                    {
                        r = mid - 1;
                    }else
                    {
                        if (target <= nums[r])
                        {
                            l = mid + 1;
                        }else{
                            r = mid - 1;
                        }
                        
                    }
                }
                
            }else{
                if (nums[mid] > target)
                {
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
                
            }
            
        }
        return -1;
    }
};

int main()
{
    vector<int> test1 = {4,5,6,7,0,1,2};
    Solution sol;
    auto result = sol.search(test1,0);
    cout << "result:" << result << endl;

    auto result1 = sol.search(test1,3);
    cout << "result:" << result1 << endl;

    vector<int> test2 = {3,5,1};
    auto result2 = sol.search(test2,3);
    cout << "result:" << result2 << endl;
    return 0;
}