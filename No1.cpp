#include <iostream>
using namespace std;

int main() {
    system ("cls");
    int m[2][3][4];
    
    for (int i = 0; i < 2; ++i)
        {
        cout << "Lapisan ke-" << i+1 << endl; 
        for (int j = 0; j < 3; ++j)
            {
            for (int k = 0; k < 4; ++k)
                {
                cin >> m[i][j][k];
                }
            }
         }

    for (int i = 0; i < 2; ++i)
         {
            cout << "\n\nLapisan ke-" << i+1 << endl;
            for (int j = 0; j < 3; ++j)
                {
                    for (int k = 0; k < 4; ++k)
                        {
                            cout << m[i][j][k] << " ";
                        }
                        cout << endl;
                }
                cout << endl;
         }
}