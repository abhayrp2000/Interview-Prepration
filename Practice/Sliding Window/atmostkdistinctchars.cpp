using namespace std;

#include <iostream>
#include <string>
#include<map>

class LongestSubstringKDistinct {
 public:
  static int findLength(const string& str, int k) {
    int maxLength = 0;

    int start=0;

    for(int end=0;end<str.size();end++){
      mp[str[end]]++;
      while(mp.size()>k){
        mp[str[start]]--;
        if(mp[str[start]]==0){
          mp.erase(mp[str[start]]);
        }
        start++;
      }
      maxLength=max(maxLength,end-start+1);
    }
    
    return maxLength;
  }
};
