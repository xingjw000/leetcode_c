#include <vector>
#include <unordered_map>
#include <iostream>
#include <stack>
using namespace std;


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        int max_area = 0;
        // for (int i = 0; i < len; i++)
        // {
        //     int curr_h = heights[i];
        //     int j = i - 1;
        //     for (; j >= 0; j--)
        //     {
        //         if (curr_h > heights[j])
        //         {
        //             break;
        //         }
        //     }

        //     int x = i + 1;
        //     for (; x < len; x++)
        //     {
        //         if (curr_h > heights[x])
        //         {
        //             break;
        //         }
        //     }
            
        //     int curr_area = (x - j - 1) * curr_h;
        //     max_area = max(curr_area, max_area);

        //     //cout << curr_h << "*" << (x - j - 1) << "==" << max_area << endl;
        // }

        vector<int> left(len), right(len, len);
        stack<int> s;

        for (int i = 0; i < len; i++)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                right[s.top()] = i;
                s.pop();
            }
            left[i] = (s.empty()? -1 : s.top());
            s.push(i);
        }
        
        for (int i = 0; i < len; i++)
        {
            max_area = max(max_area, (right[i] - left[i] - 1) * heights[i]);
        }
        
        return  max_area;
    }
};

int main()
{

    vector<int> test1 = {2,1,5,6,2,3};
    Solution sol;
    auto result = sol.largestRectangleArea(test1);

    cout << result << endl;

    vector<int> test2 = {2,4};
    auto result2 = sol.largestRectangleArea(test2);

    cout << result2 << endl;    
    
    return 0;
}