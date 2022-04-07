// 字符串 哈希表 排序 
/*
    思路：
    - 找到使得多个字符串为一组的条件（寻找一个多个字符串都符合的一种条件）：
        -- 将字符串按照字典顺序，进行排序
        -- 同一组的字符串，排序后的结果相同
    - 如何实现分组：
        -- 哈希表
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> hash;
        for(auto& str : strs) {
            string t = str;
            sort(t.begin(), t.end());
            hash[t].push_back(str);  // 相同字典顺序的为一组
        }

        for(auto& item : hash) {
            ans.push_back(item.second);
        }
        return ans;
    }
};