#include <bits/stdc++.h>
using namespace std;
 
// #define int long long
// #define float long double
// #define endl "\n"

void sort(int arr[],int l,int mid,int r){
    int n1 = mid-l+1;
    int n2 = r - mid;

    int a[n1],b[n2];
    for(int i=0;i<n1;i++){
        a[i] = arr[i+l];
    }
    for(int i=0;i<n1;i++){
        b[i] = arr[mid+i+1];
    }

    int i=0,j=0,k=l;

    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k]=a[i];i++;
        }
        else{
            arr[k]=b[j];j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=a[i];i++;k++;
    }
    while(j<n2){
        arr[k]=b[j];j++;k++;
    }
}

void mergeSort(int arr[],int l,int r){
    if(l<r){
        int mid = l+(r-l)/2;

        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);

        sort(arr,l,mid,r);
    }
}


void solve() {

    int arr[6] = {10,5,6,23,8,9};
    mergeSort(arr,0,5);

    for(int i=0;i<6;i++){
        cout << arr[i] << " ";
    }

}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
 
    int T = 1;
    // cin >> T;
    for (int t = 1; t <= T; t++) {
        // cout<<"CASE: "<<t<<endl;
        solve();
    }
    return 0;
}