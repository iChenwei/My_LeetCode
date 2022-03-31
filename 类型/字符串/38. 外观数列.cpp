// 字符串
/*
    思路：
    - 理解题意，然后模拟
    - 双指针
        - 第一个指针负责确定元素值，第二个指针负责统计元素数量，然后组成字符串
    
    - 吐槽一下：
        - 什么烂题
*/
class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for(int i = 0; i < n - 1; i ++) {
            string t;
            for(int j = 0; j < s.size();) {
                int k = j + 1;
                while(k < s.size() && s[k] == s[j]) k++;
                t += to_string(k - j) + s[j];
                j = k;
            }
            s = t;
        }
        return s;
    }
};