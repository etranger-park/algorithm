#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;
int N,V,S;

//return false when don't pass the exception
bool check_exception(int v, int n, int s){
	//No way to make answer
	if (n > v)
		return false;
	if(n<1 || v< 1 || s < 1) return false;
	//if the max value is smaller then S, no way to make answer
	if((2*v-n+1)*n / 2 < s)
		return false;
	if(n*(n+1)/2 > s)
		return false;
	return true;
}
// return the smallest value of the highest v
int find_min_max_v(int v,int n, int s){
    double k = (double)(n-1)/2 +(double)s/n;
    return ceil(k);
}

int get_num(int v, int n, int s){
    if(!check_exception(v,n,s)) return 0;
    else if (n==1) return 1;
    int min_max = find_min_max_v(v,n,s);
    int sum=0;
    for(int i = v;i>=min_max;i--){
        sum += get_num(i-1,n-1,s-i);
    }
    return sum;
}

int main() {
	cin >> V >>N >> S;
	//No way to make answer
	if(!check_exception(V,N,S)){
		cout << 0 << endl;
		return 0;
	}
	cout <<get_num(V,N,S)<<endl;
	return 0;
}
