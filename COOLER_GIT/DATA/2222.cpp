#include<bits/stdc++.h>
#include<string.h>
//#include"C:\Users\slaha\Desktop\cp\code essentials\DLLF.cpp"
#define fileio freopen("OUTPUT.txt","w",stdout); freopen("INPUT.txt","r",stdin);
#define ll long long
#define dou double
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

class node{
	public:
		int data;
		node* prev;
		node* next;
	node(int val){
		data=val;
		prev=NULL;
		next=NULL;
	}
};
void iat(node* head,int val){
	if(head==NULL){
		head=new node(val);
	}
	node* t=head;
	while(t->next!=NULL){
		t=t->next;
	}
	t->next=new node(val);
	t->next->prev=t;
	return ;
}
void display(node* head){
	if(head==NULL){
		return;
	}
	node* t=head;
	while(t!=NULL){
		cout<<t->data<<"->";
		t=t->next;
	}
	cout<<"NULL"<<endl;
	return ;
}

int main(int argc, char const *argv[])
{
	fileio;
	
	node* h =new node(1);
	iat(h,2);
	iat(h,4);
	iat(h,8);
	iat(h,16);
	iat(h,32);
	iat(h,64);
	display(h);
	//fastio;
	

	return 0;
}

   

