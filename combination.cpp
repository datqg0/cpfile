//???
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

ll c(ll n, ll m) {
		ll res = 1;
		for (int i = 0; i < m; i++) {
			//from combination formular
			/*
			nCm=n!/(m!*(n-m)!)
			so we asume a= n!/(n-m)!=(n-(m-1))*(n-(m-2))*...*n;
			and than we divine a to 1,2...,m;
			=> a=nCm;
			*/
			res = (res * (n - i)) / (i + 1);
		}
		return res;
	}

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	int t;
	cin>>t;
	cout<<c(10,3);
}
