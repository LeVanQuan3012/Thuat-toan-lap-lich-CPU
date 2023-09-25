#include <iostream>
#include <chrono>
using namespace std;

void minmax(int a[], int size) {
    int maxVal = a[0];
    int min = a[0];
    for (int i = 1; i < size; i++) {
        if (a[i] > maxVal) {
            maxVal = a[i];
        }
        if(a[i]<min){
            min = a[i];
        }
    }
    cout<<"Gia tri min "<<min;
    cout<<"\nGia tri max "<<maxVal;
}

void min(int a[], int size) {
    int min = a[0];
    for (int i = 1; i < size; i++) {
        if (a[i] < min) {
            min = a[i];
        }

    }
    cout<<"Gia tri min "<<min;
}

void max(int a[], int size) {
    int maxVal = a[0];
    for (int i = 1; i < size; i++) {
        if (a[i] > maxVal) {
            maxVal = a[i];
        }
    }
    cout<<"\nGia tri max "<<maxVal;
}


int main() {
    int a[5] = {1, 5, 3, 4, 9};

    // Bắt đầu đếm thời gian
    auto start = chrono::high_resolution_clock::now();

    minmax(a,5);
    

    // Kết thúc đếm thời gian
    auto end = chrono::high_resolution_clock::now();

    // Tính thời gian thực thi
    chrono::duration<double> duration = end - start;
    double executionTime = duration.count();

    // In ra thời gian thực thi
    cout << "\nThoi gian thuc thi: " << executionTime << " giay" << endl;


    start = chrono::high_resolution_clock::now();
    min(a,5);
    max(a,5);
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    executionTime = duration.count();
    cout << "\nThoi gian thuc thi: " << executionTime << " giay" << endl;

    delete a;
    return 0;
}
