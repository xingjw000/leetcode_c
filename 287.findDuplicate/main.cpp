#include <vector>
#include <unordered_map>
#include <iostream>
#include <stack>
using namespace std;


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];

        while(slow != fast){

            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        slow = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

int main()
{

    vector<int> test1 = {1,3,4,2,2};
    Solution sol;
    cout << sol.findDuplicate(test1) << endl;

    vector<int> test2 = {3,1,3,4,2};
    cout << sol.findDuplicate(test2) << endl;   
    

    vector<int> test3 = {3,3,3,3,3};
    cout << sol.findDuplicate(test3) << endl;   
   
    return 0;
}