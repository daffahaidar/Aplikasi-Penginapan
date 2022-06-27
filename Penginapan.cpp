/*
    kalo ada yang ditanyakan hubungi aja line daffa.h.n.zufar_27
    aku saranin bukanya pake dev c++ atau visual studio code
    trus biar maksimal outpunya di maximize aja biar gk kepotong tabelnya
*/

#include <iostream> // library input dan output di c++
#include <conio.h>  // library ini untuk mengambil inputan keyboard (opsional bisa dihapus)
#include <stdlib.h> // library ini aku pake buat manggil fungsi getch() (buat pause consolnya)
#include <string.h> // library ini aku pake buat manipulasi string

// ini aku maksimal datanya di set 100 aja ya (bisa diganti kok)
#define MAX_SIZE 100

// ini aku pake namespace biar gk ngetik std:: satu satu di cout sama cin nya
using namespace std;

// global variable
int id[MAX_SIZE]; // ini buat nampung id

// untuk stringnya aku pake array of char ya
char nama[MAX_SIZE][50];   // ini buat nampung nama maksimal 50 karakter
char alamat[MAX_SIZE][50]; // ini buat nampung alamat maksimal 50 karakter
char no_hp[MAX_SIZE][15];  // no hp aku bikin char aja soalnya bisa jadi si user inputin +62
char room[MAX_SIZE][50];   // ini buat nampung room maksimal 50 karakter
int harga[MAX_SIZE];       // ini buat nampung harga
int jumlah_data = 0;       // jumlah data awalnya aku set kosong ya

// aku bikin function prototype biar mainnya bisa ditaro sebelum function
void menu();           // function untuk menu utama
void addData();        // function untuk add data
void showData();       // function untuk show data
void updateData();     // function untuk update data
void deleteData();     // function untuk delete data
void deleteAllData();  // function untuk delete all data
void deleteDataById(); // function untuk delete data by id
void searchData();     // function untuk search data
void sortData();       // function untuk sort data
void sortDataAsc();    // function untuk sort data ascending
void sortDataDesc();   // function untuk sort data descending
void line();           // function untuk garis tabel

// ini function yang akan dijalankan pertama kali oleh compilernya
int main()
{
    // aku panggil function menu
    menu();
}

// ini function untuk menu utama
void menu()
{
    int pilihan;

    // disini aku pake do while biar pad udah milih bisa balik lagi ke menu
    do
    {
        // aku bersiin dulu layarnya
        system("cls");

        // trus aku tampilin pilihan menunya
        cout << "==============================" << endl;
        cout << "      APLIKASI PENGINAPAN" << endl;
        cout << "==============================" << endl;
        cout << "1. Sewa Kamar" << endl;
        cout << "2. Lihat Data" << endl;
        cout << "3. Edit Pesanan" << endl;
        cout << "4. Cari Data Pesanan" << endl;
        cout << "5. Urutkan Data Pesanan" << endl;
        cout << "6. Hapus Data Pesanan" << endl;
        cout << "7. Keluar" << endl;

        // aku suruh usernya milih mau menu apa
        cout << "\nMasukan Pilihan Anda: ";
        cin >> pilihan;

        // untuk percabangannya aku pake switch case ya
        switch (pilihan)
        {
        // jika user pilih 1
        case 1:
            // maka aku panggil function add data
            addData();
            getch(); // getch ini fungsi buat pause consolnya ya biar gk langsung keluar programnya
            break;
        // jika user pilih 2
        case 2:
            // maka aku panggil function show data
            showData();
            getch();
            break;
        // jika user pilih 3
        case 3:

            updateData();
            break;
        // jika user pilih 4
        case 4:
            // maka aku panggil function search data
            searchData();
            break;
        // jika user pilih 5
        case 5:
            // maka aku panggil function sort data
            sortData();
            break;
        // jika user pilih 6
        case 6:
            // maka aku panggil function delete data
            deleteData();
            getch();
            break;
        // jika user pilih 7
        case 7:
            // maka aku keluarin deh programnya
            system("cls");
            cout << "\nTerima Kasih Telah Menggunakan Aplikasi Penginapan" << endl;
            getch();
            break;

        // ini kalo usernya ngeyel inputin macem macem
        default:
            cout << "Pilihan tidak ada" << endl;
            getch();
        }
    } while (pilihan != 7); // selama pilihannya gk 7 maka jangan keluarin programnya
}

