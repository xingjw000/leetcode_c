#include <vector>
#include <unordered_map>
#include <iostream>
#include <stack>
using namespace std;


class Solution {
public:
    string decodeString(string s) {
        stack<int> nums_s;
        stack<string> str_s;

        int curr_num = 0;
        string curr_str;
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            if (isdigit(c))
            {
                curr_num = 10 * curr_num + c - '0';
            }else if(c == '['){
                nums_s.push(curr_num);
                str_s.push(curr_str);
                curr_str.clear();
                curr_num = 0;
            }else if(c == ']'){
                int repeat = nums_s.top();
                nums_s.pop();
                string pre = str_s.top();
                str_s.pop();
                string extends;
                for (int i = 0; i < repeat; i++)
                {
                    extends += curr_str;
                }

                curr_str = pre + extends;
                
            }else{
                curr_str += c;
            }
            
        }     
        return curr_str;
        
    }

};

int main()
{

    Solution sol;
    cout << sol.decodeString("3[a2[c]]") << endl;
    cout << sol.decodeString("2[abc]3[cd]ef") << endl;
    cout << sol.decodeString("abc3[cd]xyz") << endl;
    return 0;
}