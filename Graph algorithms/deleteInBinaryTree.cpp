// Deletion in Binary Tree
// Replaces desired key by deepest right node
#include<iostream>
#include<queue>
using namespace std;

typedef struct node{
	int val;
	node * left,*right;
}node;
node * addNode(int val){
	node * temp=new node;
	temp->val=val;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

// traversing tree in inorder traversal

void inorder(node * root){
	if(!root) return ;
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);
}
// deleting rightmost deepest node denoted by d_node

void deleteDeepest(node * root,node* d_node){
	queue<node *> q;
	node * temp;
	q.push(root);
	while(!q.empty()){
		temp=q.front();
		q.pop();
		if(temp==d_node){
			temp=NULL;
			delete d_node;
			return ;
		}
		if(temp->right){
			if(temp->right==d_node){
				temp->right=NULL;
				delete d_node;
				return ;
			}
			else q.push(temp->right);
		}
		if(temp->left){
			if(temp->left==d_node){
				temp->left=NULL;
				delete d_node;
				return;
			}
			else q.push(temp->left);
		}
		
	}
}

// finding node to be deleted with given value key

node * deleteNode(node * root,int key){
	queue<node*> q;
	node* temp;
	node * d_node=NULL;
	if(root->val==key){
		return NULL;
	}
	if(root->left==NULL && root->right==NULL){
		if(root->val==key){
			return NULL;
		}
		else return root;
	}
	q.push(root);
	while(!q.empty()){
		temp=q.front();
		q.pop();
		if(temp->val==key){
			d_node=temp;
		}
		if(temp->left){
			q.push(temp->left);
		}
		if(temp->right){
			q.push(temp->right);
		}
	}
	if(d_node->val==key){
		int x=temp->val;
		deleteDeepest(root,temp);
		d_node->val=x;
	}
	return root;
}
int main(){
    node* root = addNode(10); 
    root->left = addNode(11); 
    root->left->left = addNode(7); 
    root->left->right = addNode(12); 
    root->right = addNode(9); 
    root->right->left = addNode(15); 
    root->right->right = addNode(8); 

    cout << "Inorder traversal before deletion : "; 
    inorder(root); 

    int key = 11; 
    root = deleteNode(root, key); 
    cout << endl; 

    cout << "Inorder traversal after deletion : "; 
    inorder(root); 

    return 0; 
} 
