#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class CD
{
    private:
    int id;
    string casy;
    string tuaCD;
    int sobai;
    float price;
public:
    void nhap();
    void xuat();
    float get_price();
    int get_id();
    string get_tuaCD();
    string get_casy();

};
bool kiemtra(CD *a[] , int n , int c )
{
    for ( int i = 0; i < n; i++)
    {
        if(a[i]->get_id() == c)
        {
            return true;
        }
    }
    return false;
    
}
void CD::nhap()
{
    cout <<"Nhap ID:";
    cin >> id;
    cin.ignore();
    cout <<"Nhap ten ca sy:";
    getline(cin,casy);
    cin.ignore();
    cout <<"Nhap tua CD:";
    getline(cin,tuaCD);
    cout <<"Nhap so bai:";
    cin >> sobai;
    cout <<"Nhap gia thanh:";
    cin >> price;
}
void CD::xuat()
{
    cout <<"__________________________"<<endl;
    cout <<"ID:" << id <<endl;
    cout <<"Ten:" << casy << endl;
    cout <<"Tua CD:" << tuaCD << endl;
    cout <<"So bai hat:" << sobai << endl;
    cout <<"Gia Thanh:" << price << endl;
    cout <<"__________________________"<<endl;
    cout << endl;
}
int CD ::get_id()
{
    return id;
}
float CD:: get_price()
{
    return price;
}
string CD :: get_tuaCD()
{
    return tuaCD;
}
string CD:: get_casy()
{
    return casy;
}
void themCD(CD *a[], int &n)
{
    if(n < 100 )
    {
        a[n] = new CD;
        a[n]->nhap();
        int newID = a[n]->get_id();
        bool index = kiemtra(a,n,newID);
        if(index)
        {
            cout << "Them That Bai: ID da ton tai." << endl;
            delete a[n];
        }
        else
        {
            n++;
            cout << "Da them CD vao danh sach." << endl;
        }
    }
    else
    {
        cout <<"\tThem That Bai: Danh Sach day!"<<endl;

    }
}
void tongGia(CD *a[] , int n)
{
    float tong = 0;
    for(int i = 0 ; i < n ; i++)
    {
        tong = tong + a[i]->get_price();
    }
    cout <<" Tong gia thanh la:" << tong << endl;
}
void sapxep(CD *a[] , int n)
{
    for(int i = 0 ; i < n - 1 ; i++)
    {
        for(int j = i + 1 ; j < n ; j++)
        {
            if(strcmp(a[i]->get_tuaCD().c_str(), a[j]->get_tuaCD().c_str()) > 0)
            {
                swap(a[i] , a[j]);
            }
        }
    }
    for(int i = 0 ; i < n ; i++)
    {
        cout <<"CD THU " << i+1 << endl;
        a[i]->xuat();
    }
}
void xuatTT(CD *a[] , int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        cout <<"CD THU " << i+1 << endl;
        a[i]->xuat();
    }
}
void timkiem(CD *a[] , int n)
{
    string name;
    cout <<"Nhap ten Ca Sy:";
    cin.ignore();
    getline(cin,name);
    bool check = false;
    for(int i = 0 ; i < n ; i++)
    {
        if(strcmp(a[i]->get_casy().c_str(),name.c_str())==0)
        {
            a[i]->xuat();
            check = true;
            break;
        }
    }
    if(check == false)
    {
        cout <<"Khong tim thay ten ca Sy nao!"<<endl;
    }
}
int main()
{
    CD  *a[100];
    int luachon;
    int n = 0;
    do 
    {
    cout <<"___________________________MENU____________________________"<<endl;
    cout <<"\t1.Nhap du lieu"<<endl;
    cout <<"\t2.So luong CD"<<endl;
    cout <<"\t3.Tong gia thanh"<<endl;
    cout <<"\t4.Sap tang dan theo tuaCD"<<endl;
    cout <<"\t5.Tim kiem ten CaSy" <<endl;
    cout <<"\t6.xuat du lieu"<<endl;
    cout <<"____________________________________________________________"<<endl;
    cout <<"Nhap Lua Chon:";
    cin >> luachon;
    switch(luachon)
    {
    case 1:
    themCD(a,n);
        break;
    case 2:
    cout <<" so luong CD la :" << n << endl;
        break;
    case 3:
    tongGia(a,n);
    break;
    case 4:
    sapxep(a,n);
    break;
    case 5:
     timkiem(a,n);
     break;
    case 6:
    xuatTT(a,n);
    default:
    cout <<"Vui Long Nhap Lai LUA CHON ( 1 - 6)";
        break;
    }
    }while(luachon!= 0);
}