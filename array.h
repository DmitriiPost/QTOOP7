#ifndef ARRAY_H 
#define ARRAY_H
#include <iostream>

using namespace std;

template <class number>
class TArray
{
	
public:
	TArray();
	TArray(int n);
	~TArray();
	void insertElem();
	void midAndSKO();
	void insertionSortAbove();
	void insertionSortBeyond();
	void changeSize(int newSize);
	void changeElement(number, int);
	void print();
	int getSize();
	number getElem(int);
private:
    int sizeArr;
	number* elements;
};

template <class number>
TArray<number>::TArray()
{
    sizeArr = 0;
    elements = nullptr;
}

template <class number>
TArray<number>::TArray(int n) {
    sizeArr = n;
    elements = new number[sizeArr];
    for (int i = 0; i < sizeArr; i++) {
        elements[i] = 0;
    }
}

template <class number>
void TArray<number>::insertElem() {
    for (int i = 0; i < sizeArr; i++) {
        cin >> elements[i];
    }
    system("cls");
}

template <class number>
void TArray<number>::midAndSKO() {
    number sum = 0;
    number average = 0;
    number sumSko = 0;
    number sko = 0;
    for (int i = 0; i < sizeArr; i++)
    {
        sum += elements[i];
    }
    average = sum / sizeArr;
    for (int i = 0; i < sizeArr; i++)
    {
        sumSko += ((elements[i] - average) * (elements[i] - average));
    }
    sko = sqrt((number)1 / (sizeArr - 1) * sumSko);
    cout << "Среднее: " << average << "\n";
    cout << "СКО: " << sko << "\n";
    system("pause");
}

template <class number>
void TArray<number>::insertionSortAbove() {
    for (int i = 1; i < sizeArr; i++) {
        number key = elements[i];
        int j = i - 1;


        while (j >= 0 && elements[j] > key) {
            elements[j + 1] = elements[j];
            j--;
        }
        elements[j + 1] = key;
    }
}

template <class number>
void TArray<number>::insertionSortBeyond() {
    for (int i = 1; i < sizeArr; i++) {
        number key = elements[i];
        int j = i - 1;

        while (j >= 0 && elements[j] < key) {
            elements[j + 1] = elements[j];
            j--;
        }
        elements[j + 1] = key;
    }
}

template <class number>
void TArray<number>::changeSize(int newSize) {
    number* newElements = new number[newSize];
    for (int i = 0; i < (newSize < sizeArr ? newSize : sizeArr); i++) {
        newElements[i] = elements[i];
    }


    if (newSize > sizeArr) {
        for (int i = sizeArr; i < newSize; i++) {
            newElements[i] = 0;
        }
    }


    delete[] elements;


    elements = newElements;

    sizeArr = newSize;

    //cout << "Размер массива изменен на " << newSize << " элементов.\n"
    //system("pause");
}

template <class number>
void TArray<number>::changeElement(number elem, int index) {
    if (index >= 0 && index <= sizeArr - 1) {
        elements[index] = elem;
        //cout << "Успешно\n;
    }
    /*else {
        cout << "Элемента с таким индексом не существует\n";
    }*/
    //system("pause");
}

template <class number>
void TArray<number>::print() {
    for (int i = 0; i < sizeArr; i++) {
        cout << elements[i] << " ";
    }
    cout << endl;
}

template <class number>
int TArray<number>::getSize()
{
    return sizeArr;
}

template <class number>
number TArray<number>::getElem(int index)
{
    return elements[index];
}

template <class number>
TArray<number>::~TArray()
{
    if(elements != nullptr) delete[] elements;
}


#endif // ARRAY_H 
