//???
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	int n,k,q;
	cin>>n>>k>>q;
	vector<int> d(200003,0);
	for(int i=0;i<n;i++) {
		int p,b;
		cin>>p>>b;
		d[p]++;
		d[b+1]--;
	}
	vector<int> sum(200003,0);
	vector<int> a(200003,0);
	int su=0;
	int su2=0;
	for(int i=1;i<200003;i++) {
		su+=d[i];
		sum[i]=su;
		if(sum[i]>=k) {
			su2++;
		}
		a[i]=su2;
	}
	for(int i=0;i<q;i++) {
		int p,b;
		cin>>p>>b;
		cout<<a[b]-a[p-1]<<endl;
	}
}
