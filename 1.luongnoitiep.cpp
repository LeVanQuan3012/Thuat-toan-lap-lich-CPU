#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void WorkFunction(int threadId) {
    for (int i = 1; i <= 5; i++) {
        cout << "Luong " << threadId << ": Buoc " << i << endl;
        this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

int main() {
//CHAY LUONG 1
    //Bat dau tinh thoi gian luong 1
    auto start = chrono::high_resolution_clock::now();

    thread thread1(WorkFunction, 1);
    thread1.join();
    cout << "Luong 1 hoan thanh" << endl;

    //Ket thuc tinh thoi gian luong 1
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration1 = end - start;
    double executionTime1 = duration1.count();

//CHAY LUONG 2
    //Bat dau tinh thoi gian luong 2
    start = chrono::high_resolution_clock::now();

    thread thread2(WorkFunction, 2);
    thread2.join();

    cout << "Luong 2 hoan thanh" << endl;
    end = chrono::high_resolution_clock::now();
    
    chrono::duration<double> duration2 = end - start;
    double executionTime2 = duration2.count();

    cout << "\nThoi gian thuc thi: " << executionTime1 + executionTime2 << " giay" << endl;
    return 0;
}
