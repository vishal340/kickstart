#include<bits/stdc++.h>
using namespace std;

const int d4i[4]={-1,0,1,0},d4j[4]={0,1,0,-1};
vector<pair<int,int>> R(100000);
vector<int> O(100000);

void solve(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>R[i].first;
		R[i].second=i;
	}
	sort(R.begin(),R.begin()+n,[](auto a,auto b){return a.first<b.first;});
	int i=0,j=1;
	if(R[1].first>2*R[0].first){
		O[R[0].second]=-1;
		i++;
		j++;
	}
	while(j!=n){
		if(R[j].first>2*R[i].first){
			if(j==i+1){
				O[R[i].second]=R[i-1].first;
				j++;
			}
			else{O[R[i].second]=R[j-1].first;}
			i++;
		}
		else{j++;}
	}
	for(;i<n-1;i++)O[R[i].second]=R[n-1].first;
	O[R[n-1].second]=R[n-2].first;
	for(int i=0;i<n;i++)cout<<O[i]<<' ';
}

int main(){
	int T;
	cin>>T;
	for(int t=1;t<=T;t++){
		cout<<"Case #"<<t<<": ";
		solve();
		cout<<'\n';
	}
}
