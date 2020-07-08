using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class Meeting {
 public:
  int start = 0;
  int end = 0;

  Meeting(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

bool comp(Meeting &a,Meeting &b){
  return a.start<b.start;
}

class endcomp{
  public:
  bool operator()(const Meeting &x,const Meeting&y){
    return x.end>y.end;
  }

};

class MinimumMeetingRooms {
 public:
  static int findMinimumMeetingRooms(vector<Meeting> &meetings) {
    priority_queue<Meeting,vector<Meeting>,endcomp> pq;
    int count=0;
    sort(meetings.begin(),meetings.end(),comp);
    for(auto meeting:meetings){
      while(!pq.empty() && meeting.start>=pq.top().end){
        pq.pop();
      }
      pq.push(meeting);
      count=max(count,(int)pq.size());
    }
    return count;
  }
};

int main(int argc, char *argv[]) {
  vector<Meeting> input = {{4, 5}, {2, 3}, {2, 4}, {3, 5}};
  int result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

  input = {{1, 4}, {2, 5}, {7, 9}};
  result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

  
}
