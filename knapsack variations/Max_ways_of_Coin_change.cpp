// max ways of coin change from given set of coins
// unbounded knapsack
#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"Enter total numbers of coins : ";
	cin>>n;
	int i,j,w,coin[n];
	cout<<"Enter coins: ";
	for(i=0;i<n;i++){
		cin>>coin[i];
	}
	cout<<"Enter value to be exchanged : ";
	cin>>w;
	int t[n+1][w+1];
	for(i=0;i<=w;i++) t[0][i]=0;
	for(i=0;i<=n;i++) t[i][0]=1;
	for(i=1;i<=n;i++){
		for(j=1;j<=w;j++){
			if(coin[i-1]<=j){
				t[i][j]=t[i-1][j] + t[i][j-coin[i-1]];
			}
			else{
				t[i][j]=t[i-1][j];
			}
		}
	}
	for(i=0;i<=n;i++){
		for(j=0;j<=w;j++) cout<<t[i][j]<<" ";
		cout<<endl;
	}
	cout<<"Max number of ways the given value can be exchanged is :"<<t[n][w];
}
