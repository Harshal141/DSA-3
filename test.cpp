// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

// An iterative binary search function.
int binarySearch(int nums[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
 
        // Check if x is present at mid
        if (nums[m] != nums[m+1] && nums[m-1] != nums[m])
            return m;
 
        // If x greater, ignore left half
        else if (m%2==0){
            if(nums[m] == nums[m+1] )l = m + 1;
            else r = m-1;
        }
        else
            if(nums[m] == nums[m+1] )r = m-1;
            else l = m + 1;
    }

    return -1;
}

int main() {
    int ars[] = {0,1,2,3,4,5,6,7,8};
    int nums[] = {1,1,2,3,3,4,4,8,8};
    int n =sizeof(nums)/sizeof(int);
    if(n == 1) cout << nums[0];
    if(nums[0] != nums[1])cout << nums[0];
    else if(nums[n-1] != nums[n-2])cout << nums[n-1];
    else{
    int res = binarySearch(nums,1,n-2,3);
    cout << nums[res];
    }

    return 0;
}









