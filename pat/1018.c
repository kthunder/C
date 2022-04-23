#include<stdio.h>
int main()
{
    int n;
    char ca,cb;
    int array[3] = {0,};
    int arrayjia[3] = {0,};
    int arrayyi[3] = {0,};
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        getchar();
        scanf("%c %c",&ca,&cb);
        int x;
        x = ca - cb ;
        if (x == -7)
            {array[0] += 1;
            arrayjia[1] += 1;}
        else if (x == 7)
            {array[2] += 1;
            arrayyi[1] += 1;}
        else if (x == 0)
            array[1] += 1;
        else if (x == 8)
            {array[0] += 1;
            arrayjia[2] += 1;}
        else if (x == -8)
            {array[2] += 1;
            arrayyi[2] += 1;}
        else if (x == -1)
            {array[0] += 1;
            arrayjia[0] += 1;}
        else if (x == 1)
            {array[2] += 1;
            arrayyi[0] += 1;}
        
    }
    
    
    
    printf("%d %d %d\n",array[0],array[1],array[2]);
    printf("%d %d %d\n",array[2],array[1],array[0]);
    //printf("%d %d %d\n",arrayjia[0],arrayjia[1],arrayjia[2]);
    //printf("%d %d %d\n",arrayyi[0],arrayyi[1],arrayyi[2]);
    int temp;
    char ch = 0;
    temp = (arrayjia[0]>=arrayjia[1]?arrayjia[0]:arrayjia[1]) ;
    ch = (arrayjia[0]>=arrayjia[1]?66:67) ;
    //temp = (temp>=arrayjia[2]?temp:arrayjia[2]) ;
    ch = (temp>=arrayjia[2]? ch :74) ;
    printf("%c",ch);
    printf(" ");
    temp = (arrayyi[0]>=arrayyi[1]?arrayyi[0]:arrayyi[1]) ;
    ch = (arrayyi[0]>=arrayyi[1]?66:67) ;
    //temp = (temp>=arrayyi[2]?temp:arrayyi[2]) ;
    ch = (temp>=arrayyi[2]? ch :74) ;
    printf("%c",ch);
        
}