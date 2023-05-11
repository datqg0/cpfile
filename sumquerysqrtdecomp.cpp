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
	ll q;
	cin>>q;
	vector<ll> nums(n);
	
	for(ll i=0;i<n;i++) {
		cin>>nums[i];
	}
	
	ll a=sqrt(n);
	ll s=n/a;
	if(n%a!=0) {
		s++;
	}
	
	vector<pair<ll,ll>> seg(s);
	vector<ll> sumseg(s);
	ll p=0;
	ll i=0;
	
	while(p<=n-1) {
		if(p+a-1>=n-1) {
			seg[i].first=p;
			seg[i].second=n-1;
			p=n;
		}
		else {
			seg[i].first=p;
			seg[i].second=p+a-1;
			i++;
			p=p+a;
		}
	}
	
	for(ll i=0;i<seg.size();i++) {
		ll sum=0;
		for(ll j=seg[i].first;j<=seg[i].second;j++) {
			sum+=nums[j];
		}
		sumseg[i]=sum;
	}
	
	for(ll i=0;i<q;i++) {
		ll type;
		cin>>type;
		if(type==1) {
			ll k,u;
			cin>>k>>u;
			k--;
			ll p;
			for(ll j=0;j<seg.size();j++) {
				if(k>=seg[j].first&&k<=seg[j].second) {
					p=j;
					break;
				}
			}
			ll temp=u-nums[k];
			nums[k]=u;
			sumseg[p]+=temp;
		}
		else {
			ll a,b;
			cin>>a>>b;
			a--;
			b--;
			ll l,r;
			//find a
			for(ll j=0;j<seg.size();j++) {
				if(a>=seg[j].first&&a<=seg[j].second) {
					l=j;
					break;
				}
			}
			//find b
			for(ll j=0;j<seg.size();j++) {
				if(b>=seg[j].first&&b<=seg[j].second) {
					r=j;
					break;
				}
			}
			
			ll out=0;
			//generate out;
			if(l==r) {
				for(ll j=a;j<=b;j++) {
					out+=nums[j];
				}
			}
			else {
				if(a==seg[l].first) {
					out+=sumseg[l];
				}	
				else {
					for(ll j=a;j<=seg[l].second;j++) {
						out+=nums[j];
					}
				}
				
				for(ll j=l+1;j<=r-1;j++) {
					out+=sumseg[j];
				}
				
				if(b==seg[r].second) {
					out+=sumseg[r];
				}	
				else {
					for(ll j=seg[r].first;j<=b;j++) {
						out+=nums[j];
					}
				}
			}
			cout<<out<<endl;
		}
	}
	
}
