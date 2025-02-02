#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

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
		
		
		  char prev = s[0];
		  char start ='$';
		  char end;
		  int cnt = 0;
		  bool flag = true;
			vector<pair<int,int>>  v;
			v.push_back({0,0});
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
			v.push_back({n-1,n-1});
		
		
	}
}