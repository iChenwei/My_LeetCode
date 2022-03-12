// 字符串
/*
    思路：
    - 枚举每一个字符串的第一个字符，如果均相同，那么最长公共前缀的长度加1，
    - 当某一次循环中，枚举到的字符和前面的不同时，结束
    - 最后返回最长公共前缀
    - 注意：每个字符串的长度问题！
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        if(strs.empty()) return res;  // 特判：空

        // 循环次数以第一个字符串长度为准
        for(int i = 0; i < strs[0].size(); i++) {
            //if(i >= strs[0].size()) return res;  // 特判长度，以第一个字符串为标准
            char c = strs[0][i];
            for(auto& str : strs){ // 取每一个str的第i个字符进行比较 C++11
                if(str.size() <= i || str[i] != c) return res;
            }
            res += c;
        }
        return res;
    }
};