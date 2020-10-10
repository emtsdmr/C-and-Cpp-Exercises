#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include <string>
class Person{
    protected:
        string name;
        int age;
    public:
        virtual void getdata()=0; 
       /* {
            cin >> name >> age;
        }*/
        virtual void putdata() 
        {
            cout << name << " " << age << endl;
        }
};
class Student:public Person{
    public:
        Student()
        {
            id++;
            cur_id=id;
        }
        static int id;
        int cur_id;
        int marks[6];
        void getdata()
        {
            cin>>name>>age;
            for(int i=0;i<6;i++)
            {
                cin>>marks[i];
            }
        }   

        void putdata()
        {
            int sum=0;
            for(int i=0;i<6;i++)
            {
                sum+=marks[i];
            }
            cout<<name<<" "<<age<<" "<<sum<<" "<<cur_id<<endl;
        } 
};
class Professor:public Person{
    public:
        Professor()
        {
            id++;
            cur_id=id;
        }
        static int id;
        int cur_id;
        int publications;
        void getdata()
        {
            cin>>name>>age>>publications;
        }   
        void putdata()
        {
            cout<<name<<" "<<age<<" "<<publications<<" "<<cur_id<<endl;
        } 
};
int Professor::id=0;
int Student::id=0;
int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}

