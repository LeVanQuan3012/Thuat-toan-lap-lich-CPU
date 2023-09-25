#include <iostream>
#include <queue>

using namespace std;

struct Process
{
    int id;
    int thoiDiemXuatHien; 
    int timeSuDungCPU;    
    int timeConlai;       
};

void roundRobinScheduling(Process processes[], int n, int quantum)
{
    queue<Process> readyQueue;

    for (int i = 0; i < n; i++)
    {
        readyQueue.push(processes[i]);
    }

    int timeHienTai = 0;
    int tongTimeCho = 0;

    while (!readyQueue.empty())
    {
        Process currentProcess = readyQueue.front();
        readyQueue.pop();

        int executionTime = min(quantum, currentProcess.timeConlai);
        cout << "Tien trinh " << currentProcess.id << " thuc hien trong " << executionTime << " don vi thoi gian";

        currentProcess.timeConlai -= executionTime;
        timeHienTai += executionTime;

        if (currentProcess.timeConlai > 0)
        {
            cout << ". Quay tro ve hang doi" << endl
                 << endl;
            readyQueue.push(currentProcess);
        }
        else
        {
            int waitingTime = timeHienTai - currentProcess.thoiDiemXuatHien - currentProcess.timeSuDungCPU;
            tongTimeCho += waitingTime;
            cout << ". Tien trinh hoan thanh va thoi diem hoan thanh " << timeHienTai << endl;
            cout << "\tThoi gian luu lai he thong: " << timeHienTai - currentProcess.thoiDiemXuatHien << endl;
            cout << "\tThoi gian cho doi: " << (timeHienTai - currentProcess.thoiDiemXuatHien) - currentProcess.timeSuDungCPU << endl
                 << endl;
        }
    }

    double averageWaitingTime = static_cast<double>(tongTimeCho) / n;
    cout << "Thoi gian cho trung binh: " << averageWaitingTime << endl;
}

int main()
{
    int n;
    cout << "Nhap so tien trinh: ";
    cin >> n;

    Process processes[n];


    
    for (int i = 0; i < n; i++)
    {
        processes[i].id = i + 1;
        cout << "Tien trinh " << processes[i].id << " - Thoi diem xuat hien: ";
        cin >> processes[i].thoiDiemXuatHien;
        cout << "Tien trinh " << processes[i].id << " - Thoi gian su dung CPU: ";
        cin >> processes[i].timeSuDungCPU;
        processes[i].timeConlai = processes[i].timeSuDungCPU;
    }

    int quantum;
    cout << "Nhap gia tri quantum q: ";
    cin >> quantum;

    cout << "Ket qua thuc hien:" << endl;
    roundRobinScheduling(processes, n, quantum);

    return 0;
}
