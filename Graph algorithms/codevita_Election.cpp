// CORRECT 
#include<iostream>
using namespace std;

int main(){
 int i,j,count,countA=0,countB=0;
 int n;
 cin>>n;
 char voter[n];
 for(i=0;i<n;i++) cin>>voter[i];
 i=0;
 j=n-1;
 while(voter[i]=='-') i++;
 if(voter[i]=='A') countA+=i;
 while(voter[j]=='-') j--;
 if(voter[j]=='B') countB+=n-1-j;
 for(;i<n;){
  count=0;
  if(voter[i]=='B'){
   countB+=1;
   while(voter[++i]=='-') count++;
   if(voter[i]=='A') countA+=count/2, countB+=count/2;
   else if(voter[i]=='B') countB+=count;
  }
  else{
   countA+=1;
   while(voter[++i]=='-') count++;
   if(voter[i]=='A') countA+=count;
  }
 }
 if(countA>countB)
  cout<<"A";
 else if(countA<countB)
  cout<<"B";
 else
  cout<<"Coalition government";
 return 0;
}
 /*
 // correct 
//problem name  Elections
#include<iostream>
using namespace std;
int main(){
	int n,i,j;
	int countA=0,countB=0 , count;
	cin>>n;
	char voter[n];
	for(i=0;i<n;i++) cin>>voter[i];
	i=0;
	j=n-1;
	// count of '-' votes on left side before any character A or B appears.
	while(voter[i]=='-') i++;
	
	// count of '-' votes on right side before any character A or B appears.
	while(voter[j]=='-') j--;
	
	if(voter[i]=='A') countA+=i;
	if(voter[j]=='B') countB+=n-j-1;
	for(;i<n;){
		count=0;
		if(voter[i]=='B'){
			countB+=1;
			while(voter[++i]=='-') count++;
			if(voter[i]=='A') countA+=count/2, countB+=count/2;
			else if(voter[i]=='B') countB+=count;
		}
		else if(voter[i]=='A'){
			count=0;
			countA+=1;
			while(voter[++i]=='-') count++;
			if(voter[i]=='A') countA+=count;
		}
	}
	if(countA>countB){
		cout<<'A';
	}
	else if(countB>countA){
		cout<<'B';
	}
	else cout<<"Coalition government";
}
*/
