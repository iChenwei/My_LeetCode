// 字符串（找规律）
/*
    思路：等差数列
    - 第一行和最后一行的元素下标间隔为 (2n - 2)，其中 n 为题目要求的行数。
    - 其余行分成两种情况讨论
        - 第一种情况，竖线为起点，且下一个数也在竖线上的两个数，也具有等差数列的性质/规律
        - 第二种情况，斜线为起点，且下一个数也在斜线上的两个数，也具有等差数列的性质/规律
    - 特殊情况：只有一个字符
*/
class Solution {
public:
    string convert(string s, int n) {
        string res;
        if (n == 1) return s;
        for(int i = 0; i < n; i++) {
            if(i == 0 || i == n - 1) {
                for(int j = i; j < s.size(); j += 2 * n - 2) {
                    res += s[j];
                }
            } else {
                for(int j = i, k = 2 * n - 2 - i; j < s.size() || k < s.size(); j += 2 * n - 2, k += 2 * n - 2) {
                    if (j < s.size()) res += s[j];
                    if (k < s.size()) res += s[k];
                }
            }
        }
        return res;
    }
};