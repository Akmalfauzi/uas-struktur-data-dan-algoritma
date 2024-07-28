#include <iostream>
#include <string>
#include <vector>
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

void selectionSort(vector<Orang> &data)
{
    for (size_t i = 0; i < data.size() - 1; i++)
    {
        size_t min_idx = i;
        for (size_t j = i + 1; j < data.size(); j++)
        {
            if (data[j].nama < data[min_idx].nama)
            {
                min_idx = j;
            }
        }
        if (min_idx != i)
        {
            swap(data[i], data[min_idx]);
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
    selectionSort(data);
    cetakData(data, "Setelah Selection Sort");

    return 0;
}