// 字符串
/*
    思路：
    - 先确定回文串的中心点，然后左右两个指针边移动边比较
    - 注意回文串的长度问题（奇偶问题），左右指针边界
    题解：
    - 枚举中心点，当左右指针遇到所指元素不同，或者遇到边界时，枚举下一个中心点
    - 回文串长度问题(l, r) => [l+1, r-1] => length = r - 1 - (l + 1) = r - l + 1
    - 每一个中心点对应的回文串长度有两种情况（需要求出两种情况下的回文串）：
        -- 枚举长度为奇数的情况
        -- 枚举长度为偶数的情况

    补充：string.substr(start_index, length)
    - start_index：子串的首字母对应的下标
    - length：子串的长度
    - 下标范围：[start_index, start_index + length)
*/
class Solution {
public:
    string longestPalindrome(string s) {
        string res;  // 存放结果
        // 枚举中心点
        for(int i = 0; i < s.size(); i++) {
            // 奇数
            int l = i - 1, r = i + 1;
            while(l >= 0 && r < s.size() && s[l] == s[r]) l--, r++;  // l和r两个指针未出界，且对应元素相同
            if (res.size() < r - l - 1) res = s.substr(l + 1, r - l -1); // 更新res
            
            // 偶数
            l = i, r = i + 1;
            while(l >= 0 && r < s.size() && s[l] == s[r]) l--, r++;
            if (res.size() < r - l - 1) res = s.substr(l + 1, r - l -1); // 更新res
        }
        return res;
    }
};