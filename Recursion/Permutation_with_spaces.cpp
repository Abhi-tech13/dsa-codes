// Permutations with spaces
//  input : abc   output : a_bc,ab_c,a_b_c  where '_' is space;
#include<iostream>
using namespace std;

void solve(string in,string out){
	if(in.length()==0){
		cout<<out<<"  ";
		return ;
	}
	string out1=out;
	string out2=out;
	out1.append("_");
	out1.push_back(in[0]);
	out2.push_back(in[0]);
	in.erase(in.begin());
	solve(in,out2);
	solve(in,out1);
	return;
}
int main(){
	cout<<"Enter string :";
	string str,out="";
	cin>>str;
	out.push_back(str[0]);
	str.erase(str.begin()+0);
	solve(str,out);
	return 0;
}
