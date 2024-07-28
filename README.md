## UAS Struktur Data dan Algoritma

| Nama        | Nim          | Kelas | Prodi              |
| ----------- | ------------ | ----- | ------------------ |
| Akmal Fauzi | 230401010160 | IT201 | S1 PJJ Informatika |

## 1. Program Mengurutkan data menggunakan Bubble Sort dan Selection Sort

### - Bubble Sort

Program ini menggunakan algoritma Bubble Sort untuk mengurutkan data orang berdasarkan nama.

### Kode Program

```cpp
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
```

### Penjelasan Kode

#### - Bagian Include dan Namespace:

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
```

-   Mengimpor library yang diperlukan: iostream untuk input/output, string untuk manipulasi string, vector untuk menggunakan vector, dan iomanip untuk manipulasi output.

-   `using namespace std;` untuk penggunaan elemen-elemen dari namespace std tanpa awalan std::

#### - `struct Orang`

```cpp
struct Orang
{
    string nama;
    string alamat;
};
```

-   Mendefinisikan `struct` dengan dua variable: nama dan alamat yang bertipe string.

#### - Fungsi `cetakData()`

```cpp
void cetakData(const vector<Orang> &data, const string &judul)
{
    cout << "\n" << judul << ":\n";
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
```

-   Menerima vector Orang dan judul sebagai parameter.
-   Mencetak judul, header tabel, dan garis pemisah.
-   Iterasi melalui setiap orang dalam data, mencetak nama dan alamat.
-   Menambahkan tab ekstra jika nama kurang dari 8 karakter untuk merapihkan tampilan

#### - Fungsi `bubbleSort()`

```cpp
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
```

-   Implementasi algoritma Bubble Sort untuk mengurutkan vector Orang berdasarkan nama.
-   Menggunakan nested loop untuk membandingkan dan menukar elemen jika tidak dalam urutan yang benar.

#### - Fungsi `main()`

```cpp
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
```

-   Menginisialisasi vector data dengan beberapa objek Orang.
-   Memanggil fungsi cetakData untuk menampilkan data awal.
-   Memanggil fungsi bubbleSort untuk mengurutkan data.
-   Memanggil fungsi cetakData lagi untuk menampilkan data yang telah diurutkan.
-   Mengembalikan nilai 0 untuk menandakan bahwa program telah berakhir.

### Output

[![Output Bubble Sort](https://raw.githubusercontent.com/Akmalfauzi/uas-struktur-data-dan-algoritma/main/output/bubbleSort/bubble-sort.png "Output Bubble Sort")](https://raw.githubusercontent.com/Akmalfauzi/uas-struktur-data-dan-algoritma/main/output/bubbleSort/bubble-sort.png "Output Bubble Sort")

### - Selection Sort

Program ini menggunakan algoritma Selection Sort untuk mengurutkan data orang berdasarkan nama.

### Kode Program

```cpp
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
    cout << "\n" << judul << ":\n";
    cout << left << setw(15) << "Nama" << "Alamat\n";
    cout << "------------------------\n";
    for (const auto &orang : data)
    {
        cout << left << setw(15) << orang.nama << orang.alamat << endl;
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
```

### Penjelasan Kode

#### - Bagian Include dan Namespace:

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;
```

-   Mengimpor library yang diperlukan: iostream untuk input/output, string untuk manipulasi string, dan vector untuk menggunakan vector.
-   `using namespace std;` untuk penggunaan elemen-elemen dari namespace std tanpa awalan `std::`

#### - `struct Orang`

```cpp
struct Orang
{
    string nama;
    string alamat;
};
```

-   Mendefinisikan `struct` dengan dua variable: nama dan alamat yang bertipe string.

#### - Fungsi `cetakData()`

```cpp
void cetakData(const vector<Orang> &data, const string &judul)
{
    cout << "\n" << judul << ":\n";
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
```

-   Menerima vector Orang dan judul sebagai parameter.
-   Mencetak judul, header tabel, dan garis pemisah.
-   Iterasi melalui setiap orang dalam data, mencetak nama dan alamat.
-   Menambahkan tab ekstra jika nama kurang dari 8 karakter untuk merapihkan tampilan

#### - Fungsi `selectionSort()`

```cpp
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
```

-   Implementasi algoritma Selection Sort untuk mengurutkan vector Orang berdasarkan nama.
-   Mencari elemen terkecil (berdasarkan nama) dalam sisa array yang belum diurutkan.
-   Menukar elemen terkecil yang ditemukan dengan elemen pertama dari array yang belum diurutkan.

#### - Fungsi `main()`

```cpp
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
```

-   Menginisialisasi vector data dengan beberapa objek Orang.
-   Memanggil fungsi `cetakData` untuk menampilkan data awal.
-   Memanggil fungsi `selectionSort` untuk mengurutkan data.
-   Memanggil fungsi `cetakData` lagi untuk menampilkan data yang telah diurutkan.
-   Mengembalikan nilai 0 untuk menandakan bahwa program telah berakhir.

### Output

[![Output Selection Sort](https://raw.githubusercontent.com/Akmalfauzi/uas-struktur-data-dan-algoritma/main/output/selectionSort/selection-sort.png "Output Selection Sort")](https://raw.githubusercontent.com/Akmalfauzi/uas-struktur-data-dan-algoritma/main/output/selectionSort/selection-sort.png "Output Selection Sort")

## 2. Program Pencarian Biner (Binary Search)

Program ini merupakan implementasi pencarian biner yang dimodifikasi untuk mencari elemen dalam array yang mungkin memiliki duplikat.

### Kode Program

#### - Header dan Struktur Data

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Element
{
    int value;
    int originalIndex;
};
```

-   **Header Files**: Menyertakan pustaka standar yang diperlukan (iostream, vector, algorithm, dan string).
-   **Namespace**: `using namespace std`; untuk menggunakan namespace standar.
-   **Struct Element**: `Struct Element` digunakan untuk menyimpan nilai asli dan indeks asli dari elemen-elemen array.

#### - Fungsi `binarySearch()`

```cpp
vector<int> binarySearch(const vector<Element> &arr, int target)
{
    vector<int> result;
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid].value == target)
        {
            for (int i = 0; i < arr.size(); i++)
            {
                if (arr[i].value == target)
                {
                    result.push_back(arr[i].originalIndex + 1);
                }
            }
            sort(result.begin(), result.end());
            return result;
        }
        else if (arr[mid].value < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return result;
}
```

-   **Parameter**: Fungsi `binarySearch` menerima referensi konstan ke `vector<Element>` yang sudah diurutkan dan nilai target yang akan dicari.
-   **Variabel result:** Menyimpan hasil indeks asli elemen yang ditemukan.
-   **Variabel left dan right**: Digunakan untuk menentukan batas kiri dan kanan dari bagian array yang sedang dicari.
-   **Loop While**: Melakukan pencarian biner. Jika elemen tengah (mid) sama dengan target, loop kedua akan mencari semua elemen yang cocok dan menyimpannya di result.
-   **Pengurutan Hasil**: Mengurutkan hasil sebelum mengembalikannya.
-   **Pengembalian Hasil**: Mengembalikan indeks asli elemen-elemen yang ditemukan atau array kosong jika tidak ditemukan.

#### - Fungsi `displayArray()`

```cpp
void displayArray(const vector<int> &arr)
{
    cout << "Angka yang tersedia: ";
    for (size_t i = 0; i < arr.size(); ++i)
    {
        cout << arr[i];
        if (i < arr.size() - 1)
            cout << ", ";
    }
    cout << endl
         << endl;
}
```

-   **Parameter**: Menerima referensi konstan ke `vector<int>` untuk mencetak elemen-elemen array.
-   **Loop**: Menampilkan elemen-elemen array dengan pemisah koma.

#### - Fungsi `main()`

```cpp
int main()
{
    vector<int> originalArr = {19, 40, 10, 90, 2, 50, 60, 50, 1};
    vector<Element> arr;
    for (int i = 0; i < originalArr.size(); i++)
    {
        arr.push_back({originalArr[i], i});
    }

    sort(arr.begin(), arr.end(), [](const Element &a, const Element &b)
         { return a.value < b.value; });

    displayArray(originalArr);

    while (true)
    {
        string input;
        cout << "Masukkan angka yang ingin dicari (atau 'q' untuk keluar): ";
        cin >> input;

        if (input == "q" || input == "Q")
            break;

        int target;
        try
        {
            target = stoi(input);
        }
        catch (const invalid_argument &)
        {
            cout << "Input tidak valid. Masukkan angka atau 'q' untuk keluar." << endl
                 << endl;
            continue;
        }

        vector<int> result = binarySearch(arr, target);

        if (result.empty())
        {
            cout << "Angka " << target << " tidak ada dalam array" << endl;
        }
        else if (result.size() == 1)
        {
            cout << "Angka " << target << " ada di indeks ke " << result[0] << endl;
        }
        else
        {
            cout << "Angka " << target << " ada di indeks ke ";
            for (size_t i = 0; i < result.size(); ++i)
            {
                cout << result[i];
                if (i < result.size() - 1)
                    cout << " dan ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
```

-   **Inisialisasi Array**: originalArr adalah array asli yang akan diurutkan dan dicari elemennya.
-   **Membuat Vector Element**: `arr` adalah `vector<Element>` yang menyimpan nilai dan indeks asli.
-   **Sorting**: Mengurutkan `arr` berdasarkan nilai elemen menggunakan _lambda expression_.
-   **Menampilkan Array**: Memanggil displayArray untuk menampilkan array asli.
-   **Loop Input Pengguna:** Mengambil input dari pengguna untuk mencari elemen dalam array.
-   **Input Validasi**: Memeriksa apakah input adalah angka yang valid atau 'q' untuk keluar.
-   **Pencarian**: Memanggil `binarySearch` untuk mencari elemen target dan mendapatkan hasil indeks.
-   **Menampilkan Hasil**: Menampilkan hasil pencarian sesuai dengan jumlah elemen yang ditemukan.

### Output

[![Output Binary Search](https://raw.githubusercontent.com/Akmalfauzi/uas-struktur-data-dan-algoritma/main/output/binarySearch/binary-search.png "Output Binary Search")](https://raw.githubusercontent.com/Akmalfauzi/uas-struktur-data-dan-algoritma/main/output/binarySearch/binary-search.png "Output Binary Search")