// ini function buat nambahin data (sewa kamar)
void addData()
{
    // aku buat variable baru untuk pilihan tipe kamarnya
    int tipe;

    // disini aku pake pengkondisian
    // kalo jumlah datanya belom mencapai 100 (MAX DATA) data bisa ditambahin lagi
    if (jumlah_data < MAX_SIZE)
    {
        system("cls"); // ini buat clear consolenya biar rapi aja

        // trus aku suruh si user milih tipe kamarnya mau apa
        cout << "TIPE KAMAR: " << endl;
        cout << "1. Single Room (Rp. 100.000)" << endl;
        cout << "2. Double Room (Rp. 200.000)" << endl;
        cout << "3. Triple Room (Rp. 300.000)" << endl;
        cout << "\nMasukan Pilihan Kamar: ";

        // pilihan si user akan dimasukin ke variabel tipe
        // inputnya harus berupa angka ya, gaboleh string soalnya aku pake tipe data integer
        // kalo maksa pake string atau char programnya bakal error
        cin >> tipe;

        // (Ini tranversal pertama ya)
        // jika pilihannya 1
        if (tipe == 1)
        {
            // maka tipe kamar akan di set dengan "Single Room"
            strcpy(room[jumlah_data], "Single Room");
            // dan harganya akan di set dengan 100000
            harga[jumlah_data] = 100000;
            // (ini Tranversal kedua ya)
            // Jadi aku set dulu idnya setiap pertambahan data akan ditambah 1
            id[jumlah_data] = jumlah_data + 1;
            // disini user masukin nama
            cout << "\nMasukan Nama: ";
            cin >> nama[jumlah_data];
            // disini user masukin alamat
            cout << "Masukan Alamat: ";
            cin >> alamat[jumlah_data];
            // disini user masukin no hp
            cout << "Masukan No. Telp: ";
            cin >> no_hp[jumlah_data];
            // trus si jumlah datanya tambahin soalnya data yang diinput udah masuk
            jumlah_data++;
            // biar lebih jelas aku tampilin lagi pake ini
            cout << "\nKamar berhasil disewa!" << endl;
        }

        // jika pilihannya 2
        else if (tipe == 2)
        {
            // maka tipe kamar akan di set dengan "Double Room"
            strcpy(room[jumlah_data], "Double Room");
            // dan harganya akan di set dengan 200000
            harga[jumlah_data] = 200000;
            // (ini Tranversal kedua ya)
            // Jadi aku set dulu idnya setiap pertambahan data akan ditambah 1
            id[jumlah_data] = jumlah_data + 1;
            // disini user masukin nama
            cout << "\nMasukan Nama: ";
            cin >> nama[jumlah_data];
            // disini user masukin alamat
            cout << "Masukan Alamat: ";
            cin >> alamat[jumlah_data];
            // disini user masukin no hp
            cout << "Masukan No. Telp: ";
            cin >> no_hp[jumlah_data];
            // trus si jumlah datanya tambahin soalnya data yang diinput udah masuk
            jumlah_data++;
            // biar lebih jelas aku tampilin lagi pake ini
            cout << "\nKamar berhasil disewa!" << endl;
        }

        // jika pilihannya 3
        else if (tipe == 3)
        {
            // maka tipe kamar akan di set dengan "Triple Room"
            strcpy(room[jumlah_data], "Triple Room");
            // dan harganya akan di set dengan 300000
            harga[jumlah_data] = 300000;
            // (ini Tranversal kedua ya)
            // Jadi aku set dulu idnya setiap pertambahan data akan ditambah 1
            id[jumlah_data] = jumlah_data + 1;
            // disini user masukin nama
            cout << "\nMasukan Nama: ";
            cin >> nama[jumlah_data];
            // disini user masukin alamat
            cout << "Masukan Alamat: ";
            cin >> alamat[jumlah_data];
            // disini user masukin no hp
            cout << "Masukan No. Telp: ";
            cin >> no_hp[jumlah_data];
            // trus si jumlah datanya tambahin soalnya data yang diinput udah masuk
            jumlah_data++;
            // biar lebih jelas aku tampilin lagi pake ini
            cout << "\nKamar berhasil disewa!" << endl;
        }

        // jika inpunya aneh aneh
        else
        {
            // maka aku tampilin aja pesan kek gini
            cout << "Pilihan tidak ada" << endl;
        }
    }

    // Jika datanya melebihi kapasitas (MAX DATA)
    else
    {
        // aku tampilin aja kata ini
        cout << "Data sudah penuh!" << endl;
    }
}

