#include<bits/stdc++.h>
using namespace std;

void solve(){
	int N,D;
	cin>>N>>D;
	vector<int>v(N);
	for(int i=0;i<N;i++){
		cin>>v[i];
	}
	vector<vector<map<int,int64_t>>> dp(N);
	for(int i=0;i<N;i++)
		dp[i]=vector<map<int,int64_t>>(N-i,map<int,int64_t>());
	dp[N-1][0].emplace(0,0);
	for(int i=N-1;i>0;i--){
		for(int j=0;j<N-i;j++){
			for_each(dp[i][j].begin(),dp[i][j].end(),[&](auto k){
				int t1=(v[j]-k.first+D)%D;
				int t2=(v[j+i]-k.first+D)%D;
				dp[i-1][j+1].emplace(v[j],0);
				dp[i-1][j].emplace(v[j+i],0);
			});
		}
	}
	for(int i=0;i<N;i++){
		for_each(dp[0][i].begin(),dp[0][i].end(),[&](auto j){
			   int t=(D-j.first+v[i])%D;
				dp[0][i][j.first]=min(t,D-t);
		});
	}
	for(int i=1;i<N;i++){
		for(int j=0;j<N-i;j++){
			for_each(dp[i][j].begin(),dp[i][j].end(),[&](auto k){
				int t1=(v[j]-k.first+D)%D;
				int t2=(v[j+i]-k.first+D)%D;
				dp[i][j][k.first]=min(t2,D-t2)+dp[i-1][j][v[j+i]];
				dp[i][j][k.first]=min(dp[i][j][k.first],min(t1,D-t1)+dp[i-1][j+1][v[j]]);
			});
		}
	}
	cout<<dp[N-1][0][0];
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
