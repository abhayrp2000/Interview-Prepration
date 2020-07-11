class MedianFinder {
public:
    /** initialize your data structure here. */
    vector<int> stream;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(stream.empty()){
            stream.push_back(num);
        }else{
            stream.insert(lower_bound(stream.begin(),stream.end(),num),num);
        }
        
    }
    
    double findMedian() {
        int n=stream.size();
        
        if(n%2!=0){
            return stream[(n/2)];
        }else{
            return (stream[n/2]+stream[(n/2)-1])*0.5;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */