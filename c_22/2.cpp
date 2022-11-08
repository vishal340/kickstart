#include<bits/stdc++.h>
using namespace std;

const int d4i[4]={-1,0,1,0},d4j[4]={0,1,0,-1};

void solve(){
	int N,X,Y;
	cin>>N>>X>>Y;
	int sum=(N*(N+1))>>1;
	int g=X+Y;
	if((sum%g)!=0){
		cout<<"IMPOSSIBLE";
		return;
	}
	cout<<"POSSIBLE\n";
	X=(sum/g)*X;
	vector<int>v;
	while(X){
		N=min(N,X);
		X=X-N;
		v.push_back(N);
		N--;
	}
	cout<<v.size()<<'\n';
	for(auto i:v)cout<<i<<' ';
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
