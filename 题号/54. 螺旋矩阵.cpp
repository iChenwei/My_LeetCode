// 模拟
/*
    思路：
        - 按照矩阵坐标系，纵向x，横向y，确定上下左右移动的xy变化
            -- 右：x不变，y加1
            -- 下：x加1，y不变
            -- 左：x不变，y减1
            -- 上：x减1，y不变
        - 根据“右下左上”四个顺序走，直到结束
            -- 向右走，走到不能走时，向下走
            -- 向左走和向上走同理
    
    vector表示二维数组(n * m)：
        -- 二维数组的生成，可以理解为一种插入
        - vector<Template> variable
            -- vector<vector<int>> variable
        - vector<vector<int>> abc(n, vector<int>(m));  // n行m列，二维数组
            -- vector<vector<int>> abc(n, vector<int>(m, 0));  // n行m列，二维数组，且每一个元素都初始化为0
        
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res; 
        int n = matrix.size();  // 矩阵的行（x方向）
        if(!n) return res;  // 特判：空矩阵
        int m = matrix[0].size();  // 矩阵的列（y方向）

        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};  // 移动偏移量
        vector<vector<bool>> st(n, vector<bool>(m, false));  // 状态数组，用来标记是否访问过

        int x = 0, y = 0;  // 坐标
        int d = 0;  // 偏移量
        for(int i = 0; i < n * m; i++) {
            // 访问矩阵（格子）
            res.push_back(matrix[x][y]);
            st[x][y] = true;

            // 确定下一个访问位置
            int a = x + dx[d], b = y + dy[d];  // 移动之后
            
            // 判断移动后是否合法，进行调整(需要变方向 or 访问过)
            if(a < 0 || a >= n || b < 0 || b >= m || st[a][b]) {
                d = (d + 1) % 4;
                a = x + dx[d], b = y + dy[d];
            }

            x = a, y = b;  // 确定下一个位置
        }
        return res;
    }
};