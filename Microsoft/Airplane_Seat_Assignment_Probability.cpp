Problem Link - leetcode.com/problems/airplane-seat-assignment-probability/description/

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n==1){
            return 1.0;
        }
        return 0.5;
    }
};
