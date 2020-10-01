// correct 
#include<iostream>
using namespace std;
int main(){
	int n,i,j,cap;
	cout<<"Enter number of elements :";
	cin>>n;
	cout<<"Enter knapsack capacity :";
	cin>>cap;
	int pr[n],wt[n];
	cout<<"Enter profit array values:";
	for(i=0;i<n;i++) cin>>pr[i];
	cout<<"Enter weight array values:";
	for(i=0;i<n;i++) cin>>wt[i];
	int t[n+1][cap+1];
	for(i=0;i<n+1;i++) t[i][0]=0;
	for(i=0;i<cap+1;i++) t[0][i]=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=cap;j++){
			if(wt[i-1]<=j){
				t[i][j]=max(pr[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
			}
			else
				t[i][j]=t[i-1][j];
		}
	}
	for(i=0;i<n+1;i++){
		for(j=0;j<=cap;j++){
			cout<<t[i][j]<<" ";
		}cout<<endl;
	}
	cout<<endl<<"Max Profit earned is:"<<t[n][cap];
	cout<<endl<<"Backtracking selected items:";
	i=n,j=cap;
	while(j && i){
		if(t[i][j]!=t[i-1][j]){
			cout<<i<<" ";
			j-=wt[i-1];
			i--;
		}
		else{
			i--;
		}
	}
}
