#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct Orang
{
    string nama;
    string alamat;
};

void cetakData(const vector<Orang> &data, const string &judul)
{
    cout << "\n"
         << judul << ":\n";
    cout << "Nama\t\tAlamat\n";
    cout << "------------------------\n";
    for (const auto &orang : data)
    {
        cout << orang.nama;
        if (orang.nama.length() < 8)
            cout << "\t";
        cout << "\t" << orang.alamat << endl;
    }
    cout << endl;
}

void bubbleSort(vector<Orang> &data)
{
    for (size_t i = 0; i < data.size() - 1; i++)
    {
        for (size_t j = 0; j < data.size() - i - 1; j++)
        {
            if (data[j].nama > data[j + 1].nama)
            {
                swap(data[j], data[j + 1]);
            }
        }
    }
}

int main()
{
    vector<Orang> data = {
        {"Fahmi", "Jakarta"},
        {"Romi", "Solo"},
        {"Andri", "Jakarta"},
        {"Fadillah", "Banyuwangi"},
        {"Ruli", "Bandung"},
        {"Rudi", "Bali"},
        {"Dendi", "Purwokerto"},
        {"Zaki", "Madiun"}};

    cetakData(data, "Data Awal");
    bubbleSort(data);
    cetakData(data, "Setelah Bubble Sort");

    return 0;
}