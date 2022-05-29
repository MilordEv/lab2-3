#include <iostream>
#include "BinaryHeap.hpp"
using namespace std;

int InputData(int* codeType, BinaryHeap<int>** heapInt, BinaryHeap<float>** heapFloat);
int InsertKey(int* codeType, BinaryHeap<int>** heapInt, BinaryHeap<float>** heapFloat);
int GetMax(int* codeType, BinaryHeap<int>** heapInt, BinaryHeap<float>** heapFloat);
int FindKey(int* codeType, BinaryHeap<int>** heapInt, BinaryHeap<float>** heapFloat);
int Output(int* codeType, BinaryHeap<int>** heapInt, BinaryHeap<float>** heapFloat);

int f11(int v) {
    return v*v;
}

bool f21(int v) {
    return v%2;
}

int f31(int v1, int v2) {
    return v1 + v2;
} 

float f12(float v) {
    return v*v;
}

bool f22(float v) {
    return v > 5;
}

float f32(float v1, float v2) {
    return v1 + v2;
} 

int main(){
	
    BinaryHeap<int>* heapInt = nullptr;
    BinaryHeap<float>* heapFloat = nullptr;
    int codeType = 0;

    while(1 + 1 == 2) {
        cout << endl;

        cout << "Enter a number for:" << endl;
        cout << "\t1 - To enter data" << endl; 
        cout << "\t2 - To insert key" << endl;
        cout << "\t3 - To get max" << endl; 
        cout << "\t4 - find key" << endl; 
        cout << "\t5 - print Tree" << endl; 
        cout << "\t0 - To exit the test" << endl; 
        cout << endl << "Enter: ";
        
        int code = 0;
        cin >> code;

        cout << endl;

        switch(code) {
            case 1: 
                InputData(&codeType, &heapInt, &heapFloat);
                break;

            case 2: 
                InsertKey(&codeType, &heapInt, &heapFloat);
                break;

            case 3: 
                GetMax(&codeType, &heapInt, &heapFloat);
                break;

            case 4: 
                FindKey(&codeType, &heapInt, &heapFloat);
                break;

            case 5: 
                Output(&codeType, &heapInt, &heapFloat);
                break;

            case 0:
                delete heapInt;
                delete heapFloat;

                cout << endl << "Exiting the test" << endl;
                return 0;

            default: 
                cout << "Input error, please re-enter" << endl << endl;
        } 
     }

}


int InputData(int* codeType, BinaryHeap<int>** heapInt, BinaryHeap<float>** heapFloat) {
    delete *heapInt;
    delete *heapFloat;

    cout << "Enter a number for:" << endl;
    cout << "\t1 - To enter int BinaryHeap" << endl;
    cout << "\t2 - To enter float BinaryHeap" << endl;
    cout << "Enter: ";

    int code = 0;
    cin >> code;

    cout << "Enter number of items: ";
    int number = 0;
    cin >> number;

    switch(code) {

        case 1: {
            int items[number];
            for (int i = 0; i < number; i++) {
                cout << "[" << i << "]: ";
                cin >> items[i];
            }

            delete *heapInt;
            *heapInt = new BinaryHeap<int>(items, number);

            *codeType = 1;
            cout << endl << endl;
            return 0;
            break;

        }

        case 2: {
            float items[number];
            for (int i = 0; i < number; i++) {
                cout << "[" << i << "]: ";
                cin >> items[i];
            }

            delete *heapFloat;
            *heapFloat = new BinaryHeap<float>(items, number);
            *codeType = 2;
            cout << endl << endl;
            return 0;
            break;


        }

        default:
            cout << "You make mistake" << endl << endl << endl;
            return -1;
    }
}

int InsertKey(int* codeType, BinaryHeap<int>** heapInt, BinaryHeap<float>** heapFloat) {
    if (!(*codeType)) {
        cout << "Firstly create a tree";
    }

    cout << "Enter: ";
    
    if (*codeType == 1) {
        int value = 0;
        cin >> value;
        (*heapInt)->AddElement(value);
    } else {
        float value = 0;
        cin >> value;
        (*heapFloat)->AddElement(value);
    }

    return 0;
}

int GetMax(int* codeType, BinaryHeap<int>** heapInt, BinaryHeap<float>** heapFloat) {
    if (!(*codeType)) {
        cout << "Firstly create a tree";
    }

    if (*codeType == 1) {
        cout << (*heapInt)->Getmax();
    } else {
        cout << (*heapFloat)->Getmax();
    }

    return 0;
}

int FindKey(int* codeType, BinaryHeap<int>** heapInt, BinaryHeap<float>** heapFloat) {
    if (!(*codeType)) {
        cout << "Firstly create a tree";
    }

    cout << "Enter: ";
    
    if (*codeType == 1) {
        int value = 0;
        cin >> value;
        cout << (*heapInt)->Find(value) << endl;
    } else {
        float value = 0;
        cin >> value;
        cout << (*heapFloat)->Find(value) << endl;
    }

    return 0;
}

int Output(int* codeType, BinaryHeap<int>** heapInt, BinaryHeap<float>** heapFloat) {
    if (!(*codeType)) {
        cout << "Firstly create a tree";
    }
    
    if (*codeType == 1) {
        (*heapInt)->OutMatrix();
        cout << endl;
        (*heapInt)->OutHeap();
        cout << endl;
    } else {
        (*heapFloat)->OutMatrix();
        cout << endl;
        (*heapFloat)->OutHeap();
    }

    return 0;
}