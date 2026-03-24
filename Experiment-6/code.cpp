#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n;
string s,o;
vector<char>b[128];
vector<char>k[128];
bool mark[128];
bool couted[128];
bool all(){
  for(char i='a';i<'z'+1;i++)
    if(!couted[i]){
      //      cerr<<i<<endl;
      return 1;
    }
  return 0;
}
bool ready(char c){
  for(int i=0;i<b[c].size();i++)
    if(!couted[b[c][i]])
      return 0;
  return 1;
}
int lax(string a,string b){
  for(int i=0;i<min(a.length(),b.length());i++)
    if(a[i]!=b[i])
      return i;
  return -1;
}
bool v_k_u(char v,char u){
  mark[v]=1;
  for(int i=0;i<b[v].size();i++)
    if(b[v][i]==u)
      return 0;
    else if(!mark[b[v][i]])
      if(!v_k_u(b[v][i],u))
	return 0;
  return 1;
}
int main(){
  cin>>n;
  if(n==1){
    cout<<"bcdefghijklmnopqrsatuvwxyz"<<endl;
    return 0;
  }
  cin>>o;
  for(int i=1;i<n;i++){
    cin>>s;
    if(o.length()>s.length() && o.substr(0,s.length())==s){
      cout<<"Impossible"<<endl;
      return 0;
    }
    
    int pos=lax(o,s);
    if(pos==-1)continue;
    //s>o && s[pos]>o[pos]
    fill(mark,mark+128,0);
    if(v_k_u(o[pos],s[pos]))
      b[s[pos]].push_back(o[pos]),k[o[pos]].push_back(s[pos]);
    else{
      cout<<"Impossible"<<endl;
      return 0;
    }
    o=s;
  }
  for(char i='a';i<'z'+1;i++){
    if(!b[i].size()){
      cout<<i;
      couted[i]=1;
    }
  }
  while(all()){
    for(char i='a';i<'z'+1;i++)
      if(!couted[i] && ready(i))
	couted[i]=1,cout<<i;
  }
  cout<<endl;
  return 0;
}
