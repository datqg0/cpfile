//???
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
//recursion approach
/*
int dp (int n ) {
	if(n==1) {
		return 3;
	}
	if(n==2) {
		return 8;
	}
	return 2*dp(n-1)+2*dp(n-2);
}*/
//dp memorization approach
/*
int dp (int n,vector<int>&sto,vector<bool>&check) {
	if(check[n]==true) {
		return sto[n];
	}
	sto[n]=2*dp(n-1,sto,check)+2*dp(n-2,sto,check);
	check[n]=true;
	return sto[n];
}*/

int main() {
	int n;
	cin>>n;
	//cout<<dp(n);
	/*vector<int> sto(n+1);
	vector<bool> check(n+1,false);
	sto[0]=0;
	sto[1]=3;
	sto[2]=8;
	check[1]=true;
	check[2]=true;
	check[0]=true;
	cout<<dp(n,sto,check);*/
	//linear (interactive solution)
	vector<int> dp(n+1);
	dp[0]=0;
	dp[1]=3;
	dp[2]=8;
	for(int i=3;i<=n;i++) {
		dp[i]=2*dp[i-1]+2*dp[i-2];
	}
	cout<<dp[n];
}
