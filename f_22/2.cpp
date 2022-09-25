#include<bits/stdc++.h>
#include <utility>
using namespace std;

void dfs(int node,int parent,const vector<vector<int>>& v,vector<int>& d){
	d[node]=d[parent]+1;
	for(auto i:v[node]){
		if(i!=parent)
			dfs(i,node,v,d);
	}
}
void solve(){
	int n,Q;
	cin>>n>>Q;
	vector<vector<int>> v(n,vector<int>());
	for(int i=0;i<n-1;i++){
		int t1,t2;
		cin>>t1>>t2;
		t1--;t2--;
		v[t1].push_back(t2);
		v[t2].push_back(t1);
	}
	vector<int>d(n,0);
	for(auto i:v[0]){
		dfs(i,0,v,d);
	}
	vector<int>dn(n,0);
	for(auto i:d)dn[i]++;
	for(int i=0;i<Q;i++){
		int q;cin>>q;
	}
	int count=1;
	for(int i=1;i<n;i++){
		if(count+dn[i]<=Q)count+=dn[i];
		else{
			cout<<count;
			return;
		}
	}
	cout<<n;
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
