#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int k;
    cin >> k;

    int kc = 0;
    int p = 0;
    for (int i = 1; i <= n; i++) {
        int s;
        cin >> s;
        if (s == 0)
            break;

        if (i == k)
            kc = s;

        if (i <= k || s >= kc)
            p++;
        
    }

    cout << p << endl;

    return 0;
}
