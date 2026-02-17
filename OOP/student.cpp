#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student; // forward declaration

// -------------------- Group --------------------
class Group {
private:
    string name;
    vector<Student*> students;

public:
    Group(string name) : name(name) {}

    string getName() const {
        return name;
    }

    void addStudent(Student* st);

    void removeStudent(Student* st);

    void printStudents() const;
    
};

// -------------------- User --------------------
class User {
protected:
    string first_name;
    string last_name;
    string phone;
    string birth_day;

public:
    User(string first_name, string last_name, string phone, string birth_day)
        : first_name(first_name), last_name(last_name), phone(phone), birth_day(birth_day) {}

    string getFullName() const {
        return first_name + " " + last_name;
    }
};

// -------------------- Student --------------------
class Student : public User {
private:
    Group* group;

public:
    Student(string first_name, string last_name, string phone, string birth_day)
        : User(first_name, last_name, phone, birth_day), group(nullptr) {}

    string getName() const {
        return getFullName();
    }

    Group* getGroup() const {
        return group;
    }

    void setGroup(Group* newGroup) {
        if (group == newGroup) return; // якщо це та сама група — нічого не робимо

        // якщо студент вже був у якійсь групі — видаляємо його звідти
        if (group != nullptr) {
            group->removeStudent(this);
        }

        // встановлюємо нову групу
        group = newGroup;

        // додаємо студента до нової групи
        if (group != nullptr) {
            group->addStudent(this);
        }
    }
};

// -------------------- Group methods --------------------
void Group::addStudent(Student* st) {
    // перевірка чи студент вже є в групі
    for (auto s : students) {
        if (s == st) return;
    }
    students.push_back(st);
}

void Group::removeStudent(Student* st) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i] == st) {
            students.erase(students.begin() + i);
            return;
        }
    }
}

void Group::printStudents() const {
    cout << "Group " << name << " students:" << endl;

    if (students.empty()) {
        cout << "- None" << endl;
        return;
    }

    for (auto st : students) {
        cout << "- " << st->getName() << endl;
    }
}

// -------------------- main --------------------
int main() {
    Group g1("IPZ-21");
    Group g2("KN-11");

    Student st1("Oleksandr", "Chemeris", "+380111111111", "2006-05-12");
    Student st2("Ivan", "Petrenko", "+380222222222", "2005-10-01");

    st1.setGroup(&g1);
    st2.setGroup(&g1);

    cout << "=== Before moving ===" << endl;
    g1.printStudents();
    g2.printStudents();

    cout << "\n=== Moving Oleksandr to KN-11 ===" << endl;
    st1.setGroup(&g2);

    cout << "\n=== After moving ===" << endl;
    g1.printStudents();
    g2.printStudents();

    return 0;
}
