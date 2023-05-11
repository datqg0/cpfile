//???
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

//we store segment tree by vector for optimization i will code basic in other file
//parent element at position i so left is 2*i and r is 2*i+1

void build (vector<ll>& nums,vector<ll>&segtree,ll m,ll l,ll r ) {
	if(l==r) {
		segtree[m]=nums[l];
	}
	else {
		ll mid=(l+r)/2;
		//left child node
		build (nums,segtree,2*m,l,mid);
		//right child node
		build (nums,segtree,2*m+1,mid+1,r);
		//parent node
		segtree[m]=segtree[2*m]+segtree[2*m+1];
	}
}

void query1 (vector<ll>&segtree,ll m,ll l,ll r,ll k,ll u)  {
	if(l==r) {
		if(l==k) {
			segtree[m]=u;
		}
	}
	else {
		ll mid= (l+r)/2;
		if(k<=mid) {
			query1(segtree,2*m,l,mid,k,u); 
		}
		else {
			query1(segtree,2*m+1,mid+1,r,k,u);
		}
		segtree[m]=segtree[2*m]+segtree[2*m+1];
	}
}

ll query2 (vector<ll>&segtree,ll m,ll l,ll r,ll a,ll b) {
	if(b<l||a>r) {
		return 0;
	}
	if(l>r) {
		return 0;
	}
	if(a==l && b==r ) {
		return segtree[m];
	}
	ll mid = (l+r)/2;
	return  query2 (segtree,2*m,l,mid,a,min(mid,b))+query2 (segtree,2*m+1,mid+1,r,max(a,mid+1),b);
}
int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	ll n;
	cin>>n;
	//ll q;
	//cin>>q;
	vector<ll> nums(n);
	vector<ll> segtree(4*n+1,0);
	
	for(ll i=0;i<n;i++) {
		cin>>nums[i];
	}
	
	build (nums,segtree,1,0,n-1);
	
	for(int i=0;i<segtree.size();i++) {
		cout<<segtree[i]<<" ";
	}
	cout<<endl;
	
	/*
	for(ll i=0;i<q;i++) {
		ll type;
		cin>>type;
		if(type==1) {
			ll k,u;
			cin>>k>>u;
			k--;
			query1(segtree,1,0,n-1,k,u);
		}
		else {
			ll a,b;
			cin>>a>>b;
			a--;
			b--;
			cout<<query2(segtree,1,0,n-1,a,b)<<endl;
		}
	}
	*/
}
