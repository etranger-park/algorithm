#include <iostream>

using namespace std;
int main()
{
    int i,N,change,c=0;
    int money[6] = {500, 100, 50, 10, 5, 1};
    cin >> N ;
    change = 1000 - N;
    for(i=0;i<6;i++)
    {
        c += (change/money[i]);
        change = change %(money[i]);
    }
    cout << c << endl;
    return 0;
}
