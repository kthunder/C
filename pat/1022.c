#include <stdio.h>

int main() {
    int a, b, d;
    scanf("%d%d%d", &a, &b, &d);
    int sum = a + b;
    int ans[31], num = 0;  //ans存放D进制的每一位
    do {  //进制转换
        ans[num++] = sum % d;
        sum /= d;
    } while(sum != 0);
    for(int i = num - 1; i >= 0; i--) {  //从高位到低位进行输出
        printf("%d", ans[i]);
    }
    return 0;
}