#include<bits/stdc++.h>
#include <iomanip>
using namespace std;

const double pi=3.1415927;
void solve(){
	int R,A,B;
	cin>>R>>A>>B;
	int64_t res=(int64_t)R*R;
	int t=R;
	while(t>=1){
		t*=A;
		res+=(int64_t)t*t;
		t/=B;
		res+=(int64_t)t*t;
	}
	double c=pi*res;
	cout<<fixed<<setprecision(6)<<c;
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
