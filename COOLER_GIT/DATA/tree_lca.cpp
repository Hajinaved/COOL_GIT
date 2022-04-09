#include<bits/stdc++.h>
#include<string.h>
#define fileio freopen("OUTPUT.txt","w",stdout); freopen("INPUT.txt","r",stdin);
#define ll long long
#define dou double
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

class node{
public: 
	int data;
	node* left;
	node* right;
	node(int val){
		data=val;
		left=NULL;
		right=NULL;
	}
};


node* lca(int p,int q,node* r){
	if(r==NULL){return NULL;}
	if(r->data==p||r->data==q){return r;}
	node* le=lca(p,q,r->left);
	node* ri=lca(p,q,r->right);
	if(le!=NULL&&ri!=NULL){return r;}
	if(le!=NULL){return le;}
	else{return ri;}

}
void morristraversal(node* r){
	node* curr= r;
	while(curr!=NULL){
		if(curr->left==NULL){cout<<curr->data<<" ";curr=curr->right;}
		else{
			node* t=curr->left;
			while(t->right!=NULL&&t->right!=curr){
				t=t->right;

			}
			if(t->right==NULL){
				t->right=curr;
				curr=curr->left;
			}
			else{
				t->right=NULL;
				cout<<curr->data<<" ";
				curr=curr->right;
			}
			
		}

	}
	return ;
}
int main(int argc, char const *argv[])
{
	fileio;
	//fastio;
	node* r=new node(1);
	r->left=new node(2);
	r->right=new node(3);
	r->left->left=new node(4);
	r->left->right=new node(5);
	r->right->left=new node(6);
	r->right->right= new node(7);
	morristraversal(r);
	
	/*HERE GOES YOUR CODE !!!!*/


	return 0;
}

   

