#include <iostream>
#include <thread>
#include <time.h>
#include <string>
#include <mutex>

using namespace std;

mutex m;

struct c {
    int count = 0;
} a;


void foo(int b);
void bar();

int main() {
    thread th1(foo, 5);
    thread th2(foo, 4);

    th1.join();
    th2.join();

    cout << "Total Count: " << a.count << endl;
    return 0;
}


void foo(int b) {
    for (int i = 0; i < b; i++) {
        bar();
    }
}

void bar() {
    a.count++;
}
