// it counts the number of subsets partition with difference d(given).
// it is closely related to count of subset with given sum.
// only we have to apply formula  sum=(sum(array)+diff)/2;

#include<iostream>
using namespace std;

int main(){
	int i,j,n;
	cout<<"Enter number of elements:";
	cin>>n;
	int ar[n],diff, sum=0;
	cout<<"Enter elements:";
	for(i=0;i<n;i++) cin>>ar[i], sum+=ar[i];
	cout<<"Enter desired difference of two subsets:"; cin>>diff;
	sum=(sum+diff)/2;
	int t[n+1][sum+1];
	for(i=0;i<=sum;i++) t[0][i]=0;
	for(i=0;i<=n;i++) t[i][0]=1;
	for(i=1;i<=n;i++){
		for(j=1;j<=sum;j++){
			if(ar[i-1]<=j){
				t[i][j]= t[i-1][j-ar[i-1]]+ t[i-1][j];
			}
			else t[i][j]=t[i-1][j];
		}
	}
	for(i=0;i<=n;i++){
		for(j=0;j<=sum;j++){
			cout<<t[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"The number of subsets partition having difference "<<diff<<"  is:"<<t[n][sum];
}
