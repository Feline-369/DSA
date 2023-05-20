#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        int n;
        cin >> n;
        cin >> s;
        int c1 = 0;
        int c2 = 0;
        int count = 0;
        int arr[] = {0, 0};
        for (int i = 0; i < n; i++)
        {
            if (s[i] = 'R')
            {
                if (arr[0] == 1 && arr[1] == 1)
                {
                    cout << "yes" << endl;
                    break;
                }
                arr[0] = c1++;
            }
            if (s[i] = 'L')
            {
                if (arr[0] == 1 && arr[1] == 1)
                {
                    cout << "yes" << endl;
                    break;
                }
                arr[0] = c1--;
            }
            if (s[i] = 'U')
            {
                if (arr[0] == 1 && arr[1] == 1)
                {
                    cout << "yes" << endl;
                    break;
                }
                arr[1] = c2++;
            }
            if (s[i] = 'D')
            {
                if (arr[0] == 1 && arr[1] == 1)
                {
                    cout << "yes" << endl;
                    break;
                }
                arr[1] = c2--;
            }
            count++;
        }
        if (count == n)
            cout << "no" << endl;
    }
}