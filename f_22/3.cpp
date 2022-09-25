#include<bits/stdc++.h>
using namespace std;
void solve(){
	int N;
	int64_t D,X;
	cin>>D>>N>>X;
	int64_t val=0;
	struct seed{int64_t a,b;int c;};
	vector<seed>Z(N);
	for(int i=0;i<N;i++){
		cin>>Z[i].a>>Z[i].b>>Z[i].c;
	}
	sort(Z.begin(),Z.end(),[](auto& a,auto& b){return a.b<b.b;});
	auto compare=[](auto a,auto b){return a.first<b.first;};
	priority_queue<pair<int,int64_t>,std::vector<pair<int,int64_t>>,decltype(compare)>pq(compare);
	for(int i=0;i<N;i++){
		pq.emplace(Z[i].c,Z[i].a);
		int64_t dif= (i<N-1 ? (Z[i+1].b-Z[i].b) : (D-Z[i].b))*X;
		while(dif>0 && !pq.empty()){
			auto t=pq.top();
			pq.pop();
			int64_t t1=min(dif,t.second);
			val+=t1*t.first;
			t.second-=t1;
			dif-=t1;
			if(t.second>0)
				pq.emplace(t);
		}
	}
	cout<<val;
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
