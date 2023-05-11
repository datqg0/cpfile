//???
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

double binpow(double a, ll b) {
    if (b == 0)
        return 1;
    ld res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	double n;
  	int m;
  	cin>>n>>m;
  	double a=n;
	cout<<a*binpow(1.000000011,m);
}
