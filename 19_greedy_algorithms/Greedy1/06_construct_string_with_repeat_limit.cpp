// https://leetcode.com/problems/construct-string-with-repeat-limit/
#define pr pair<char,int>
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pr> pq;
        unordered_map<char,int> mp;

        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
        }

        for(auto entry : mp){
            char key = entry.first;
            int val = entry.second;
            pq.push({key,val});
        }
        string ans = "";
        while(!pq.empty()){
            pr top = pq.top();
            pq.pop();
            char ch = top.first;
            int freq = top.second;

            if(freq <= repeatLimit){
                while(freq != 0){
                    ans += ch;
                    freq--;
                }
            }else{
                int cnt = 0;
                while(cnt < repeatLimit){
                    ans += ch;
                    ++cnt;
                }
                pr stp;
                if(!pq.empty()){
                    stp = pq.top();
                    pq.pop();
                    ans += stp.first;
                }else{
                    return ans;
                }
                
                stp.second = stp.second - 1;
                if(stp.second > 0) pq.push(stp); 
                top.second = top.second - repeatLimit;
                if(top.second > 0) pq.push(top);
                
            }
        }

        return ans;
    }
};