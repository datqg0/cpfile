//???
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int gcdeuclid (int a,int b) {
	if(a%b==0) {
		return b;
	}
	return gcdeuclid(b,a%b);
}

int extendegcdeuclid (int )

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	
	
	//a = r+n*ceil(a/n)
	//a mod n = r
	//a mod n + b mod n = (a+b) mod n
	//a mod n - b mod n = (a-b) mod n
	//(a mod n) * (b mod n) =a*b mod n
	// modulo negative number 
	// type 1 negative result
	// -8%7 = -1
	// mean -7 * 1 + -1 =-8
	// type 2 positive result
	// -8%7 =6 (just plus n to type one result)
	//mean -7*2+6=-8 
	
	// if a mod n = b mod n
	// a-b mod n = 0
	// for p is prime number a^p-a mod p =0 (small fermat theorem)
	// or it can be said if p is prime number a^p mod p = a mod p
	// another is a^(m-1) mod m =1
	
	//a ≡ b (mod n) when a mod n = b mod n
	// consequence -a ≡ -b (mod n) still right with  (a^k,a*k,a+k);
	// a ≡ 0 (mod n) mean a mod n = 0 mod n =0;
	
	// euclid to find gcd fast
	int a,b;
	cin>>a>>b;
	cout<<gcdeuclid(max(a,b),min(a,b))<<" "<<__gcd(a,b);
	
	//proof 
   /*in this proof a>=b if in real life a<b we can swap a and b
	+n is time a mod b in fucntion
	we call a mod b = r[i]
	we call r[n-1] is the last r[i]!=0 so :
	+first we prove a and b mod r[n-1]=0
	we have r[n-2] mod r[n-1] =  r[n] = 0
	so r[n-2] = k[n-1] * r[n-1] (k[i] is integer numbers)  
	we have r[n-3]=k[n-2] * r[n-2] +r[n-1];
		so  r[n-3]=(k[n-1]+1)r[n-1]
		=>r[n-3] mod r[n-1]=0
		use in duction we can prove r[0](a) mod  and r[1](b) all mod r[n-1]=0
		=> a mod r[n-1] =0 and b mod r[n-1] = 0
	+second we prove r[n-1] mod all common divisors of a and b =0
		we have c is common divisor of a and b
		so a= n*c
		   b= m*c
		   a = m*c * r[1]
		<=>r1 = a- m*c
		<=>r1 = n*c -m*c
		<=>r1 = c*(n-m)
		=> r1 mod c =0
		use induction we can prove r[i] mod c =0
	=>so c<= r[n-1] and if c is biggest we can take c= r[n-1] 
	because in first we prove a and b mod r[n-1]=0
			   second we prove r[n-1] mod c =0 with c is 
			   common divisor of a and b
	so final consequence greatest common divisor of a and b is r[n-1]
	*/
	
	
	
}
