//???
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;


int findset (int x,vector<int>& parent) {
    if(x==parent[x]) {
        return x;
    }
    int p= findset(parent[x],parent);
    parent[x]=p;
    return p;
}

void unionset (int a,int b,vector<int> & parent,vector<int>&rank) {
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
        int n;
        cin>>n;
        int g;
        cin>>g;
        vector<bool> checki(n,false);
        vector<int> parent(n);
        vector<int> temp;
        vector<int> rank(n);
        vector<vector<int> > graph(n,temp);
        for(int i=0;i<n;i++) {
            parent[i]=i;
            rank[i]=0;
        }

        for(int i=0;i<g;i++) {
            int a,b;
            cin>>a>>b;
            a--;
            b--;
            graph[a].push_back(b);
            graph[b].push_back(a);
            unionset(a,b,parent,rank);
        }

        vector<int> top;
        map<int,int> m;
        for(int i=0;i<n;i++) {
            int x= findset(i,parent);
            if(m[x]!=true) {
                m[x]= true;
                top.push_back(x);
            }
        }

        int out=0;
        for(int i=0;i<top.size();i++) {
            if(graph[top[i]].size()==2) {
                int goal=graph[top[i]][1];
                bool check=false;
                stack<int> dfs;
                dfs.push(graph[top[i]][0]);
                while(dfs.empty()== false) {
                    int x=dfs.top();
                    if(graph[x].size()!=2) {
                        check=false;
                        break;
                    }
                    else {
                        if(x==goal) {
                            check = true;
                            break;
                        }
                        else {
                            for(int k=0;k<graph[x].size();k++) {
                                if(checki[graph[x][k]]==false) {
                                    dfs.push(graph[x][k]);
                                    checki[graph[x][k]]=true;
                                }
                            }
                        }
                    }
                    if(dfs.top()==x) {
                        dfs.pop();
                    }
                }
                if(check==true) {
                    out++;
                }
             }
        }

        cout<<out<<endl;
    }
