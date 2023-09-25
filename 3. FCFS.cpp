#include <iostream>
#include <vector>

using namespace std;

struct Process{
    int id;
    int timeXuatHien;
    int timeSuDungCPU;
    int timeCho;

    Process(int id1, int XH, int SD){
        id = id1;
        timeXuatHien = XH;
        timeSuDungCPU = SD;
        timeCho = 0;
    }
};

int main(){
    //Tao danh sach cac tien trinh


    vector<Process> tientrinh;



    int n;
    cout<<"Nhap so tien trinh: ";
    cin>>n;
    int xuatHien,suDung;

    //Nhap thong tin cac tien trinh
    for(int i=0; i<n; i++){
        cout<<"Nhap thoi gian xuat hien cua tien trinh "<<i+1<<": ";
        cin>>xuatHien;
        cout<<"Nhap thoi gian su dung CPU cua tien trinh"<<i+1<<": ";
        cin>>suDung;
        tientrinh.push_back(Process(i+1,xuatHien,suDung));
        cout<<endl;
    }

   /* //Sap xep tien trinh theo thoi gian cho
    for(int i=0; i<tientrinh.size()-1; i++){
        for(int j=i+1; j<tientrinh.size(); j++){
            if(tientrinh.at(i).timeCho > tientrinh.at(j).timeCho){
                Process tmp = tientrinh.at(i);
                tientrinh.at(i) = tientrinh.at(j);
                tientrinh.at(j) = tmp;
            }
        }
    }*/

    int timeHienTai = 0;
    int tongTimeCho = 0;
    for(int i=0; i<tientrinh.size(); i++){
        const Process& process = tientrinh[i];
        tongTimeCho += timeHienTai - process.timeXuatHien;
        timeHienTai += process.timeSuDungCPU;

        cout<<"Tien trinh "<<process.id<<endl;
        cout<<"\tThoi gian luu lai he thong: "<<timeHienTai - process.timeXuatHien<<endl;
        cout<<"\tThoi gian cho: "<<(timeHienTai - process.timeXuatHien)-process.timeSuDungCPU;
        cout<<endl;
    }

    double timeTB = tongTimeCho*1.0/tientrinh.size();
    cout<<"\nThoi gian cho trung binh: "<<timeTB<<endl;


    
    return 0;

}
