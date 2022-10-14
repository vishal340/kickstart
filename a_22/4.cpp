#include<bits/stdc++.h>
#include <cstring>
using namespace std;

int64_t dp[2][2][109][109];
int hcf[109][10];

int64_t func(int64_t n){
	int64_t ret=0;
	for(int t=1;t<109;t++){
		int64_t x=n;
		memset(&dp[1][0][0][0], 0, sizeof(dp[0]));
		dp[1][0][0][t]=1;
		for(int i=0;i<13;i++){
			int d=x%10;
			memset(&dp[i&1][0][0][0], 0, sizeof(dp[0]));
			for(int v=0;v<2;v++){
				for(int j=0;j<109;j++){
					for (int k = 0; k < 109; k++) {
						if(!dp[i&1^1][v][j][k])continue;
						for(int s=0;s<10;s++){
							if(j+s>t)break;
							dp[i&1][s<d+v][s+j][hcf[k][s]]+=dp[i&1^1][v][j][k];
							if(s && hcf[k][s]==1 && ( s<d+v || x>9 ) && s+j==t )
								ret+=dp[i&1^1][v][j][k];
						}
					}
				}
			}
			x/=10;
		}
	}
	return ret;
}

void solve(){
	int64_t a,b;
	cin>>a>>b;
	cout<<func(b+1)-func(a);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int j=1;j<109;j++)
		for(int i=0;i<10;i++)
			hcf[j][i]=j/__gcd(j,i);

	int T;
	cin>>T;
	for(int t=1;t<=T;t++){
		cout<<"Case #"<<t<<": ";
		solve();
		cout<<'\n';
	}
}
