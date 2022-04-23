#include<stdio.h>
#include<ctype.h>
//写得稀烂
int main(int argc, char const *argv[])
{
    int aa[102] = {0};
    int bb[102] = {0};
    int a[102] = {0};
    int b[102] = {0};
    int out[102] = {0};
    int temp ,lena,lenb;
    int lenaa, lenbb,lenout;
    int c;
    lena = lenb = 0;

    for (int i = 1; isdigit(c = getchar()) ; i++)
    {
        aa[i] = c - '0';
        lena++;
    }
    for (int i = 1; isdigit(c = getchar()) ; i++)
    {
        bb[i] = c - '0';
        lenb++;
    }
    lenaa = lena;
    lenbb = lenb;
    for (int i = 1; lena != 0; i++)
    {
        a[i] = aa[lena];
        lena--;
    }
    for (int i = 1; lenb != 0; i++)
    {
        b[i] = bb[lenb];
        lenb--;
    }
    for (int i = 1; i <= (lenaa > lenbb ? lenaa : lenbb); i++)
    {
        if (i%2 == 1)
        {
            out[i] = (a[i] + b[i]) % 13;
        }
        else
        {
            temp = b[i] - a[i];
            while (temp < 0)
            {
                temp += 10;
            }
            out[i] = temp;
        }

    }
    lenout = (lenaa > lenbb ? lenaa : lenbb);
    for (int i = lenout; i>=1 ; i--)
    {
        if (out[i] == 10)
            putchar('J');
        else if (out[i] == 11)
            putchar('Q');
        else if (out[i] == 12)
            putchar('K');
        else
            printf("%d", out[i]);
    }

    return 0;
}
