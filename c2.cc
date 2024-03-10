#include <iostream>
#include <cstring>
using namespace std;

class PERSON {
public:
    string Hoten;
    string Ngaysinh;
    string Quequan;
    void nhap();
    void xuat();
};

class DIEM {
public:
    int toan;
    int ly;
    int hoa;
    void nhap();
    void xuat();
};

class HOCSINH : public PERSON, public DIEM {
public:
    string lop;
    int tongdiem;
    void nhap();
    void xuat();
};

void PERSON::nhap() {
    cin.ignore();
    cout <<"Nhập họ tên: ";
    getline(cin, Hoten);
    cout <<"Nhập ngày sinh: ";
    getline(cin, Ngaysinh);
    cout <<"Nhập quê quán: ";
    getline(cin, Quequan);
}

void PERSON::xuat() {
    cout <<"Họ tên: " << Hoten << endl;
    cout <<"Ngày sinh: "<< Ngaysinh << endl;
    cout <<"Quê quán: "<< Quequan << endl;
}

void DIEM::nhap() {
    cout <<"Nhập điểm toán: ";
    cin >> toan;
    cout <<"Nhập điểm lý: ";
    cin >> ly;
    cout <<"Nhập điểm hóa: ";
    cin >> hoa;
}

void DIEM::xuat() {
    cout <<"Điểm Toán: " << toan << endl;
    cout <<"Điểm Lý: " << ly << endl;
    cout <<"Điểm Hóa: " << hoa << endl;
}

void HOCSINH::nhap() {
    PERSON::nhap();
    cout <<"Nhập lớp: ";
    cin.ignore();
    getline(cin, lop);
    DIEM::nhap();
    tongdiem = toan + ly + hoa;
}

void HOCSINH::xuat() {
    PERSON::xuat();
    cout <<"Lớp: " << lop << endl;
    DIEM::xuat();
    cout <<"Tổng Điểm: " << tongdiem << endl;
}

int main() {
    int n;
    cout <<"Nhập tổng số học sinh: ";
    cin >> n;
    HOCSINH a[n];

    for(int i = 0 ; i < n ; i++) {
        cout <<"\nNhập thông tin cho học sinh thứ " << i + 1 << ":\n";
        a[i].nhap();
    }

    cout <<"\nThông tin của các học sinh:\n";
    for(int i = 0 ; i < n ; i++) {
        cout <<"\nHọc sinh thứ " << i + 1 << ":\n";
        a[i].xuat();
    }

    return 0;
}
