// picking the best quality lemons
// converting vectors to priority queue
// Mikhail Nesterenko
// 2/17/2023

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::priority_queue;
using std::string;
using std::vector;

struct Lemon {
    double quality;
    friend bool operator<(const Lemon& left, const Lemon& right) {
        return left.quality < right.quality;
    }
};

const int maxBoxSize = 30;
const int highestQuality = 10;

int main() {
    srand(time(nullptr));
    priority_queue<Lemon> box;  // random box size
    // random quality assingment
    int size = rand() % maxBoxSize + 1;
    for (int i = 0; i < size; i++) {
        Lemon a;
        a.quality = static_cast<double>(rand()) / RAND_MAX * highestQuality;
        box.push(a);
    }

    cout << "Here are the lemons (best first): ";

    while (!box.empty()) {
        auto bestLemon = box.top();
        cout << bestLemon.quality << ", ";
        box.pop();
    }
    cout << endl;
}
