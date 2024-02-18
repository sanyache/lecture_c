#include<iostream>
#include<vector>

using namespace std;

struct Student{

    string first_name;
    string last_name;
    int age;
    string group;
    void print_student() const{

        cout<<last_name<<' '<<first_name<<' '<<age<<"from "<<group<<'\n';
    }
    bool is_adult() const{

        return age > 17;
    }
};

void print_student(const Student &student){

    cout<<student.last_name<<' '<<student.first_name<<' '<<student.age<<"from "<<student.group<<'\n';
}

int main(){

    //Student student;
    //student.age = 17;
    //student.first_name = "Mykola";
    //student.last_name = "Petrenko";
    //student.group = "11-A";
    //print_student(student);
    //student.print_student();
    //cout<<student.is_adult();
    vector<Student> Group;
    Group.resize(5);
    for(int i=0; i<2; i++){
        Student student;
        cout<<"Enter last name ";
        cin>>student.last_name;
        cout<<"Enter first name ";
        cin>>student.first_name;
        cout<<"Enter age ";
        cin>>student.age;
        cout<<"Enter group";
        cin>>student.group;
        Group.push_back(student);
    }
    for(size_t i=0; i<Group.size(); i++)
        Group[i].print_student();
    return 0;
}
