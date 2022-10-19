#include<bits/stdc++.h>
using namespace std;

const int d4i[4]={-1,0,1,0},d4j[4]={0,1,0,-1};

int B1[8],B2[8];

int distance(int l1,int l2){
	int f=l1*l1+l2*l2;
	return f;
}
void solve(){
	int r1,r2;
	cin>>r1>>r2;
	int n1,n2;
	cin>>n1;
	int target=(r1+r2)*(r1+r2)+1;
	int score1=0,score2=0;
	bool b=true;
	int m=target;
	int t1,t2;
	for(int i=0;i<n1;i++){
		cin>>t2>>t1;
		B1[i]=distance(t1,t2);
		if(B1[i]>=target)B1[i]=target;
		else{
			m=min(m,B1[i]);
			score1++;
		}
	}
	cin>>n2;
	for(int i=0;i<n2;i++){
		cin>>t1>>t2;
		B2[i]=distance(t1, t2);
		if(B2[i]>target)B2[i]=target;
		else{
			if(B2[i]<m){
				b=false;
				score2++;
				score1=0;
			}
			else if(b){
				for(int j=0;j<n1;j++){
					if(B1[j]<target && B1[j]>B2[i]){
						score1--;
						B1[j]=target;
					}
				}
			}
		}
	}
	cout<<score1<<' '<<score2;
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
