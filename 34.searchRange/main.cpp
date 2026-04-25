#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        bool has = false;
        int mid = 0;
        while(left <= right){
            mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                has = true;
                break;
            }else if(target < nums[mid]){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        if (!has)
        {
            return {-1,-1};
        }
        
        // find max pos
        int max_pos = mid;
        while(max_pos <= right)
        {
            int right_mid = (max_pos + right) / 2;
            if (nums[right_mid] != target)
            {
                right = right_mid - 1;
            }else{
                max_pos = right_mid + 1;
            }
        }

        int min_pos = mid;
        while(left <= min_pos){
            int left_mid = (min_pos + left) / 2;
            if (nums[left_mid] != target)
            {
                left = left_mid + 1;
            }else{
                min_pos = left_mid - 1;
            } 
        }

        return {min_pos + 1, max_pos - 1};

    }
};

int main()
{
    vector<int> test1 = {5,7,7,8,8,10};
    Solution sol;
    auto result = sol.searchRange(test1,8);
    cout << "result:" << result[0] << "," << result[1] << endl;

    auto result1 = sol.searchRange(test1,6);
    cout << "result:" << result1[0] << "," << result1[1] << endl;

    vector<int> test2 = {1};
    auto result2 = sol.searchRange(test2,1);
    cout << "result:" << result2[0] << "," << result2[1] << endl;    
    return 0;
}