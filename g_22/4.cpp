#include<bits/stdc++.h>
using namespace std;

const int d4i[4]={-1,0,1,0},d4j[4]={0,1,0,-1};

void solve(){
	int n,e;
	cin>>n>>e;
	vector<array<int,3>>data(n);
	for(int i=0;i<n;i++){
		cin>>data[i][0]>>data[i][1]>>data[i][2];
	}
	if(n==1){
		cout<<data[0][2];
		return;
	}
	sort(data.begin(),data.end(),[](auto a,auto b){return (a[1]>b[1]) ||(a[1]==b[1] && a[0]<b[0]);});
	map<int,int64_t>F;
	map<int,int64_t>B;
	int i=1;
	F[data[0][0]]=data[0][2];
	while(i!=n && data[i][1]==data[0][1]){
		F[data[i][0]]=F[data[i-1][0]]+data[i][2];
		i++;
	}
	while(i!=n){
		int l=0;
		int64_t end=F.rbegin()->second;
		auto it1=F.begin();
		do{
			it1=upper_bound(it1,F.end(),data[i][0],[](auto a,auto e){return a<e.first;});
			int64_t t=0l;
			if(it1!=F.begin()){
				t=(--it1)->second;
				it1++;
			}
			if(!B.empty() && data[i-1][1]!=data[i][1]){
				t=max(t,B.begin()->second -e);
			}
			t+=data[i][2];
			auto it2=upper_bound(it1,F.end(),t,[](auto a,auto e){return a<e.second;});
			if(it2==F.end() || (it1!=F.end() && it1->first<=it2->first)){
				it1=F.erase(it1,it2);
				F[data[i][0]]=t;
			}
			i++;
			l++;
		}
		while(i!=n && data[i-1][1]==data[i][1]);
		it1=B.end();
		for(int j=1;j<=l;j++){
			it1=upper_bound(B.begin(),it1,data[i-j][0],[](auto a,auto e){return a<=e.first;});
			int64_t t=0l;
			if(it1!=B.end()){
				t=it1->second;
				if(j==1){
					t=max(t,end-e);
				}
			}
			else if(j==1){
				t=end-e;
			}
			t+=data[i-j][2];
			auto it2=upper_bound(B.begin(),it1,t,[](auto a,auto e){return a>=e.second;});
			if(it1==B.end() || (it2!=B.end() && it2->second>=it1->second)){
				it1=B.erase(it2,it1);
				B[data[i-j][0]]=t;
			}
		}
	}
	if(!B.empty())
		cout<<max(F.rbegin()->second , B.begin()->second);
	else{
		cout<<F.rbegin()->second;
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
