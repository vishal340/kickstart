#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

const int d4i[4]={-1,0,1,0},d4j[4]={0,1,0,-1};
array<array<int,3>,100001>A;
array<array<int,3>,100001>A1;
array<array<int,2>,100001>A2;
void solve(){
	int N,L,B=0;
	cin>>N>>L;
	for(int i=0;i<N;i++){
		A[i][0]=i+1;
		cin>>A[i][1]>>A[i][2];
		if(A[i][2]==0)B++;
	}
	sort(A.begin(),A.begin()+N,[](auto a,auto b){return a[1]<b[1];});
	copy(A.begin(),A.begin()+N,A1.begin());
	stable_partition(A1.begin(),A1.begin()+N,[](auto a){return a[2]==0;});
	for(int i=0;i<B;i++){
		A2[i][0]=A[i][0];
		A2[i][1]=A1[i][1];
	}
	for(int i=B;i<N;i++){
		A2[N-i+B-1][0]=A[i][0];
		A2[N-i+B-1][1]=L-A1[i][1];
	}
	inplace_merge(A2.begin(),A2.begin()+B,A2.begin()+N,[](auto a,auto b){return (a[1]<b[1] || (a[1]==b[1] && a[0]<b[0]));});
	for(int i=0;i<N;i++)cout<<A2[i][0]<<' ';
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
