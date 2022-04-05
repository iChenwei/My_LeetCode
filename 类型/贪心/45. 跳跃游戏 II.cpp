// 动态规划  贪心
/*
    参考（直接看这个吧）：
        https://www.acwing.com/solution/content/12505/
        https://www.acwing.com/solution/content/12675/

    思路：
        - 状态数组f[i]：从起点到i所需要的步数（steps）
        - 根据每一个结点能跳到的最远距离，可以得出结论：每一步（step）能够到达的距离是一个连续区间的，
        从起点到终点是由一个个连续的范围组成的，求出每一个连续区间内能够到达的最远位置，最终能够得到f[n]即在第几个区间（或者说，所需要的步数）。     
    
    实现：
        - 不需要准确分割数组中的每一个连续区间，使用双指针来实现：i遍历数组，j来枚举上一个区间中能够到达区间的终点。
        - 只要i<=j，说明仍然在当前step步的区间内，一直i++即可。
        - 当i > j时，到了step++步的区间内，更新step += 1，同时更新j为step步区间的起点
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);  // 从 起点 到 i 要走的步数
        
        for(int i = 0, last = 0; i < n; i++) {
            if(!i) f[i] = 0;  // 起点出发，跳0步
            else {
                while(last < n && last + nums[last] < i) last++;  // 找到第一个能够一步跳到 i 的位置 
                f[i] = f[last] + 1;  // 更新跳到 i 所需要的步数
            }
        }
        return f[n - 1];  // 最终结果
    }
};