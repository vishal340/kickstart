#include<bits/stdc++.h>
#include <iterator>
using namespace std;

void solve(){
	int N,K,X,D,M;
	cin>>N>>K>>X>>D>>M;
	struct meet{int p,l,r;};
	vector<meet>v(M);
	for(int i=0;i<M;i++){
		cin>>v[i].p>>v[i].l>>v[i].r;
		v[i].p--;
	}
	sort(v.begin(),v.end(),[](auto a,auto b){return a.l<b.l;});
	vector<meet>v1(M);
	copy(v.begin(),v.end(),v1.begin());
	sort(v1.begin(),v1.end(),[](auto a,auto b){return a.r<b.r;});
	vector<int>num(M+1,0);
	num[0]=N;
	vector<int>dev(N,0);
	int J=0;
	for(int i=0;i<X;i++){
		while(J<M && v[J].l==i){
			int k=v[J].p;
			num[dev[k]]--;
			dev[k]++;
			num[dev[k]]++;
			J++;
		}
	}
	int t1=num[0]<K ? K-num[0]:0;
	int ret=0;
	int t2=0;
	for(int i=1;i<M+1;i++){
		if(t2+num[i]<=t1){
			t2+=num[i];
			ret+=i*num[i];
		}
		else{
			ret+=i*(t1-t2);
			break;
		}
	}
	int J1=0;
	for(int i=X;i<D;i++){
		while(J<M && v[J].l==i){
			int k=v[J].p;
			num[dev[k]]--;
			dev[k]++;
			num[dev[k]]++;
			J++;
		}
		while(J1<M && v1[J1].r==i-X+1){
			int k=v1[J1].p;
			num[dev[k]]--;
			dev[k]--;
			num[dev[k]]++;
			J1++;
		}
		t1=num[0]<K ? K-num[0]:0;
		t2=0;
		int temp=0;
		for(int j=1;j<M+1;j++){
			if(t2+num[j]<=t1){
				t2+=num[j];
				temp+=j*num[j];
			}
			else{
				temp+=j*(t1-t2);
				break;
			}
		}
		ret=min(ret,temp);
	}
	cout<<ret;
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
