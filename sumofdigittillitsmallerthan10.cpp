/*
*	Author: datqg
*/
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int calculate (int n) {
	int sum=0;
	while(n>0) {
		sum+=n%10;
		n=n/10;
	}
	if(sum>=10) {
		return calculate(sum);
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	int n;
  	cin>>n;
  	n=100000;
  	string out="YES";
	for(int i=0;i<=n;i++) {
		int x=i%9;
		if(x==0&&i!=0) {
			x=9;
		}
		cout<<x<<" "<<calculate(i)<<endl;
	}
	cout<<out<<endl;
}
