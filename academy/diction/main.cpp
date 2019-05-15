#include <iostream>
#include <string>
#include <cstdio>

using namespace std;
char value[5] = {'A','E','I','O','U'};
uint32_t c[5] = {781, 156, 31, 6, 1};
uint32_t find_result(string str,uint32_t v)
{
    if(str.length() == v) return 1;
    uint32_t result = 0;
    int i;
    for(i=0;i<5;i++)
    {
        if(value[i] == str[v])
            break;
    }
    result = result + c[v]*i;
    return result + find_result(str,v+1) +1;
}

int main()
{
    uint32_t result = 0;
    string str;
    getline(cin,str);
    result = find_result(str,0);
    printf("%u",result-1);
    return 0;
}
