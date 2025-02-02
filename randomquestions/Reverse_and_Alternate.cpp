#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

void solve(){
  
}
int main() {
	IOS
int t ;
	cin>>t;
	while(t--){
	  int n;
    cin>>n;
  string s;
  cin>>s;
 
		int cnt1 = 0;
		int cnt0 = 0;
		for(auto i:s){
		    if(i=='0') cnt0++;
		    else cnt1++;
		}
		if(cnt1==cnt0 or cnt1==cnt0+1 or cnt1==cnt0-1){
		  char prev = s[0];
		  char start ='$';
		  char end;
		  int cnt = 0;
		  bool flag = true;
		  for(int  i = 1;i<n;i++){
		      
					
					if(s[i]!=prev)prev = s[i];
		      else if(s[i]==prev and cnt==0){
		           start = prev;
		           cnt++;
		       }
		       else if(s[i]==prev and cnt==1){
		           end = prev;
		           if(start==end){
		               flag= false;
		               break;
		           }
		           cnt++;
		       }
		       else {
		           flag = false;
		           break;
		       }
		       
		  }
		  if(flag)cout<<"Yes\n";
		  else cout<<"No\n";
		}
		else cout<<"No\n";
	}
}