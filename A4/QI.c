#include<stdio.h>
int main(){
    int m, k;
    scanf("%d %d", &m, &k);
    if(m == 1 && k == 0){
        printf("0 0");
    }
    else if((m != 1 && k == 0) || ((k / 9) > m) || ((k / 9) == m && (k % 9 > 0))){
        printf("-1 -1");
    }
    else{
        char l[m + 1], r[m + 1];
        for(int i = 0; i < m; i++){
            l[i] = '0';
            r[i] = '0';
        }
        l[m] = '\0';
        r[m] = '\0';
        int n = k / 9;
        int ld = k % 9;
        int i = 0;
        while(i != n){
            r[i] = r[i] + 9;
            i++; 
        }
        r[i] = r[i] + ld;
        l[0] = '1';
        n = (k - 1) / 9;
        ld = (k - 1) % 9;
        i = 0;
        while(i != n){
            l[m - i - 1] = l[m - i - 1] + 9;
            i++; 
        }
        l[m - i - 1] = l[m - i - 1] + ld;
        printf("%s %s", l, r);
    }
    return 0;
}
