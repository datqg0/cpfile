//???
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

void merge (vector<int> &nums,int left,int mid,int right) {
	vector<int> l;
	vector<int> r;
	
	for(int i=left;i<=mid;i++) {
		l.push_back(nums[i]);
	}
	for(int i=mid+1;i<=right;i++) {
		r.push_back(nums[i]);
	}
	
	int i=0;
	int j=0;
	int a=l.size();
	int b=r.size();
	int st=left;
	
	while(i<a&&j<b) {
		if(l[i]<r[j]) {
			nums[st]=l[i];
			st++;
			i++;
		}
		else if(r[j]<l[i]) {
			nums[st]=r[j];
			st++;
			j++;
		}
		else {
			nums[st]=l[i];
			st++;
			nums[st]=l[i];
			st++;
			i++;
			j++;
		}
	}
	
	while(j<b) {
		nums[st]=r[j];
		st++;
		j++;
	}
	
	while(i<a) {
		nums[st]=l[i];
		st++;
		i++;
	}
}

void mergesort (vector<int> &nums ,int l,int r) {
	if(l<r) {
		int m=(l+r)/2;
		mergesort(nums,l,m);
		mergesort(nums,m+1,r);
		
		merge (nums,l,m,r);
	}
}

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	
	int n;
	cin>>n;
	vector<int> nums(n);
	
	for(int i=0;i<n;i++) {
		cin>>nums[i];
	}
	
	mergesort(nums,0,nums.size()-1);
	
	for(int i=0;i<n;i++) {
		cout<<nums[i]<<" ";
	}
	cout<<endl;
	
}
