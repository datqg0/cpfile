//???
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int parent[200001];
int sizek[200001];
int ranks[200001];

void makeset (int i){
	parent[i]=i;
	sizek[i]=1;
	ranks[i]=0;
}

int findset (int i) {
	if(i==parent[i]) {
		return i;
	}
	return findset(parent[i]);
}

/*
//connect road optimization
//mean if we must to go from a->b->c we make a->c and b->c
int findset (int v) {
	if(parent[v]==v) {
		return v;
	}
	int p=findset(parent[v]);
	parent[v]=p;
	return p;
}
*/
/*
void makeunion (int a,int b) {
	a=findset(a);
	b=findset(b);
	if(a!=b) {
		parent[b]=a;
	}
}
*/

//size optimization
void makeunion (int a,int b) {
	a=findset(a);
	b=findset(b);
	if(a!=b) {
		if(sizek[a]<sizek[b]) {
			swap(a,b);
		}
		parent[b]=a;
		sizek[a]+=sizek[b];
	}
}
/*
//heigh optimization
void makeunion3 (int a,int b) {
	a=findset(a);
	b=findset(b);
	if(a!=b) {
		if(ranks[a]<ranks[b]) {
			swap(a,b);
		}
		parent[b]=a;
		if(ranks[a]==ranks[b]) {
			ranks[a]++;
		}
	}
}
*/
/*
//combine size+heigh optimization
void makeunion (int a,int b) {
	a=findset(a);
	b=findset(b);
	if(a!=b) {
		if(ranks[a]<ranks[b]) {
			swap(a,b);
		}
		if(sizek[a]<sizek[b]) {
			swap(a,b);
		}
		parent[b]=a;
		if(ranks[a]==ranks[b]) {
			ranks[a]++;
		}
		sizek[a]+=sizek[b];
	}
}*/

int main() {
	int n;
	cin>>n;
	for(int i=0;i<=n;i++) {
		makeset(i);
	}
	int q;
	cin>>q;
	for (int k=0;k<q;k++) {
		int type,a,b;
		cin>>type>>a>>b;
		if(type==0) {
			makeunion(a,b);
		}
		else {
			int x=findset(a);
			int y=findset(b);
			if(x==y) {
				cout<<"1"<<endl;
			}
			else {
				cout<<"0"<<endl;
			}
		}
	}
}
