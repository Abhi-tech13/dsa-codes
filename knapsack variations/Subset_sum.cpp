// correct 
// Returns if there is a subset in given array with desired sum or not.
#include<iostream>
using namespace std;

int main(){
	int n,i,j,cap;
	cout<<"Enter size of array:";
	cin>>n;
	int ar[n];
	cout<<"Enter elements of array :";
	for(i=0;i<n;i++) cin>>ar[i];
	cout<<"Enter subset sum:";
	cin>>cap;
	bool t[n+1][cap+1];
	for(i=0;i<cap+1;i++) t[0][i]=false;
	for(i=0;i<n+1;i++) t[i][0]=true;
	for(i=1;i<=n;i++){
		for(j=1;j<=cap;j++){
			if(ar[i-1]<=j){
				t[i][j]=(t[i-1][j] || t[i-1][j-ar[i-1]]);
			}
			else{
				t[i][j]=t[i-1][j];
			}
		}
	}
/*	for(i=0;i<=n;i++){
		for(j=0;j<=cap;j++){
			cout<<t[i][j]<<" ";
		}
		cout<<endl;
	}*/
	cout<<"Subset with sum="<<cap<<" is present in array :"<<t[n][cap];
}
