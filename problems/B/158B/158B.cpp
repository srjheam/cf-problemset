#include <algorithm>
#include <array>
#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    std::array<int, 3> groups = {0};

    int taxis = 0;
    while (n--) {
        int g;
        std::cin >> g;

        if (g == 4) {
            taxis++;
            continue;
        }

        groups[g - 1]++;
    }

    taxis += groups[2];
    groups[0] -= groups[2];

    taxis += groups[1] / 2;
    if (groups[0] > 0) {
        bool odd = groups[1] % 2;
        if (odd) {
            taxis++;
            groups[0] -= 2 * odd;
            groups[1] = 0;
        }

        taxis += (groups[0] + 4 - 1) / 4;
    }
    taxis += groups[1] % 2;

    std::cout << taxis << std::endl;

    return 0;
}
