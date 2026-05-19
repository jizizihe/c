#include <stdio.h>
// 函数：将矩阵顺时针旋转90度
void rotate(int matrix[][3], int n) {
    // 第一步：转置矩阵
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // 交换 matrix[i][j] 和 matrix[j][i]
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // 第二步：水平翻转每一行
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            // 交换 matrix[i][j] 和 matrix[i][n-1-j]
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][n - 1 - j];
            matrix[i][n - 1 - j] = temp;
        }
    }
}

// 测试代码
int main() {
    // 创建一个 3x3 的示例矩阵
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    // 执行旋转操作
    rotate(matrix, 3);
    
    return 0;
} 
