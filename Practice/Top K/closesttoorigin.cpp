class ds{
    public:
    int x;
    int y;
    float distance;
    
    ds(int x1,int y1,float d){
        x=x1;
        y=y1;
        distance=d;
    }
};

class comp{
    public:
    bool operator()(ds &a,ds &b){
        return a.distance>b.distance;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        priority_queue<ds,vector<ds>,comp> pq;
        
        for(int i=0;i<points.size();i++){
            float dist=sqrt(pow(points[i][0],2)+pow(points[i][1],2));
            pq.push({points[i][0],points[i][1],dist});
        }
        
        
        vector<vector<int>> res;
        for(int i=0;i<K;i++){
            auto p=pq.top();
            res.push_back({p.x,p.y});
            pq.pop();
        }
        return res;
    }
};