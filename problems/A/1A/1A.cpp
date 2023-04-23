#include <iostream>
using namespace std;

int main() {
    int m, n, a;
    cin >> m;
    cin >> n;
    cin >> a;

    int sm = 1 + ((m - 1) / a);
    int sn = 1 + ((n - 1) / a);

    long long s = (long long)sm * sn;

    cout << s <<  endl;

    return 0;
}
