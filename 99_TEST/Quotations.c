#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

char *str[] = {
    "不断总结思考，提高开发效率",
    "无论在何种实现中，我们都应保持相同的用户接口",
    "不要做多余的事",
    "程序员的编程能力取决于最初的一切，抱着多少热诚学习，观摩多严谨的代码，反复操练基础多少次，最后才能写出优秀的代码。",
    "代码是最初级的，思路最高级",
    "代码就是也要写成这样，看上去很朴素",
    "在团队里面不能做不稳的事情",
    "强者连1秒钟 都不会浪费",
    "先结婚 后恋爱",
    "没有实力也得不到爱情",
    "你还年轻 要想长久 最方便的方式方法就是这样",
    "下者劳力，中者劳智，上者劳人"};

int main(int argc, char const *argv[])
{
    int count = sizeof(str) / sizeof(char *);

    while (TRUE)
    {
        printf("何家桢说过：%s", str[rand() % count]);
        Sleep(3000);
        system("cls");
    }

    return 0;
}
