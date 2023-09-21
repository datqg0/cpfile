//???
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int getsum(vector<int> & bit,int range) {
	int idx=range;
	int out=0;
	while(idx>0) {
		out+=bit[idx];
		idx-=(idx&(-idx));
	}
	return out;
}

void update (vector<int>&bit,int range) {
	int idx=range;
	int n=bit.size();
	while(idx<=n) {
		bit[idx]++;
		idx+=(idx&(-idx));
	}
}

int main() {
	int n;
	cin>>n;
	vector<int> memo(n);
	for (int i=0;i<n;i++) {
		cin>>memo[i];
	}
	int number0=0;
	int bitsize=2;
	int a=2;
	while(a<memo.size()) {
		a=a*2;
	}
	vector<int> bit(a+1,0);
	int sum=0;
	for (int i=0;i<n;i++) {
		if(memo[i]!=0) {
			cout<<i-(getsum(bit,memo[i])+number0)<<" ";
			sum+=i-(getsum(bit,memo[i])+number0);
			update (bit,memo[i]);
		}
		else {
			sum+=(i-number0);
			cout<<i-number0<<" ";
			number0++;
		}
	}
	cout<<endl;
	cout<<sum;
}
