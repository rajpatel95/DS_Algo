class Solution {
public:
  
    // Maintain a Max Heap of size K
    
    typedef struct Point{
        double distance;
        pair<int, int> co_ordinates;
    };
    
    double calcDistance(int x, int y){
        return sqrt(x*x + y*y);
    }
    
    typedef struct CompareDist {
        bool operator()(Point const& p1, Point const& p2){
        
            return p1.distance < p2.distance;
        }
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<Point, vector<Point>, CompareDist> heap;
        vector<vector<int>> ans;
        vector<Point> points_distances;
        
        
        for( int i = 0 ; i < points.size(); i++){
            Point point;
            point.distance = calcDistance(points[i][0],points[i][1]);
            point.co_ordinates = {points[i][0], points[i][1]};
            
            points_distances.push_back(point);
        }
        
        for( int i = 0 ; i < points_distances.size(); i++){
            if(heap.size() < K){
                heap.push(points_distances[i]);
            }
            else{
                if(points_distances[i].distance < heap.top().distance){
                    heap.pop();
                    heap.push(points_distances[i]);
                }
            }
        }
        
        while(!heap.empty()){
            vector<int> temp;
            temp.push_back(heap.top().co_ordinates.first);
            temp.push_back(heap.top().co_ordinates.second);
            ans.push_back(temp);
            heap.pop();
        }
        
        return ans;
    }
};
