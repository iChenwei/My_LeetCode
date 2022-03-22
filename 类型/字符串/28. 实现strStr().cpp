// 字符串（KMP）
/*
    思路：
    - KMP算法（下标从1开始，求出结果后再转为下标从0开始）
    - 求出next数组，next[k]表示目标串1～k中，最长公共前后缀的大小（长度）
    - 匹配
    注意：
    - 指针i与主串相关（在求next数组时，i与模式串相关）
    - 指针j与模式串相关
*/
class Solution {
public:
    int strStr(string s, string p) {
        if(p.empty()) return -1; // 特判

        // s的起始下标调整为1
        int n = s.size(), m = p.size();  // 记录主串s和模式串p的长度
        s = ' ' + s, p = ' ' + p;

        // 求next数组
        vector<int> next(m + 1); // 从1开始，所以vector需要多申请一个空间; 且next[1]默认初始化为0
        for(int i = 2, j = 0; i <= m; i++) {
            while(j && p[i] != p[j + 1]) j = next[j];
            if(p[i] == p[j + 1]) j++;
            next[i] = j;
        }

        for(int i = 1, j = 0; i <= n; i++) {
            while(j && s[i] != p[j + 1]) j = next[j];
            if(s[i] == p[j + 1]) j++;
            if(j == m) return i - m;
        }
        return -1;
    }
};