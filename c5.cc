#include <iostream>
using namespace std;
class Ve
{
    public:
    float giagoc;
    string ngay;
    void nhap();
    void xuat();
};
class VeNL :public Ve
{
    public:
    int giam;
    float giave;
    void nhap();
    void xuat();
};
class VeTE :public Ve
{
    public:
    int giam;
    float giave;
    void nhap();
    void xuat();
};
void Ve::nhap()
{
    cout <<"Gia goc:";
    cin >> giagoc;
    cin.ignore();
    cout <<"Ngay :";
    getline(cin,ngay);
}
void Ve::xuat()
{
    cout <<"Gia Goc:" << giagoc << endl;
    cout <<"Ngay :" << ngay << endl;
}
void VeNL::nhap()
{
    Ve::nhap();
    cout <<"giam:";
    cin >> giam;
    giave = giagoc - (giagoc * giam) / 100;
}
void VeNL::xuat()
{
    cout <<"=========================="<< endl;
    Ve::xuat();
    cout <<"Giam:" << giam << endl;
    cout <<"Gia Ve :" << giave;
}
void VeTE::nhap()
{
    Ve::nhap();
    cout <<"giam:";
    cin >> giam;
    giave = giagoc - (giagoc * giam) / 100;
}
void VeTE::xuat()
{
    cout <<"_________________________" << endl;
    Ve::xuat();
    cout <<"Giam:" << giam << endl;
    cout <<"Gia Ve :" << giave << endl;
}
int main()
{
    VeNL a;
    VeTE b;
    cout <<"\t VE NGUOI LON" << endl;
    a.nhap();
    a.xuat();
    cout << endl;
    cout <<"\t VE TRE EM" << endl;
    b.nhap();
    b.xuat();
}