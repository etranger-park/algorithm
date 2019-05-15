#include <stdio.h>
#include <stdlib.h>
char c[81];

int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",c);
        printf("%s",c);
    }
    return 0;
}
