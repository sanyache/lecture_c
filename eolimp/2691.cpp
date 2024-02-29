#include<iostream>
#include<vector>

using namespace std;

struct Student{

    string last_name;
    string first_name;
    int subjects_number;
    int64_t total_score = 0;
    int get_average(){
        return total_score/subjects_number;
    }
    void get_student(){
        cout<<last_name<<' '<<first_name<<'\n';
    }
};
int main(){
    vector<Student>Students;
    string s, word;
    int n, target;
    cin>>n;
    for(size_t i=0; i<n; i++){
        Student student;
        cin>>student.last_name>>student.first_name>>student.subjects_number;
        for(size_t i=0; i<student.subjects_number; i++){
            int score;
            cin>>score;
            student.total_score += score;
        }
        Students.push_back(student);
    }

    cin>>target;
    for(auto student: Students)
        if(student.get_average() >= target) student.get_student();
    return 0;
}
