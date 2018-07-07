#include <stdio.h>
#include <stdlib.h>
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))

int step[301] ={0};//the max score when step next stair
int non_step[301] = {0};//the max score when don't step next stair
int *score;

void init(int n)
{
    non_step[n-1] = step[n-1] = *(score + n -1);
    if(n == 1) return;
    non_step[n-2] = -1000000;//It's impossible don't step final stair
    step[n-2] = *(score + n -2) + step[n-1];
    return;
}

void dp(int n)
{
    //this input is smaller then n-2
    int my_score = *(score + n);
    non_step[n] = my_score  + MAX(step[n+2],non_step[n+2]);
    step[n] = my_score + non_step[n+1];
}

int main()
{
    int i,n,result,first_step,second_step,max = 0;
    scanf("%d",&n);
    score =(int*)malloc(n*sizeof(int));
    if(n==0)
    {
        printf("0"); //Zero input Exception
        return 0;
    }

    for(i=0;i<n;i++)
    {
        scanf("%d",score+i);
    }
    init(n);
    for(i=n-3;i>=0;i--)
    {
        dp(i);
    }
    first_step = MAX(step[0],non_step[0]); //When get the score of first stair
    second_step = MAX(step[1],non_step[1]);//it can be jump first stair (no get score of the first stair)
    result = MAX(first_step,second_step);
    printf("%d",result);
    return 0;
}

