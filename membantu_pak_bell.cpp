// Pendidikan RSC 2025 DAY1
// Nama: Muhammad Haidar Fadhilah
// NIM: 16024166

#include <iostream>
#include <string>
#include <cctype>


// UTILS start

int const MAX_CONTACT = 8; // Jumlah maksimal contact
// fungsi untuk membuat string menjadi kapital 
std::string to_uppercase(std::string text)
{
    for (char &c : text)
    {
        c = std::toupper(c);
    }

    return text;
}
// fungsi untuk menyuruh user agar input
void get_input(std::string prompt, std::string& output)
{
    std::cout << prompt;
    std::getline(std::cin, output);
}

// UTILS end


class Contact
{
    private:
        int id;
        std::string nama;
        std::string alamat;
        std::string kekuatan;

    public:
        // Constructor
        Contact() // Untuk kosongan
        {
            id = -1;    // Jika kontak kosong, id akan default di set ke -1
            nama = "";
            alamat = "";
            kekuatan = ""; 
        }
        Contact(int Id, std::string Nama, std::string Alamat, std::string Kekuatan)
        {
            id = Id;
            nama = Nama;
            alamat = Alamat;
            kekuatan = Kekuatan;
        }  

        // Getters
        int get_id() {return id;}
        std::string get_nama() {return nama;}
        std::string get_alamat() {return alamat;}
        std::string get_kekuatan() {return kekuatan;}

        // cek apakah class kosong, atau tidak
        bool is_empty()
        {
            if (id == -1) { return true; }
            return false;
        }

        // menampilkan info kontak
        void contact_info()
        {
            std::cout << id << ". " << "Nama    : " << nama << "\n";
            std::cout << "   " << "Alamat  : " << alamat << "\n";
            std::cout << "   " << "Kekuatan: " << kekuatan << "\n";
            std::cout << "\n";
        }
};


class PhoneBook
{
    private:
        Contact contact[MAX_CONTACT]; //phonebook hanya memiliki MAX_CONTACT kapasitas contact

    public:
        // method untuk save kontak
        void save(Contact kontak, int index) 
        {
            contact[index] = kontak;
        }

        // method untuk print seluruh kontak yang ada dalam phonebook
        void display_brief()
        {
            std::cout << "Daftar Kontak \n";
            std::cout << "------------------\n";
            for (int i = 0; i < MAX_CONTACT; i++)
            {
                if (!contact[i].is_empty())
                {
                    std::cout << contact[i].get_id() << ". " << contact[i].get_nama() << "\n";
                }
            }
            std::cout << "\n";
        }
        
        // method untuk mencari kontak lalu print informasi contact tersebut (input nama yang ingin dicari)
        void search(std::string key)
        {
            bool ketemu = false;

            for (int i = 0; i < MAX_CONTACT; i++)
            {
                if (to_uppercase(key) == to_uppercase(contact[i].get_nama()))
                {
                    contact[i].contact_info();
                    ketemu = true;
                }
            }

            if (!ketemu)
            {
                std::cout << "Kontak tidak ditemukan \n";
            }
        }
};

// fungsi utama
int main() 
{
    std::cout << "Selamat datang di Buku Kontak \n"; // greet
    // Deklarasi Variabel
    PhoneBook phone_book;
    int index = 0;

    // looping utama
    while (true)
    {
        // Deklarasi variabel
        std::string user_input;

        // Mendapatkan input user
        get_input("Masukkan pilihan (ADD/VIEW/SEARCH/EXIT): ", user_input);

        // kode untuk menu-menu
        // Menambahkan contact baru ke phonebook
        if (to_uppercase(user_input) == "ADD")
        {
            // Minta user memasukkan info contact yang ingin ditambahkan
            std::string nama, alamat, kekuatan;
            get_input("Nama    : ", nama);
            get_input("Alamat  : ", alamat);
            get_input("Kekuatan: ", kekuatan);

            // jika kosong, input ke yang kosong paling atas, jika penuh input ke kontak terlama
            phone_book.save(Contact((index % MAX_CONTACT) + 1, nama, alamat, kekuatan), index % MAX_CONTACT);
            index++;
            std::cout << "\n";
        }
        
        // menu untuk menampilkan kontak yang sudah disimpan
        if (to_uppercase(user_input) == "VIEW")
        {
            phone_book.display_brief();
        }
        
        if (to_uppercase(user_input) == "SEARCH")
        {
            std::string cari;

            get_input("Masukkan nama: ", cari);
            phone_book.search(cari);
        }
        
        if (to_uppercase(user_input) == "EXIT")
        {
            return 0; // exit memlalui EXIT
        }
    }

    // exit dengan error
    return 1;
}