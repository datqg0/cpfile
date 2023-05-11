//???
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

ll binarysearch1 (vector<ll>&nums ,ll x) {
	ll l=0;
	ll r=nums.size()-1;
	
	while(l<=r) {
		
		ll mid=(l+r)/2;
		
		if(nums[mid]==x) {
			return mid+1;
		}
		
		else if(nums[mid]<x) {
			l=mid+1;
		} 
		
		else {
			r=mid-1;
		}
		
	}
	return -1;
}

ll lower_bound (vector<ll>&nums,ll x) {
	
	ll l=0;
	ll r=nums.size()-1;
	ll point=0;
	
	while(l<=r) {
		
		ll mid=(l+r)/2;
		
		if(nums[mid]==x) {
			if(nums[point]==nums[mid]&&mid>point) {
				point=mid;
			}
			else if(nums[point]<nums[mid]) {
				point=mid;
			}
			l=mid+1;
		}
		else if(nums[mid]<x) {
			if(nums[point]<nums[mid]) {
				point=mid;
			}
			l=mid+1;
		}
		else {
			r=mid-1;
		}
		
	}
	
	if(nums[point]>x) {
		return -1;
	}
	
	return point;
}

ll upper_bound (vector<ll>&nums,ll x) {
	ll l=0;
	ll r=nums.size()-1;
	ll point=r;
	
	while(l<=r) {
		
		ll mid=(l+r)/2;
		
		if(nums[mid]==x) {
			l=mid+1;
		}
		else if(nums[mid]<x) {
			l=mid+1;
		}
		else {
			if(nums[mid]<nums[point]) {
				point=mid;
			}
			else if(nums[mid]==nums[point]&&mid<point) {
				point=mid;
			}
			r=mid-1;
		}
		
	}
	
	if(nums[point]<=x) {
		return -1;
	}
	
	return point;
}

ll equalorbigger (vector<ll>nums,int x) {
	int l=0;
	int r=nums.size()-1;
	int mid;
	int point=nums.size()-1;
	
	while(l<=r) {
		mid=(l+r)/2;
		if(nums[mid]<x) {
			l=mid+1;
		}
		else {
			if(mid<point) {
				point=mid;
			}
			r=mid-1;
		}
	}
	
	if(nums[point]<x) {
		return -1;
	}
	return point;
}

ll numberofnumberssmallerthanxinsortedarr ( vector<ll>&nums,ll x) {
	
	ll l=0;
	ll r=nums.size()-1;
	
	while(l<=r) {
		ll mid=(l+r)/2;
		
		if(nums[mid]>=x) {
			r=mid-1;
		}
		else {
			l=mid+1;
		}
	}
	
	return l;
}

ll sqrtb (ll x) {
	
	ll out=1;
	ll l=1;
	ll r=x;
	
	while(l<=r) {
		
		ll mid=(l+r)/2;
		
		if(mid*mid==x) {
			out=mid;
			break;
		}
		else if (mid*mid<x) {
			if(mid>out) {
				out=mid;
			}
			l=mid+1;
		}
		else {
			r=mid-1;
		}
	}
		
	return out;
}

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	ll n;
	cin>>n;
	vector<ll> nums(n);
	
	for(ll i=0;i<n;i++)  {
		cin>>nums[i];
	}
	
	sort(nums.begin(),nums.end());
	
	ll x;
	cin>>x;
	
	cout<<numberofnumberssmallerthanxinsortedarr (nums,x)<<endl; ;
	cout<< binarysearch1(nums ,100)<<endl;
	cout<<lower_bound(nums,7)<<endl;
	cout<<upper_bound(nums,100)<<endl;
	cout<<sqrtb(10000)<<endl;
	cout<<equalorbigger(nums,9);
	
}
