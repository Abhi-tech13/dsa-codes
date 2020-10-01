// Finding mid element of linked list
#include<iostream>
using namespace std;

typedef struct node{
	int data;
	node * next;
}node;

node * push(node* head,int val){
	node *t=new node;
	t->data=val;
	t->next=head;
	head=t;
	return head;
}

node * createList(int n){
	node *head=NULL;
	int v;
	cout<<"Enter nodes values :";
	for(int i=0;i<n;i++){
		cin>>v;
		head=push(head,v);
	}
	return head;
}
void printLL(node * head){
	node *t=head;
	while(t!=NULL){
		cout<<t->data<<" ";
		t=t->next;
	}
}
void printMid(node *head){
	node *s,*f;
	s=head;
	f=head;
	while(f!=NULL && f->next!=NULL){
		s=s->next;
		f=f->next->next;
	}
	cout<<s->data<<endl;
}
int main(){
	int n;
	cout<<"Enter total nodes :";
	cin>>n;
	node *head=createList(n);
	cout<<"List created :";
	printLL(head);
	cout<<endl<<"Mid element of list is :";
	printMid(head);
	return 0;
}
