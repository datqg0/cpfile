//???
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
ll dp (ll n,vector<ll>&sto,vector<bool>&check) {
	if (n<0) {
		return 0;
	}
	if(check[n]==true) {
		return sto[n];
	}
	if(n==0) {
		return 1;
	}
	for(int i=1;i<=6;i++) {
		sto[n]+=dp(n-i,sto,check);
		sto[n]=sto[n]%1000000007;
	}
	check[n]=true;
	return sto[n];
}

int main() {
		int n;
		cin>>n;
		vector<ll> sto(n+1,0);
		vector<bool>check(n+1,false);
		cout<<dp(n,sto,check)<<endl;
}
