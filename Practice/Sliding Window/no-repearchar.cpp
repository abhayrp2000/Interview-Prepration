using namespace std;

#include <iostream>
#include <string>
#include <map>

class NoRepeatSubstring {
 public:
  static int findLength(const string& str) {
    int maxLength = 0;
    int start=0;

    map<char,int> mp;

    for(int end=0;end<str.size();end++){
      if(mp.find(str[end])!=mp.end()){
        start=max(start,mp[str[end]]+1);
      }
      mp[str[end]]=end;
      maxLength=max(maxLength,end-start+1);
    }
    return maxLength;
  }
};
