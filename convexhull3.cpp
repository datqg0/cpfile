//???
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

struct Point {
	int x,y;
};
int oriented (Point &a,Point& b,Point& c) {
	int d=(b.y-a.y)*(c.x-b.x)-(c.y-b.y)*(b.x-a.x);
	if (d==0) {
		return 0;
	}
	else if(d<0) {
		return 2;
	}
	return 1;
}
vector<Point> convexhull (vector<Point> & sto) {
	int n=sto.size();
	sort (sto.begin(),sto.end(),[&sto](Point &a,Point &b) {
		if(a.x<b.x) {
			return true;
		}
		else if(a.x>b.x) {
			return false;
		}
		else {
			return a.y<b.y;
		}
	});
	vector<Point> out;
	out.push_back(sto[0]);
	for (int i=1;i<n;i++) {
		while(out.size()>=2&&oriented (out[out.size()-2],out[out.size()-1],sto[i])!=1) {
			out.pop_back();
		}
		out.push_back(sto[i]);
	}
	/*for (int i=0;i<sto.size();i++) {
		cout<<sto[i].x<<" "<<sto[i].y<<endl;
	}
	cout<<endl;
	for (int i=0;i<out.size();i++) {
		cout<<out[i].x<<" "<<out[i].y<<endl;
	}
	cout<<endl;*/
	for (int i=n-2;i>=0;i--) {
		while(out.size()>=2&&oriented (out[out.size()-2],out[out.size()-1],sto[i])!=1) {
			out.pop_back();
		}
		out.push_back(sto[i]);
	}
	out.pop_back();
	return out;
}


int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	int n;
  	cin>>n;
	vector<Point>sto(n);
	for (int i=0;i<n;i++) {
		cin>>sto[i].x>>sto[i].y;
	}
	vector<Point> out;
	out=convexhull(sto);
	//cout<<oriented(sto[0],sto[7],sto[5])<<endl;
	int k=out.size();
	for (int i=0;i<k;i++) {
		cout<<out[i].x<<" "<<out[i].y<<endl;
	}
}
