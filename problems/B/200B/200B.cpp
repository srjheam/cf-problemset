#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int sum = 0;
    int d = n * 100;
    while (n--) {
        int i;
        std::cin >> i;

        sum += i;
    }

    std::cout << (sum / (double)d) * 100 << std::endl;

    return 0;
}
