#include<bits/stdc++.h>
using namespace std;

const int d4i[4]={-1,0,1,0},d4j[4]={0,1,0,-1};

int J[31][1000];
int M[31];
void solve(){
	int m,n,p;
	cin>>m>>n>>p;
	p--;
	memset(&M[0],0,4*n);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>J[j][i];
			M[j]=max(M[j],J[j][i]);
		}
	}
	int sum=0;
	for(int j=0;j<n;j++)sum+= (M[j]>J[j][p] ? (M[j]-J[j][p]):0);
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
