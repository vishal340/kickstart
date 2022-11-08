#include<bits/stdc++.h>
using namespace std;

const int d4i[4]={-1,0,1,0},d4j[4]={0,1,0,-1};

void solve(){
	int n;
	cin>>n;
	char ch[n];
	cin>>ch;
	bool up=false,down=false,digit=false,spec=false;
	cout<<ch;
	for(int i=0;i<n;i++){
		if(up && down && digit && spec){
			return;
		}
		else{
			if(ch[i]>='0' && ch[i]<='9')digit=true;
			else if(ch[i]>='a' && ch[i]<='z')down=true;
			else if(ch[i]>='A' && ch[i]<='Z')up=true;
			else if(ch[i]=='&' || ch[i]=='*' || ch[i]=='#' || ch[i]=='@'){
				spec=true;
			}
		}
	}
	if(!up){
	    n++;
	    cout<<'A';
	}
	if(!down){
	    n++;
	    cout<<'a';
	}
	if(!digit){
	    n++;
	    cout<<'0';
	}
	if(!spec){
	    n++;
	    cout<<'&';
	}
	for(int i=n;i<7;i++)cout<<'1';
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
