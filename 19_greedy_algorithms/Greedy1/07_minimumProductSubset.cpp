//Problem Statement : we have been given an array, in which -ve ,0 and +ve number can exist
//we have to return the minimum subset product of the given array
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int minProduct(vector<int>& arr){
    int cn =0,cz =0,cp=0;
    int pos_prod =1;
    int neg_prod =1;
    int largestNegative = INT32_MIN;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<0){
            cn++;
            neg_prod *= arr[i];
            largestNegative = max(largestNegative,arr[i]);
        }
        else if(arr[i]==0) cz++;
        else{
            cp++;
            pos_prod *= arr[i];
        }
    }
    if(cn==0){
        if(cz>0) return 0;
        else{
            sort(arr.begin(),arr.end());
            return arr[0];
        }
    }
    else{
        if(cn%2==0){//even
            return (neg_prod/largestNegative)*pos_prod;
        }
        else{//odd
            return (neg_prod*pos_prod);
        }
    }
}
int main(){
    vector<int>arr {11,2,3};
    cout<<minProduct(arr)<<" ";
    return 0;
}