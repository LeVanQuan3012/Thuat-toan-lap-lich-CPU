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
    //Bat dau tinh thoi gian
    auto start = chrono::high_resolution_clock::now();

    thread thread1(WorkFunction, 1);
    thread thread2(WorkFunction, 2);

    // Chờ cho cả hai luồng hoàn thành
    thread1.join();
    thread2.join();

    cout << "Ca hai luong deu hoan thanh" << endl;
    
    //ket thuc tinh thoi gian
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = end - start;
    double executionTime = duration.count();

    // In ra thời gian thực thi
    cout << "\nThoi gian thuc thi: " << executionTime << " giay" << endl;

    return 0;
}
