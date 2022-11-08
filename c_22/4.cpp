#include<bits/stdc++.h>
using namespace std;

const int d4i[4]={-1,0,1,0},d4j[4]={0,1,0,-1};
int64_t mod=1000000007;
int64_t inv(int64_t a){
	int64_t ret=(a*a)%mod;
	ret=(ret*a)%mod;
	a=ret;
	for(int i=0;i<4;i++)ret=(ret*a)%mod;
	a=ret;
	ret=1;
	for(int i=0;i<27;i++){
		if(66666667 &(1<<i))ret=(ret*a)%mod;
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
	for(int i=N-2;i>=0;i--){
		fact[i]=(mul*fact[i])%mod;
		mul=(mul*(N-i+1))%mod;
	}
	int64_t sum=(2*fact[N])%mod;
	function<void(int,int,int,int64_t&)> lambda;
	lambda = [&](int a,int b,int it,int64_t& sum){
		sum=(sum+(b-a-1)*fact[it-1])%mod;
		for(int k=a+1;k<b-1;k++){
			for(int l=k+1;l<b;l++){
				if(ch[k]==ch[l]){
					sum=(sum+fact[it-2])%mod;
					lambda(k,l,it-2,sum);
				}
			}
		}
	};
	for(int i=0;i<N-1;i++){
		for(int j=i+1;j<N;j++){
			if(ch[i]==ch[j]){
				sum=(sum+fact[N-2])%mod;
				lambda(i,j,N-2,sum);
			}
		}
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
