
#include <iostream>
#include <mutex>

using namespace std;


mutex  m;

void hello() {
    cout << "hey 2" << endl;
    lock_guard<mutex> lock3(m);
    cout << "hey 3" << endl;
}

int main() {
    cout << "hey 0" << endl;
    lock_guard<mutex> lock(m);
    lock_guard<mutex> lock2(m);
    cout << "hey 1" << endl;
    hello();
    cout << "hey 4" << endl;
}