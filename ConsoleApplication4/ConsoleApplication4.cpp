//#include <iostream> 
//#include <string> 
// 
//using namespace std; 
// 
//string** addRow(string** text, int row, int col) { 
//    string** newar = new string * [row + 1]; 
//    for (int i = 0; i < row; i++) { 
//        newar[i] = new string[col]; 
//        for (int j = 0; j < col; j++) { 
//            newar[i][j] = text[i][j]; 
//        } 
//    } 
//    newar[row] = new string[col]; 
//    for (int j = 0; j < col; j++) { 
//        newar[row][j] = "hello"; 
//    } 
//    for (int i = 0; i < row; i++) { 
//        delete[] text[i]; 
//    } 
//    delete[] text; 
//    return newar; 
//} 
// 
//int main() { 
//    int row = 2, col = 2; 
//    system("chcp 1251>null"); 
//    string** ar = new string * [2]; 
//    cout << "введіть текст" << endl; 
//    for (int i = 0; i < 2; i++) { 
//        ar[i] = new string[3]; 
//        for (int j = 0; j < 3; j++) { 
//            cin >> ar[i][j]; 
//        } 
//    } 
// 
//    for (int i = 0; i < 2; i++) { 
//        for (int j = 0; j < 3; j++) { 
//            cout << ar[i][j] << " "; 
//        } 
//        cout << endl; 
//    } 
// 
//    ar = addRow(ar, 2, 3); 
// 
//    for (int i = 0; i < 3; i++) { 
//        for (int j = 0; j < 3; j++) { 
//            cout << ar[i][j] << " "; 
//        } 
//        cout << endl; 
//    } 
// 
//    for (int i = 0; i < 3; i++) { 
//        delete[] ar[i]; 
//    } 
//    delete[] ar; 
// 
//    return 0; 
//} 
// 
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//string** addRow(string** text, int row, int col) {
//    string** newar = new string * [row + 1];
//    newar[0]= new string[col];
//    for (int j = 0; j < col; j++) {
//        newar[0][j] = "hello";
//    }
//    for (int i = 0; i < row; i++) {
//        newar[i+1] = new string[col];
//        for (int j = 0; j < col; j++) {
//            newar[i+1][j] = text[i][j];
//        }
//    }
//   
//    for (int i = 0; i < row; i++) {
//        delete[] text[i];
//    }
//    delete[] text;
//    return newar;
//}
//
//int main() {
//    int row = 2, col = 3; 
//    system("chcp 1251>null");
//
//    string** ar = new string * [row];
//    cout << "введіть текст" << endl;
//
//    for (int i = 0; i < row; i++) {
//        ar[i] = new string[col]; 
//        for (int j = 0; j < col; j++) {
//            cin >> ar[i][j];
//        }
//    }
//
//    cout << "\nВведений текст:" << endl;
//    for (int i = 0; i < row; i++) {
//        for (int j = 0; j < col; j++) {
//            cout << ar[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//    ar = addRow(ar, 2, 3);
//
//    cout << "Текст після додавання нового рядка:" << endl;
//    for (int i = 0; i < 3 ; i++) { 
//        for (int j = 0; j < 3; j++) {
//            cout << ar[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//    for (int i = 0; i < row ; i++) { 
//        delete[] ar[i];
//    }
//    delete[] ar;
//
//    return 0;
//}
#include <iostream> 
#include <string>
#include <cstring>

using namespace std;

string** addRow(string** text, int row, int col, int str) {
    string** newar = new string * [row + 1];

    for (int i = 0; i < row + 1; i++) {
        newar[i] = new string[col];
        if (i < str) {
            for (int j = 0; j < col; j++)
                newar[i][j] = text[i][j];
        }
        else if (i == str) {
            for (int r = 0; r < col; r++)
                newar[i][r] = "text";
        }
        else {
            for (int j = 0; j < col; j++) {
                newar[i][j] = text[i - 1][j];
            }
        }
    }

    for (int i = 0; i < row; i++) {
        delete[] text[i];
    }
    delete[] text;
    return newar;
}

int main() {
    system("chcp 1251>null");
    int row = 2, col = 3;

    string** ar = new string * [2];
    cout << "введіть текст" << endl;

    for (int i = 0; i < 2; i++) {
        ar[i] = new string[3];
        for (int j = 0; j < 3; j++) {
            cin >> ar[i][j];
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }
    int str;
    cout << "enter number" << endl;
    cin >> str;
    if (str > row && str < row) {
        cout << "erorr";
        return 0;
    }
    str--;


    ar = addRow(ar, row, col, str);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 3; i++) {
        delete[] ar[i];
    }
    delete[] ar;

    return 0;
}