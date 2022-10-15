#include<bits/stdc++.h>
using namespace std;

const int d4i[4]={-1,0,1,0},d4j[4]={0,1,0,-1};
vector<int> A(10000);
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	sort(A.begin(),A.begin()+n);
	int ret=0;
	for(int i=n-m+1;i<n;i++)ret+=A[i];
	if((n-m)&1){
		int t=(n-m)/2;
		int temp=A[t]+A[t+1];
		cout<<ret+temp/2;
		if(temp&1)cout<<".5";
	}
	else{cout<<ret+A[(n-m)/2];}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	for(int t=1;t<=T;t++){
		cout<<"Case #"<<t<<": ";
		solve();
		cout<<'\n';
	}
}
