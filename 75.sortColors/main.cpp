#include <vector>
#include <unordered_map>
#include <iostream>
#include <stack>
using namespace std;


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        for (int i = 0; i <= right; i++)
        {
            while(i <= right && nums[i] == 2){
                swap(nums[i], nums[right]);
                right--;
            }

            if (nums[i] == 0)
            { 
                swap(nums[i], nums[left]);
                left++;
            }
            
        }
        
    }
};

int main()
{

    vector<int> test1 = {2,0,2,1,1,0};
    Solution sol;
    sol.sortColors(test1);

    for (auto &e : test1)
    {
        cout << e << ",";
    }
    
    cout << endl;

    vector<int> test2 = {2,0,1};
    sol.sortColors(test2);

    for (auto &e : test2)
    {
        cout << e << ",";
    }
    
    cout << endl;    
    
    return 0;
}