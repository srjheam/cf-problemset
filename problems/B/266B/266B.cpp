#include <deque>
#include <iostream>

#define GIRL 'G'
#define BOY 'B'

int main() {
    int n;
    std::cin >> n;

    int s;
    std::cin >> s;

    std::string q;
    std::cin >> q;

    while (s--) {
        for (int i = 1; i <= n; i++) {
            if (q[i] == GIRL && q[i - 1] == BOY) {
                q[i] = BOY;
                q[i - 1] = GIRL;
                i++;
            }
        }
    }

    std::cout << q << std::endl;

    return 0;
}
