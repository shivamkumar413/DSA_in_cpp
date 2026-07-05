#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//https://leetcode.com/problems/boats-to-save-people/
class Solution {
public:  
    int numRescueBoats(vector<int>& people, int limit) {
        //Time complexity = O(n*logn) due to sorting
        int n = people.size();
        sort(people.begin(),people.end());
        int i =0;
        int j = n-1;
        int boatsCount =0;
        while(i<=j){
            if((people[i]+people[j])<=limit){
                boatsCount++;
                i++;
                j--;
            }
            else{
                boatsCount++;//allocate the boat to the heaviest
                j--;
            }
        }
        return boatsCount;
    }
};
int main(){

}