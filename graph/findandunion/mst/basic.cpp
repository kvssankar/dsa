class Solution {
public:
    int find(vector<int>&parent,int x){
        if(parent[x]!=x){
            return parent[x]=find(parent,parent[x]);
        }
        return parent[x];
    }
    bool unionSet(vector<int>&parent, vector<int>&rank,int x,int y){
        int px=find(parent,x);
        int py=find(parent,y);
        if(px==py) return false;
        if(rank[px]<rank[py]){
            parent[px]=py;
        }else if(rank[px]>rank[py]){
            parent[py]=px;
        }else{
            parent[py]=px;
            rank[px]++;
        }
        return true;
    }
    int minCost(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(),edges.end(),[](auto &a, auto &b){
            return a[2]<b[2];
        });
        vector<int>parent(n,0),rank(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<int>mste;
        for(auto &e:edges){
            int u=e[0],v=e[1],w=e[2];
            if(unionSet(parent,rank,u,v)){
                mste.push_back(w);
            }
        }
        sort(mste.begin(),mste.end());
        // for(int i:mste)cout<<i<<endl;
        for(int i=0;i<k-1 && !mste.empty();i++){
            // cout<<mste[i]<<endl;
            mste.pop_back();
        }
        return mste.size()==0 ? 0 : mste[mste.size()-1];
    }
};