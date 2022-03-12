// 字符串
/*
    思路：
    - 对于4、9、40、90、400、900这些由两个字符组成的二元组
        - 当前面的字符比后面的字符要小的时候，就减去当前这个小的字符对应的数值，然后加上后面较大的字符对应的数值
    - 其他数字对应的字符正常加法即可。
*/
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> hash;
        hash['I'] = 1, hash['V'] = 5,
        hash['X'] = 10, hash['L'] = 50,
        hash['C'] = 100, hash['D'] = 500,
        hash['M'] = 1000;

        int res = 0;
        for(int i = 0; i < s.size(); i++) {
            if(i + 1 < s.size() && hash[s[i]] < hash[s[i + 1]]) 
                res -= hash[s[i]];
            else 
                res += hash[s[i]];
        }
        return res;
    }
};
