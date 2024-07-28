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