// 数组 矩阵
/*
    思路：
    - 将旋转90度拆分成两个步骤（目的，多次两两交换，实现一次旋转多个位置的多个元素旋转）
        -- 沿左上角到右下角为轴旋转
        -- 沿中轴线（竖向）翻转 / 左右翻转
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0, k = n - 1; j < k; j++, k--) {
                swap(matrix[i][j], matrix[i][k]);
            }
        }
    }
};