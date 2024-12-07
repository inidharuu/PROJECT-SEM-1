#include <bits/stdc++.h>
using namespace std;

class Pasien;
class Dokter;
class Pendaftaran;
class Penyakit;
class Pembayaran;
class Kefokusan;
class Spesialisasi;

class MainApp
{
private:
    vector<shared_ptr<Pasien>> dataPasien;
    vector<shared_ptr<Pendaftaran>> Daftar;
    time_t tanggalDaftar;
    vector<shared_ptr<Penyakit>> dataPenyakit;
    vector<shared_ptr<Pembayaran>> Payment;
    vector<shared_ptr<Dokter>> dataDokter;
    vector<shared_ptr<Kefokusan>> keFokusan;
    vector<shared_ptr<Spesialisasi>> Spesialis;

public:
    MainApp();
    void addPasien(const string &name, int age, const string tempatTinggal, const string gender);
    void addPendaftaran(string const &keperluan, string const &tanggalDatang);
    void addTanggalDaftar(time_t TglDaftar);
    void addPenyakit(const string &penyakit);
    void addPembayaran(const string &payment, const string &bank, int noRek, const string &namaPemilik, int noBPJS);
    void addDokter(const string &nama, const string &jabatan, int NIP);
    void addSpesialis(const string &spesialis);
    void addKefokusan(const string &kefokusan);
    void inputPasien();
    void inputPendaftaran();
    void inputTanggalDaftar();
    void inputPenyakit();
    void inputPembayaran();
    void inputDokter();
    void inputSpesialis();
    void inputKefokusan();
    void displayPasien() const;
    void displayPendaftaran() const;
    void displayTanggalDaftar();
    void displayPenyakit() const;
    void displayPembayaran() const;
    void displayDokter() const;
    void displayKefokusan() const;
    void displaySpesialis() const;
};

MainApp::MainApp() : dataPasien(), Daftar(), tanggalDaftar(), dataDokter(), dataPenyakit(), Payment(), keFokusan(), Spesialis() {}

/*========== CLASS PASIEN ==========*/
class Pasien
{
private:
    string Nama;
    int Umur;
    string TempatTinggal;
    string Kelamin;

public:
    Pasien(const string name, int age, const string tempatTinggal, const string gender);

    void displayPasien() const;
};

/*========== MAIN PASIEN ==========*/

void MainApp::addPasien(const string &name, int age, const string tempatTinggal, const string gender)
{
    dataPasien.push_back(make_shared<Pasien>(name, age, tempatTinggal, gender));
}

