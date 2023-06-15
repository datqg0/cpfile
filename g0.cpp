//???
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	cout<<100<<endl;
	int t=100;
	srand (time(NULL));
	while(t--) {
		
		int n=rand()%10;
		if(n==0) {
			n++;
		}
		cout<<n<<endl;
		for(int i=0;i<n;i++) {
			int x=rand()%n;
			if(x==0) {
				x++;
			}
			cout<<x<<" ";
		}
		cout<<endl;
		
		for(int i=0;i<n;i++) {
			int x=rand()%n;
			if(x==0) {
				x++;
			}
			cout<<x<<" ";
		}
		cout<<endl;
	}
}
