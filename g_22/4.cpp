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
	sort(data.begin(),data.end(),[](auto a,auto b){return a[1]<b[1];});
	sort(data.begin(),data.end(),[](auto a,auto b){if(a[1]==b[1])return a[0]<b[0];else{return true;}});
	// for(auto i:data)cout<<i[0]<<' '<<i[1]<<' '<<i[2]<<'\n';
	map<int,int64_t>F;
	map<int,int64_t>B;
	int i=1;
	int64_t sum=data[0][2];
	F[data[0][0]]=data[0][2];
	while(i!=n && data[i][1]==data[0][1]){
		sum+=data[i][2];
		F[data[i][0]]=sum;
		i++;
	}
	while(i!=n){
		int l=0;
		int64_t end=F.rbegin()->second;
		do{
			auto it1=upper_bound(F.begin(),F.end(),data[i][0],[](auto a,auto e){return a<e.first;});
			int64_t t=0;
			if(it1!=F.begin()){
				t=(--it1)->second;
				it1++;
			}
			if(!B.empty() && data[i-1][1]!=data[i][1]){
				t=max(t,B.begin()->second -e);
			}
			t+=data[i][2];
			auto it2=upper_bound(F.begin(),F.end(),t,[](auto a,auto e){return a<=e.second;});
			if(it2!=it1 || it1->first<it2->first){
				F.erase(it1,it2);
			}
			F[data[i][0]]=t;
			i++;
			l++;
			// cout<<t<<'\n';
		}
		while(i!=n && data[i-1][1]==data[i][1]);
		for(int j=1;j<=l;j++){
			auto it1=upper_bound(B.begin(),B.end(),data[i-j][0],[](auto a,auto e){return a<=e.first;});
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
			auto it2=upper_bound(B.begin(),B.end(),t,[](auto a,auto e){return a<=e.second;});
			if(it1==B.end() || (it2!=B.end() && it2->second>it1->second)){
				B.erase(it2,it1);
				break;
			}
			B[data[i-j][0]]=t;
			// cout<<t<<'\n';
		}
	}
	for(auto i:F)cout<<i.first<<' '<<i.second<<'\n';
	cout<<'\n';
	for(auto i:B)cout<<i.first<<' '<<i.second<<'\n';
	// if(!B.empty())
	// 	cout<<max(F.rbegin()->second , B.begin()->second);
	// else{
	// 	cout<<F.rbegin()->second;
	// }
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
