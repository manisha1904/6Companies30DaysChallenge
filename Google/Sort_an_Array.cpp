// Problem Link - https://leetcode.com/problems/sort-an-array/description/

class Solution {
public:
void merge(int l,int mid,int h,vector<int>& nums){
    int temp[h-l+1];
    int i=l,j=mid+1,k=0;
    while(i<=mid && j<=h){
        if(nums[i]<nums[j]){
            temp[k++]=nums[i++];
        }else{
            temp[k++]=nums[j++];
        }
    }
    while(i<=mid){
        temp[k++]=nums[i++];
    }
    while(j<=h){
        temp[k++]=nums[j++];
    }
    for(int m=0;m<k;m++){
        nums[l+m]=temp[m];
    }

}
void mergeSort(int l,int h,vector<int>& nums){
    if(l>=h)return;
    int mid = l+(h-l)/2;
    mergeSort(l,mid,nums);
    mergeSort(mid+1,h,nums);
    merge(l,mid,h,nums);
}
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(0,nums.size()-1,nums);
        return nums;
    }
};
