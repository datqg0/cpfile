//prefixxor
//???
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
	ll n;
	cin>>n;
	ll q;
	cin>>q;
	vector<ll> nums(n);
	vector<ll> prefixxor(n);
	ll sumxor=-1;
	for (ll i=0;i<n;i++) {
		cin>>nums[i];
		if(sumxor==-1) {
			sumxor=nums[i];
		}
		else {
			sumxor=sumxor^nums[i];
		}
		prefixxor[i]=sumxor;
	}
	for (ll i=0;i<q;i++) {
		ll l,r;
		cin>>l>>r;
		l--;
		r--;
		if(l==r) {
			cout<<nums[l];
		}
		else if (r==n-1) {
			if(l==0) {
				cout<<prefixxor[r];
			}
			else {
				ll x=prefixxor[r]^prefixxor[l-1];
				cout<<x;
			}
		}
		else if(l==0) {
			cout<<prefixxor[r];
		}
		else {
			ll x=prefixxor[n-1]^prefixxor[l-1];
			ll y=prefixxor[n-1]^prefixxor[r];
			ll z=x^y;
			cout<<z;
		}
		cout<<endl;
	}
}
