#include <iostream>
using namespace std;

class Student
{
private:
    int marks;
    static int count;
public:
    Student(int m)
    {
        marks = m;
        count++;
    }
    static void showCount()
    {
        cout << "Total objects: " << count << endl;
    }
    friend void compare(Student, Student);
    friend class Teacher;
    void display()
    {
        cout << "Marks: " << marks << endl;
    }
};
int Student::count = 0;
void compare(Student s1, Student s2)
{
    if (s1.marks > s2.marks)
        cout << "Student 1 has higher marks." << endl;
    else if (s1.marks < s2.marks)
        cout << "Student 2 has higher marks." << endl;
    else
        cout << "Both students have equal marks." << endl;
}
class Teacher
{
public:
    void showMarks(Student s)
    {
        cout << "Marks accessed by Teacher: " << s.marks << endl;
    }
};
int main()
{
    Student s1(80);
    Student s2(90);
    cout << "Student 1: ";
    s1.display();
    cout << "Student 2: ";
    s2.display();
    Student::showCount();
    compare(s1, s2);
    Teacher t;
    t.showMarks(s1);
    return 0;
}
