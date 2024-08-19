#include <iostream>
#include <boost/shared_ptr.hpp>

using namespace std;

int main() {
    boost::shared_ptr<int> ptr(new int);
    *ptr = 10;
    cout << "pointer :" << *ptr << endl;
}