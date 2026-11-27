class Solution {
public:
int V;
void dfs(int node,vector<vector<int>>& graph,vector<vector<int>>&ans,vector<int>&temp,vector<int> &vis){
    vis[node]=1;
    temp.push_back(node);

    if(node==V-1){
        ans.push_back(temp);
    }

    for(auto &adjNode:graph[node]){
        if(!vis[adjNode]){
            // temp.push_back(adjNode);
            dfs(adjNode,graph,ans,temp,vis);
            // temp.pop_back();
        }
    }

    vis[node]=0;
    temp.pop_back();
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
         V=graph.size();

        vector<vector<int>> ans;
        vector<int>temp;

        vector<int> vis(V,0);

      
        dfs(0,graph,ans,temp,vis);

        return ans;
        
    }
};