void MainApp::inputPasien()
{
    string name, tempatTinggal, gender;
    int age;

    cin.sync();

    cout << "Masukkan nama pasien: ";
    while (name.empty())
    {
        getline(cin, name);
        if (name.empty())
        {
            cout << "Nama tidak boleh kosong. Masukkan nama pasien: ";
        }
    }

    while (true)
    {
        cout << "Masukkan umur pasien: ";
        if (cin >> age && age > 0)
        {
            cin.ignore();
            break;
        }
        else
        {
            cout << "Input tidak valid. Harap masukkan angka positif." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cout << "Masukkan tempat tinggal pasien: ";
    while (tempatTinggal.empty())
    {
        getline(cin, tempatTinggal);
        if (tempatTinggal.empty())
        {
            cout << "Tempat tinggal tidak boleh kosong. Masukkan tempat tinggal: ";
        }
    }

    cout << "Masukkan jenis kelamin pasien: ";
    while (gender.empty())
    {
        getline(cin, gender);
        if (gender.empty())
        {
            cout << "Jenis kelamin tidak boleh kosong. Masukkan jenis kelamin: ";
        }
    }

    addPasien(name, age, tempatTinggal, gender);
}

void MainApp::displayPasien() const
{

    for (const auto &pasien : dataPasien)
    {
        pasien->displayPasien();
    }
}

Pasien::Pasien(const string name, int age, const string tempatTinggal, const string gender)
    : Nama(name), Umur(age), TempatTinggal(tempatTinggal), Kelamin(gender) {}

void Pasien::displayPasien() const
{
    cout << "\n====== Formulir Pendaftaran ======" << endl;

    cout << "Nama\t\t: " << Nama << endl;
    cout << "Umur\t\t: " << Umur << endl;
    cout << "Tempat Tinggal\t: " << TempatTinggal << endl;
    cout << "Kelamin\t\t: " << Kelamin << endl;
}

/*========== CLASS TANGGAL DAFTAR ==========*/
class TanggalDaftar
{
private:
    time_t TglDaftar;

public:
    TanggalDaftar(time_t tglDaftar);

    void displayTanggalDaftar();
};

/*========== MAIN TANGGAL DAFTAR ==========*/
void MainApp::addTanggalDaftar(time_t TglDaftar)
{
}

void MainApp::inputTanggalDaftar()
{
    time_t Tgldaftar = time(nullptr);

    tm *waktuLokal = localtime(&Tgldaftar);

    addTanggalDaftar(Tgldaftar);
}

void MainApp::displayTanggalDaftar()
{
    time_t Tgldaftar = time(nullptr);

    // Konversi ke struktur tm (time)
    tm *waktuLokal = localtime(&Tgldaftar);

    // Tampilkan tanggal
    cout << "Tanggal Daftar\t: ";
    cout << waktuLokal->tm_mday << "-"
         << (waktuLokal->tm_mon + 1) << "-"
         << (waktuLokal->tm_year + 1900) << endl;
}

TanggalDaftar::TanggalDaftar(time_t Tgldaftar)
    : TglDaftar(Tgldaftar) {}

/*========== CLASS PENDAFTARAN ==========*/
class Pendaftaran
{
private:
    string Keperluan;
    string TanggalDatang;

public:
    Pendaftaran(string const &keperluan, string const &tanggalDatang);
    void displayPendaftaran() const;
};

/*========== MAIN PENDAFTARAN ==========*/
void MainApp::addPendaftaran(const string &keperluan, string const &tanggalDatang)
{
    Daftar.push_back(make_shared<Pendaftaran>(keperluan, tanggalDatang));
}

void MainApp::inputPendaftaran()
{
    string keperluan, tglDatang;

    cout << "\nKeperluan : " << endl;
    cout << "=> Kontrol" << endl;
    cout << "=> Periksa " << endl;
    cin >> keperluan;
    cin.ignore();
    if (keperluan == "Kontrol" || keperluan == "kontrol")
    {
        cout << "Masukkan tanggal kontrol: ";
    }
    else if (keperluan == "Periksa" || keperluan == "periksa")
    {
        cout << "Masukkan tanggal periksa: ";
    }
    else
    {
        cout << "\nKeperluan tidak ditemukan" << endl;
        terminate();
    }
    cin >> tglDatang;
    cin.ignore();

    addPendaftaran(keperluan, tglDatang);
}

void MainApp::displayPendaftaran() const
{
    for (const auto &keperluan : Daftar)
    {
        keperluan->displayPendaftaran();
    }
}
Pendaftaran::Pendaftaran(const string &keperluan, string const &tanggalDatang)
    : Keperluan(keperluan), TanggalDatang(tanggalDatang) {}

void Pendaftaran::displayPendaftaran() const
{
    cout << "Keperluan\t: " << Keperluan << endl;
    cout << "Tanggal Datang\t: " << TanggalDatang << endl;
}

/*========== CLASS PENYAKIT ==========*/
class Penyakit
{
private:
    string penyakit;

public:
    Penyakit(const string &disease);

    void displayPenyakit() const;
};

/*========== MAIN PENYAKIT ==========*/

void MainApp::addPenyakit(const string &penyakit)
{
    dataPenyakit.push_back(make_shared<Penyakit>(penyakit));
}

void MainApp::inputPenyakit()
{
    string penyakit;

    cout << "\n=> Umum" << endl;
    cout << "=> Internis" << endl;
    cout << "Pilih penyakit anda: ";
    cin >> penyakit;
    cin.ignore();

    if (penyakit != "Umum" && penyakit != "umum" && penyakit != "Internis" && penyakit != "internis")
    {
        cout << "\nPenyakit tidak ditemukan" << endl;
        terminate();
    }
    else
    {
    }

    addPenyakit(penyakit);
}

void MainApp::displayPenyakit() const
{

    for (const auto &penyakit : dataPenyakit)
    {
        penyakit->displayPenyakit();
    }
}

Penyakit::Penyakit(const string &disease)
    : penyakit(disease) {}

void Penyakit::displayPenyakit() const
{
    cout << "Penyakit\t: " << penyakit << endl;
}

/*========== CLASS PEMBAYARAN ==========*/
class Pembayaran
{
private:
    string jenisPembayaran;
    string bank;
    int NoRek;
    string NamaPemilik;
    int NoBPJS;

public:
    Pembayaran(const string &payment, const string &bank, int noRek, const string &namaPemilik, int noBPJS);

    void displayPembayaran() const;
};

/*========== MAIN PEMBAYARAN ==========*/

void MainApp::addPembayaran(const string &pembayaran, const string &bank, int noRek, const string &namaPemilik, int noBPJS)
{
    Payment.push_back(make_shared<Pembayaran>(pembayaran, bank, noRek, namaPemilik, noBPJS));
}

void MainApp::inputPembayaran()
{
    string payment, Bank, namaPemilik;
    int noRek = 0, noBPJS = 0;
    bool validPayment = false;

    while (!validPayment)
    {
        cout << "\n=> Pribadi" << endl;
        cout << "=> Asuransi" << endl;
        cout << "Pilih jenis pembayaran anda: ";

        getline(cin, payment);

        for (char &c : payment)
        {
            c = tolower(c);
        }

        if (payment == "pribadi" || payment == "Pribadi")
        {
            cout << "Masukkan Bank: ";
            while (Bank.empty())
            {
                getline(cin, Bank);
                if (Bank.empty())
                {
                    cout << "Bank tidak boleh kosong. Masukkan nama Bank: ";
                }
            }

            while (true)
            {
                cout << "Masukkan Nomor Rekening: ";
                if (cin >> noRek)
                {
                    cin.ignore();
                    break;
                }
                else
                {
                    cout << "Input tidak valid. Harap masukkan angka." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }

            cout << "Masukkan Nama Pemilik Rekening: ";
            while (namaPemilik.empty())
            {
                getline(cin, namaPemilik);
                if (namaPemilik.empty())
                {
                    cout << "Nama Pemilik tidak boleh kosong. Masukkan Nama Pemilik: ";
                }
            }

            validPayment = true;
        }
        else if (payment == "asuransi" || payment == "Asuransi")
        {

            while (true)
            {
                cout << "Masukkan Nomor BPJS: ";
                if (cin >> noBPJS)
                {
                    cin.ignore();
                    break;
                }
                else
                {
                    cout << "Input tidak valid. Harap masukkan angka." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }

            validPayment = true;
        }
        else
        {
            cout << "Opsi pembayaran tidak tersedia." << endl;
            cout << "Silakan pilih 'Pribadi' atau 'Asuransi'." << endl;
        }
    }
    addPembayaran(payment, Bank, noRek, namaPemilik, noBPJS);
}

void MainApp::displayPembayaran() const
{
    for (const auto &pembayaran : Payment)
    {
        pembayaran->displayPembayaran();
    }
}

Pembayaran::Pembayaran(const string &payment, const string &Bank, int noRek, const string &namaPemilik, int noBPJS)
    : jenisPembayaran(payment), bank(Bank), NoRek(noRek), NamaPemilik(namaPemilik), NoBPJS(noBPJS) {}

void Pembayaran::displayPembayaran() const
{
    cout << "Pembayaran\t: " << jenisPembayaran << endl;
    cout << "Bank\t\t: " << bank << endl;
    cout << "Nomor Rekening\t: " << NoRek << endl;
    cout << "Nama Pemilik\t: " << NamaPemilik << endl;
    cout << "Nomor BPJS\t: " << NoBPJS << endl;
}

/*========== CLASS DOKTER ==========*/
class Dokter
{
private:
    string Nama;
    string Pangkat;
    int NIP;

public:
    Dokter(const string nama, const string jabatan, int NIP);

    void displayDokter() const;
};

/*========== MAIN DOKTER ==========*/

void MainApp::addDokter(const string &nama, const string &jabatan, int NIP)
{
    dataDokter.push_back(make_shared<Dokter>(nama, jabatan, NIP));
}

void MainApp::inputDokter()
{
    string Nama, Jabatan;
    int NIP;

    cout << "Masukkan nama Dokter: ";
    while (Nama.empty())
    {
        getline(cin, Nama);
        if (Nama.empty())
        {
            cout << "Nama Dokter tidak boleh kosong. Masukkan Nama Dokter: ";
        }
    }

    cout << "Masukkan pangkat Dokter: ";
    getline(cin, Jabatan);
    while (Jabatan.empty())
    {
        getline(cin, Jabatan);
        if (Jabatan.empty())
        {
            cout << "Jabatan tidak boleh kosong. Masukkan Jabatan: ";
        }
    }

    while (true)
    {
        cout << "Masukkan Nomor BPJS: ";
        if (cin >> NIP)
        {
            cin.ignore();
            break;
        }
        else
        {
            cout << "Input tidak valid. Harap masukkan angka." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    addDokter(Nama, Jabatan, NIP);
}

void MainApp::displayDokter() const
{
    cout << "\nCurrent Doctors: " << endl;
    for (const auto &dokter : dataDokter)
    {
        dokter->displayDokter();
    }
}

Dokter::Dokter(const string nama, const string jabatan, int NIP)
    : Nama(nama), Pangkat(jabatan), NIP(NIP) {}

void Dokter::displayDokter() const
{
    ofstream dataDokter;

    dataDokter.open("daBaseDokter.txt", ios::app);
    dataDokter << "Nama\t\t\t: " << Nama << endl;
    dataDokter << "Pangkat\t\t\t: " << Pangkat << endl;
    dataDokter << "NIP\t\t\t\t: " << NIP << endl;

    dataDokter.close();
}

/*========== CLASS SPESIALISASI ==========*/
class Spesialisasi
{
private:
    string spesialisasi;

public:
    Spesialisasi(const string &spesialis);
    void displaySpesialis() const;
};

/*========== MAIN SPESIALISASI ==========*/
void MainApp::addSpesialis(const string &spesialis)
{
    Spesialis.push_back(make_shared<Spesialisasi>(spesialis));
}

void MainApp::inputSpesialis()
{
    string spesialis;
    cout << "Masukkan Spesialisasi: ";
    while (spesialis.empty())
    {
        getline(cin, spesialis);
        if (spesialis.empty())
        {
            cout << "Spesialisasi Dokter tidak boleh kosong. Masukkan spesialisasi Dokter: ";
        }
    }
    addSpesialis(spesialis);
}

void MainApp::displaySpesialis() const
{
    cout << "\nCurrent Specialization: " << endl;
    for (const auto &spesialis : Spesialis)
    {
        spesialis->displaySpesialis();
    }
}

Spesialisasi::Spesialisasi(const string &spesialis)
    : spesialisasi(spesialis) {}

void Spesialisasi::displaySpesialis() const
{
    ofstream dataDokter;

    dataDokter.open("daBaseDokter.txt", ios::app);
    dataDokter << "Spesialisasi\t: " << spesialisasi << endl;
    dataDokter.close();
}

/*========== CLASS KEFOKUSAN ==========*/
class Kefokusan
{
private:
    string keFokusan;

public:
    Kefokusan(const string &kefokusan);
    void displayKefokusan() const;
};

/*========== MAIN KEFOKUSAN ==========*/
void MainApp::addKefokusan(const string &kefokusan)
{
    keFokusan.push_back(make_shared<Kefokusan>(kefokusan));
}

void MainApp::inputKefokusan()
{
    string kefokusan;
    bool validKefokusan = false;

    while (!validKefokusan)
    {
        cout << "\n=> Umum" << endl;
        cout << "=> Spesialis" << endl;
        cout << "Masukkan Kefokusan: ";
        getline(cin, kefokusan);

        for (char &c : kefokusan)
        {
            c = tolower(c);
        }

        if (kefokusan == "Umum" || kefokusan == "umum")
        {
            break;
        }
        else if (kefokusan == "Spesialis" || kefokusan == "spesialis")
        {
            inputSpesialis();
        }
        else
        {
            cout << "\nKefokusan tidak ditemukan" << endl;
            cout << "Silahkan pilih 'Umum' atau 'Spesialis'." << endl;
        }
        validKefokusan = true;
    }
    addKefokusan(kefokusan);
}

void MainApp::displayKefokusan() const
{
    for (const auto &focus : keFokusan)
    {
        focus->displayKefokusan();
    }
}

Kefokusan::Kefokusan(const string &kefokusan)
    : keFokusan(kefokusan) {}

void Kefokusan::displayKefokusan() const
{
    ofstream dataDokter;

    dataDokter.open("daBaseDokter.txt", ios::app);
    dataDokter << "Kefokusan\t\t: " << keFokusan << endl;
    dataDokter.close();
}

int main(int argc, char const *argv[])
{
    MainApp klinik;
    char pilut, pildok;
    string passwordAdmin, passwordDokter;
    passwordAdmin = "KlinikSehat24%";
    bool password = false;

    cout << "=========== SELAMAT DATANG =========" << endl;
    cout << "===== DI APLIKASI KLINIK SEHAT =====" << endl;
    cout << "\nA. Pasien" << endl;
    cout << "B. Dokter" << endl;

    cout << "Anda sebagai: ";
    cin >> pilut;
    cin.ignore();

    if (pilut == 'A')
    {
        klinik.inputPendaftaran();
        klinik.inputTanggalDaftar();
        klinik.inputPasien();
        klinik.inputPenyakit();
        klinik.inputPembayaran();
        klinik.displayPasien();
        klinik.displayPendaftaran();
        klinik.displayTanggalDaftar();
        klinik.displayPenyakit();
        klinik.displayPembayaran();
    }
    else if (pilut == 'B')
    {

        cout << "Masukkan Password: ";
        getline(cin, passwordDokter);

        if (passwordDokter == passwordAdmin)
        {
            do
            {
                klinik.inputDokter();
                klinik.inputKefokusan();
                cout << "\nApakah ingin menambahkan Dokter lagi? (Y/N): ";
                cin >> pildok;
                cin.ignore();
            } while (pildok == 'Y');

            klinik.displayDokter();
            klinik.displayKefokusan();
            klinik.displaySpesialis();
            password = true;
        }
        else
        {
            cout << "Password anda salah!" << endl;
        }
    }

    return 0;
}
