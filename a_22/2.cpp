#include<bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin>>T;
	for(int t=1;t<=T;t++){
		string n;
		cin>>n;
		int s=0;
		const int size=n.size();
		for(auto& i:n){
			s+=i-48;
		}
		s=s%9;
		if(s==0){
			cout<<"Case #"<<t<<": "<<n[0]<<'0'<<n.substr(1)<<'\n';
			continue;
		}
		s=9-s;
		for(int i=0;i<size;i++){
			if(s<(n[i]-48)){
				cout<<"Case #"<<t<<": ";
				if(i)cout<<n.substr(0,i);
				cout<<s<<n.substr(i)<<'\n';
				break;
			}
			if(i==size-1)
				cout<<"Case #"<<t<<": "<<n<<s<<'\n';
		}
	}
}
