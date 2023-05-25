#include <bits/stdc++.h>
using namespace std;
 
// #define int long long
// #define float long double
// #define endl "\n"

int divider(int arr[],int l,int r){
    int i = l-1;
    int pivot = arr[r];
    for(int j=l;j<r;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i++;
}

void sort(int arr[],int l,int r){
    if(l<r){
        int p = divider(arr,l,r);

        sort(arr,l,p-1);
        sort(arr,p+1,r);
    }              
}

int main() {

    int arr[6] = {10,5,6,23,8,9};
    sort(arr,0,5);
    // cout << divider(arr,0,5) << endl;

    for(int i=0;i<6;i++){
        cout << arr[i] << " ";
    }
    return 0;

}