#include<bits/stdc++.h>
using namespace std;

bool is_palindrome(char* c,int len){
    for(int i=0;i<len-4;i++){
        if(c[i]==c[i+4] && c[i+1]==c[i+3])
            return 1;
    }
    for(int i=0;i<len-5;i++){
        if(c[i]==c[i+5] && c[i+1]==c[i+4] && c[i+2]==c[i+3])
            return 1;
    }
    return 0;
}
void dfs(char* c,const vector<int>& loc,int cur,int N,bool& flag){
	int l=loc[cur];
	c[l]='1';
	int j1=min(cur+1<loc.size() ? loc[cur+1]-1:N-1,l+5);
	int j2=max(0,l-5);
	if(!is_palindrome(&c[j2],j1-j2+1)){
		if(cur+1<loc.size())
			dfs(c,loc,cur+1,N,flag);
		else{
			flag=true;
		}
	}
	if(!flag){
		c[l]='0';
		j1=min((cur+1<loc.size() ? loc[cur+1]-1:N-1),l+5);
		j2=max(0,l-5);
		if(!is_palindrome(&c[j2],j1-j2+1)){
			if(cur+1<loc.size())
				dfs(c,loc,cur+1,N,flag);
			else{
				flag=true;
			}
		}
	}
}
void solve(){
	int N;
	cin>>N;
	string c;
	cin>>c;
	vector<int>loc;
	for(int i=0;i<N;i++){
		if(c[i]=='?')loc.push_back(i);
	}

	int start=0;
	int loclen=loc.size();
	for(int i=0;i<loclen;i++){
		if(is_palindrome(&c[start], loc[i]-start)){
			cout<<"IMPOSSIBLE";
			return;
		}
		start=loc[i]+1;
	}
	if(is_palindrome(&c[start], N-start)){
		cout<<"IMPOSSIBLE";
		return;
	}
	else if(start==0){
		cout<<"POSSIBLE";
		return;
	}
	bool flag=false;
	if(loclen)
		dfs(&c[0],loc,0,N,flag);
	if(flag)cout<<"POSSIBLE";
	else{cout<<"IMPOSSIBLE";}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		cout<<"Case #"<<i<<": ";
	solve();
	cout<<'\n';
	}
}
