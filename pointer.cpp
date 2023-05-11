//???
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
	//pointer
	
	//address of a variable
	int a=100;
	//&a is check address of a
	cout<<&a<<endl;
	
	// (*) is dereference operator
	// (&) is address operator
	//type pointer-save the address of a variable
	//define 
	// i call data in the address x is data and in pointer we can get data from address by use  *' pointer name'
	int* ad;
	cout<<*ad<<endl; 
	//(the initial data of pointer ad is depend on machine)
	//assign address of a for pointer  
	ad=&a;
	
	//data of ad is change be cause ad = (address of a)
	cout<<*ad<<endl;
  	// a pointer still have address (now ad point to adress so also change value of a)
  	cout<<&ad<<endl;
  	// assign using *
  	*ad=900;
  	cout<<a<<" "<<*ad<<endl;
  	
  	/*Note that the asterisk (*) used when declaring a pointer only means that it is a pointer (it is part of its type compound specifier), 
  	and should not be confused with the dereference operator seen a bit earlier, 
  	but which is also written with an asterisk (*). They are simply two different things represented with the same sign.*/
  	
  	//array pointer and iterator in vector
  	
  	//array
  	int arr[5];
  	//point to first element in array
  	int *p =arr;
  	*p=1;
  	cout<<arr[0];
  	//increase p to one element
  	p++;
  	*p=2;
  	cout<<*p<<endl; 
  	/*this lines of code mean address will change if it not in arr !will not error 
  	and value is random or you can think it is element out of bounds and point to random value*/
  	p+=500;
  	cout<<*p<<endl;
  	
  	//vector
  	vector<int> vt ={1,2,3,4,5};
  	vector<int> ::iterator it; // pointer int vector;
  	//first element of vt 
  	//it=vt.begin() ;
  	//cout<<*it<<endl;
  	//end of vt vt.begin()-1 is address of final element
  	//it=vt.end();
  	//this line will cause memory errot because v.end() is not any element in vt cout<<*it<<endl;
  	//vt.end() like a limit
  /*	for (it=vt.begin();it<vt.end();it++) {
  		cout<<*it<<" ";
  	}*/
  	//pointer can assign to const but can modify it 
  	// array vector string is the same
  	
  	//Pointers to pointers
  	int *c;
  	//c is a pointer and the address of c point to a integer
  	int **d;
  	//d is the pointer and d point to another pointer and this pointer point to a integer 
  	int o=9;
  	c=&o;
  	d=&c;
  	cout<<**d<<endl;
  	/*in this  case d is the pointer and point to c and c is pointer point to o*/
/* illustrate :
  	d      				c     				 o
  (d address)  ----- (c adress)		------(o address)
  			   |					|
  (d value)	---		(c value)  -----		(o value)
  */
  
  	//void pointer
  	/*a special type of pointer.
  	In C++, void represents the absence of type. Therefore, void pointers are pointers 
  	that point to a value that has no type (and thus also an undetermined length and
	undetermined dereferencing properties).*/
	/*This gives void pointers a great flexibility,
	 by being able to point to any data type, 
	 from an integer value or a float to a string of characters. 
	 In exchange, they have a great limitation: the data pointed
	to by them cannot be directly dereferenced (which is logical, 
	since we have no type to dereference to), and for that reason, any 
	address in a void pointer needs to be transformed into some other pointer type that 
	points to a concrete data type before being dereferenced.*/
	/* example and expplain 
	// display
#include <iostream>
#include <string>
using namespace std;

void display (void* data, string type)
{
	//change void point ter to type pointer
	//type is variable have type of data
  if ( type == "char" )  {
  	char* pchar; 
  	pchar=(char*)data; 
  	cout<<*pchar <<endl;
  	}
  else if (type=="int") { 
  	int* pint; 
  	pint=(int*)data; 
  	cout<<*pint<<endl; 
  	}
}

int main ()
{
  char a = 'x';
  int b = 1602;
  display (&a,"char");
  display (&b,"int");
  cout << a << ", " << b <<endl;
}

*/

//pointer to function
/*#include <iostream>
using namespace std;

int addition (int a, int b)
{ return (a+b); }

int subtraction (int a, int b)
{ return (a-b); }

//point to a fuction
int operation (int x, int y, int (*functocall)(int,int))
{
  int g;
  g = (*functocall)(x,y);
  return (g);
}

int main ()
{
  int m,n;
  int (*minus)(int,int) = subtraction;

  m = operation (7, 5, addition);
  n = operation (20, m, minus);
  cout <<n;
  return 0;
}
*/

//pounter in void and fuction to reduce memory and change value
/*#include <iostream> 
using namespace std;

//int void or fuction if you want change data (local data you must to pount to this data address if not it will clone new data with sam value)
void increase (int &a) {
	a++;
}
int main() {
	int a=0;
	increase(a);
}
  	*/
}
