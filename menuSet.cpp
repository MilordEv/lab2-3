#include <iostream>
#include "Set.hpp"
using namespace std;

int InputData(int* codeType, Set<int>** treeInt, Set<float>** treeFloat);
int InsertKey(int* codeType, Set<int>** treeInt, Set<float>** treeFloat);
int RemoveKey(int* codeType, Set<int>** treeInt, Set<float>** treeFloat);
int Map(int* codeType, Set<int>** treeInt, Set<float>** treeFloat);
int Where(int* codeType, Set<int>** treeInt, Set<float>** treeFloat);
int ReduceTree(int* codeType, Set<int>** treeInt, Set<float>** treeFloat);
int FindKey(int* codeType, Set<int>** treeInt, Set<float>** treeFloat);
int SubTree(int* codeType, Set<int>** treeInt, Set<float>** treeFloat);
int Output(int* codeType, Set<int>** treeInt, Set<float>** treeFloat);

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
	
    Set<int>* treeInt = nullptr;
    Set<float>* treeFloat = nullptr;
    int codeType = 0;

    while(1 + 1 == 2) {
        cout << endl;

        cout << "Enter a number for:" << endl;
        cout << "\t1 - To enter data" << endl; 
        cout << "\t2 - To insert key" << endl;
        cout << "\t3 - To remove key" << endl; 
        cout << "\t4 - map" << endl; 
        cout << "\t5 - where" << endl; 
        cout << "\t6 - reduce" << endl; 
        cout << "\t7 - find key" << endl; 
        cout << "\t8 - Save to string" << endl; 
        cout << "\t9 - print set" << endl; 
        cout << "\t0 - To exit the test" << endl; 
        cout << endl << "Enter: ";
        
        int code = 0;
        cin >> code;

        cout << endl;

        switch(code) {
            case 1: 
                InputData(&codeType, &treeInt, &treeFloat);
                break;

            case 2: 
                InsertKey(&codeType, &treeInt, &treeFloat);
                break;

            case 3: 
                RemoveKey(&codeType, &treeInt, &treeFloat);
                break;

            case 4: 
                Map(&codeType, &treeInt, &treeFloat);
                break;

            case 5: 
                Where(&codeType, &treeInt, &treeFloat);
                break;

            case 6: 
                ReduceTree(&codeType, &treeInt, &treeFloat);
                break;

            case 7: 
                FindKey(&codeType, &treeInt, &treeFloat);
                break;

            case 8: 
                //SubTree(&codeType, &treeInt, &treeFloat);
                break;

            case 9: 
                Output(&codeType, &treeInt, &treeFloat);
                break;

            case 0:
                delete treeInt;
                delete treeFloat;

                cout << endl << "Exiting the test" << endl;
                return 0;

            default: 
                cout << "Input error, please re-enter" << endl << endl;
        } 
     }

}


int InputData(int* codeType, Set<int>** treeInt, Set<float>** treeFloat) {
    delete *treeInt;
    delete *treeFloat;

    cout << "Enter a number for:" << endl;
    cout << "\t1 - To enter int Set" << endl;
    cout << "\t2 - To enter float Set" << endl;
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

            delete *treeInt;
            *treeInt = new Set<int>(items, number);

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

            delete *treeFloat;
            *treeFloat = new Set<float>(items, number);
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

int InsertKey(int* codeType, Set<int>** treeInt, Set<float>** treeFloat) {
    if (!(*codeType)) {
        cout << "Firstly create a tree";
    }

    cout << "Enter: ";
    
    if (*codeType == 1) {
        int value = 0;
        cin >> value;
        (*treeInt)->Add(value);
    } else {
        float value = 0;
        cin >> value;
        (*treeFloat)->Add(value);
    }

    return 0;
}

int RemoveKey(int* codeType, Set<int>** treeInt, Set<float>** treeFloat) {
    if (!(*codeType)) {
        cout << "Firstly create a tree";
    }

    cout << "Enter: ";
    
    if (*codeType == 1) {
        int value = 0;
        cin >> value;
        (*treeInt)->Remove(value);
    } else {
        float value = 0;
        cin >> value;
        (*treeFloat)->Remove(value);
    }

    return 0;
}

int Map(int* codeType, Set<int>** treeInt, Set<float>** treeFloat) {
    if (!(*codeType)) {
        cout << "Firstly create a tree";
    }
    
    if (*codeType == 1) {
        (*treeInt)->Map(f11);
    } else {
        (*treeFloat)->Map(f12);
    }

    return 0;
}

int Where(int* codeType, Set<int>** treeInt, Set<float>** treeFloat) {
    if (!(*codeType)) {
        cout << "Firstly create a tree";
    }
    
    if (*codeType == 1) {
        (*treeInt)->Where(f21);
    } else {
        (*treeFloat)->Where(f22);
    }

    return 0;
}

int ReduceTree(int* codeType, Set<int>** treeInt, Set<float>** treeFloat) {
    if (!(*codeType)) {
        cout << "Firstly create a tree";
    }
    
    if (*codeType == 1) {
        cout << (*treeInt)->Reduce(f31, 0) << endl;
    } else {
        cout << (*treeFloat)->Reduce(f32, 0) << endl;
    }

    return 0;
}

int FindKey(int* codeType, Set<int>** treeInt, Set<float>** treeFloat) {
    if (!(*codeType)) {
        cout << "Firstly create a tree";
    }

    cout << "Enter: ";
    
    if (*codeType == 1) {
        int value = 0;
        cin >> value;
        cout << (*treeInt)->Find(value) << endl;
    } else {
        float value = 0;
        cin >> value;
        cout << (*treeFloat)->Find(value) << endl;
    }

    return 0;
}

int Output(int* codeType, Set<int>** treeInt, Set<float>** treeFloat) {
    if (!(*codeType)) {
        cout << "Firstly create a tree";
    };
    
    if (*codeType == 1) {
        (*treeInt)->Print();
    } else {
        (*treeFloat)->Print();
    }

    return 0;
}