// ini function buat nampilin data
void showData()
{
    // aku bersiin dulu layarnya
    system("cls");
    // aku tambahin garis tabel biar rapi
    line();
    // nah ini aku printnya pake format tabel ya biar enak diliatnya
    printf("|%3s|%15s|%15s|%15s|%15s|%10s|\n", "Id", "Nama", "Alamat", "Phone", "Tipe Kamar", "Harga");
    line();

    // jika gk ada data di arraynya
    if (jumlah_data == 0)
    {
        // maka aku tampilin aja kata ini
        cout << "\nData Kosong!" << endl;
    }
    // kalo datanya gk kosong
    else
    {
        // aku tampilin datanya pake looping soalnya ini array
        for (int i = 0; i < jumlah_data; i++)
        {
            // seperti biasa aku tampilin lagi pake format table
            printf("|%3d|%15s|%15s|%15s|%15s|%10d|\n", id[i], nama[i], alamat[i], no_hp[i], room[i], harga[i]);
        }
    }
    line();
    // disini aku tampilin sisa kamar yang kosongnya (bisa dihapus sih klo gk perlu)
    cout << "\nMasih tersedia " << MAX_SIZE - jumlah_data << " kamar lagi yang kosong!" << endl;
    cout << "\n\nKembali ke menu ";
}

// ini function buat update data
void updateData()
{
    // update data ini kita perlu searching dulu data mana yang ingin di update
    // makanya aku buat variable sementara
    int id_update;
    int found = 0; // found ini klo nilainya 1 artinya datanya ketemu kalo 0 gak ketemu
    int updateTipe;

    system("cls");
    // aku suruh user masukin id data yang ingin di update
    cout << "Masukan no Id yang ingin diubah: ";
    cin >> id_update;

    // aku cari datanya pake looping
    for (int i = 0; i < jumlah_data; i++)
    {
        // jika datanya ketemu
        if (id[i] == id_update)
        {
            // aku kasih tau ke variable datanya udah ketemu
            found = 1;

            // tinggal update deh, prosesnya sama kaya input data
            // cuma bedanya yang dimasukin ke array bukan jumlah data tapi variabel i yang ada di looping
            cout << "\nTIPE KAMAR: " << endl;
            cout << "1. Single Room (Rp. 100.000)" << endl;
            cout << "2. Double Room (Rp. 200.000)" << endl;
            cout << "3. Triple Room (Rp. 300.000)" << endl;
            cout << "\nMasukan Pilihan Kamar: ";
            cin >> updateTipe;

            if (updateTipe == 1)
            {
                strcpy(room[i], "Single Room");
                harga[i] = 100000;
                cout << "Nama: ";
                cin >> nama[i];
                cout << "Alamat: ";
                cin >> alamat[i];
                cout << "No. Telp: ";
                cin >> no_hp[i];

                cout << "\nData pesanan berhasil diupdate!" << endl;
                getch();
            }
            else if (updateTipe == 2)
            {
                strcpy(room[i], "Double Room");
                harga[i] = 200000;
                cout << "Nama: ";
                cin >> nama[i];
                cout << "Alamat: ";
                cin >> alamat[i];
                cout << "No. Telp: ";
                cin >> no_hp[i];

                cout << "\nData pesanan berhasil diupdate!" << endl;
                getch();
            }
            else if (updateTipe == 3)
            {
                strcpy(room[i], "Triple Room");
                harga[i] = 300000;
                cout << "Nama: ";
                cin >> nama[i];
                cout << "Alamat: ";
                cin >> alamat[i];
                cout << "No. Telp: ";
                cin >> no_hp[i];

                cout << "\nData pesanan berhasil diupdate!" << endl;
                getch();
            }
            // lagi lagi ini buat user yang inputannya ngeyel
            else
            {
                cout << "Pilihan tidak ada" << endl;
                getch();
            }
        }
    }
    // jika datanya gak ketemu
    if (found == 0)
    {
        // maka aku tampilin pesan kek gini
        cout << "Id " << id_update << " tidak ditemukan!" << endl;
        getch();
    }
}

