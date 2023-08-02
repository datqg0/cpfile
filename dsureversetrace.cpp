//???
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
//C.Destroying array codeforces https://codeforces.com/contest/722/problem/Cs

ll findset (ll a,vector<ll>&parent) {
	if(a==parent[a]) {
		return a;
	}
	ll p=findset(parent[a],parent);
	parent[a]=p;
	return p;
}
 
void makeunion (ll a,ll b,vector<ll>&parent,vector<ll>&rank) {
	a=findset(a,parent);
	b=findset(b,parent);
	if(a!=b) {
		if(rank[a]<rank[b]) {
			swap(a,b);
		}
		parent[b]=a;
		if(rank[a]==rank[b]) {
			rank[a]++;
		}
	} 
}

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	// freopen("codeforces.inp","r",stdin);
    // freopen("codeforces.out","w",stdout);
	ll n;
	cin>>n;
	vector<ll> nums(n);
	vector<ll> del(n);
	vector<ll> parent(n);
	vector<ll> rank(n,0);
	map<ll,bool> m;
	map<ll,ll> msum;
	vector<ll> prefixsum(n);
	
	for(ll i=0;i<n;i++) {
		parent[i]=i;
	}
	vector<ll> top;
	for(ll i=0;i<n;i++) {
		cin>>nums[i];
		if(i==0) {
			prefixsum[i]=nums[i];
		}
		else {
			prefixsum[i]=prefixsum[i-1]+nums[i];
		}
	}
	for(ll i=0;i<n;i++) {
		cin>>del[i];
		del[i]--;
	}
	ll maxi=-1;
	if(n<=1) {
		cout<<0;
		return 0;
	}
	vector<ll> out(1,0);
	for(ll i=del.size()-1;i>=0;i--) {
		m[del[i]]=true;
		msum[del[i]]=nums[del[i]];
		if(del[i]==0) {
			if(m[del[i]+1]==true) {
				ll y=findset(del[i]+1,parent);
				ll tempsum=nums[del[i]]+msum[y];
				makeunion(y,del[i],parent,rank);
				y=findset(y,parent);
				msum[y]=tempsum;
			}
		}
		else if(del[i]==n-1) {
			if(m[del[i]-1]==true) {
				ll y=findset(del[i]-1,parent);
				ll tempsum=nums[del[i]]+msum[y];
				makeunion(y,del[i],parent,rank);
				y=findset(y,parent);
				msum[y]=tempsum;
			}
		}
		else {
			ll x=del[i];
			if(m[x-1]==true) {
				ll y=findset(x-1,parent);
				ll tempsum=msum[x]+msum[y];
				makeunion(y,x,parent,rank);
				y=findset(y,parent);
				msum[y]=tempsum;
			}
			ll k=findset(x,parent);
			if(m[x+1]==true) {
				ll y=findset(x+1,parent);
				ll tempsum=msum[k]+msum[y];
				makeunion(y,k,parent,rank);
				y=findset(y,parent);
				msum[y]=tempsum;
			}
		}
		ll temp=findset(del[i],parent);
		if(i==n-1) {
			maxi=msum[temp];
		}
		else {
			maxi=max(msum[temp],maxi);
		}
		out.push_back(maxi);
	}
	reverse(out.begin(),out.end());
	for(ll i=1;i<out.size();i++) {
		cout<<out[i]<<endl;
	}
	
 }
