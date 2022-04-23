#include <stdio.h>

int main()
{
    int n;
    float requirement;
    float porfit = 0;
    scanf("%d %f",&n,&requirement);
    struct moonCake
    {
        float quailty;
        float amount;
        float price;
    }moonCakeList[n],temp;
    for (int i = 0; i < n; i++)
    {
        scanf("%f",&moonCakeList[i].quailty);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%f",&moonCakeList[i].amount);
        moonCakeList[i].price = (float)moonCakeList[i].amount/(float)moonCakeList[i].quailty;
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (moonCakeList[j].price < moonCakeList[j+1].price)
            {
                temp = moonCakeList[j];
                moonCakeList[j] = moonCakeList[j+1];
                moonCakeList[j+1] = temp;
            }
            
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        requirement -= (float)moonCakeList[i].quailty;
        if (requirement >= 0)
        {
            porfit += moonCakeList[i].amount;//printf("%0.2f\n",porfit);
        }
        else if (requirement < 0)
        {
            porfit += (requirement+(float)moonCakeList[i].quailty)*moonCakeList[i].price;//printf("%0.2f\n",porfit);
            break;
        }
  
    }
    printf("%0.2f",porfit);
}