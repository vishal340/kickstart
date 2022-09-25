#include<bits/stdc++.h>
using namespace std;

bool palindrome(char* ch,int s){
  for(int i=0;i<s/2;i++){
    if(ch[i]!=ch[s-i-1])
      return false;
  }
  return true;
}
int append(char* str,const int s){
  const char last =str[0];
  for(int i=s/2;i<s;i++){
    if(str[0]!=str[i]){
      break;
    }
    if(i==s-1)
      return 1;
  }
  for(int i=1;i<s-1;i++){
    if(last==str[i] && last==str[i+1]){
      if(palindrome(&str[1],i-1) && palindrome(&str[i+2], s-i-3))
        return i+1;
    }
  }
  return s;
}

int main(){
  int m,n;
  cin>>m;
  for(int j=1;j<=m;j++){
    cin>>n;
    char s[n];
    cin>>s;
    cout<<"Case #"<<j<<": ";
    for(int i=0;i<append(&s[0],n);i++){
      cout<<s[i];
    }
    cout<<'\n';
  }
};
