#include <iostream>
#include <locale.h>
#include <fstream>
using namespace std;

int* fill_array (int* arr, int size, ifstream & in) {

    for (int i = 0; i < size; i++) {
        in >> arr[i];
    }
    return arr;
}

void rec_1(int* arr, int size, ofstream &out) {

    for (int i = 1; i < size; i++) {
        int temp = arr[i-1];
        arr[i-1] = arr[i];
        arr[i] = temp;
    }
    out << size << endl;
    for (int i = 0; i < size; i++) {
        out << arr[i] << " ";
    }
}

void rec_2(int* arr, int size, ofstream &out) {

    for (int i = 0; i < size; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1];
        arr[size - 1] = temp;
    }
    out << size << endl;
    for (int i = 0; i < size; i++) {
        out << arr[i] << " ";
    }
    out << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    ifstream in("in.txt");
    ofstream out("out.txt");
    if (!in.is_open() || (!out.is_open())) {
        cout << "Файл не найден";
        exit(0);
    }
    int size_1 = 0;
    int size_2 = 0;
    in >> size_1;
    int* array_1 = new int[size_1];
    fill_array(array_1, size_1, in);
    in >> size_2;
    int* array_2 = new int[size_2];
    fill_array(array_2, size_2, in);
    rec_2(array_2, size_2, out);
    rec_1(array_1, size_1, out);
    in.close();
    out.close();
    delete[] array_1;
    delete[] array_2;
    return 0;
}
