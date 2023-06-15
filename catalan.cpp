//???
#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define ld long double
using namespace std;

/* way1:naive recusion
int catalan (int n) {
	if(n<=1) {
		return 1;
	}
	int x=4*n-2;
	return catalan(n-1)*x/(n+1);
}*/

/* way2:still recusion
ull catalan (int n) {
	if(n<=1) {
		return 1;
	}
	ull res=0;
	for(int i=0;i<n;i++) {
		res+= (catalan(i)*catalan(n-i-1));
	}
	return res;
}*/

/* way3 :my usual dp
it will optimize by memorize c(i) and if c(i) was memorized when the fuction 
call it will reduce time to call the orther
ull catalan (int n,vector<ull>&sto,vector<bool>&check) {
	if(check[n]==true) {
		return sto[n];
	}
	ull res=0;
	for(int i=0;i<n;i++) {
		res+=(catalan(i,sto,check)*catalan(n-i-1,sto,check));
	}
	sto[n]=res;
	check[n]=true;
	return sto[n];
}
*/

/* good dp sol 
ull catalan (int n) {
	vector<ull> sto(n+1);
	sto[0]=1;
	sto[1]=1;
	for(int i=2;i<=n;i++) {
		sto[i]=0;
		for(int j=0;j<i;j++) {
			sto[i]+=(sto[j]*sto[i-j-1]);
		}
	}
	return sto[n];
}*/

/*dp sol depend on formular
ull catalan(int n) {
	vector<ull> sto(n+1);
	sto[0]=1;
	sto[1]=1;
	sto[2]=2;
	for(int i=3;i<=n;i++) {
		int x=4*i-2;
		sto[i]=sto[i-1]*x;
		sto[i]/=(i+1);
	}
	return sto[n];
}
*/

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	int n;
  	cin>>n;
  /*vector<ull> sto(n+1);
  	vector<bool> check(n+1,false);
  	check[0]=true;
  	check[1]=true;
  	check[2]=true;
  	sto[0]=1;
  	sto[1]=1;
  	sto[2]=2;	
	cout<<catalan (n,sto,check);*/
	cout<<catalan(n);
}
