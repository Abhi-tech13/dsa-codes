// Reversing a linked list
#include<iostream>
using namespace std;

typedef struct node{
	int val;
	node* next;
} node;

node * addNode(node *head,int val){
	node *t=new node;
	t->val=val;
	t->next=NULL;
	if(head!=NULL)
		t->next=head;
	head=t;
	return head;
}
node * createList(int n){
	node *head=NULL;
	int i,v;
	cout<<"Enter nodes values :";
	for(i=0;i<n;i++){
		cin>>v;
		head=addNode(head,v);
	}
	return head;
}
void printLL(node * head){
	node * t=head;
	while(t!=NULL){
		cout<<t->val<<" ";
		t=t->next;
	}
}
int main(){
	int n;
	cout<<"Enter total nodes in linked list :";
	cin>>n;
	node *head=createList(n);
	cout<<endl<<"List created is :";
	printLL(head);
	// reversing
	node *prev=NULL,*next=NULL,*cur;
	cur=head;
	while(cur!=NULL){
		next=cur->next;
		cur->next=prev;
		prev=cur;
		cur=next;
	}
	head=prev;
	cout<<"\nReversed list is :";
	printLL(head);
	return 0;
}
