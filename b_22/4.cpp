#include<bits/stdc++.h>
using namespace std;

const int hor[4]={0,1,0,-1};
const int ver[4]={1,0,-1,0};
const char dir[4]={'S','E','N','W'};
void dfs(int row,int col,const int N1,const int N2,const int num,const int total,pair<bool,int>* dp,char* ret, bool& exit){
	for(int i=0;i<4;i++){
		if(exit)
			return;
		int row1=row+ver[i];
		int col1=col+hor[i];
		int pos=row1*N2+col1;
		if(row1>=0 && row1<N1 && col1>=0 && col1<N2 && dp[pos].first && !dp[pos].second){
			dp[pos].second=num;
			ret[num-2]=dir[i];
			if(num==total){
				exit=1;
				if(ret[0]=='E')ret[num-1]='N';
				else{ret[num-1]='W';}
				break;
			}
			dfs(row1,col1,N1,N2,num+1,total,dp,ret,exit);
		}
	}
}

void solve(){
	int N1,N2;
	cin>>N1>>N2;
	N1<<=1;N2<<=1;
	pair<bool,int>* dp=new pair<bool,int>[N1*N2]{make_pair(0,0)};
	dp[0]={1,1};
	int num=0;
	string c;
	for(int i=0;i<(N1>>1);i++){
		cin>>c;
		for(int k=0;k<(N2>>1);k++){
			if(c[k]=='*'){
				num+=4;
				auto temp=&dp[(i<<1)*N2+(k<<1)];
				temp[0].first=1;
				temp[1].first=1;
				temp[N2].first=1;
				temp[N2+1].first=1;
			}
		}
	}
	char* ret=new char[num];
	bool exit=false;
	dfs(0,0,N1,N2,2,num,&dp[0],&ret[0],exit);
	if(!exit)
		cout<<"IMPOSSIBLE";
	else{
		for(int i=0;i<num;i++)cout<<ret[i];
	}
	delete []dp;
	delete []ret;
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
