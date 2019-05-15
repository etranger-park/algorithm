#include <stdio.h>
#include <stdlib.h>
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define N 1000 + 1

int red_min_cost[N] = {0}; // When paint red color on n-th house, the MIN cost
int green_min_cost[N] = {0}; // When paint green color on n-th house, the MIN cost
int blue_min_cost[N] = {0}; // When paint blue color on n-th house, the MIN cost

int red_cost[N] = {0}; //the cost of painting n-th house to red
int green_cost[N] = {0};//the cost of painting n-th house to blue
int blue_cost[N] = {0};//the cost of painting n-th house to blue


void init()
{
    red_min_cost[0] = red_cost[0];
    green_min_cost[0] = green_cost[0];
    blue_min_cost[0] = blue_cost[0];
}

//input n > 0, Check Left house, It can't be painted by same color
//it set up the color_min_cost[n] using color_min_cost[n-1]
void dp(int n)
{
    if(n==0) return; //Error Case
    const int red = red_cost[n];
    const int green = green_cost[n];
    const int blue = blue_cost[n];
    red_min_cost[n] = red + MIN(green_min_cost[n-1],blue_min_cost[n-1]);
    green_min_cost[n] = green + MIN(blue_min_cost[n-1],red_min_cost[n-1]);
    blue_min_cost[n] = blue + MIN(red_min_cost[n-1],green_min_cost[n-1]);
    return;
}

int min(int a, int b, int c)
{
    if(a<=b && a<=c) return a;
    else if(b<=a && b<=c) return b;
    else return c;
}

int main()
{
    int n,i,result;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d %d %d",red_cost+i,green_cost+i,blue_cost+i);
    if(n == 0)
    {
        printf("0"); //Zero Exception
        return;
    }

    init();

    for(i=1;i<n;i++)
        dp(i);
    result = min(red_min_cost[n-1],green_min_cost[n-1],blue_min_cost[n-1]);
    printf("%d",result);
    return 0;
}

