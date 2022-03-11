// 数学
/*
    思路：
    - 方法一：转换成字符串，判断字符串和“其倒序”是否一样
    
        class Solution {
        public:
            bool isPalindrome(int x) {
                if(x < 0) return 0; // 特判
                string s = to_string(x);
                return s == string(s.rbegin(), s.rend());  // 正序和倒序判断
            }
        };
    
    - 方法二：数字法（秦九韶算法），每取出一位，扩大10倍再相加
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return 0;
        int tmp = x;  // x在后续处理中发生了变化需要保存
        long long res = 0;
        while(x) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        x = tmp;
        return res == x;
    }
};