//???
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	ll n,q;
	cin>>n>>q;
	vector<ll> nums(n);
	ll maxi;
	
	for(ll i=0;i<n;i++) {
		cin>>nums[i];
		if(i==0) {
			maxi=nums[i];
		}
		else {
			maxi=max(maxi,nums[i]);
		}
	}
	
	ll a=sqrt(n);
	ll s=n/a;
	if(n%a!=0) {
		s++;
	}
	
	vector<pair<ll,ll>> decomp(s);
	vector<ll> minseg(s);
	
	ll p=0;
	ll mini=maxi;
	ll i=0;
	
	while(p<=n) {
		if((p+a-1)>=n-1) {
			decomp[i].first=p;
			decomp[i].second=n-1;	
			p=n+1;
		}
		else {
			decomp[i].first=p;
			decomp[i].second=p+a-1;
			p=p+a;
			i++;
		}
	} 
	
	for(ll i=0;i<decomp.size();i++) {
		mini=maxi;
		for(ll j=decomp[i].first;j<=decomp[i].second;j++) {
			mini=min(mini,nums[j]);
		}	
		minseg[i]=mini;
	}
	
/*	for(ll i=0;i<decomp.size();i++) {
		cout<<decomp[i].first<<" "<<decomp[i].second<<endl;
	}
	for(ll i=0;i<minseg.size();i++) {
		cout<<minseg[i]<<" ";
	}
	cout<<endl;*/
	
	for(ll i=0;i<q;i++) {
		ll type;
		cin>>type;
		if(type==1) {
			ll k,u;
			cin>>k>>u;
			k--;
			//find k
			ll p;
			for(ll j=0;j<decomp.size();j++) {
				if(k>=decomp[j].first&&k<=decomp[j].second) {
					p=j;
					break;
				}
			}
			nums[k]=u;
			maxi=max(u,maxi);
			minseg[p]=maxi;
			for(ll j=decomp[p].first;j<=decomp[p].second;j++) {
				minseg[p]=min(minseg[p],nums[j]);
			}
			
		}
		else {
		ll a,b;
		cin>>a>>b;
		a--;
		b--;
		ll minout=maxi;
		ll l=-1;
		ll r=-1;
		// find a 
		for(ll j=0;j<decomp.size();j++) {
			ll x=decomp[j].first;
			ll y=decomp[j].second;
			if(a>=x&&a<=y) {
				l=j;
				break;
			}
		}
		// find b 
		for(ll j=0;j<decomp.size();j++) {
			ll x=decomp[j].first;
			ll y=decomp[j].second;
			if(b>=x&&b<=y) {
				r=j;
				break;
			}
		}
		//generate minout
		//cout<<l<<" "<<r<<endl;
		
		if(l==r) {
			for(ll j=a;j<=b;j++) {
				minout=min(minout,nums[j]);
			}
		}
		else {
			if(a==decomp[l].first) {
				minout=min(minout,minseg[l]);
			}
			else {
				for(ll j=a;j<=decomp[l].second;j++) {
					minout=min(minout,nums[j]);
				}
			}
			
			for(ll j=l+1;j<=r-1;j++) {
				minout=min(minseg[j],minout);
			}
			
			if(b==decomp[r].second) {
				minout=min(minout,minseg[r]);
			}
			else {
				for(ll j=decomp[r].first;j<=b;j++) {
					minout=min(minout,nums[j]);
				}
			}
		}
			cout<<minout<<endl;
		}
	}
	
}
