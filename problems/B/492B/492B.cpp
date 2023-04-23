#include <iomanip>
#include <iostream>
#include <algorithm>

int main() {
    int n, l;
    std::cin >> n >> l;

    int lamps[n] = { 0 };
    for (int i = 0; i < n; i++)
        std::cin >> lamps[i];

    std::sort(lamps, lamps + n);

    int max = 2 * std::max(lamps[0], l - lamps[n - 1]);
    for (int i = 1; i < n; i++)
        max = std::max(lamps[i] - lamps[i - 1], max);

    std::cout << std::fixed << std::setprecision(10);
    std::cout << max / (double)2 << std::endl;

    return 0;
}
