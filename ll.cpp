//???
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

class Node {
	public:
	//node data
	int data;
	//pointer point to next node data
	Node* next;
};

void travel (Node*head) {
	Node* temp=head;
	while(temp!=NULL) {
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

void insert (Node*head,int position,int x ) {
	int count=0;
	Node*a;
	Node*b;
	Node*temp;
	
	temp = new Node();
	a    = new Node();
	b	 = new Node();
	
	temp=head;
	while(temp!=NULL && count < position) {
		count++;
		a=temp;
		b=temp->next;
		temp=temp->next;
	}
	
	Node* add = new Node ;
	add->data = x;
	add->next =b;
	a->next=add;
}
void deletepos (Node* &head,int position) {
	int count=0;
	Node*a;
	Node*b;
	Node*temp;
	
	temp = new Node();
	a    = new Node();
	b	 = new Node();
	
	if(position==0) {
		head =head->next;
	}
	else {
		temp=head;
		a=temp;
		while(temp!=NULL && count < position) {
			count++;
			b=temp->next;
			temp=temp->next;
			if(count==position) {
				a->next=b->next;
				break;
			}
			a=temp;
		}
	}
}

int searchpos (Node*head ,int position) {
	int count=0;
	Node*temp=head;
	
	while(temp!=NULL) {
		if(count==position) {
			return temp->data;
		}
		temp=temp->next;
		count++;
	} 
	return -1;
}

vector<int> searchval (Node*head,int value) {
	vector<int> sto;
	int count=0;
	Node*temp=head;
	
	while(temp!=NULL) {
		if(temp->data==value) {
			sto.push_back(count);
		}
		count++;
		temp=temp->next;
	} 
	return sto;
}

int listsize (Node*head){
	int out=0;
	Node*temp=head;
	
	while(temp!=NULL) {
		out++;
		temp=temp->next;
	}
	return out;
}

void deleteval (Node* head,int x) {
	int sub=0;
	vector<int> del =searchval(head,x);
	for(int i=0;i<del.size();i++){
		deletepos(head,del[i]-sub);
		sub++;
	}
}

void swap (Node* head,int pos1,int pos2) {
	
	//get data of position1 and position2
	int a = searchpos(head,pos1);
	int b = searchpos(head,pos2);
	int count = 0 ;
	Node*temp = head;
	
	//change data
	while(temp!=NULL) {
		if(count==pos1) {
			temp->data=b;
			break;
		}
		count++;
		temp=temp->next;
	}
	
	while(temp!=NULL) {
		if(count==pos2) {
			temp->data=a;
			break;
		}
		count++;
		temp=temp->next;
	}
}

void sort1 (Node*head) {
	//o(n^2) normal sort
	Node *temp=head;
	
	while(temp->next!=NULL) {
		Node*now=temp->next;
		int b=temp->data; 
		while(now!=NULL){
			int a = now->data;
			if (a<b) {
				temp->data=a;
				now->data=b;
				int temp=b;
				b=a;
				a=temp;
			}
			now=now->next;
		}
		temp=temp->next;
	}
}

void reversed1 (Node*head) {
	int a=listsize(head);
	int mid=a/2;
	mid--;
	
	Node*temp=head;
	
	vector<Node*> sto(mid+1);
	int j=mid;
	
	int count =0;
	while(count<=mid) {
		sto[j]=temp;
		temp=temp->next;
		count++;
		j--;
	}
	
	if(a&1) {
		temp=temp->next;
	}
	
	for(int i=0;i<sto.size();i++) {
		int r=temp->data;
		temp->data=sto[i]->data;
		sto[i]->data=r;
		temp=temp->next;
	}
}

void reversed2 (Node*head) {
	vector<int> sto(listsize(head),0);
	Node*temp = head;
	
	int j=sto.size()-1;
	
	while(temp!=NULL) {
		sto[j]=temp->data;
		j--;
		temp=temp->next;
	}
	
	j=0;
	temp=head;
	
	while(temp!=NULL) {
		temp->data=sto[j];
		j++;
		temp=temp->next;
	}
}

void sort2 (Node*head) {
	//o(n^2) buble sort 
	
}

int main() {
	//creat poiters to point to node address
	Node * head ;
	Node * one ;
	Node * two ;
	Node * tail;
	
	// allocate poiters to heap
	head= new Node();
	one = new Node();
	two = new Node();
	tail= new Node();
	
	// assign data for linked list
	head ->data = 0;
	head ->next = one;
	one -> data = 1;
	one -> next =two;
	two -> data =2;
	two -> next =tail;
	tail-> data =3;
	tail-> next =NULL; 
	
	//travel void
	travel(head);
	
	//insert
	insert(head,1,10);
	travel(head);
	
	//delete
	deletepos (head,0);
	travel(head);
	deleteval(head,9);
	travel(head);
	
	insert(head,4,9);
	travel(head);
	
	//size
	cout<<listsize(head)<<endl;
	insert(head,listsize(head),9);
	insert(head,listsize(head),9);
	insert(head,listsize(head),9);
	insert(head,listsize(head),9);
	
	//search
	cout<<searchpos(head,2)<<endl;
	vector<int> st=searchval(head,9);
	for(int i=0;i<st.size();i++) {
		cout<<st[i]<<" ";
	}
	cout<<endl;
	
	//swap
	swap (head,0,1);
	travel(head);
	
	//sort
	sort1(head);
	travel(head);
	reversed2(head);
	travel(head);
	reversed1(head);
	
	//
}