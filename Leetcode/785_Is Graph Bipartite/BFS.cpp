class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        // -1 means black, 1 means white, and 0 means no color assigned(unvisited)
        vector<int> color(graph.size(), 0);
        queue<int> q;

        for( int i = 0 ; i < color.size() ; i++ ){
           if( color[i] == 0 ){
               q.push(i);
               color[i] = 1;
               
               while( !q.empty() ){
                    int curr = q.front();
                    q.pop();

                    for( int i : graph[curr]){
                        if( color[i] == 0 ){
                            color[i] = -color[curr];
                            q.push(i);
                        }
                        else if( color[i] == color[curr]){
                            // If the adjacent vertices have similar Color
                            return false;
                        }
                    }
                }
           }
        }
        
        return true;
    }
};
