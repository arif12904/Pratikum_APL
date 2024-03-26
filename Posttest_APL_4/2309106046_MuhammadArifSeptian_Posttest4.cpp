#include <iostream>
using namespace std;

int jmlh = 0;
int menu, indeks;

struct mainan{
    string nama_mainan;
};

struct harga{
    int harga;
};

struct data_produk
{
    mainan mn;
    harga hrg;
};

data_produk dpr[10];



void lanjutkan(){
    cout<<"\nJika ingin melanjutkan tekan enter";
    cin.ignore();
    cin.get();
    system("cls");
}

bool login();

void tampilan_menu();

void tambah_produk();

void menampilkan_produk();

void update_produk();

void hapus_produk();

int hitung_jumlah_produk_rekursif(int index);

int main(){
    char pilih;

    bool menu_login = login();
    if (menu_login == true)
    {
        while (true)
        {
            tampilan_menu();
            cin>>pilih;

            if (pilih == '1')
            {
                tambah_produk();
                lanjutkan();
            } else if (pilih == '2')
            {
                menampilkan_produk();
                lanjutkan();
            } else if (pilih == '3')
            {
                update_produk();
                lanjutkan();
            } else if (pilih == '4')
            {
                hapus_produk();
                lanjutkan();
            } else if (pilih == '5')
            {
                cout<< "Jumlah produk saat ini adalah: "<< hitung_jumlah_produk_rekursif(0)<<endl;
                lanjutkan();
            } else if (pilih == '6')
            {
                break;
            }else{
                cout<<"Tidak ada pilihan menu"<<endl;
                lanjutkan();
            }
            

            
            
            
            
        }
        
        
    }
    cout<<"Program telah selesai"<<endl;

    return 0;
}

bool login(){
    int batas_login = 3;
    bool login_berhasil = false;
    while (batas_login > 0)
    {
        string nama,nim;

        cout<<"Masukkan Nama: ";
        getline(cin,nama);
        cout<<"Masukkan NIM: ";
        cin>>nim;
        batas_login--;
        cin.ignore();

        if (nama == "Muhammad Arif Septian" and nim == "2309106046")
        {
            login_berhasil = true;
            break;
        } else{
            if (batas_login != 0)
            {
                cout<< "Sisa login anda tersisa "<< batas_login<<endl;
            } else{
                cout<< "batas login anda telah habis"<<endl;
            }
            
            
        }
        

    }
    return login_berhasil;
    
}

void tampilan_menu(){
    cout<<"1. Menambahkan nama mainan"<<endl;
    cout<<"2. Menampilkan nama mainan"<<endl;
    cout<<"3. Update nama mainan"<<endl;
    cout<<"4. Menghapus nama mainan"<<endl;
    cout<<"5. lihat jumlah mainan"<<endl;
    cout<<"6. Keluar"<<endl;
    cout<<"pilih 1/2/3/4/5/6: ";
}

void tambah_produk(){
    cin.ignore();
    cout<<"Masukkan nama mainan: ";
    getline(cin,dpr[jmlh].mn.nama_mainan);
    cout<<"Masukkan harga mainan: ";
    while (true)
    {
        cin>> dpr[jmlh].hrg.harga;
        if (cin.fail())
        {
            cout<<"Input tidak valid, mohon masukkan harga: ";
            cin.clear();
            cin.ignore();
        }
        else
        {
            break;
        }
        
        
    }
    jmlh++;
    cout<<"Berhasil ditambahkan"<<endl;
}

void menampilkan_produk(){
    if (jmlh > 0)
    {
        cout<<"No "<<"     Nama Mainan "<<"     Harga"<<endl;
        for (int i = 0; i < jmlh; i++)
        {
            cout<<i + 1<<".      "<<dpr[i].mn.nama_mainan<<"              ";
            cout<<dpr[i].hrg.harga<<endl;
        }

        
    }else{
        cout<<"Nama mainan belum ada di data";
    }
    
}

void update_produk(){
    menampilkan_produk();
    if (jmlh > 0)
    {
        cout<<"Masukkan urutan nama yang ingin di update: ";
        cin>>indeks;
        if (indeks <= jmlh && indeks > 0)
        {
            cin.ignore();
            cout<<"Masukkan nama mainan: ";
            getline(cin, dpr[indeks - 1].mn.nama_mainan);
            cout<<"Data berhasil di update";
        } else{
            cout<<"Data tidak ditemukan"; 
        }
    }
    
   
}

void hapus_produk(){
    menampilkan_produk();
    if (jmlh > 0)
    {
        cout<<"Masukkan nama yang ingin dihapus"<<endl;
        cout<<"Masukkan urutan nama mainan: ";
        cin.ignore();
        cin>>indeks;
        if(indeks <= jmlh && indeks > 0){
        for (int i = indeks - 1; i < jmlh; i++)
        {
            dpr[i].mn.nama_mainan = dpr[i + 1].mn.nama_mainan;
        }
        jmlh--;
        cout<<"Data berhasil dihapus";
        } else{
            cout<<"Data tidak ditemukan";
        }
    } 
}

int hitung_jumlah_produk_rekursif(int index) {
    if (index < jmlh) {
        return 1 + hitung_jumlah_produk_rekursif(index + 1);
    }
    return 0;
}