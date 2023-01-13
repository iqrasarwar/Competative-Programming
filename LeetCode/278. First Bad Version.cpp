// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        while(isBadVersion(n-1))
            n--;
        return n;
    }
};
