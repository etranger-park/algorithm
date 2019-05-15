#include <iostream>

using namespace std;

int main()
{
    int i,N,sum = 0;
    int col,row;
    cin >> N ;
    for(i=1;i<10000;i++){
        sum +=i;
        if(N<=sum) break;
    }
    col = sum - N;
    row = i - col - 1;
    if(i%2==0)
        cout<< row+1 <<'/'<<col+1<< endl;
    else
        cout<< col+1 <<'/'<<row+1<< endl;
    return 0;
}
