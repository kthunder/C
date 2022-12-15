#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char str[10];
    scanf("%s",str);
    int length;
    int sum;
    int ch;
    double j = 0;
    length = strlen(str);
    for (int i = length - 1; i >= 0; i--)
    {
        if (str[i]== 'x'||str[i]== 'X')
        {
            break;
        }
        
        if(str[i]>='a'&&str[i]<='f')
        {
            ch = str[i]-'a'+10;
        }
        else if(str[i]>='A'&&str[i]<='F')
        {
            ch = str[i]-'A'+10;
        }
        else if (str[i]>='0'&&str[i]<='9')
        {
            ch = str[i]-'0';
        }
        sum += ch*(int)pow(16.0,j);
        j+=1.0;
    }
    printf("%d",sum);
}