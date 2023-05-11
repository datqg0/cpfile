//prefixsum
//???
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	ll n;
	cin>>n;
	vector<ll> nums(n);
	ll sum=0;
	vector<ll> sums(n+1);
	
	sums[0]=0;
	
	for(ll i=0;i<n;i++) {
		cin>>nums[i];
		sum+=nums[i];
		sums[i+1]=sum;
	}
	
	ll count=0;
	
/*	for(ll i=0;i<sums.size();i++) {
		cout<<sums[i]<<" ";
	}
	cout<<endl;*/
	if(sum%3==0) {
	
	ll a=sum/3; 
	
	vector<ll> sto1;
	vector<ll> sto2;
	ll mini=n;
	
	for(ll i=1;i<n-1;i++) {
		if(sums[i]==a) {
			sto1.push_back(i);
		}
		if(sums[n]-sums[i+1]==a) {
			sto2.push_back(i+1);
		}
	}	
	
	
	if(sto1.size()>0) {
		
	for(ll i=0;i<sto2.size();i++) {
		
		ll l=0;
		ll r=sto1.size()-1;
		
		while(l<=r) {
			ll mid =l+(r-l)/2;
			if(sto1[mid]>=sto2[i]) {
				r=mid-1;
			}
			else {
				l=mid+1;
			}
		}
		
		count+=l;
	}
	
	}
	
	}
	cout<<count<<endl;
}
