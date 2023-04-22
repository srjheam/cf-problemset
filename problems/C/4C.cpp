#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> r;

    int n;
    cin >> n;

    while (n--) {
        string name;
        cin >> name;

        if (r.find(name) == r.end()) {
            r[name] = 0;
            cout << "OK" << endl;
            continue;
        }

        r[name]++;
        cout << name << r[name] << endl;
    }

    return 0;
}
