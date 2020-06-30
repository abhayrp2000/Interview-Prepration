using namespace std;

#include <iostream>
#include <string>
#include <map>

class CharacterReplacement {
 public:
  static int findLength(const string& str, int k) {
    int maxLength = 0;
    int maxfreq=0;

    map<char,int> mp;

    int start=0;
    for(int end=0;end<str.size();end++){
      mp[str[end]]++;
      maxfreq=max(maxfreq,mp[str[end]]);

      if(end-start+1-maxfreq>k){
        mp[str[start]]--;
        start++;
      }
      maxLength=max(end-start+1,maxLength);
    }

    return maxLength;
  }
};
