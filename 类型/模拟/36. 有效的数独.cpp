// 模拟
/*
    思路：
        - 按照题目要求来
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool st[10];  // 标记 i 是否出现过
        // 判断行
        for(int i = 0; i < 9; i++) { // 行
            memset(st, 0, sizeof(st)); // 初始化，当前行1～9均未出现
            for(int j = 0; j < 9; j++) { // 列
                int t = board[i][j] - '0';
                if(board[i][j] != '.') {
                    if(st[t] == true) return false; // 已经出现过
                    else st[t] = true;
                }
            }
        }

        // 判断列
        for(int i = 0; i < 9; i++) { // 列
            memset(st, 0, sizeof(st));
            for(int j = 0; j < 9; j++) { // 行
                int t = board[j][i] - '0';
                if(board[j][i] != '.') {
                    if(st[t] == true) return false;
                    else st[t] = true;
                }
            }
        }

        // 判断3*3小方格
        for(int i = 0; i < 9; i += 3) { // 行
            for(int j = 0; j < 9; j += 3) { // 列
                memset(st, 0, sizeof(st));
                // 偏移量 行-x 列-y
                for(int x = 0; x < 3; x++) {
                    for(int y = 0; y < 3; y++) {
                        int t = board[i + x][j + y] - '0';
                        if(board[i + x][j + y] != '.') {
                            if(st[t] == true) return false;
                            else st[t] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};