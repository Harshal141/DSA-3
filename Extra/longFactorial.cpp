#include <bits/stdc++.h>
using namespace std;

string areyaar()
{
    return "Are Yaar";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> v;v.push_back(1);
    int n;cin >> n;
    int rem =0;
    for(int b=1;b<=n;++b){
        int rem = 0;
        for(int i=0;i<v.size();i++){
            int temp = v[i]*b;
            temp+=rem;
            v[i] = temp%10;
            rem = temp/10;
        }
        while(rem!=0){
            int neww = rem%10;
            v.push_back(neww);
            rem /=10;
        }}
        
    for(int i=v.size()-1;i>=0;i--){
        cout << v[i] ;
    }
    

    //string s;

    // string s = areyaar();    
    // cout << s;
    return 0;
}