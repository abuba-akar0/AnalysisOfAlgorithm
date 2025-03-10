#include <iostream>
using namespace std;

void nestedLoops(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << i << " " << j << std::endl;
        }
    }
}

int main() {
    nestedLoops(3);
    return 0;
}