//???
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

void build (vector<int>&t,int n) {
	for(int i=n-1;i>0;--i) {
		t[i]= t[i<<1]+t[i<<1|1];
		cout<<t[i]<<" "<<t[i*2]<<" "<<t[i*2+1]<<endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	int n;
	cin>>n;
	vector<int> t(2*n+4,0);
	for(int i=0;i<n;i++) {
		cin>>t[n+i];
	}
	
	for(int i=0;i<t.size();i++) {
		cout<<t[i]<<" ";
	}
	cout<<endl;
	
	build (t,n);
	
	for(int i=0;i<t.size();i++) {
		cout<<t[i]<<" ";
	}
	cout<<endl;
}
