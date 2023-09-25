#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Process
{
    int id;
    int timeXuatHien;
    int timeSuDungCPU;
    int timeConLai;

    Process(int id, int timeXuatHien, int timeSuDungCPU) : id(id), timeXuatHien(timeXuatHien), 
    timeSuDungCPU(timeSuDungCPU), timeConLai(timeSuDungCPU) {}
};

bool kiemtra(const Process &p1, const Process &p2)
{
    return p1.timeXuatHien < p2.timeXuatHien;
}

int main()
{
    int n; // Number of processes
    cout << "Nhap so luong tien trinh: ";
    cin >> n;

    double timeChoTB = 0.0;

    vector<Process> processes;


    for (int i = 0; i < n; ++i)
    {
        int timeXuatHien, timeSuDungCPU;
        cout << "Nhap thoi diem xuat hien va thoi gian su dung CPU cua tien trinh " << i + 1 << ": ";
        cin >> timeXuatHien >> timeSuDungCPU;
        processes.push_back(Process(i + 1, timeXuatHien, timeSuDungCPU));
    }
    cout << endl;
    sort(processes.begin(), processes.end(), kiemtra);

    int timeHienTai = 0;
    int hoanThanh = 0;


    queue<int> readyQueue;


    // vector<int> completionTimes(n);

    while (hoanThanh < n)
    {
        int tienTrinhDuocChon = -1;
        for (int i = 0; i < n; ++i)
        {
            if (processes[i].timeXuatHien <= timeHienTai && processes[i].timeConLai > 0)
            {
                if (tienTrinhDuocChon == -1 || processes[i].timeConLai < processes[tienTrinhDuocChon].timeConLai)
                {
                    tienTrinhDuocChon = i;
                }
            }
        }

        if (tienTrinhDuocChon == -1)
        {
            timeHienTai++;
        }
        else
        {
            cout << "Tien trinh " << processes[tienTrinhDuocChon].id << " chay 1 don vi thoi gian ";
            processes[tienTrinhDuocChon].timeConLai--;

            if (processes[tienTrinhDuocChon].timeConLai == 0)
            {
                cout << ".Tien trinh hoan thanh." << endl;
                hoanThanh++;
                // completionTimes[tienTrinhDuocChon] = timeHienTai;
                cout << "\tThoi gian luu lai he thong: " << timeHienTai + 1 - processes[tienTrinhDuocChon].timeXuatHien << endl;
                cout << "\tThoi gian cho: " << timeHienTai + 1 - processes[tienTrinhDuocChon].timeXuatHien - 
                processes[tienTrinhDuocChon].timeSuDungCPU << endl;
                cout << endl;
                timeChoTB += timeHienTai + 1 - processes[tienTrinhDuocChon].timeXuatHien - processes[tienTrinhDuocChon].timeSuDungCPU;
            }
            else
            {
                cout << ".Tien trinh quay tro lai hang doi." << endl
                     << endl;
            }

            timeHienTai++;
        }
    }

    cout << endl
         << "Thoi gian cho trung binh = " << timeChoTB / processes.size();

    return 0;
}
