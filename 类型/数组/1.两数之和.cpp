// 暴力算法 O(n^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < nums.size(); j++) {
                if(i != j && target == nums[i] + nums[j]) {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};
// 哈希表
/*
    - 使用unordered_map实现复杂度为O(1)的查找；
    - C++中map的实现为平衡树，查找的复杂度为O(log n)；
*/
/*
    题解：遍历数组，访问当前元素时，查找前面的元素（存放于unordered_map中）是否有匹配；如果有，则放回结果，如果没有，则将当前元素放入unordered_map中
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> heap;  // <数组元素,下标>
        for(int i = 0; i < nums.size(); i++) {
            int r = target - heap[r];
            if(heap.count(r)) {  // 找到目标元素，返回结果
                return {heap[r], i};
            }
            heap[nums[i]] = i;  // 当前元素，加入到unordered_map中
        }
        return {};
    }
};