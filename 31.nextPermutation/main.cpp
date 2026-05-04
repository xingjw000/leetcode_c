#include <vector>
#include <unordered_map>
#include <iostream>
#include <stack>
using namespace std;


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i;
        for (i = n-2; i >= 0; i--)
        {
            if (nums[i] < nums[i+1])
            {
                break;
            }
            
        }

        if (i >= 0)
        {
            int j = n - 1;
            for (j = n - 1; j > i; j--)
            {
                if (nums[j] > nums[i])
                {
                    break;
                }
                
            }
            
            swap(nums[i], nums[j]);
        }

        int l = i + 1;
        int r = n - 1;

        while (l < r)
        {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
        
        
        
    }
};

int main()
{

    vector<int> test1 = {1,2,3};
    Solution sol;
    sol.nextPermutation(test1);

    for (auto &e : test1)
    {
        cout << e << ",";
    }
    
    cout << endl;

    vector<int> test2 = {3,2,1};
    sol.nextPermutation(test2);

    for (auto &e : test2)
    {
        cout << e << ",";
    }
    
    cout << endl;    
    

    vector<int> test3 = {1,1,5};
    sol.nextPermutation(test3);

    for (auto &e : test3)
    {
        cout << e << ",";
    }
    
    cout << endl;     
    return 0;
}