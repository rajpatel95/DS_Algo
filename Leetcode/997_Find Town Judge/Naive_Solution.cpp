class Solution {
public:
    
    //  Very Naive Solution, optimizing it, possibly with Topological Sort
    
    
    int graph[1001][1001];
    int flag[1001];
    
    void init(int n){
        for( int i = 1 ; i <= n ; i++ ){
            for( int j = 1 ; j <= n ; j++ ){
                graph[i][j] = 0;
            }
            flag[i] = 0;
        }
    }
    
    int findJudge(int N, vector<vector<int>>& trust) {
        init(N);
        
        for( int i = 0 ; i < trust.size() ; i++ ){
            graph[trust[i][0]][trust[i][1]] = 1;
            flag[trust[i][0]] = 1;
        }
        
        int flag1 = 0;
        int ans;
        for( int i = 1 ; i <= N ; i++ ){
            if(flag[i] == 0){
                if( flag1 == 1 ){
                    return -1;
                }
                flag1 = 1;
                ans = i;
            }
        }
        
        if( flag1 == 1){
            for( int i = 1 ; i <= N ; i++ ){
                if( i == ans ){
                    continue;
                }
                if(graph[i][ans] == 0 ){
                    return -1;
                }
            }
            return ans;
        }
        
        return -1;
    }
};
