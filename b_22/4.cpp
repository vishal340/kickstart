#include<bits/stdc++.h>
using namespace std;
const int hor[4]{0,2,0,-2};
const int ver[4]{2,0,-2,0};
void dfs(int row,int col,int N1,int N2,int total,vector<vector<pair<char,bool>>>& dp,int& num){
	if(num==total)
		return;
	for(int i=0;i<4;i++){
		int row1=row+ver[i];
		int col1=col+hor[i];
		if(row1>=0 && col1>=0 && row1<N1 && col1<N2 && dp[row1][col1].first && !dp[row1][col1].second){
			num++;
			dp[row1][col1].second=true;
			dp[row1][col1+1].second=true;
			dp[row1+1][col1].second=true;
			dp[row1+1][col1+1].second=true;
			switch(i){
				case 0:
					dp[row1-1][col1+1].first='S';
					dp[row1][col1].first='N';
					break;
				case 1:
					dp[row1][col1-1].first='E';
					dp[row1+1][col1].first='W';
					break;
				case 2:
					dp[row1+1][col1+1].first='S';
					dp[row1+2][col1].first='N';
					break;
				case 3:
					dp[row1][col1+1].first='E';
					dp[row1+1][col1+2].first='W';
					break;
			}
			dfs(row1,col1,N1,N2,total,dp,num);
		}
	}
}
void solve(){
	int N1,N2;
	cin>>N1>>N2;
	vector<vector<pair<char,bool>>> ret(2*N1,vector<pair<char,bool>>(2*N2,{'\0',0}));
	string c;
	int num=0;
	N1<<=1;
	for(int i=0;i<N1;i+=2){
		cin>>c;
		for(int j=0;j<N2;j++){
			if(c[j]=='*'){
				num++;
				ret[i][2*j].first='E';
				ret[i][2*j+1].first='S';
				ret[i+1][2*j].first='N';
				ret[i+1][2*j+1].first='W';
			}
		}
	}
	ret[0][0].second=true;
	ret[0][1].second=true;
	ret[1][0].second=true;
	ret[1][1].second=true;
	int connect=1;
	dfs(0,0,N1,2*N2,num,ret,connect);
	if(connect<num)cout<<"IMPOSSIBLE";
	else{
		int n1=0,n2=0;
		do{
			cout<<ret[n1][n2].first;
			switch(ret[n1][n2].first){
				case 'E':
					n2++;
					break;
				case 'S':
					n1++;
					break;
				case 'N':
					n1--;
					break;
				case 'W':
					n2--;
					break;
			}
		}while(n1 || n2);
	}
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
