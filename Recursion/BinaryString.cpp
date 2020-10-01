// generating binary string having number of 1's >= number of 0's in all prefixes.
#include<iostream>
using namespace std;

void solve(int ones,int zeros,int n,string output){
	if(ones+zeros==n){
		cout<<output<<endl;
		return;
	}
	string out=output;
	if(ones<n)
	output.push_back('1') ,ones++,
	solve(ones,zeros,n,output);
	ones--;
	if(ones>zeros ){
		zeros++;
		out.push_back('0');
		solve(ones,zeros,n,out);
	}
	
}

int main(){
	int n;
	cout<<"Enter number of bits : ";
	cin>>n;
	solve(0,0,n,"");
}
