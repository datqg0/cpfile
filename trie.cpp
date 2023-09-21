//???
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

struct Trie {
	struct Node {
		Node* child[2];
		ll cnt;
		Node() {
		child[0]=NULL;
		child[1]=NULL;
		cnt=0;
		};
	};
	ll n;
	Node*root;
	Trie(): n(0) {
		root=new Node();
	}
	void addnode (vector<ll>&bin) {
		Node *p=root;
		for (ll i=30;i>=0;i--) {
			ll add=0;
			if((i+1)<=(ll)bin.size()) {
				add=bin[i];
			}
			if(p->child[add]==NULL) {
				p->child[add]=new Node();
			}
			p=p->child[add];
			p->cnt++;
		}
	}
	bool delnode (Node*p,vector<ll>&del,ll pos) {
		if(pos!=(ll)del.size()) {
			bool check=delnode(p->child[del[pos]],del,pos+1);
			if(check==true) {
				del.pop_back();
				p->child[del[pos]]=NULL;
			}
		}
		else {
			
		}
		if(p!=NULL) {
			p->cnt--;
			if(p->cnt==0&&p!=root) {
				delete(p);
				return true;
			}
		}
		return false;
	}
	ll find (vector<ll>&bin,ll modelpow) {
		ll clone=modelpow;
		ll clone2=0;
		vector<ll> del;
		Node* p=root;
		ll out=0;
		for (ll i=30;i>=0;i--) {
			modelpow/=2;
			ll add=0;
			ll com=0;
			if((i+1)<=(ll)bin.size()) {
				add=bin[i];
				com=bin[i];
			}
			if(p->child[add]==NULL) {
				if(add==0) {
					add=1;
				}
				else {
					add=0;
				}
			}
			if(add!=com) {
					out+=modelpow;
				}
			
			del.push_back(add);
			p=p->child[add];
		}
	/*	for (ll k=0;k<del.size();k++) {
			clone/=2;
			cout<<del[k]<<" ";
			if(del[k]==1) {
				clone2+=clone;
			}
		}
		cout<<endl;
		cout<<"XORED :"<<clone2<<endl;*/
		delnode(root,del,0);
		del.clear();
		//cout<<endl;
		return out;
	}
};

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	Trie sto;
	ll n;
	cin>>n;
	ll modelpow=1;
	for (ll i=0;i<31;i++) {
		modelpow*=2;
	} 
	vector<ll> a(n);
	vector<ll> b(n);
	for (ll i=0;i<n;i++) {
		cin>>a[i];
	}
	vector<ll> bin;
	for (ll i=0;i<n;i++) {
		cin>>b[i];
		bin.clear();
		while(b[i]>0) {
			if(b[i]&1) {
				bin.push_back(1);
			}
			else {
				bin.push_back(0);
			}
			b[i]/=2;
		}
		sto.addnode(bin);
	}
	for (ll i=0;i<n;i++) {
		//cout<<a[i]<<" ";
		bin.clear();
		while(a[i]>0) {
			if(a[i]&1) {
				bin.push_back(1);
			}
			else {
				bin.push_back(0);
			}
			a[i]/=2;
		}
		cout<<sto.find(bin,modelpow)<<" ";
	}
	
}