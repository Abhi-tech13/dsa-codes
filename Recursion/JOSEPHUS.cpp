// Josephus problem 
// persons are standing in a circle and start counting k ,kth person to be killed
// counting begins from next person and so on....
// person who is alive at last will be the answer.
#include<iostream>
#include<vector>
using namespace std;
void solve(vector<int>& v,int i,int k){
	if(v.size()==1){
		cout<<"Last man Standing position in original circle is :"<<v[0];
		return ;
	}
	int index=(i+ k )% v.size();
	v.erase(v.begin()+index);
	solve(v,index,k);
}
int main(){
	int n,k;
	cout<<"Enter total number of soldiers : ";
	cin>>n;
	cout<<"Enter count to kill person : ";
	cin>>k;
	k--;
	vector<int> v;
	for(int i=0;i<n;i++) v.push_back(i+1);
	solve(v,0,k);
}
