#include <iostream>
using namespace std;
#include <cctype>

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

bool cek_string_kosong(string& str) {
    for (char c : str) {
        if (!isspace(c)) {
            return false;
        }
    }
    return true;
}

bool login();

void tampilan_menu();

void tambah_produk(data_produk* ptr_produk);

void menampilkan_produk();

void update_produk();

void hapus_produk();

int hitung_jumlah_produk_rekursif(int index);

void bubble_sort_descending(data_produk arr[], int n);

void swap(data_produk& a, data_produk& b);

void selection_sort_ascending(data_produk arr[], int n);


int partition(data_produk arr[], int low, int high);

void quick_sort_ascending(data_produk arr[], int low, int high);

void menu_sorting();

int sequential_search(data_produk arr[], int n, string target);

void pencarian_ascending();

int binary_search(data_produk arr[], int n, string target);

void pencarian_descending();

void menu_searching();






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
                tambah_produk(&dpr[jmlh]);
                lanjutkan();
            } else if (pilih == '2')
            {
                menu_sorting();
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
                menu_searching();
                lanjutkan();
            } else if (pilih == '7')
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
    cout<<"6. searching"<<endl;
    cout<<"7. Keluar"<<endl;
    cout<<"pilih 1/2/3/4/5/6/7: ";
}

void tambah_produk(data_produk* ptr_produk){
    cin.ignore();
    while(true){
        cout<<"Masukkan nama mainan: ";
        getline(cin,ptr_produk->mn.nama_mainan);
        if (ptr_produk->mn.nama_mainan.empty() or cek_string_kosong(ptr_produk->mn.nama_mainan)){
            cout<<"Input tidak boleh kosong"<<endl;
        }
        else{
            break;
        }
        }
    cout<<"Masukkan harga mainan: ";
    while (true)
    {
        cin>> ptr_produk->hrg.harga;
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

void bubble_sort_descending(data_produk arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j].mn.nama_mainan < arr[j + 1].mn.nama_mainan) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void swap(data_produk& a, data_produk& b) {
    data_produk temp = a;
    a = b;
    b = temp;
}


void selection_sort_ascending(data_produk arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j].hrg.harga < arr[min_index].hrg.harga) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap(arr[i], arr[min_index]);
        }
    }
}


int partition(data_produk arr[], int low, int high) {
    string pivot = arr[high].mn.nama_mainan;
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j].mn.nama_mainan < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quick_sort_ascending(data_produk arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort_ascending(arr, low, pi - 1);
        quick_sort_ascending(arr, pi + 1, high);
    }
}


void menu_sorting(){
    char pilih;
    cout << "1. Menu default" << endl;
    cout << "2. Mengurutkan nama produk secara descending" << endl;
    cout << "3. Mengurutkan harga produk secara ascending" << endl;
    cout << "4. Mengurutkan nama produk secara ascending" << endl;
    cout << "Pilih 1/2/3/4: ";
    cin >> pilih;

    if (pilih == '1') {
        cin.ignore();
        menampilkan_produk();
    } else if (pilih == '2') {
        cin.ignore();
        bubble_sort_descending(dpr, jmlh);
        menampilkan_produk();
    } else if (pilih == '3') {
        cin.ignore();
        selection_sort_ascending(dpr, jmlh);
        menampilkan_produk();
    } else if (pilih == '4') {
        cin.ignore();
        quick_sort_ascending(dpr, 0, jmlh - 1);
        menampilkan_produk();
    } else {
        return;
    }
}

int sequential_search(data_produk arr[], int n, string target) {
    for (int i = 0; i < n; ++i) {
        if (arr[i].mn.nama_mainan == target) {
            return i;
        }
    }
    return -1; 
}

void pencarian_ascending(){
    quick_sort_ascending(dpr, 0, jmlh - 1);
    string target;
    cout << "\nMasukkan nama mainan yang ingin dicari: ";
    cin.ignore();
    getline(cin, target);
    int index = sequential_search(dpr, jmlh, target);
    if (index != -1) {
         cout << "Mainan " << target << " ditemukan pada indeks: " << index << endl;
        cout<<"Nama Mainan "<<"     Harga"<<endl;
        cout<<dpr[index].mn.nama_mainan<<"              ";
        cout<<dpr[index].hrg.harga<<endl;
    } else {
        cout << "Mainan " << target << " tidak ditemukan." << endl;
    }
}


int binary_search(data_produk arr[], int n, string target) {
    int low = 0;
    int high = n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
    
        if (arr[mid].mn.nama_mainan == target) {
            return mid;
        }
        else if (arr[mid].mn.nama_mainan > target) {
            high = mid - 1;
        }
    
        else {
            low = mid + 1;
        }
    }
    
    return -1;
}   

void pencarian_descending(){
    bubble_sort_descending(dpr, jmlh);{
    string target;
    cout << "\nMasukkan nama mainan yang ingin dicari: ";
    cin.ignore();
    getline(cin, target);
    int index = binary_search(dpr, jmlh, target);
    if (index != -1) {
        cout << "Mainan " << target << " ditemukan pada indeks: " << index << endl;
        cout<<"Nama Mainan "<<"     Harga"<<endl;
        cout<<dpr[index].mn.nama_mainan<<"              ";
        cout<<dpr[index].hrg.harga<<endl;
        
    } else {
        cout << "Mainan " << target << " tidak ditemukan." << endl;
    }
}
}

void menu_searching(){
    char pilih;
    cout<<"1."<<"searching nama produk secara ascending"<<endl;
    cout<<"2."<<"searching nama produk secara descending"<<endl;
    cout<<"pilih 1/2: ";
    cin>>pilih;

    if (pilih == '1')
    {
        pencarian_ascending();
    } else if (pilih == '2')
    {
        pencarian_descending();
    } else{
        return;
    }
}