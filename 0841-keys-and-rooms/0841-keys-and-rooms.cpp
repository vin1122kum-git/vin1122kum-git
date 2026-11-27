class Solution {
public:

    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        //cycle detection in undirected graph

        //create adj list

        int n=rooms.size();

         queue<int> q;
        q.push(0);


        vector<int> vis(n,0);
        vis[0]=1;

        int count=1;

        while(!q.empty()){

            int node = q.front();

            q.pop();

            for(auto &adjNode:rooms[node]){
                    if(!vis[adjNode]){
                           vis[adjNode] = 1;
                            count++;
                       q.push(adjNode);
                    }
                   
                      
                }
                 
            }


    return count==n;
       
        
    }
};