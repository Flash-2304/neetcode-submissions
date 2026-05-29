class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> mp1,mp2;
        for(char c:s){
            mp1[c]++;
        }
        for(char c:t){
            mp2[c]++;
        }
        bool ans = true;
        for(int i = 0;i < t.size();i++){
            if(mp1[t[i]] == 0){
                ans = false;
            }else{
                mp1[t[i]]--;
            }
        }
        for(int i = 0;i < s.size();i++){
            if(mp2[s[i]] == 0){
                ans = false;
            }else{
                mp2[s[i]]--;
            }
        }

        return ans;
    }
};
