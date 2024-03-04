#include <iostream>
#include <cstdlib>
using namespace std;

void menu_konversi()
{
    cout << "1. Konversi Kilometer/jam ke (Centimeter/detik, Meter/detik, Mil/jam)" << endl;
    cout << "2. Konversi Centimeter/detik ke (Kilometer/jam, Meter/detik, Mil/jam)" << endl;
    cout << "3. Konversi Meter/detik ke (Kilometer/jam, Meter/detik, Mil/jam)" << endl;
    cout << "4. Konversi Mil/jam ke (Kilometer/jam, Centimeter/detik, Meter/detik)" << endl;
    cout << "Pilih dari salah satu pilihan di atas (1/2/3/4): ";
}

float kilometer_ke_centimeter(float kilometer)
{
    return (kilometer * 100000) / 3600;
}

float kilometer_ke_meter(float kilometer)
{
    return (kilometer * 1000) / 3600;
}

float kilometer_ke_mil(float kilometer)
{
    return kilometer * 0.621371;
}

float centimeter_ke_kilometer(float centimeter)
{
    return centimeter * 3600 / 100000;
}

float centimeter_ke_meter(float centimeter)
{
    return centimeter / 100;
}

float centimeter_ke_mil(float centimeter)
{
    return (centimeter * 3600) / 160934;
}

float meter_ke_kilometer(float meter)
{
    return meter * 3600 / 1000;
}

float meter_ke_centimeter(float meter)
{
    return meter * 100;
}

float meter_ke_mil(float meter)
{
    return meter * 3600 / 1609.34;
}

float mil_ke_kilometer(float mil)
{
    return mil / 0.621371;
}

float mil_ke_centimeter(float mil)
{
    return mil * 160934 / 3600;
}

float mil_ke_meter(float mil)
{
    return mil * 1609.34 / 3600;
}

int main()
{
    string nama, nim;
    int batas_login = 3;
    float kecepatan;

    while (batas_login > 0)
    {
        cout << "Masukkan nama: ";
        getline(cin, nama);

        cout << "Masukkan NIM: ";
        cin >> nim;
        cin.ignore();

        if (nama == "Muhammad Arif Septian" and nim == "2309106046")
        {
            char lanjut_program;
            while (true)
            {
                string pilih;
                system("cls");
                menu_konversi();
                cin >> pilih;

                if (pilih == "1")
                {   
                    system("cls");
                    cout << "Masukkan Kilometer/jam: ";
                    cin >> kecepatan;
                    cout << "Kilometer/jam ke Centimeter/detik: " << kilometer_ke_centimeter(kecepatan) << endl;
                    cout << "Kilometer/jam ke Meter/detik: " << kilometer_ke_meter(kecepatan) << endl;
                    cout << "Kilometer/jam ke Mil/jam: " << kilometer_ke_mil(kecepatan) << endl;
                    cout << "Ingin melanjutkan program (ketik y jika ingin lanjut): ";
                    cin >> lanjut_program;
                    if (lanjut_program == 'y')
                    {
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
                else if (pilih == "2")
                {
                    system("cls");
                    cout << "Masukkan Centimeter/detik: ";
                    cin >> kecepatan;
                    cout << "Centimeter/detik ke Kilometer/jam: " << centimeter_ke_kilometer(kecepatan) << endl;
                    cout << "Centimeter/detik ke Meter/detik: " << centimeter_ke_meter(kecepatan) << endl;
                    cout << "Centimeter/detik ke mil/jam: " << centimeter_ke_mil(kecepatan) << endl;
                    cout << "Ingin melanjutkan program (ketik y jika ingin lanjut): ";
                    cin >> lanjut_program;
                    if (lanjut_program == 'y')
                    {
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
                else if (pilih == "3")
                {
                    system("cls");
                    cout << "Masukkan Meter/detik: ";
                    cin >> kecepatan;
                    cout << "Meter/detik ke Kilometer/jam: " << meter_ke_kilometer(kecepatan) << endl;
                    cout << "Meter/detik ke Centimeter/detik: " << meter_ke_centimeter(kecepatan) << endl;
                    cout << "Meter/detik ke Mil/jam: " << meter_ke_mil(kecepatan) << endl;
                    cout << "Ingin melanjutkan program (ketik y jika ingin lanjut): ";
                    cin >> lanjut_program;
                    if (lanjut_program == 'y')
                    {
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
                else if (pilih == "4")
                {
                    system("cls");
                    cout << "Masukkan Mil/jam: ";
                    cin >> kecepatan;
                    cout << "Mil/detik ke Kilometer/jam: " << mil_ke_kilometer(kecepatan) << endl;
                    cout << "Mil/detik ke Centimeter/detik: " << mil_ke_centimeter(kecepatan) << endl;
                    cout << "Mil/detik ke meter/detik: " << mil_ke_meter(kecepatan) << endl;
                    cout << "Ingin melanjutkan program (ketik y jika ingin lanjut): ";
                    cin >> lanjut_program;
                    if (lanjut_program == 'y')
                    {
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    system("cls");
                    cout << "Pilihan tidak ada di menu"<<endl;
                    cout << "Ingin melanjutkan program (ketik y jika ingin lanjut): ";
                    cin >> lanjut_program;
                    if (lanjut_program == 'y')
                    {
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            break;
        }
        else
        {
            cout << "Nama atau NIM yang anda masukkan salah" << endl;
            batas_login--;
            if (batas_login == 0)
            {
                cout << "Kesempatan login anda telah habis" << endl;
            }
            else
            {
                cout << "Sisa kesempatan login anda sisa " << batas_login << endl;
            }
        }
    }
    system("cls");
    cout << "Program telah selesai :v";

    return 0;
}