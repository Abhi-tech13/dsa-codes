// Letter Case Permutations
//  input : abc   output : Abc , abc,aBc,ABc,abC,.....
#include<iostream>
#include<string.h>
using namespace std;

void solve(string in,string out){
	if(in.length()==0){
		cout<<out<<"  ";
		return ;
	}
	string out1=out;
	string out2=out;
	char c1=tolower(in[0]);
	char c2=toupper(in[0]);
	out1.push_back(c1);
	out2.push_back(c2);
	in.erase(in.begin());
	solve(in,out1);
	solve(in,out2);
	return;
}
int main(){
	cout<<"Enter string :";
	string str,out="";
	cin>>str;
	solve(str,out);
	return 0;
}
