//makeking testkey
//:)))))))
/*
*	Author: datqg
*/
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
	//range of testcase
	int t;
	cin>>t;
	//range of n
	ll n;
	cin>>n;
	//range of a[i]
	int range;
	cin>>range;
	//from lb to ub
	//int lb = 20, ub = 100;
	cout<<t<<endl;
	while(t--) {
	int x=rand() %10000;
	cout<<x<<endl;
	//srand(time(0)); generate the same
	for(int i=0;i<x;i++) {
		cout<<rand()%range<<" ";
		//cout << (rand() % (ub - lb + 1)) + lb << " ";
	}
	cout<<endl;
	}
}
