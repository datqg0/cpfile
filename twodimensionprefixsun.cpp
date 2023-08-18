//???
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	int n;
	cin>>n;
	int q;
	cin>>q;
	vector<string> forest(n);
	int prefixsum[n][n];
	for (int i=0;i<n;i++) {
		cin>>forest[i];
	}
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			int x=0;
			if(forest[i][j]=='*') {
				x=1;
			}
			if(i==0&&j==0) {
				prefixsum[i][j]=x;
			}
			else if(i==0) {
				prefixsum[i][j]=prefixsum[i][j-1]+x;
			}
			else if(j==0) {
				prefixsum[i][j]=prefixsum[i-1][j]+x;
			}
			else {
				prefixsum[i][j]=x+prefixsum[i-1][j-1]+(prefixsum[i-1][j]-prefixsum[i-1][j-1])+(prefixsum[i][j-1]-prefixsum[i-1][j-1]);
			}
		}
	}
	for (int i=0;i<q;i++) {
		int x1,y1,x2,y2;
		cin>>y1>>x1>>y2>>x2;
		y1--;
		y2--;
		x1--;
		x2--;
		int p1,p2,p3,p4;
		p2=0,p3=0,p1=0;
		p4=prefixsum[y2][x2];
		if((x1-1)>=0) {
			p3=prefixsum[y2][x1-1];
		}
		if((y1-1)>=0) {
			p2=prefixsum[y1-1][x2];
		}
		if((x1-1)>=0&&(y1-1)>=0) {
			p1=prefixsum[y1-1][x1-1];
		}
		cout<<p4-p3-p2+p1<<endl;
	}
}
