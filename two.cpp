class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int s = 0;
        int e = n-1;
        while(s<=e){
            int m = (s+e)/2;
            if(arr[s]<=arr[e])
        }
    }
};#include<bits/stdc++.h>
#include<functional>
#define int ll
#define ll long long

using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i= 0;i<n;i++)cin>>arr[i];
    stack<int> s1,s2;
    vector<int> ma(n),mi(n);
    s1.push(-1);
    s2.push(-1);
    for(int i = 0;i<n;i++){
        while(s1.top()!=-1 and arr[i]>arr[s1.top()])s1.pop();
        while(s2.top()!=-1 and arr[i]<arr[s2.top()])s2.pop();
        ma[i]+=i-s1.top();
        mi[i]+=i-s2.top();
        s1.push(i);
        s2.push(i);
    }
    while(s1.size())s1.pop();
    while(s2.size())s2.pop();
		s1.push(n);s2.push(n);
    for(int i =n-1;i>=0;i--){
         while(s1.top()!=n and arr[i]>arr[s1.top()])s1.pop();
        while(s2.top()!=n and arr[i]<arr[s2.top()])s2.pop();
        ma[i]+=s1.top()-i;
        mi[i]+=s2.top()-i;
        s1.push(i);
        s2.push(i);
    }
		int sum = 0;
   for(int i =0;i<n;i++){
		sum+=arr[i]*(ma[i]-mi[i]);
	 }
	 cout<<sum<<'\n';
    
    
}
signed main() {

int t;
t=1;while(t--){
solve();
}
}