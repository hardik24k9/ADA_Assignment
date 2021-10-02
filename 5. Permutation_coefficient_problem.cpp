#include<bits/stdc++.h>
using namespace std;

// Approach :- 1
// Time Complexity :- O(N)
// Space Complexity :- O(N)

int main()
{
    int n,k;
    cin >> n >> k;
    int arr[n+1];
    arr[0] = 1;

    for(int i=1;i<=n;i++)
    {
        arr[i] = i*arr[i-1];
    }
    int ans = arr[n]/arr[n-k];
    cout << ans << endl;
}

// Approach :- 2
// Time Complexity :- O(N)
// Space Complexity :- O(1)

int main()
{
    int n,k;
    cin >> n >> k;
    int ans = 1;

    for(int i=0;i<k;i++)
    {
        ans *= (n-i);
    }

    cout << ans << endl;
}