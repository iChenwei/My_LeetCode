// 滑动窗口（双指针）+ 哈希表
/*
    思路：
        - 如何枚举出所有的情况：
            -- 以下标 r 为结尾字符的子串，从0到(n-1)可以表示出所有情况
        - 如何确定当前情况/以下标 r 为结尾字符的子串下，所有不重复出现的字符：
            -- 使用指针l，枚举从 l ～ r 连续区间内所有字符不重复
        - 使用哈希表维护 l ~ r 之间每个字符出现的次数
        - 每次循环 r + 1，同时判断当前位置字符是否重复
            -- 如果不重复，继续移动到下一位
            -- 如果出现重复，说明前面 l ~ r 是合法的，需要重新确定 l 的位置，即 l向后移动到与str[r+1]不同的第一个字符处
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;  // 结果
        unordered_map<char, int> hash;  // 字符，次数
        for(int l = 0, r = 0; r < s.size(); r++) {
            hash[s[r]]++;  // 加入新的字符
            while(hash[s[r]] > 1) { // 新加入的字符有重复
                hash[s[l]]--;  // 移动指针l的过程中更新每个字符出现的次数
                l++;
            }
            res = max(res, r - l + 1);  // 更新结果
        }
        return res;
    }
};