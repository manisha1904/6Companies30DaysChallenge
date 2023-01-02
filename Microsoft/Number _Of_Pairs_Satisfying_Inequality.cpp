Problem Link - leetcode.com/problems/number-of-pairs-satisfying-inequality/description/
  
class Solution {
public:
long long count;
void merge(vector<int>& v,int start,int mid,int end,int diff){
    int l = start,r=mid+1;
    while(l<=mid && r<=end){
        if(v[l]<=v[r]+diff){
            count+=(end-r+1);
            l++;
        }else{
            r++;
        }
    }
    sort(v.begin()+start,v.begin()+end+1);
    return;
}
void mergeSort(vector<int>& v,int start,int end,int diff){
    if(start<end){
        int mid = start+(end-start)/2;
        mergeSort(v,start,mid,diff);
        mergeSort(v,mid+1,end,diff);
        merge(v,start,mid,end,diff);
        return;
    }
    return;
}
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        vector<int>v;
        count=0;
        int n = nums1.size();
        for(int i=0;i<n;i++){
            v.push_back(nums1[i]-nums2[i]);
        }
        mergeSort(v,0,n-1,diff);
        return count;
    }
};
