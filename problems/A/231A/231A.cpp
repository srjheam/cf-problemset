#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int w = 0;
    while (n--) {
        int s = 0;

        for (int i = 0; i < 3; i++) {
            int tmp;
            cin >> tmp;
            s += tmp;            
        }
        
        w += s >> 1;
    }

    cout << w << endl;

    return 0;
}
