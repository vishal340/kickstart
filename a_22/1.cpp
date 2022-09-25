#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin>>T;
	for(int t=1;t<=T;t++){
		int n=0;
		string S1,S2;
		cin>>S1>>S2;
		const int s1=S1.size(),s2=S2.size();
		int i=0,j=0;
		while(i<s1){
			if(S1[i]==S2[j]){
				i++;j++;
			}
			else if(j<s2-1){
				n++;j++;
			}
			else{
				cout<<"Case #"<<t<<": IMPOSSIBLE\n";
				break;
			}
		}
		if(i==s1){
			if(j<s2) n+=s2-j;
			cout<<"Case #"<<t<<": "<<n<<'\n';
		}
	}
}
