/*
*	Author: datqg
*/
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	set<int> s;
	s.insert(10);
	s.insert(10);
	s.insert(20);
	s.insert(20);
	s.insert(20);
	s.insert(20);
	s.insert(30);
	//s.insert(30);
	s.insert(50);
	s.insert(70);
	//10 20 30 50
	set<int> :: iterator it;
	it=lower_bound(s.begin(),s.end(),30);//first element greater or equal than value
	//it--;
	cout<<*it<<endl;
	it=upper_bound(s.begin(),s.end(),30);//first element greater than value
	//it--;
	cout<<*it<<endl;
}
