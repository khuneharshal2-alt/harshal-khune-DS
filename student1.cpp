#include<iostream>
using namespace std;

class student
{
    public:
    int rollno;
    void input()
    {
        cout<<"roll no of the student: "<<endl;
        cin>>rollno;

    }
    void display()
    {
        cout<<"roll no of the student is: "<<rollno<<endl;

    }
};
int main()
{
    student s1;
    student s2;
    student s3;
    student s4;
    student s5;

    s1.input();
    s1.display();

    s2.input();
    s2.display();

    s3.input();
    s3.display();


    s4.input();
    s4.display();

    s5.input();
    s5.display();

    return 0;
}
