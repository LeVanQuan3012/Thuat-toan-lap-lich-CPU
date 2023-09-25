#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int id;
    int thoiDiemXuatHien;
    int timeSuDungCPU;
    int timeConLai;

    Process(int i, int at, int bt) : id(i), thoiDiemXuatHien(at), timeSuDungCPU(bt), timeConLai(bt) {}
};

bool compareArrivalTime(const Process &a, const Process &b) {
    return a.thoiDiemXuatHien < b.thoiDiemXuatHien;
}

bool compareBurstTime(const Process &a, const Process &b) {
    return a.timeConLai < b.timeConLai;
}

int main() {
    int n;
    cout << "Nhap so luong tien trinh: ";
    cin >> n;

    vector<Process> processes;

    for (int i = 0; i < n; i++) {
        int at, bt;
        cout << "Nhap thoi gian den va thoi gian thuc thi cho tien trinh " << i + 1 << ": ";
        cin >> at >> bt;
        processes.push_back(Process(i + 1, at, bt));
    }

    sort(processes.begin(), processes.end(), compareArrivalTime);

    int timeHienTai = 0;
    double timeChoTB = 0.0;

    cout << "\nKet qua:\n";

    while (!processes.empty()) {
        int shortestJobIndex = -1;
        for (int i = 0; i < processes.size(); i++) {
            if (processes[i].thoiDiemXuatHien <= timeHienTai && (shortestJobIndex == -1 
            || processes[i].timeConLai < processes[shortestJobIndex].timeConLai)) {
                shortestJobIndex = i;
            }
        }

        if (shortestJobIndex == -1) {
            timeHienTai++;
        } else {
            Process &currentProcess = processes[shortestJobIndex];
            cout << "Tien trinh " << currentProcess.id << endl;
            cout << "\tThoi gian luu lai he thong: " << timeHienTai + currentProcess.timeSuDungCPU - currentProcess.thoiDiemXuatHien 
            << endl;
            cout << "\tThoi gian cho: " << timeHienTai - currentProcess.thoiDiemXuatHien << "\n";
            cout << endl;
            timeChoTB += (timeHienTai - currentProcess.thoiDiemXuatHien);
            timeHienTai += currentProcess.timeSuDungCPU;
            currentProcess.timeConLai = 0;
            processes.erase(processes.begin() + shortestJobIndex);
        }
    }

    timeChoTB /= n;

    cout << "\nThoi gian cho doi trung binh = " << timeChoTB << " thoi gian don vi" << endl;

    return 0;
}
