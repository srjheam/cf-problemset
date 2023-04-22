#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        std::string word;
        cin >> word;

        if (word.length() <= 10) {
            cout << word << "\n";
            continue;
        }

        cout << word[0] << word.length() - 2 << word.back() << "\n";
    }

    return 0;
}
