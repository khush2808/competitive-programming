#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, sz;
    DSU(int n) : p(n), sz(n,1) {
        for(int i=0;i<n;i++) p[i]=i;
    }
    int find(int x){
        return (p[x]==x ? x : p[x]=find(p[x]));
    }
    void unite(int x,int y){
        x=find(x); y=find(y);
        if(x!=y){
            if(sz[x]<sz[y]) swap(x,y);
            p[y]=x; sz[x]+=sz[y];
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        int n, m1, m2; 
        cin >> n >> m1 >> m2;

        // Build F edges
        vector<pair<int,int>> Fedges(m1);
        for(int i=0;i<m1;i++){
            cin >> Fedges[i].first >> Fedges[i].second;
            Fedges[i].first--, Fedges[i].second--;
        }

        // Build DSU for G
        DSU dsuG(n);
        for(int i=0;i<m2;i++){
            int u,v; cin >> u >> v; 
            dsuG.unite(u-1,v-1);
        }

        // gSet[v] = which G component v belongs to
        vector<int> gSet(n);
        for(int i=0;i<n;i++){
            gSet[i] = dsuG.find(i);
        }

        // Count edges in F that connect different G-subsets
        long long crossEdges = 0;
        // Build FIntra DSU for edges within same G-subset
        DSU FIntra(n);
        for(auto &e: Fedges){
            int u=e.first, v=e.second;
            if(gSet[u] != gSet[v]){
                crossEdges++;
            } else {
                FIntra.unite(u,v);
            }
        }

        // Count distinct FIntra components
        int compCountFIntra=0;
        for(int i=0;i<n;i++){
            if(FIntra.find(i)==i) compCountFIntra++;
        }

        // Count distinct G components
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(gSet[i]);
        }
        int distinctG = (int)st.size();

        // Total cost: remove crossEdges + add edges to unify each G-subset
        long long ans = crossEdges + (compCountFIntra - distinctG);
        cout << ans << "\n";
    }
    return 0;
}