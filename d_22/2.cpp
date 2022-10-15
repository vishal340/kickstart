#include<bits/stdc++.h>
using namespace std;

const int d4i[4]={-1,0,1,0},d4j[4]={0,1,0,-1};
int A[6000],B[6000];
int64_t K[3001],MA[3000],MB[3000];
void solve(){
	int n1,k;
	cin>>n1;
	for(int i=0;i<n1;i++)cin>>A[i];
	int n2;
	cin>>n2;
	for(int i=0;i<n2;i++)cin>>B[i];
	cin>>k;
	int ka=min(k,n1)+1;
	K[0]=0;
	for(int i=1;i<ka;i++){
		K[i]=K[i-1]+A[n1-i];
		for(int j=0;j<i;j++){
			K[j]+=A[i-1-j];
		}
		MA[i-1]=0;
		for(int j=0;j<=i;j++){
			MA[i-1]=max(MA[i-1],K[j]);
		}
	}
	int kb=min(k,n2)+1;
	K[0]=0;
	for(int i=1;i<kb;i++){
		K[i]=K[i-1]+B[n2-i];
		for(int j=0;j<i;j++){
			K[j]+=B[i-1-j];
		}
		MB[i-1]=0;
		for(int j=0;j<=i;j++){
			MB[i-1]=max(MB[i-1],K[j]);
		}
	}
	int64_t M=max(MA[ka-2],MB[kb-2]);
	int l1=min(ka,kb)-1;
	for(int i=0;i<min(k-1,l1);i++){
		if(n1<n2)
			M=max(M,MA[i]+MB[min(k-2-i,n2-1)]);
		else{
			M=max(M,MB[i]+MA[min(k-2-i,n1-1)]);
		}
	}
	cout<<M;
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
