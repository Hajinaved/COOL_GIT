#include<bits/stdc++.h>
#include<string.h>
#define fileio freopen("OUTPUT.txt","w",stdout); freopen("INPUT.txt","r",stdin);
#define ll long long
#define dou double
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void swap(int arr[],int i,int j){
	int temp= arr[i];
	arr[i]=arr[j];
	arr[j]=temp;

}
void cyclic_sort(int arr[],int n ){
int i=0;
while(i<n){
	int current = arr[i];
	if(i!=current){
		swap(arr,i,current);
	}
}
}

int main(int argc, char const *argv[])
{
	//fileio;
	//fastio;
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	swap(arr,0,1);

	/*cyclic_sort(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}

*/
	return 0;
}

   