// ini function buat nyari data
void searchData()
{
    int searchChoice;

    system("cls");

    // aku kasih 2 pilihan metode pencarian
    cout << "Cari data berdasarkan:" << endl;
    cout << "1. Nama" << endl;
    cout << "2. Id" << endl;
    cout << "Pilihan: ";
    cin >> searchChoice;

    // jika pilihan 1
    if (searchChoice == 1)
    {
        // aku cari datanya berdasarkan nama yang diinputin user
        char nama_cari[50];
        int foundname = 0; // found ini klo nilainya 1 artinya datanya ketemu kalo 0 gak ketemu
        system("cls");
        // aku suruh user masukin nama yang ingin dicari
        cout << "Masukan Nama yang ingin dicari: ";
        cin >> nama_cari;
        // aku cari datanya pake looping
        for (int i = 0; i < jumlah_data; i++)
        {
            // jika datanya ketemu
            if (strcmp(nama[i], nama_cari) == 0) // strcmp ini fungsinya buat ngecocokin string ya
            {
                // aku ubah variabel foundnya ke 1
                foundname = 1;
                system("cls");
                // dan aku tampilin deh datanya
                cout << "Nama Ditemukan!" << endl;
                line();
                printf("|%3s|%15s|%15s|%15s|%15s|%10s|\n", "Id", "Nama", "Alamat", "Phone", "Tipe Kamar", "Harga");
                line();
                printf("|%3d|%15s|%15s|%15s|%15s|%10d|\n", id[i], nama[i], alamat[i], no_hp[i], room[i], harga[i]);
                line();
            }
        }
        // jika datanya gak ketemu
        if (foundname == 0)
        {
            // maka aku tampilin pesan kek gini
            cout << "Nama tidak ditemukan!" << endl;
        }
        cout << "\nKembali ke menu ";
        getch();
    }
    // jika pilihan usernya 2
    else if (searchChoice == 2)
    {
        // aku cari datanya berdasarkan id yang diinputin user
        // caranya sama aja si kaya search nama cuma bedanya idnya yang dicari
        int id_cari;
        int foundId = 0;
        system("cls");
        cout << "Masukan Nomor Id yang ingin dicari: ";
        cin >> id_cari;
        for (int i = 0; i < jumlah_data; i++)
        {
            if (id[i] == id_cari)
            {
                foundId = 1;
                system("cls");
                cout << "Nama dengan Id " << id_cari << " Ditemukan!" << endl;
                line();
                printf("|%3s|%15s|%15s|%15s|%15s|%10s|\n", "Id", "Nama", "Alamat", "Phone", "Tipe Kamar", "Harga");
                line();
                printf("|%3d|%15s|%15s|%15s|%15s|%10d|\n", id[i], nama[i], alamat[i], no_hp[i], room[i], harga[i]);
                line();
            }
        }
        if (foundId == 0)
        {
            cout << "Nama dengan Id " << id_cari << " tidak ditemukan!" << endl;
        }
        cout << "\nKembali ke menu ";
        getch();
    }
}

// ini function buat sorting data
void sortData()
{
    int sortChoice;

    system("cls");
    // lagi lagi aku kasih 2 pilihan metode sorting ke user
    cout << "Urutkan data secara:" << endl;
    cout << "1. Ascending [A-Z]" << endl;
    cout << "2. Descending [Z-A]" << endl;
    cout << "Pilihan: ";
    cin >> sortChoice;

    // kalo user milih 1
    if (sortChoice == 1)
    {
        // maka aku sorting datanya dari A-Z (ascending) dengan manggil function sortDataAsc
        sortDataAsc();
        cout << "\nData berhasil diurutkan secara ascending [A-Z]!" << endl;
        getch();
    }
    // kalo user milih 2
    else if (sortChoice == 2)
    {
        // maka aku sorting datanya dari Z-A (descending) dengan manggil function sortDataDesc
        sortDataDesc();
        cout << "\nData berhasil diurutkan secara descending [Z-A]!" << endl;
        getch();
    }
    // kalo user milihnya ngeyel
    else
    {
        // aku kasih tau lagi
        cout << "Pilihan tidak ada!" << endl;
        getch();
    }
}

