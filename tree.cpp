//???
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

class Node {
	public:
	int data;
	Node * left ;
	Node * right ;
	//if we call new Node (x) it will creat a node have data=x and left=right=NULL
	Node (int x) {
		data=x;
		left=NULL;
		right=NULL;
	}
	
};

//traversal
//inorder like dfs
//ver1 recursion ;
//left->root->right
void inorder (Node *root) {
	if(root==NULL) {
		
	}
	else {
	
	inorder(root->left);
	cout<< root->data<<" ";
	inorder(root->right);
	
	}
}
//ver2 use stack;
//preorder root -> left-> right
void preorderstack (Node * root) {
	map<Node*,bool> check;
	stack<Node*> dfs;
	
	check[NULL]=true;
	dfs.push(root);
	Node *temp = dfs.top();
	//cout<<temp->data<<" ";
	
	while(dfs.empty()==false) {
		temp = dfs.top();
		
		if(check[temp->left]==false) {
			Node * print =temp->left;
			//cout<<print->data<<" ";
			check[temp->left]=true;
			dfs.push(temp->left);
		}
		else if (check[temp->right]==false) {
			Node * print =temp->right;
			//cout<<print->data<<" ";
			check[temp->right]=true;
			dfs.push(temp->right);
		}
		
		if(dfs.top()==temp) {
			dfs.pop();
		}
	}
}

// preorder traversal
void preorder (Node *root) {
	if(root==NULL) {
		
	}
	else {
	cout<< root->data<<" ";	
	
	preorder(root->left);
	preorder(root->right);
	
	}
}
//postorder traversal 
//left->right->root
void postorder (Node *root) {
	if(root==NULL) {
		
	}
	else {
	
	postorder(root->left);
	postorder(root->right);
	
	cout<< root->data<<" ";
	
	}
}
//number of Node 
int numnode (Node*root) {
	if(root==NULL) {
		return 0;
	}
	
	return 1+numnode(root->left)+numnode(root->right);
}

//basic definttion

// depth of a node (number of edge from root to this node)
void depthofnode (Node * root ,int x,int level) {
	if(root==NULL) {
		
	}
	else {
		if(root->data==x) {
			 cout<<level;
		} 
		depthofnode (root->left,x,level+1);
		depthofnode (root->right,x,level+1);
	}
	
}
// height of a node (longest path from this node to left)

void heightofthenode (Node * root,int x,int level) {
	
}


//search

bool searchdata (Node * root,int data) {
		
}

// print child node 

void printchild (Node * root ,int x) {
	if(root==NULL) {
		
	}
	else {
		if(root->data==x) {
			cout<<"child Node of "<<x<<" : ";
			Node*a=root ->left;
			
			if(a!=NULL) {
				cout<<a->data<<" ";
			}
			
			a= root->right;
			
			if(a!=NULL) {
				cout<<a->data<<" ";
			}
		}
		else {
			printchild(root->left,x);
			printchild(root->right,x);
		}
	}
}

int main() {
	Node * root = new Node(0);
	Node * one  = new Node(1);
	Node * two  = new Node(2);
	Node * three= new Node(3);
	Node * four = new Node(4);
	Node * five = new Node(5);
	Node * six  = new Node(6);
	Node * seven= new Node(7);
	
	root->left=one;
	root->right=two;
	one ->left=three;
	one ->right=four;
	two ->left =five;
	two ->right=six;
	six->right=seven;
	
	//traversal
	cout<<"inorder"<<endl;
	inorder (root);
	cout<<endl;
	cout<<"preorder"<<endl;
	preorder(root);
	cout<<endl;
	cout<<"postorder"<<endl;
	postorder(root);
	cout<<endl;
	//preorderstack(root);
	//cout<<endl;
	
	//number of node(tree size) 
	cout<<"number of root :" << numnode(root) <<endl;
	
	// relationship
	printchild (root ,6);
	cout<<endl;
	cout<<"depthofnode is ";
	depthofnode(root,5,0);
	cout<<endl;
	
}
