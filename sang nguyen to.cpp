/*
*	prime number
*/
//basic seive
/*
  	ll n=1000000000;
	vector<bool> prime (n+1,true);
	prime[0]=false;
	prime[1]=false;
	for(ll i=2;i*i<n;i++) {
		if(prime[i]==true) {
			for(ll j=i*i;j<n;j+=i) {
				prime[j]=false;
			}
		} 
	}
	for(ll i=0;i<=100;i++) {
		 if(prime[i]==true) {
			cout<<i<<" ";
		}
	}
	 */
	 
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	const int N = 100000000;
vector<int> lp(N+1);
vector<int> pr;

for (int i=2; i <= N; ++i) {
    if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back(i);
    }
    for (int j = 0; i * pr[j] <= N; ++j) {
        lp[i * pr[j]] = pr[j];
        if (pr[j] == lp[i]) {
            break;
        }
    }
}
}
