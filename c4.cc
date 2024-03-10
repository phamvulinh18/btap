#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
class NSX
{
    private:
    string TenNSX;
    string Diachi;
    public:
    void nhap();
    void xuat();
};
class MAY
{
    public:
    string NhanHieu;
    string NhaSX;
    float gia;
    void nhap();
    void xuat();
    string get_NhaSX();
};
class MT :public NSX,public MAY
{
    public:
    float tocdo;
    int dungluong;
    int DLHDD;
    void nhap();
    void xuat();
};
void NSX ::nhap()
{
    cin.ignore();
    cout <<"Ten NSX:";
    getline(cin,TenNSX);
    cin.ignore();
    cout <<"Nhap dia chi:";
    getline(cin,Diachi);
}
void NSX ::xuat()
{
    cout <<"Ten NSX:" << TenNSX << endl;
    cout <<"Dia Chi:" << Diachi << endl;
}
void MAY ::nhap()
{
    cin.ignore();
    cout <<"Nhap Nhan Hieu:";
    getline(cin,NhanHieu);
    cin.ignore();
    cout <<"Nhap Nha Sx :";
    getline(cin,NhaSX);
    cout <<"Nhap Gia:";
    cin >> gia;
}
void MAY ::xuat()
{
    cout <<"Nhan Hieu :" << NhanHieu << endl;
    cout <<"Nha Sx :" << NhaSX << endl;
    cout <<"Gia :" << gia << endl;
}
void MT ::nhap()
{
    NSX::nhap();
    MAY::nhap();
    cout <<"Nhap Toc do:";
    cin >> tocdo;
    cout <<"Nhap dung luong:";
    cin >> dungluong;
    cout <<"Nhap dung luong HDD:";
    cin >> DLHDD;
    cout << endl;
}
void sapxep(MT a[] , int n)
{
    for(int i = 0 ; i < n - 1 ; i++)
    {
        for(int j = i + 1 ; j < n ; j++)
        {
            if(a[i].gia > a[j].gia)
            {
                swap(a[i],a[j]);
            }
        }
    }
   for(int i = 0 ; i < n ; i++)
   {
    a[i].xuat();
   }
}
void xuatIBM(MT a[] , int n)
{
    string name= "IBM";
    bool check = false;
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i].get_NhaSX()==name)
        {
            check = true;
            a[i].xuat();
        }
    }
    if(check == false)
    {
        cout <<"Khong co nha SX IBM";
    }
}
void MT ::xuat()
{
    cout <<"_____________________________" << endl;
    NSX::xuat();
    MAY::xuat();
    cout <<"Toc do :" << tocdo << endl;
    cout <<"Dung Luong :" << dungluong << endl;
    cout <<"Dung Luong HDD :" << DLHDD << endl;
}
string MAY::get_NhaSX()
{
    return NhaSX;
}
void xoaIntel(MT a[] , int &n)
{
    string name = "Intel";
    int vitri = -1;
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i].get_NhaSX()== name)
        {
            vitri = i;
            break;
        }
    }
    if(vitri == -1)
    {
        cout <<"Khong tim thay Intel"<<endl;
        return;
    }
    for(int i = vitri ; i < n -1 ; i++)
    {
        a[i] = a[i + 1];
    }
    n--;
    for(int i = 0 ; i < n ; i++)
    
   {
    a[i].xuat();
   }
}
// 785106
int main()
{
    int n;
    int luachon;
    cout <<"So Luong:";
    cin >> n;
    MT a[100];
    for(int i = 0 ; i < n ; i++)
    {
        cout <<"\tNhap Thong tin"<<endl;
        a[i].nhap();
    }
    do 
    {
    cout <<"==============================="<<endl;
    cout <<"\t1.Sap xep " << endl;
    cout <<"\t2.Hang IBM"<< endl;
    cout <<"\t3.Xoa Intel" << endl;
    cout <<"==============================="<<endl;
    cout <<"Nhap lua chon :";
    cin >> luachon;
    switch(luachon)
    {
        case 1:
        cout <<"\tSap Xep Tang"<<endl;
         sapxep(a,n);
          cout <<endl;
          break;
        case 2:
         cout <<"\tHang IBM"<<endl;
            xuatIBM(a,n);
            break;
        case 3:
        cout <<"\tXOA NHA SX INTEL" << endl;
    xoaIntel(a,n);
    break;
    default:
    cout <<"Lua chon khong hop le:";
    }
    }while(luachon != 0);
}