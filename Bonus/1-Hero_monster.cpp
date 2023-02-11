#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int birthday = 7, endcard = 5;
    int delbirthday = 3, seconcard = 3;
    int matrix[10][10] = {};
    
    matrix[rand()%10][rand()%10] = 1;      //Tree
    matrix[birthday][endcard] = 2;         //Hero
    matrix[delbirthday][seconcard] = 3;    //Monster
    
    for (int i=0; i<5; i++)                                           //Rotation matrix 90 degree
    {
        for (int j=i; j<10-i-1; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][10 - i - 1];
            matrix[j][10 - i - 1] = matrix[10 - i - 1][10 - j - 1];

            matrix[10 - i - 1][10 - j - 1] = matrix[10 - j - 1][i];
            matrix[10 - j - 1][i] = temp;
        }
    }
    
    for (int i=0; i<10; i++)                //Matrix
    {
        for (int j = 0; j < 10; j++)
        {
            cout << matrix[i][j];
        }
        cout << endl;
    }
    
    int taxicab = abs(delbirthday-birthday) + abs(seconcard-endcard);
    float euclidean = sqrt(pow(delbirthday-birthday,2) + pow(seconcard-endcard,2));
    int chebyshev = max(abs(birthday-(delbirthday)),abs(seconcard-endcard));

    cout << "Taxicab distance = " << taxicab << endl;
    cout << "Euclidean distance = " << euclidean << endl;
    cout << "Chebyshev distance = " << chebyshev << endl;

    return 0;
}