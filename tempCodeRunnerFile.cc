#include <iostream>
#include <algorithm>
using namespace std;
class BV
{
    public:
    string tenBV;
    string diachi;
    void nhap();
    void xuat();
};
class BS
{
    public:
    string hoten;
    void nhap();
    void xuat();
};
class BN :public BS,public BV
{
    public:
    string ten ;
    int tuoi;
    string chuandoan;
    void nhap();
    void xuat();
};
void BV::nhap()
{
    cin.ignore();
    cout <<"Ten BV:";
    getline(cin,tenBV);
     cin.ignore();
    cout <<"Dia chi:";
    getline(cin,diachi);
}
void BV::xuat()
{
    cout <<" Ten BV :" << tenBV << endl;
    cout <<" Dia chi :" << diachi << endl;
}
void BS::nhap()
{
     cin.ignore();
    cout <<"Ten bac si:";
    getline(cin,hoten);
}
void BS ::xuat()
{
    cout <<"Ten BS :" << hoten << endl;
}
void BN ::nhap()
{
    cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    BV::nhap();
    BS::nhap();
     cin.ignore();
    cout <<"Ten BN :";
    getline(cin,ten);
    cout <<"Tuoi :";
    cin >> tuoi;
    cin.ignore();
    cout <<"Benh :";
    getline(cin,chuandoan);
     cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
     cout << endl;

}
void BN::xuat()
{
    cout <<"==============================" << endl;
    BV::xuat();
    BS::xuat();
    cout <<" Ten BN :" << ten << endl;
    cout <<"Tuoi :" << tuoi << endl;
    cout <<"Benh:" <<chuandoan << endl;
    cout <<"==============================" << endl;
    cout << endl;
}
void sapxep(BN a[] , int n)
{
    for(int i = 0 ; i < n - 1; i++)
    {
        for(int j = i + 1 ; j < n ; j++)
        {
            if(a[i].tuoi > a[j].tuoi)
            {
                swap(a[i],a[j]);
            }
        }
    }
    for(int i = 0 ; i < n ; i++)
    {
        cout <<"thong tin thu " << i + 1<<endl;
        a[i].xuat();
    }
}
void inBS(BN a[] , int n)
{
    string name = "Hoang Ha";
    bool check = false;
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i].hoten == name)
        {
            a[i].xuat();
        }
    }
}
int main()
{
    BN a[100];
    int n ,i,luachon;
    cout <<"Nhap so luong:";
    cin >> n;
    for(i = 0 ; i < n ; i++)
    {
        cout <<"Nhap thong tin thu " << i + 1<<endl;
        a[i].nhap();
    }
    do 
    {
    cout <<"______________________________________"<<endl;
    cout <<"\t1.Sap xep tang theo tuoi" << endl;
    cout <<"\t2.In bac si co ten Hoang Ha"<<endl;
    cout <<"______________________________________"<<endl;
    cout <<"nhap lua chon:";
    cin >> luachon;
    switch(luachon)
    {
        case 1:
        sapxep(a,n);
        break;
        case 2:
        inBS(a,n);
    }
    }while(luachon !=0);
}