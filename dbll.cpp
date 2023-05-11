//???
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

class Node {
	public:
	int data;
	Node * prev;
	Node * next;
};

void addnode (Node*head,int x) {
	
	Node * temp = head;
	Node * add  = new Node();
	add->data = x; 
	
	while(temp->next!=NULL) {
		temp=temp->next;
	}  
	
	temp -> next = add;
	add -> next  = NULL;
	add -> prev  = temp;
}

void display (Node*head) {
	
	Node*temp = head;
	
	while(temp!=NULL) {
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	
	cout<<endl;
}

void insert (Node* &head ,int position,int x) {
	
	Node * add = new Node();
	add->data=x;
	
	Node * temp= head;
	Node * a = head;
	Node * b = head->next;
	
	if(position ==0) {
		add -> prev = NULL;
		add -> next = head;
		head =add;
	}
	else {
		int count = 0;
		while(temp!=NULL) {
			count++;
			a=temp;
			b=temp->next;
			if (count==position) {
				if(b==NULL) {
					a->next=add;
					add->prev=a;
					add->next=NULL;
				}
				else {
					a->next=add;
					add->prev=a;
					add->next=b;
					b->prev=add;
				}
			}
			temp=temp->next;
		}	
	}
}

void deletepos (Node* &head,int position ) {
	
	Node * temp = head;
	
	if(position==0) {
		head=head->next;
		head->prev=NULL;
	}	
	else {
		int count=0;
		while(temp!=NULL) {
			if(count==position) {
				
				Node*a=new Node;
				Node*b=new Node;
				
				a=temp->prev;
				b=temp->next;
				
				if(b==NULL) {
					a->next=b;
				}
				else {
					b->prev=a;
					a->next=b;
				}
			}
			temp=temp->next;
			count++;
		}
	}
} 

void deleteval (Node* &head,int value) {
	Node*temp = head;
	
	while(temp!=NULL) {
		if(temp->data==value) {
			if(temp==head) {
				head=head->next;
				head->prev=NULL;
				temp=head;
			}
			else {
				Node*a=new Node;
				Node*b=new Node;
				
				a=temp->prev;
				b=temp->next;
				
				if(b==NULL) {
					a->next=b;
				}
				else {
					b->prev=a;
					a->next=b;
				}
			}
		}
		temp=temp->next;
	}
	
}
void sort () {
	
}
int main() {
	ios::sync_with_stdio(false);
	
	//cread head node
	Node * head = new Node();
	head ->data = 1;
	head ->prev = NULL;
	head ->next = NULL;
	
	//add node
	addnode(head,2);
	addnode(head,3);
	addnode(head,4);
	addnode(head,4);
	addnode(head,4);
	addnode(head,4);
	addnode(head,4);
	addnode(head,4);
	display(head);
	
	//insert 
	//place add
	// 0 | 1 | 2 | 3 | 4 | 5 | 6 | ....  	
	insert(head,2,100);
	display(head);
	insert (head,10,1000);
	display (head);
	
	//delete
	deletepos(head,2);
	display(head);
	deleteval(head,4);
	display(head);
}
