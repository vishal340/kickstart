#include<bits/stdc++.h>
using namespace std;

const int d4i[4]={-1,0,1,0},d4j[4]={0,1,0,-1};
template<typename T,typename U>void vec(vector<T>&v,U x,size_t n){
	v=vector<T>(n,x);
}
template<typename T,typename U>void vec(vector<T>&v,U x,size_t n,size_t N...){
	v=vector<T>(n);
	for(size_t i=0;i<n;i++)vec(v[i],x,N);
}

void solve(){

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
