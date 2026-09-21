#include<iostream>
using namespace std;

int main()
{
    int marks[5];

    
    cout << "Enter marks of 5 students:" << endl;

    for(int i = 0; i < 5; i++)
    {
        cin >> marks[i];
    }

    
    for(int i = 0; i < 5; i++)
    {
        for(int j = i + 1; j < 5; j++)
        {
            if(marks[i] < marks[j]);
            {
                int temp = marks[i];
                marks[i] = marks[j];
                marks[j] = temp;
            }
        }
    }

    
    cout << "Marks from highest to lowest:" << endl;

    for(int i = 0; i < 5; i++)
    {
        cout << marks[i] << endl;
    }

    return 0;
}
