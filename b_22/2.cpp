#include<bits/stdc++.h>
using namespace std;

bool is_palindrome(int64_t n){
	int8_t a[11];
	int8_t i=0;
	while(n){
		a[i]=n%10;
		n/=10;
		i++;
	}
	for(int8_t j=0;j<i/2;j++){
		if(a[j]!=a[i-1-j])
			return false;
	}
	return true;
}
void solve(){
	int64_t A;
	cin>>A;
	if(A==0){
		cout<<1;
		return;
	}
	int s=sqrt(A);
	int out=0;
	int64_t A1;
	for(int i=1;i<=s;i++){
		if(!(A%i)){
			A1=A/i;
			if(A1!=s)out+=is_palindrome(i);
			out+=is_palindrome(A1);
		}
	}
	cout<<out;
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
