// 字符串 & 数学（秦九韶算法）
/*
    没啥思路，挺简单的    
*/
class Solution {
public:
    int myAtoi(string s) {
        int k = 0;  // 用于扫描字符串的指针
        while(k < s.size() && s[k] == ' ') k++;
        if(k == s.size()) return 0; // 特判

        int flag = 1;   // 符号位，负数为-1
        if(s[k] == '-') flag = -1, k++; // 变更符号，并移动指针到数字部分
        else if(s[k] == '+') k++; // 直接移动指针到数字部分

        long long  res = 0;  // 秦九韶算法
        while(k < s.size() && s[k] >= '0' && s[k] <= '9') {
            res = res * 10 + s[k] - '0';
            k++;
            if(res > INT_MAX) break;
        }

        res *= flag;    // 别忘了符号

        if(res > INT_MAX) return INT_MAX;
        if(res < INT_MIN) return INT_MIN;

        return res;
    }
};