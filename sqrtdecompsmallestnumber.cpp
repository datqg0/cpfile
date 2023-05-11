//???
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	int n,q;
	cin>>n>>q;
	vector<int> nums(n);
	int maxi;
	
	for(int i=0;i<n;i++) {
		cin>>nums[i];
		if(i==0) {
			maxi=nums[i];
		}
		else {
			maxi=max(maxi,nums[i]);
		}
	}
	
	int a=sqrt(n);
	int s=n/a;
	if(n%a!=0) {
		s++;
	}
	
	vector<pair<int,int>> decomp(s);
	vector<int> minseg(s);
	
	int p=0;
	int mini=maxi;
	int i=0;
	
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
	
	for(int i=0;i<decomp.size();i++) {
		mini=maxi;
		for(int j=decomp[i].first;j<=decomp[i].second;j++) {
			mini=min(mini,nums[j]);
		}	
		minseg[i]=mini;
	}
	
/*	for(int i=0;i<decomp.size();i++) {
		cout<<decomp[i].first<<" "<<decomp[i].second<<endl;
	}
	for(int i=0;i<minseg.size();i++) {
		cout<<minseg[i]<<" ";
	}
	cout<<endl;*/
	
	for(int i=0;i<q;i++) {
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		int minout=maxi;
		int l=-1;
		int r=-1;
		// find a 
		for(int j=0;j<decomp.size();j++) {
			int x=decomp[j].first;
			int y=decomp[j].second;
			if(a>=x&&a<=y) {
				l=j;
				break;
			}
		}
		// find b 
		for(int j=0;j<decomp.size();j++) {
			int x=decomp[j].first;
			int y=decomp[j].second;
			if(b>=x&&b<=y) {
				r=j;
				break;
			}
		}
		//generate minout
		//cout<<l<<" "<<r<<endl;
		
		if(l==r) {
			for(int j=a;j<=b;j++) {
				minout=min(minout,nums[j]);
			}
		}
		else {
			if(a==decomp[l].first) {
				minout=min(minout,minseg[l]);
			}
			else {
				for(int j=a;j<=decomp[l].second;j++) {
					minout=min(minout,nums[j]);
				}
			}
			
			for(int j=l+1;j<=r-1;j++) {
				minout=min(minseg[j],minout);
			}
			
			if(b==decomp[r].second) {
				minout=min(minout,minseg[r]);
			}
			else {
				for(int j=decomp[r].first;j<=b;j++) {
					minout=min(minout,nums[j]);
				}
			}
		}
		cout<<minout<<endl;
	}
	
}
