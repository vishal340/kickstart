#include<bits/stdc++.h>
using namespace std;

const int d4i[4]={-1,0,1,0},d4j[4]={0,1,0,-1};
array<int,21>L;
void solve(){
	int n,m,k,t1,t2;
	cin>>n>>m>>k;
	vector<bool>I(n,false);
	vector<bool>I1(n,true);
	unordered_map<int,vector<int>>M;
	unordered_map<int,vector<int>>M_;
	for(int i=0;i<m;i++){
		cin>>t1>>t2;
		t1--;t2--;
		M[t2].push_back(t1);
		M_[t1].push_back(t2);
	}
	if(k==1){
		cout<<M.size();
		return;
	}
	auto lambda1=[&](int a,auto& self)->void {
		for(auto a1:M_[a]){
			if(!I[a1]){
				I[a1]=true;
				if(M_.count(a1))
					self(a1,self);
			}
		}
	};
	for(auto i:M){
	 int b=i.first;
		if(!I[b] && I1[b]){
			 int j=1;
			 L[0]=b;
			 int count=1+i.second.size();
			 if(count>k){
				 I[b]=true;
				 if(M_.count(b))
					 lambda1(b,lambda1);
			 }
			 else{
				 bool cont=true;
				 set<int>acc1;
				 vector<int>acc;
				 acc.push_back(b);
				 acc1.insert(b);
				 acc1.insert(i.second.begin(),i.second.end());
				 for(auto i1:i.second){
					 L[j]=i1;
					 auto lambda =[&](int a,int j,auto& self) -> void{
						 for(int i2=0;i2<j;i2++){
							 if(L[i2]==a)return;
						 }
						 j++;
						 if(M.count(a)){
							 acc1.insert(M[a].begin(),M[a].end());
							 if(acc1.size()<=k){
								 for(auto i2:M[a]){
									 if(!cont)
										 return;
									 if(find(acc.begin(),acc.end(),i2)==acc.end()){
									 	L[j]=i2;
									 	self(i2,j,self);
										acc.push_back(i2);
									 }
								 }
							 }
							 else{
								 cont=false;
								 I[b]=true;
							 }
						 } 
					 };
					 acc.push_back(i1);
					 lambda(i1,j,lambda);
				 }
				 if(I[b] && M_.count(b)){
					 lambda1(b,lambda1);
				 }
				 if(!I[b]){
					 for(auto l:acc1){
						 I1[l]=false;
					 }
				 }
			 }
		}
	}
	cout<<count_if(I.begin(), I.end(), [](auto a){return a;});
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
