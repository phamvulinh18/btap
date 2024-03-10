#include <iostream>
#include <string>
using namespace std;

class CD {
private:
    int maCD;
    string tuaCD;
    string caSy;
    int soBaiHat;
    float giaThanh;
public:
    void nhapThongTin();
    void xuatThongTin();
    int layMaCD();
    float layGiaThanh();
    string layTuaCD();
};

void CD::nhapThongTin() {
    cout << "Nhap ma CD: ";
    cin >> maCD;
    cout << "Nhap tua CD: ";
    cin.ignore();
    getline(cin, tuaCD);
    cout << "Nhap ten ca sy: ";
    getline(cin, caSy);
    cout << "Nhap so bai hat: ";
    cin >> soBaiHat;
    cout << "Nhap gia thanh: ";
    cin >> giaThanh;
}

void CD::xuatThongTin() {
    cout << "Ma CD: " << maCD << endl;
    cout << "Tua CD: " << tuaCD << endl;
    cout << "Ca sy: " << caSy << endl;
    cout << "So bai hat: " << soBaiHat << endl;
    cout << "Gia thanh: " << giaThanh << endl;
}

int CD::layMaCD() {
    return maCD;
}

float CD::layGiaThanh() {
    return giaThanh;
}

string CD::layTuaCD() {
    return tuaCD;
}

void themCD(CD *dsCD[], int &soLuong) {
    if (soLuong < 10) {
        dsCD[soLuong] = new CD();
        dsCD[soLuong]->nhapThongTin();
        soLuong++;
        cout << "Da them CD vao danh sach." << endl;
    } else {
        cout << "Danh sach da day, khong the them CD moi." << endl;
    }
}

int demSoLuongCD(CD *dsCD[], int soLuong) {
    return soLuong;
}

float tinhTongGiaThanh(CD *dsCD[], int soLuong) {
    float tong = 0;
    for (int i = 0; i < soLuong; i++) {
        tong += dsCD[i]->layGiaThanh();
    }
    return tong;
}

void sapXepGiamDanTheoGiaThanh(CD *dsCD[], int soLuong) {
    for (int i = 0; i < soLuong - 1; i++) {
        for (int j = i + 1; j < soLuong; j++) {
            if (dsCD[i]->layGiaThanh() < dsCD[j]->layGiaThanh()) {
                swap(dsCD[i], dsCD[j]);
            }
        }
    }
}

void sapXepTangDanTheoTuaCD(CD *dsCD[], int soLuong) {
    for (int i = 0; i < soLuong - 1; i++) {
        for (int j = i + 1; j < soLuong; j++) {
            if (dsCD[i]->layTuaCD() > dsCD[j]->layTuaCD()) {
                swap(dsCD[i], dsCD[j]);
            }
        }
    }
}

void xuatDanhSachCD(CD *dsCD[], int soLuong) {
    cout << "Danh sach CD:" << endl;
    for (int i = 0; i < soLuong; i++) {
        cout << "CD thu " << i + 1 << ":" << endl;
        dsCD[i]->xuatThongTin();
        cout << endl;
    }
}

int main() {
    CD *danhSachCD[10];
    int soLuongCD = 0;
    int luaChon;
    
    do {
        cout << "===== MENU =====" << endl;
        cout << "1. Them CD moi" << endl;
        cout << "2. Dem so luong CD" << endl;
        cout << "3. Tinh tong gia thanh cua cac CD" << endl;
        cout << "4. Sap xep giam dan theo gia thanh" << endl;
        cout << "5. Sap xep tang dan theo tua CD" << endl;
        cout << "6. Xuat danh sach CD" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;
        
        switch (luaChon) {
            case 1:
                themCD(danhSachCD, soLuongCD);
                break;
            case 2:
                cout << "So luong CD hien tai: " << demSoLuongCD(danhSachCD, soLuongCD) << endl;
                break;
            case 3:
                cout << "Tong gia thanh cua cac CD: " << tinhTongGiaThanh(danhSachCD, soLuongCD) << endl;
                break;
            case 4:
                sapXepGiamDanTheoGiaThanh(danhSachCD, soLuongCD);
                cout << "Da sap xep giam dan theo gia thanh." << endl;
                break;
            case 5:
                sapXepTangDanTheoTuaCD(danhSachCD, soLuongCD);
                cout << "Da sap xep tang dan theo tua CD." << endl;
                break;
            case 6:
                xuatDanhSachCD(danhSachCD, soLuongCD);
                break;
            case 0:
                cout << "Tam biet!";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai." << endl;
        }
    } while (luaChon != 0);
    
    // Giải phóng bộ nhớ
    for (int i = 0; i < soLuongCD; i++) {
        delete danhSachCD[i];
    }

    return 0;
}
