#include<iostream>
using namespace std;

int main()
{
   int cancel[5];
   int top = -1;

   cout << "ENTER ORDER NUMBER :" << endl;

   for(int i=0;i<5;i++)
   {
     cin>>cancel[++top];
     
   }
   cout << "CANCELLED ORDER :" << endl;

   while(top >= 0)
   {

    cout << cancel[top] << endl;
    top--;

   }
   return 0;
}
