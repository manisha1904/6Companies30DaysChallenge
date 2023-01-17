// Problem Link - https://leetcode.com/problems/find-in-mountain-array/description/

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len=mountainArr.length();
        int start=0;
        int pivot=-1;
        while(start<len){
            int mid=(start+len)/2;
            int temp=mountainArr.get(mid);
            if(mid==0 && mid<len-1){
                if(temp>mountainArr.get(mid+1)){
                    pivot=mid;
                    break;
                }
                else
                    start=mid+1;
            }
            else if(mid>0 && mid==len-1){
                if(temp>mountainArr.get(mid-1)){
                    pivot=mid;
                    break;
                }
                else
                    len=mid;
            }
            else if(mid>0 && mid<len-1 && mountainArr.get(mid-1)<temp && temp>mountainArr.get(mid+1)){
                pivot=mid;
                break;
            }
            else if(mid>0 && mid<len-1 && mountainArr.get(mid-1)>temp && mountainArr.get(mid+1)<temp)
                len=mid;
            else
                start=mid+1;
            
        }
        if(pivot!=-1){
            start=0;
            len=pivot+1;
        }
        else
        {
            start=0;
            len=mountainArr.length();
        }
        while(start<len){
            int mid=(len+start)/2;
            cout<<mountainArr.get(mid)<<"  ";
            if(mountainArr.get(mid)==target)
                return mid;
            else if(mountainArr.get(mid)<target)
                start=mid+1;
            else
                len=mid;
        }
        if(pivot!=-1){
            start=pivot;
        len=mountainArr.length();
        }
        else{
            start=0;
            len=mountainArr.length();
        }
        while(start<len){
            int mid=(len+start)/2;
            cout<<mountainArr.get(mid)<<"  ";
            if(mountainArr.get(mid)==target)
                return mid;
            else if(mountainArr.get(mid)<target)
                len=mid;
            else
                start=mid+1;;
        }
       
        return -1;
        
    }
};
