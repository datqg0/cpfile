/*
*	Author: datqg
*/
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	int t;
	cin>>t;
	int time=t;
	while(t--) {
		int n;
		cin>>n;
		vector<int> nums(n);
		for(int i=0;i<n;i++) {
			cin>>nums[i];
		}
		int out=0;
		sort(nums.begin(),nums.end());
		/*for(int i=0;i<n;i++) {
			cout<<nums[i]<<" ";
		}
		cout<<endl;*/
		if(n==1) {
			out=1;
		}
		else {
		multiset<int> :: iterator it;
		for(int k=1;k<=n;k++) {
			//cout<<k<<" :" <<endl;
			bool check=true;
			multiset<int>temp(nums.begin(),nums.end());
			for(int i=k;i>=1;i--) {
			/*	for(auto c:temp) {
					cout<<c<<" ";
				}
				cout<<endl;*/
				if(temp.size()==0) {
					check=false;
					break;
				}
				it=upper_bound(temp.begin(),temp.end(),i);
				if(it==temp.begin()) {
					check=false;
					break;
				}
				else  {
					it--;
					temp.erase(it);
				}
				if(temp.size()>0) {
				int x=*temp.begin()+i;
				temp.erase(temp.begin());
				temp.insert(x);
				}
			}
			//cout<<endl;
			if(check==true) {
				out=k;
			}
			temp.clear();
		}
		}
		cout<<out<<endl;
	}
}
