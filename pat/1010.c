

#include <stdio.h>

int main() {
    int a, b;
    if (scanf("%d%d", &a, &b)) {
//       b==0 表示是常数项，第一项是常数，则直接输出0 0
        if (b == 0) {
            printf("0 0");
            return 0;
       } else {
            printf("%d %d", a * b, b - 1);
        }
    }
    while (scanf("%d %d", &a, &b) == 2) {
//        b==0 表示是常数项，导数为0，程序终止
        if (b == 0) {
            return 0;
        } else {
            printf(" %d %d", a * b, b - 1);
        }
    }
    return 0;
}