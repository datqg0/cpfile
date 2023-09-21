//???
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

struct Point {
	int x;
	int y;
	bool operator!=(const Point &o) {
        return  x != o.x || y != o.y;
    }
    bool operator==(const Point &o) {
        return  x == o.x && y == o.y;
    }
};
int oriented (Point a,Point b,Point c) {
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
	//cout<<n<<endl;
	for (int i=0;i<n;i++) {
		if(sto[i].x<sto[0].x) {
			swap (sto[0],sto[i]);
		}
	}
	vector<Point> hullout;
	Point p=sto[0];
	do  {
		hullout.push_back(p);
		Point q=sto[0];
		for (int i=0;i<n;i++) {
			if(q==p) {
				q=sto[i];
			}
			if(oriented(p,q,sto[i])==2) {
				q=sto[i];
			}
		}
		p=q;
	}
	while (p!=sto[0]);
	return hullout;
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
