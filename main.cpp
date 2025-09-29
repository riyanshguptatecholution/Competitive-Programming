// You have two large bags of numbers. Initially, the first bag contains 𝑛
//  numbers: 𝑎1,𝑎2,…,𝑎𝑛
// , while the second bag is empty. You are allowed to perform the following operations:

// Choose any number from the first bag and move it to the second bag.
// Choose a number from the first bag that is also present in the second bag and increase it by one.
// You can perform an unlimited number of operations of both types, in any order. Is it possible to make the contents of the first and second bags identical?

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdlib>
#include <numeric>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

#define append push_back
#define ll long long int
#define all(v) v.begin(), v.end()
#define phuck() ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define printv(v) for(auto &&val:v) cout<<val<<" "; cout<<endl;

using namespace std;

// using namespace __gnu_pbds;

// template <class T> using ordered_set = tree<T, null_type,
// less<T>, rb_tree_tag, tree_order_statistics_node_update>;

signed main(){
    phuck();
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n);
        for(auto &val:v) cin >> val;
        sort(all(v));
        set<int> s(all(v));
        
        int cnt = s.size();
        string ans = "Yes";
        vector<int> a; int m = v[0];
        for(int i=0; i+1<n; i+=2){
            if (m>=v[i]){
                a.append(m);
            } 
            else {
                a.append(v[i]); 
                a.append(v[i+1]); 
                m=v[i+1]; m++;
                continue;
            }
            if (m>=v[i+1]){
                a.append(m);
                m++;
            } 
            else {
                m = v[i+1];
                a.append(m);
                m++;
            }
        }
        map<int, int> mp;
        for(auto &&val: a) mp[val]++;
        for(auto &&pr: mp) {if (pr.second%2!=0) {ans = "No"; break;}}
        cout<<ans<<endl;

    }
    return 0;
}
