#include<bits/stdc++.h>
using namespace std;

void solve(){
	struct s{
		int b,c;
		string a;
	};
	int n;
	cin>>n;
	vector<s>v(n),v1(n);
	for(int i=0;i<n;i++)
		cin>>v[i].a>>v[i].b>>v[i].c;
	partial_sort_copy(v.begin(),v.end(),v1.begin(),v1.end(),[](s a,s b){
			if(a.a==b.a){return a.c<b.c;}return a.a<b.a;});
	sort(v.begin(),v.end(),[](s a,s b){if(a.b==b.b){return a.c<b.c;}return a.b<b.b;});
	int count=0;
	for(int i=0;i<n;i++){
		if(v[i].a==v1[i].a && v[i].b==v1[i].b && v[i].c==v1[i].c)count++;
	}
	cout<<count;
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
