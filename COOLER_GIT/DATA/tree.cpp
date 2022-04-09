#include<bits/stdc++.h>
#include<string.h>
#define fileio freopen("OUTPUT.txt","w",stdout); freopen("INPUT.txt","r",stdin);
#define ll long long
#define dou double
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

class node{
public:
	int data ;
	node* right;
	node* left;

	node(int val){
		data=val;
		right=NULL;
		left=NULL;
	}
};
void postorder(node* r){
	if(r==NULL){
		return ;
	}
	postorder(r->left);
	postorder(r->right);
	cout<<r->data<<" ";
	return ;
}
void inorder(node* r){
	if(r==NULL){
		return ;
	}
	inorder(r->left);
	cout<<r->data<<" ";
	inorder(r->right);
	return ;
}
void preorder(node* r){
	if(r==NULL){
		return ;
	}
	cout<<r->data<<" ";
	preorder(r->left);
	preorder(r->right);
	return ;
}
void levelorder(node* r){
	if(r==NULL){return;}
	queue<node*> q;
	q.push(r);
	while(!q.empty()){
		node* t=q.front();
		if(t->left!=NULL){
			q.push(t->left);
		}
		if(t->right!=NULL){
			q.push(t->right);
		}
		cout<<t->data<<" ";
		q.pop();
	}
	return ;
}
int main(int argc, char const *argv[])
{	
	vector<int> io={4,2,5,1,6,3,7};
	fileio;
	//fastio;
	node* r=new node(1);
	r->left=new node(2);
	r->right=new node(3);
	r->left->left=new node(4);
	r->left->right=new node(5);
	r->right->left=new node(6);
	r->right->right=new node(7);
	inorder(r);
	cout<<endl;
	preorder(r);
	cout<<endl;
	postorder(r);
	cout<<endl;
	levelorder(r);
	return 0;
}

   

