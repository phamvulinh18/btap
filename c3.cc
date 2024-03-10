#include <iostream>
#include <cstring>
using namespace std;
class PERSON 
{
    public:
    string Hoten;
    string Ngaysinh;
    string Quequan;
    void nhap();
    void xuat();
    PERSON()
    {
        Hoten = "";
        Ngaysinh = "";
        Quequan = "";
    }
};
class DIEM
{
    public:
    int toan;
    int ly;
    int hoa;
void nhap();
void xuat();
DIEM()
{
    toan = ly = hoa=0;
}
};
class HOCSINH :public PERSON,public DIEM
{
    public:
    string lop;
    int tongdiem;
    void nhap();
    void xuat();
    HOCSINH()
    {
        lop = "";
        tongdiem =0;
    }
};
void PERSON ::nhap()
{
     cin.ignore();
    cout <<"Nhap ho ten:";
    getline(cin,Hoten);
    cin.ignore();
    cout <<"Nhap ngay sinh:";
    getline(cin,Ngaysinh);
    cin.ignore();
    cout <<"Nhap que quan:";
    getline(cin,Quequan);
}
void PERSON ::xuat()
{
    cout <<"Ho ten:" <<Hoten << endl;
    cout <<"Ngaysinh:"<<Ngaysinh << endl;
    cout <<"Que quan:"<<Quequan << endl;
}
void DIEM::nhap()
{
    cout <<"Nhap diem toan:";
    cin >> toan;
    cout <<"Nhap diem ly:";
    cin >> ly;
    cout <<"Nhap diem hoa:";
    cin >> hoa;
}
void DIEM ::xuat()
{
    cout <<"Diem Toan:" << toan << endl;
    cout <<"Diem Ly:" << ly << endl;
    cout <<"Diem Hoa:" << hoa << endl;
}
void HOCSINH ::nhap()
{
    PERSON ::nhap();
    cin.ignore();
    cout <<"Nhap lop:";
    getline(cin,lop);
    DIEM ::nhap();
    tongdiem = toan + ly + hoa;
}
void HOCSINH ::xuat()
{
    cout <<"_________________________" << endl;
    PERSON :: xuat();
    cout <<"Lop:" << lop << endl;
    DIEM ::xuat();
    cout <<"Tong Diem :" << tongdiem << endl;
}
int main()
{
    HOCSINH a[100];
    int n , i;
    cout <<"Nhap so luong:";
    cin >> n;
    for(i = 0 ; i < n ; i++)
    {
        cout <<"\tNHAP HOC SINH THU :" << i + 1 << endl;
        a[i].nhap();
    }
    for(int i = 0 ; i < n ; i++)
    {
        cout <<"\tHOC SINH THU :" <<  i + 1 << endl;
        a[i].xuat();
    }
}