// Unbounded knapsack
//here we can select an item many times if it can be selected.else element is processed and 
// cannot be considered again.
// similar problem is rod cutting problem to give max profit by cutting rod in given size pieces.
#include<iostream>
using namespace std;
int main(){
	int n,i,j;
	cout<<"Enter number of elements:";
	cin>>n;
	int pr[n],wt[n];
	cout<<"Enter profit of elements:";
	for(i=0;i<n;i++) cin>>pr[i];
	cout<<"Enter weight of elements:";
	for(i=0;i<n;i++) cin>>wt[i];
	cout<<"Enter capacity:";
	int cap;
	cin>>cap;
	int t[n+1][cap+1];
	for(i=0;i<n+1;i++) t[i][0]=0;
	for(i=0;i<cap+1;i++) t[0][i]=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=cap;j++){
			if(wt[i-1]<=j){
				t[i][j]=max(t[i-1][j], pr[i-1]+t[i][j-wt[i-1]]); 	// here is change in code ,instead of t[i-1] its t[i][j-wt[i-1]]
			}
			else 
				t[i][j]=t[i-1][j];
		}
	}
	for(i=0;i<n+1;i++){
		for(j=0;j<=cap;j++) cout<<t[i][j]<<" ";
		cout<<endl;
	}
	cout<<"Maximum profit for unbounded knapsack is:"<<t[n][cap];
}
