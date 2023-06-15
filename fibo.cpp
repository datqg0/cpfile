//???
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

ll fibow1 (ll n) {
	if(n<=1) {
		return n;
	}
	else return fibow1(n-1)+fibow1(n-2);
}

ll fibow2 (ll n,vector<ll> & sto,vector<bool> &check) {
	if(n<=1) {
		return n;
	}
	if(check[n]==true) {
		return sto[n];
	}
	sto[n]=fibow2(n-2,sto,check)+fibow2(n-1,sto,check);
	check[n]=true;
	return sto[n];
}

ll fibow3 (ll n,vector<ll>& f) {
	for(ll i=2;i<=n;i++) {
		f[i]=f[i-1]+f[i-2];
	}
	return f[n];
}

ll fibow4 () {
	
}

int main() {
	ll n;
	cin>>n;
	vector<ll> sto(n+34,1);
	vector<bool> check(n+34,false);
	sto[0]=0;
	sto[1]=1;
	check[0]=true;
	check[1]=true;
	vector<ll> f(n+1);
	f[0]=0;
	f[1]=1;
	cout<<fibow1(n)<<endl;
	cout<<fibow2(n,sto,check)<<endl;
	cout<<fibow3(n,f)<<endl;
}
