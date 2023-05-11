/*
*	Author: datqg
*/

#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
string mutiple1(string s1,string s2) {
	string out="";
	int t;
	string temp1;
	int mtp1;
	int mtp2=s2[0]-48;
	int memo=0;
	for(int i=s1.size()-1;i>=0;i--) {
		mtp1=s1[i]-48;
		t=mtp1*mtp2;
		t+=memo;
		if(t<10) {
			temp1=t+48;
			out=temp1+out;
			memo=0;
		}
		else {
			if(i==0) {
				temp1=to_string(t);
				out=temp1+out;
			}
			else {
				int r=t%10;
				t=t/10;
				memo=t;
				temp1=r+48;
				out=temp1+out;
			}
		}
	}
	return out;
}

void mutiple2 (string s1,string s2) {
	string out;
	vector<string> store;
	for(int i=s2.size()-1;i>=0;i--) {
		string mtp="";
		mtp+=s2[i];
		string pb=mutiple1(s1,mtp);
		for(int j=0;j<(s2.size()-1)-i;j++) {
			pb+='0';
		}
		store.push_back(pb);
	}
	int em=store[store.size()-1].size();
	for(int i=0;i<store.size();i++) {
		if(store[i].size()<em) {
			int time=em-store[i].size();
			for(int j=0;j<time;j++) {
				store[i]='0'+store[i];
			}
		}
		//cout<<store[i]<<endl;
	}
	//cout<<endl;

	int memo=0;
	
	for(int i=em-1;i>=0;i--) {
		//cout<<memo<<endl;
		int sum=0;
	for(int k=0;k<store.size();k++) {
		int x=store[k][i]-48;
		sum+=x;
	}
	//cout<<sum<<" "<<endl;
	sum+=memo;
	string xuli=to_string(sum);
	if(xuli.size()==1) {
		out=xuli+out;
		memo=0;
	}
	else {
		if(i!=0) {
			string tem="";
			tem+=xuli[xuli.size()-1];
		out=tem+out;
		memo=0;
		int a=1;
		for (int b=xuli.size()-2;b>=0;b--) {
			int f=xuli[b]-48;
			f=f*a;
			memo+=f;
			a=a*10;
		}
		}
		else {
			out=xuli+out;
		}
	}
}
	cout<<out;
}


int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	int n,m;
  	string s1,s2;
  	cin>>s1>>s2;
  	n=s1.size();
  	m=s2.size();
  	string s3;
  	mutiple2(s1,s2);
}
