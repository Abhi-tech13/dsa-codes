// correct 
// it calculates the minimum difference of two subsets formed by the given array.
// it checks the last row of subset sum problem matrix and checks which subsets are possible
// then it puts in formula (total_sum-2* subsetsum[i]) and find minimum.
// mockvita 2  petrol pump question can be solved
#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n,i,j;
	cout<<"Enter total numbers of elements:";
	cin>>n;
	int ar[n] , sum=0;
	cout<<"Enter elements:";
	for(i=0;i<n;i++) cin>>ar[i] , sum+=ar[i];
	bool t[n+1][sum+1];
	for(i=0;i<=sum;i++) t[0][i]=0;
	for(i=0;i<n+1;i++) t[i][0]=1;
	for(i=1;i<=n;i++){
		for(j=1;j<=sum;j++){
			if(ar[i-1]<=j){
				t[i][j]= t[i-1][j] ||t[i-1][j-ar[i-1]];
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
	vector<int> vec;
	for(i=0;i<=sum/2;i++){
		if(t[n][i]){
			vec.push_back(i);
		}
	}
	int mn=INT_MAX;
	for(i=0;i<vec.size();i++){
		mn=min(mn,sum-2*vec[i]);
	}
	cout<<"Minimum subset difference is :"<<mn;
//	cout<<"\nAns for petrol pump question is :"<<sum/2+mn;
}
