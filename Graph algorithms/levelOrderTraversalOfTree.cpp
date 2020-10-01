// printing nodes present at each level

#include<iostream>
using namespace std;

class node{
	public:
	int val;
	node * left;
	node * right;
};

void printGivenLevel(node * tree,int level){
	if(tree==NULL) return ;
	if(level==1){
		cout<<tree->val<<" ";
	}
	else{
		printGivenLevel(tree->left,level-1);
		printGivenLevel(tree->right,level-1);
	}
}

int heightOfTree(node * tree){
	int lheight,rheight;
	if(tree==NULL) return 0;
	else{
		lheight=heightOfTree(tree->left);
		rheight=heightOfTree(tree->right);
	}
	if(lheight>rheight) return lheight+1;
	else return rheight+1;
}

void printBFS(node *tree){
	int i,d;
	d=heightOfTree(tree);
	for(i=1;i<=d;i++){
		printGivenLevel(tree,i);
		cout<<endl;
	}
}
node* addNode(int val){
	node *n=new node();
	n->val=val;
	n->left=NULL;
	n->right=NULL;
	return n;
}
int main(){
	node * tree;
	tree=addNode(1);
	tree->left=addNode(2);
	tree->right=addNode(4);
	tree->left->left=addNode(3);
	tree->left->right=addNode(5);
	tree->right->right=addNode(6);
	printBFS(tree);
	return 0;
}
