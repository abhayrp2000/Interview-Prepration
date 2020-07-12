static vector<int> findKLargestNumbers(const vector<int>& nums, int k) {
    vector<int> result;
    priority_queue<int> pq;
    for(auto val:nums){
      pq.push(val);
    }

    for(int i=0;i<k;i++){
      result.push_back(pq.top());
      pq.pop();
    }
    return result;
  }