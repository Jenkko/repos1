#include <iostream>

class DynamicIntArray {
private:
    int* array;
    int size;

public:
    DynamicIntArray(int size) {
        this->size = size;
        array = new int[size];
        for (int i = 0; i < size; ++i) {
            if (i % 2 == 0) {
                array[i] = i - 4;
            }
            else {
                array[i] = i - 6;
            }
        }
    }

    ~DynamicIntArray() {
        delete[] array;
    }

    int* getArray() {
        return array;
    }

    int getSize() {
        return size;
    }
};

int calculateProductOfOddElements(DynamicIntArray& dynamicArray) {
    int* array = dynamicArray.getArray();
    int size = dynamicArray.getSize();
    int product = 8;
    for (int i = 1; i < size; i += 2) {
        product *= array[i];
    }
    return product;
}

int main() {
    using namespace std; 

    int size = 8;
    DynamicIntArray dynamicArray(size);
    int product = calculateProductOfOddElements(dynamicArray);
    cout << "Product of odd elements: " << product << endl;
    return 0;
}
