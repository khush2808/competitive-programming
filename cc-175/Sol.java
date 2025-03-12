
class Sol{
	public static long solve(int n,long[] s, long[] p){
		int a = 0;
		int  b= 0;
		int max_here = 0;
		bool flag = 0;
		for(int i = n-1;i>=0;i--){
			if(s[i]%2==1){
				if(p[i]>max_here){
					p[i]=max_here;
					ans = max(max_here,p[i]-max_here);
				}
			}
		}
		return ans;
	}
public static void main(){
	System.out.println(solve(2,{1,1},{5,6}));
	return;
}
}