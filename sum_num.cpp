#include <iostream>

using namespace std;

template <class T>
T sum(T *array, int len) {
    T total = 0;

    for (int i = 0; i < len; i++) {
        total += array[i];
    }

    return total;
}

template <class T>
T sub(T *array, int len) {
    T total = 0;

    for (int i = 0; i < len; i++) {
        total -= array[i];
    }

    return total;
}

template <class T>
void output(T *array, int len) {
    cout << "Output of array: ";
    
    for (int i = 0; i < len; i++) {
        if (i > 0) {
            cout << ", ";
        }
        
        cout << array[i];
    }
    
    cout << endl;   
}

int main(int argc, char** argv) {
    int array[] = {5, 5, 10};
    double array2[] = {4.5, 4.5};    
    
    cout << "Result Sum: " << sum(array, 3) << endl;
    cout << "Result2 Sum: " << sum(array2, 2) << endl;
    
    cout << "Result Sub: " << sub(array, 3) << endl;
    cout << "Result2 Sub: " << sub(array2, 3) << endl;
    
    output(array, 3);
    output(array2, 2);

    return 0;
}

