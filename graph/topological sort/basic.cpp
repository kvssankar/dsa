class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n,0);
        vector<int>adj[n];
        for(vector<int>v:edges){
            adj[v[0]].push_back(v[1]);
            indegree[v[1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>order;
        int cnt=0;
        while(!q.empty()){
            int v=q.front();
            q.pop();
            cnt++;
            order.push_back(v);
            for(int i:adj[v]){
                if(--indegree[i]==0){
                    q.push(i);
                }
            }
        }
        if(cnt!=n) return {};
        
        //pre req courses
        reverse(order.begin(),order.end());
        
        return order;
    }
};