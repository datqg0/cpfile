//???
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

class hi {
	public:
	int data1;
	int data2;
};

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	int t;
	cin>>t;
	//use . with basic object 
	hi o;
	o.data1=0;
	o.data2=0;
	cout<<o.data1<<" "<<o.data2<<endl;
	
	//use -> with pointer object it point to what pointer point to
	hi* p;
	//allocated p because  that objects instantiated on the heap (using new) need to be cleaned up manually, those instantiated on the stack (without new) are automatically cleaned up when they go out of scope.
	/*heap and stack memory
	
	p=new hi(); 
	p->data1=1;
	p->data2=1;
	cout<<p->data1<<" "<<p->data2<<endl;
}
