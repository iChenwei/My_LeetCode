// 滑动窗口（双指针）+ 哈希表
/*
    思路：如何遍历所有的情况
    题解：
    - 以第i个元素结尾的子串，j从前往后遍历；
    - i向后移动时，j也跟着移动（++）；
    - 使用unordered_map存放j到i这一段上每一个元素出现的次数；
    - 每次i后移一位时，发生了重复，在哈希表中删掉j所指元素的个数（同时让j后移一位），直到j移动到下一个满足“j到i元素均不同”的位置，更新此时的结果；否则，直接更新结果；
    - 每一次重复的发生，必然是当前i后移（添加新元素）所导致，只需要判断i所指元素出现的次数是否大于1，便可判断重复的发生与否；
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_map<char, int> hash;  // <字符,出现次数>
        for(int i = 0, j = 0; i < s.size(); i++) {
            hash[s[i]] ++;
            while(hash[s[i]] > 1) {    // 子串有重复字符
                hash[s[j]]--;
                j++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};