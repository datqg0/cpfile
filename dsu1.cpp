//???
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

void makeset (int i,int parent[]){
	parent[i]=i;
}

int findset (int i,int parent[]) {
	if(i==parent[i]) {
		return i;
	}
	return findset(parent[i],parent);
}

void makeunion (int a,int b,int parent[]) {
	a=findset(a,parent);
	b=findset(b,parent);
	if(a!=b) {
		parent[b]=a;
	}
}

int main() {
	int n;
	cin>>n;
	int parent[n+1];
	for(int i=0;i<=n;i++) {
		makeset(i,parent);
	}
	int q;
	cin>>q;
	for (int k=0;k<q;k++) {
		int type,a,b;
		cin>>type>>a>>b;
		if(type==1) {
			makeunion(a,b,parent);
		}
		else {
			int x=findset(a,parent);
			int y=findset(b,parent);
			if(x==y) {
				cout<<"YES"<<endl;
			}
			else {
				cout<<"NO"<<endl;
			}
		}
	}
}
