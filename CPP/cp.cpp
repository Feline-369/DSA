#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    int t;
    int a;
    vector<int> arr;
    cin >> t;
    while (t > 0)
    {
        cin >> a;
        for (int i = 0; i < a; i++)
        {
            int input;
            cin >> input;
            arr.push_back(input);
        }
        sort(arr.begin(), arr.end());
        int f = 0;
        int l = a - 1;
        int ans = 0;
        while (f < l)
        {
            ans += arr[l] - arr[f];
            f++;
            l--;
        }
        cout << ans << endl;
        t--;
    }
} /*6
 5
 1 5 6 3 4
 1
 5
 4
 1 6 3 9
 6
 1 13 9 3 7 2
 4
 2 2 2 2
 5
 4 5 2 2 3
 */