// ini function buat sorting data ascending
void sortDataAsc()
{
    // ini aku pake sorting merge sort
    // aku bikin variable sementara
    int i, j, k;
    int n = jumlah_data;
    char temp[50];
    char temp2[50];
    char temp3[50];
    int temp4;

    // ini algoritma buat merge sort ya kalo gak tau algoritma ini bisa dibaca di google kok
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            // aku compare dulu string namanya karena aku mau ngurutin berdasarkan nama
            if (strcmp(nama[j], nama[j + 1]) > 0)
            {
                // abis itu aku copy semua stringnya ke variable sementara
                strcpy(temp, nama[j]);
                strcpy(nama[j], nama[j + 1]);
                strcpy(nama[j + 1], temp);
                // alamanya juga aku copy biar sama kya nama yang diurutin
                strcpy(temp2, alamat[j]);
                strcpy(alamat[j], alamat[j + 1]);
                strcpy(alamat[j + 1], temp2);
                // aku copy no hp juga
                strcpy(temp3, no_hp[j]);
                strcpy(no_hp[j], no_hp[j + 1]);
                strcpy(no_hp[j + 1], temp3);
                // abis itu aku masukin deh ke array
                temp4 = id[j];
                id[j] = id[j + 1];
                id[j + 1] = temp4;

                strcpy(temp, room[j]);
                strcpy(room[j], room[j + 1]);
                strcpy(room[j + 1], temp);

                temp4 = harga[j];
                harga[j] = harga[j + 1];
                harga[j + 1] = temp4;
            }
        }
    }
}

// ini function buat sorting data descending
void sortDataDesc()
{
    //  sama ini juga aku pakenya algoritma merge sort
    int i, j, k;
    int n = jumlah_data;
    char temp[50];
    char temp2[50];
    char temp3[50];
    int temp4;

    // bedanya proses sortingnya aku balikin dari Z ke A
    for (i = 1; i < n; i++)
    {
        // intinya untuk sorting ini aku banyak pake strcmp sama strcpy buat manipulasi stringnya
        j = i - 1;
        strcpy(temp, nama[i]);
        strcpy(temp2, alamat[i]);
        strcpy(temp3, no_hp[i]);
        temp4 = id[i];
        strcpy(room[i], room[i]);
        harga[i] = harga[i];

        while ((j >= 0) && (strcmp(nama[j], temp) < 0))
        {
            strcpy(nama[j + 1], nama[j]);
            strcpy(alamat[j + 1], alamat[j]);
            strcpy(no_hp[j + 1], no_hp[j]);
            id[j + 1] = id[j];
            strcpy(room[j + 1], room[j]);
            harga[j + 1] = harga[j];
            j = j - 1;
        }
        strcpy(nama[j + 1], temp);
        strcpy(alamat[j + 1], temp2);
        strcpy(no_hp[j + 1], temp3);
        id[j + 1] = temp4;
        strcpy(room[j + 1], room[i]);
        harga[j + 1] = harga[i];
    }
}

// ini function buat ngehapus data
void deleteData()
{
    system("cls");
    int deleteChoice;

    // aku kasih user 2 pilihan metode hapus data
    cout << "Pilih metode penghapusan data:" << endl;
    cout << "1. Hapus Berdasarkan Id" << endl;
    cout << "2. Hapus Semua Data" << endl;
    cout << "Pilihan: ";
    cin >> deleteChoice;

    // kalo user milih 1
    if (deleteChoice == 1)
    {
        // aku panggil function deleteDataById (hapus berdasarkan id yang dicari)
        deleteDataById();
    }
    // kalo user milih 2
    else if (deleteChoice == 2)
    {
        // aku panggil function deleteAllData (hapus semua data)
        deleteAllData();
    }
    // kalo user milihnya ngeyel
    else
    {
        // aku kasih tau lagi
        cout << "Pilihan tidak ada!" << endl;
        getch();
    }
}

