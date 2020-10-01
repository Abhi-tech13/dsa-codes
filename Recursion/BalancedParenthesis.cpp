// Generating all types of Balanced Parenthesis for given numbers of brackets.

#include<iostream>
#include<vector>
using namespace std;
vector<string> v;
void solve(int open,int close,string output){
	if(open==close && open==0){
		v.push_back(output);
		return ;
	}
	string out=output;
	if(open){
		out.push_back('(');
		solve(open-1,close,out);
		
	}
	if(close>open){
		output.push_back(')');
		solve(open,close-1,output);
	}
	return;
}

int main(){
	string output="";
	int i,n;
	v.clear();
	cout<<"Enter n : ";
	cin>>n;
	solve(n,n,output);
	cout<<"Balanced Parenthesis are : ";
	for(i=0;i<v.size();i++){
		cout<<v[i]<<endl;
	}
}
