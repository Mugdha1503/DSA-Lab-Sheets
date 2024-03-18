#include <stdio.h>
char board[5000][5000];
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", board[i]);
    }
    for (int j = 0; j < m; ++j) {
        int bottom = n - 1; 
        for (int i = n - 1; i >= 0; --i) {
            if (board[i][j] == '*') {
                board[i][j] = '.'; 
                board[bottom][j] = '*'; 
                bottom--; 
            } else if (board[i][j] == 'o') {
                bottom = i - 1; 
            }
        }
    }
    for (int i = 0; i < n; ++i) 
        printf("%s\n", board[i]);
    return 0;
}



