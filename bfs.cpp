//???
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

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
	
	//bfs with queue
	/*queue <int> bfs;
	bfs.push(1);
	check[1]=true;
	while (bfs.empty()!=true) {
		int o=bfs.front();
		for(int i=0;i<edge[bfs.front()].size();i++) {
			if(check[edge[o][i]]==false) {
				check[edge[o][i]]=true;
				bfs.push(edge[o][i]);
			}
		}
		cout<<o<<" ";
		bfs.pop();
	}*/
	
}
