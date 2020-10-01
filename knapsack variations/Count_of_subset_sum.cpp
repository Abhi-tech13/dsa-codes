//correct 
// it counts the number of subsets for given sum.

#include<iostream>
using namespace std;

int main(){
	int n,i,j;
	cout<<"Enter total numbers of elements:";
	cin>>n;
	int ar[n];
	cout<<"Enter elements:";
	for(i=0;i<n;i++) cin>>ar[i];
	cout<<"Enter sum:";
	int sum;
	cin>>sum;
	int t[n+1][sum+1];
	for(i=0;i<=sum;i++) t[0][i]=0;
	for(i=0;i<n+1;i++) t[i][0]=1;
	for(i=1;i<=n;i++){
		for(j=1;j<=sum;j++){
			if(ar[i-1]<=j){
				t[i][j]= t[i-1][j]+t[i-1][j-ar[i-1]];
			}
			else
			t[i][j]=t[i-1][j];
		}
	}
	for(i=0;i<n+1;i++){
		for(j=0;j<=sum;j++){
			cout<<t[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Count of subsets having sum="<<sum<<" is :"<<t[n][sum];
}
