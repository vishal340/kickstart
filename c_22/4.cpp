#include<bits/stdc++.h>
using namespace std;

int64_t mod=1000000007;
inline int64_t inv(int64_t a){
	int64_t ret=1;
	for(int i=0;i<31;i++){
		if((mod-2) &(1<<i))ret=(ret*a)%mod;
		a=(a*a)%mod;
	}
	return ret;
}
void solve(){
	int N;
	cin>>N;
	char ch[N];
	cin>>ch;
	int64_t fact[N+1];
	fact[0]=0;fact[1]=1;
	for(int i=2;i<=N;i++){
		fact[i]=(fact[i-1]*i)%mod;
	}
	int64_t mul=2;
	for(int i=N-2;i>0;i--){
		fact[i]=(mul*fact[i])%mod;
		mul=(mul*(N-i+1))%mod;
	}
	vector<vector<vector<int64_t>>> dp(N,vector<vector<int64_t>>(N,vector<int64_t>(N,0)));
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			dp[i][j][0]=1;
		for(int j=i;j<N;j++)
			dp[i][j][1]=j-i+1;
	}
	for(int l=2;l<N;l++){
		for(int d=l-1;d<N;d++){
			for(int i=0;i<N-d;i++){
				if(ch[i]==ch[i+d])dp[i][i+d][l]=dp[i+1][i+d-1][l-2];
				else{
					dp[i][i+d][l]=(dp[i+1][i+d][l]+dp[i][i+d-1][l]+mod-dp[i+1][i+d-1][l])%mod;
				}
			}
		}
	}
	int64_t sum=(2*fact[N])%mod;
	for(int i=2;i<N;i++){
		int64_t t=(dp[0][N-1][i]*fact[i])%mod;
		sum=(sum+t)%mod;
	}
	cout<<(sum*inv(fact[N]))%mod;
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
