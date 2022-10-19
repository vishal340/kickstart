#include<bits/stdc++.h>
using namespace std;

const int d4i[4]={-1,0,1,0},d4j[4]={0,1,0,-1};
int64_t C[400001];
int64_t S[400001];
void solve(){
	int n;
	cin>>n;
	int64_t sum=0;
	C[0]=0;
	S[0]=0;
	for(int i=1;i<=n;i++){
		cin>>C[i];
		C[i]+=C[i-1];
		S[i]=S[i-1]+C[i];
	}
	vector<int>v;
	int j;
	for(int i=n;i>=0;i--){
		while(!v.empty() && C[v.back()]>=C[i]){
			v.pop_back();
		}
		if(!v.empty()){
			j=v.back();
		}
		else{
			j=n+1;
		}
		sum+=S[j-1]-S[i]-(j-i-1)*C[i];
		v.push_back(i);
	}
	cout<<sum;
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
