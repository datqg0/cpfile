#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
//dfs recursion
void dfs (vector<vector<int>>&edge ,vector<bool> & check,int n) {
	
	for(int i=0;i<edge[n].size();i++) {
		if(check[edge[n][i]]==false) {
			check[edge[n][i]]=true;
			cout<<edge[n][i]<<" ";
			dfs(edge,check,edge[n][i]);
		}
	}
	
}

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	
	int n,m;
	cin>>n>>m;
	
	vector<bool> check(n+1,false);
	vector<int> temp;
	vector<vector<int> > edge(n+1,temp);
	
	for(int i=0;i<m;i++) {
		int a,b;
		cin>>a>>b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	
	for(int i=1;i<n;i++) {
		cout<<i<<" : ";
		for(int j=0;j<edge[i].size();j++) {
			cout<<edge[i][j]<<" ";
		}
		cout<<endl;
	}
	
	//dfs with stack
	/*stack<int> dfs;
	dfs.push(1);
	cout<<1<<" ";
	check[1]=true;
	while(dfs.empty()==false) {
		int a=dfs.top();
		for(int i=0;i<edge[a].size();i++) {
			if(check[edge[a][i]]==false) {
				check[edge[a][i]]=true;
				dfs.push(edge[a][i]);
				cout<<edge[a][i]<<" ";
				break;
			}
		}
		if(dfs.top()==a) {
				dfs.pop();
			}
	}*/
	
	cout<<1<<" ";
	check[1]=true;
	dfs (edge,check,1);
}
