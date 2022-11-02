#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

const int d4i[4]={-1,0,1,0},d4j[4]={0,1,0,-1};

array<int,2500>N;
void solve(){
	int n,m,m1;
	cin>>n;
	for(int i=0;i<n;i++)cin>>N[i];
	cin>>m;
	unordered_map<int,vector<int>>M;
	for(int i=0;i<m;i++){
		cin>>m1;
		M[m1].push_back(i);
	}
	vector<pair<int,int64_t>>S[2];
	bool j=true;
	int i=n-1;
	for(auto k:M[N[i]])S[0].emplace_back(k,0);
	i--;
	while(i>=0){
		if(N[i]==N[i+1]){
			i--;
			continue;
		}
		S[j].clear();
		auto it=S[1^j].begin();
		for(auto k:M[N[i]]){
			it=upper_bound(it,S[1^j].end(),k,[](auto e,auto a){return e<a.first;});
			int64_t temp;
			if(it!=S[1^j].end()){
				temp=it->second+it->first-k;
				if(it!=S[1^j].begin()){
					it--;
					temp=min(temp,it->second+k-it->first);
					it++;
				}
			}
			else{
				it--;
				temp=it->second+k-it->first;
				it++;
			}
			S[j].emplace_back(k,temp);
		}
		j=1^j;
		i--;
	}
	j=1^j;
	int64_t minimum=INT64_MAX;
	for(auto i:S[j]){
		minimum=min(minimum,i.second);
	}
	cout<<minimum;
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
