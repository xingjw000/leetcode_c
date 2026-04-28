#include <vector>
#include <unordered_map>
#include <iostream>
#include "limits.h"
using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n)
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int l = 0;
        int r = m;
        int m1 = 0;
        int m2 = 0;

        while(l <= r){
            int i = (l + r)/2;
            int j = (m + n + 1)/2 - i;

            int a_i_1 = (i == 0 ? INT_MIN: nums1[i-1]);
            int a_i = (i == m ? INT_MAX:nums1[i]);
            int b_j_1 = (j == 0 ? INT_MIN : nums2[j-1]);
            int b_j = (j == n ? INT_MAX : nums2[j]);

            if (a_i_1 <= b_j)
            {
                m1 = max(a_i_1, b_j_1);
                m2 = min(a_i, b_j);
                l = i + 1;
            }else{
                r = i - 1;
            }
        }

        return (m+n)%2 == 0 ? 1.0*(m1 + m2)/2 : m1;
        
    }
};

int main()
{
    vector<int> test1 = {1,3};
    vector<int> test2 = {2};
    Solution sol;
    auto result = sol.findMedianSortedArrays(test1, test2);
    cout << "result:" << result << endl; 

    vector<int> test3 = {1,2};
    vector<int> test4 = {3,4};
    auto result1 = sol.findMedianSortedArrays(test3, test4);
    cout << "result:" << result1 << endl;    
    return 0;
}