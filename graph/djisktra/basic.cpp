class Solution {
public:
    int minDisFromSingleSource(int n, vector<vector<int>>& edges, vector<int>& weights, int start, int end) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],weights[i]});
            adj[edges[i][1]].push_back({edges[i][0],weights[i]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,start});
        vector<int> visited(n,0);
        vector<int>dis(n,INT_MAX);
        dis[start]=0;

        
        while(!pq.empty()){
            auto temp=pq.top();
            int node=temp.second;
            int d=temp.first;
            pq.pop();
            visited[node]=1;
            
            if(node==end)
                return d;
            
            for(auto child:adj[node]){
                if(!visited[child.first] && dis[child.first]>d+child.second){
                    dis[child.first]=dis[node]+child.second;
                    pq.push({dis[child.first],child.first});
                }
            }
        }
        return 0;
    }
};