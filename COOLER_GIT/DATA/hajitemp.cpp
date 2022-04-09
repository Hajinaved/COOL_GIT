#include<bits/stdc++.h>
#include<string.h>
#include"C:\Users\slaha\Desktop\cp\code essentials\SLLF.cpp"
#define fileio freopen("OUTPUT.txt","w",stdout); freopen("INPUT.txt","r",stdin);
#define ll long long
#define dou double
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
node* ittreve(node* head){
	if(head==NULL){
		return NULL;
	}
	if(head->next==NULL){
		return head;
	}
	node* previous = NULL;
	node* current  = head;
	node* agla     = head->next;
	while(current!=NULL){
		current->next=previous;
		previous=current;
		current=agla;
		agla=agla->next;
	}
	return previous;
}

void reverseknode(node* head,int val){
	if(head==NULL){return ;}
	node* temp=head;
	while(temp->data!=val&&temp!=NULL){
		temp=temp->next;
	}
	if(temp==NULL){
		cout<<"kth node not found"<<endl;
	}
	node* temp2=reverse(temp);
	temp=temp2;
	return;
}
void del(node* head,int val){
	if(head ==NULL){
		return ;
	}//when head is null
	if(head->next ==NULL){
		dah(head);
		return;
	}//when head is the only node
	node* temp=head;
	while(temp->next->data!=val){
		temp=temp->next;
		if(temp->next==NULL){
			cout<<"value not found"<<endl;
			return ;
		}
	}
	node* todelete=temp->next;
	temp->next=temp->next->next;
	delete todelete;
	
}

//recursive trial
/*void printinrevers(node* head){
	if(head==NULL){return ;}
	node* t=head;
	if(t->next==NULL){
		cout<<"NULL<-"<<head->data<<"<-";

	}
	printinrevers(t->next);
	cout<<t->data<<"<-";
	return;
}*/
void print_in_reverse(node* head){
	stack<int> h;
	if(head==NULL){return;}
	node* t=head;
	while(t!=NULL){
		h.push(t->data);
		t=t->next;
	}
	while(!h.empty()){
		cout<<h.top()<<endl;
		h.pop();
	}
	return ;
}
node* merged_list(node* h1,node*h2){
	node* t=h1;
	node* ans=t;
	while(t->next!=NULL){
		t=t->next;
	}
	t->next=h2;
	return ans;
}
node* midnode(node* head){
	if(head==NULL){return NULL;}
	int len=length(head);
	int mid=len/2;
	node* t=head;
	for(int i=0;i<mid;i++){
		t=t->next;
	}
	return t;
}
node* remove_k(node* h,int k){
	if(h==NULL){
		return NULL;
	}
	node* t=h;
	vector<int> tt;
	while(t!=NULL){
		tt.push_back(t->data);
		t=t->next;
	}
	node* ans;
	for(auto i : tt){
		if(i!=k){
			iat(ans,i);
		}
	}
	return ans;

}
void cyinsert(node* h,int val){
	if(h==NULL){
		h=new node(val);
		return ;
	}
	if(h->next==NULL){
		h->next=new node(val);
		h->next->next=h;
		return;
	}
	node* t=h;
	while(t->next!=NULL){
		t=t->next;
	}
	t->next=new node(val);
	t->next->next=h;
	return;

}
int cydisplay(node* h){
	int count=0;
	if(h==NULL){return -1 ;}
	if(h->next==NULL){cout<<h->data<<endl;return 1;}
	node* t=h;
	for(int i=0;i<30;i++){
		if(t==h){count++;}
		cout<<t->data<<"->";
		t=t->next;
	}
	return count;
}
void zor(int a,int b){
	int c=a^b;
	cout<<c<<endl;
}
int main(int argc, char const *argv[])
{
	fileio;
	//fastio;
	zor(4,5);
	/*node* head= new node(1);
	iat(head,2);
	iat(head,3);
	iat(head,4);
	iat(head,5);
	makecycle(head,2);
	cout<<cydisplay(head)<<endl;*/

	return 0;
}

   