// ini function buat ngehapus semua data
void deleteAllData()
{
    char confirm;

    system("cls");
    // kalo mau ngehapus semua data aku konfirmasi dulu setuju nggaknya
    cout << "Apakah anda yakin ingin menghapus semua data? [Y/N]: ";
    cin >> confirm;

    // kalo setuju
    if (confirm == 'Y' || confirm == 'y')
    {
        // maka aku kunjungi setiap arraynya (Tranversal) pake looping
        for (int i = 0; i < jumlah_data; i++)
        {
            // dan aku hapus semua datanya dengan ngosongin semua arraynya
            id[i] = 0;
            strcpy(nama[i], "");
            strcpy(alamat[i], "");
            strcpy(no_hp[i], "");
            strcpy(room[i], "");
            harga[i] = 0;
        }
        // jangan lupa jumlah datanya juga harus di reset ke 0
        jumlah_data = 0;
        cout << "\nSemua data berhasil dihapus!" << endl;
        getch();
    }

    // kalo user gk setuju buat dihapus
    else
    {
        // maka data gk akan dihapus dan aku tampilin pesan kya gini
        cout << "Data tidak jadi dihapus!" << endl;
        getch();
    }
}

// ini function buat ngehapus data berdasarkan id
void deleteDataById()
{
    int id_hapus;
    // kalo ngehapus berdasarkan id otomatis datanya harus kita cari dulu makanya aku bikin foundId
    int foundId = 0; // found ini klo nilainya 1 artinya datanya ketemu kalo 0 gak ketemu
    system("cls");

    // aku suruh user masukin id yang akan dihapus
    cout << "Masukan nomor Id yang ingin dihapus: ";
    cin >> id_hapus;

    // seperti biasa kita pake tranversal lagi untuk cari datanya
    for (int i = 0; i < jumlah_data; i++)
    {
        // kalo idnya ketemu
        if (id[i] == id_hapus)
        {
            // aku set foundId nya dengan 1
            foundId = 1;
            system("cls");
            // aku tampilin dulu datanya bener gk data ini yang akan dihapus
            cout << "Data dengan Id " << id_hapus << " Ditemukan!" << endl;
            line();
            printf("|%3s|%15s|%15s|%15s|%15s|%10s|\n", "Id", "Nama", "Alamat", "Phone", "Tipe Kamar", "Harga");
            line();
            printf("|%3d|%15s|%15s|%15s|%15s|%10d|\n", id[i], nama[i], alamat[i], no_hp[i], room[i], harga[i]);
            line();
            // makanya aku kasih konfirmasi lagi biar gk salah hapus
            cout << "\nData dengan Id " << id_hapus << " akan dihapus!" << endl;
            cout << "Apakah anda yakin? [Y/N]: ";
            char confirm;
            cin >> confirm;

            // kalo usernya setuju datanya bakal dihapus
            if (confirm == 'Y' || confirm == 'y')
            {
                // yaudah aku hapus datanya berdasarkan id yang dipilih user
                for (int j = i; j < jumlah_data - 1; j++)
                {
                    strcpy(nama[j], nama[j + 1]);
                    strcpy(alamat[j], alamat[j + 1]);
                    strcpy(no_hp[j], no_hp[j + 1]);
                    id[j] = id[j + 1];
                    strcpy(room[j], room[j + 1]);
                    harga[j] = harga[j + 1];
                }
                // jangan lupa jumlah datanya juga harus dikurangi 1
                jumlah_data--;
                cout << "Data berhasil dihapus!" << endl;
                getch();
            }
            // kalo user gk setuju datanya dihapus
            else
            {
                // maka datanya gk akan terhapus dan aku tampilin pesan kya gini
                cout << "Data tidak jadi dihapus!" << endl;
                getch();
            }
        }
    }
    // jika idnya gk ketemu maka
    if (foundId == 0)
    {
        // aku tampilin pesan kya gini
        cout << "Data tidak ditemukan!" << endl;
        getch();
    }
}

// ini function untuk membuat tabel biar gk diketik satu satu garisnya
void line()
{
    // ini aku looping sebanyak panjang tabelnya (aku set 80)
    for (int i = 0; i < 80; i++)
    {
        // ini aku print garisnya pake strip aja (bisa diganti * kok)
        cout << "-";
    }
    // biar ada space kebawahnya aku tambahin baris baru
    cout << endl;
}
