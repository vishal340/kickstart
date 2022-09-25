#include <algorithm>
#include<iostream>
#include <cmath>
#include <cstdint>
#include <vector>
#include<sstream>

using namespace std;

int main(){
  int m;
  cin>>m;
  int64_t Case[m];
  for(int z=0;z<m;z++){
    int n,p,M,a[2];
    cin>>n>>p>>M>>a[0]>>a[1];
    a[0]--;a[1]--;
    string s;
    getline(cin,s);
    pair<int64_t,char> t[4];
    for(int i=0;i<4;i++){
      getline(cin,s);
      t[i].second=s[0];
      t[i].first=atoi(&s[2]);
    }
    auto op=[t](int64_t num,int i){
      switch (t[i].second) {
        case '+':
          return  num+t[i].first;
        case '-':
          return num-t[i].first;
        case '*':
          return num*t[i].first;
        case '/':
          return (int64_t)floor((double)num/(double)t[i].first);
        default:
          throw("wrong operator error\n");
      }
    };
    vector<vector<int>>cust(n,vector<int>(n,0));
    vector<vector<int64_t>>coin(n,vector<int64_t>(n,0));
    for(int i=0;i<p;i++){
      getline(cin,s);
      stringstream ss(s);
      int x,y;
      int64_t z;
      ss>>x>>y>>z;
      x--;y--;z;
      cust[x][y]=1<<i;
      coin[x][y]=z;
    }
    const int dr[]={0,1,-1,0};
    const int dc[]={-1,0,0,1};
    vector<vector<vector<int64_t>>> val(n,vector<vector<int64_t>>(n,vector<int64_t>((1<<p),INT64_MIN)));
    val[a[0]][a[1]][0]=0;
    for(int l=0;l<M;l++){
    vector<vector<vector<int64_t>>> temp(n,vector<vector<int64_t>>(n,vector<int64_t>((1<<p),INT64_MIN)));
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          for(int k=0;k<(1<<p);k++){
            if(val[i][j][k]==INT64_MIN)
              continue;
            temp[i][j][k]=max(temp[i][j][k],val[i][j][k]);
            for(int dir=0;dir<4;dir++){
              int r1=j+dr[dir];
              int c1=i+dc[dir];
              if((r1 | c1)<0 || max(r1,c1)>=n)
                continue;
              temp[c1][r1][k]=max(temp[c1][r1][k],op(val[i][j][k], dir));
              int k1= k | cust[c1][r1];
              int nadd= (k & cust[c1][r1])!=0 ? 0:coin[c1][r1];
              temp[c1][r1][k1]=max(temp[c1][r1][k1],op(val[i][j][k],dir)+nadd);
            }
          }
        }
      }
      val=std::move(temp);
    }
    int64_t ret=INT64_MIN;
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        ret=max(ret,val[i][j][(1<<p)-1]);
    Case[z]=ret;
  }
  for(int i=0;i<m;i++){
    if(Case[i]==INT64_MIN)
      cout<<"Case #"<<i+1<<": "<<"IMPOSSIBLE\n";
    else
      cout<<"Case #"<<i+1<<": "<<Case[i]<<'\n';
  }
}
