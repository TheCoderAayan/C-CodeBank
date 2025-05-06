#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a)  {
	
	name=n;
	age=a;
	}

    virtual void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    
    string getName() const { return name; }
};

class Student : public Person {
private:
    int rollNumber;
    string branch;
    int marks;

public:
    Student(string n, int a, int roll, string b, int m) : Person(n, a), rollNumber(roll), branch(b), marks(m) {}

    float cgpa() {
        if (marks > 90) return 10.0;
        else if (marks > 80) return 9.0;
        else if (marks > 70) return 8.0;
        else if (marks > 60) return 7.0;
        else if (marks > 50) return 6.0;
        else if (marks > 40) return 5.0;
        else return 0.0;
    }

    void display() override {
        Person::display();
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Branch: " << branch << endl;
        cout << "Marks: " << marks << ", CGPA: " << cgpa() << endl;
    }


    string getBranch() const { return branch; }
    int getMarks() const { return marks; }
};

class Faculty : public Person {
private:
    int facultyID;
    string department;
    float salary;

public:
    Faculty(string n, int a, int id, string dept, float sal) : Person(n, a), facultyID(id), department(dept), salary(sal) {}

    void display() override {
        Person::display();
        cout << "Faculty ID: " << facultyID << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }

  
    int getFacultyID() const { return facultyID; }
    string getDepartment() const { return department; }
    float getSalary() const { return salary; }
};

class TeachingAssistant : public Student, public Faculty {
public:
    TeachingAssistant(string n, int a, int roll, string b, int m, int id, string dept, float sal)
        : Student(n, a, roll, b, m), Faculty(n, a, id, dept, sal) {}

    void display() override {
        Student::display();
        
        cout << "Faculty ID: " << getFacultyID() << endl;
        cout << "Department: " << getDepartment() << endl;
        cout << "Salary: " << getSalary() << endl;
    }
};

class Administration {
public:
    void displayDetails(Student &s, Faculty &f) {
        cout << endl << "Administration Function:" << endl;
        cout << "Student " << s.getName() << " from " << s.getBranch() << " scored " << s.getMarks() << " marks." << endl;
        cout << "Faculty " << f.getName() << " teaches " << f.getDepartment() << "." << endl;
    }
};

int main() {
    Student s1("Raj Malhotra", 20, 2023101, "CSE (AI-ML)", 89);
    Faculty f1("Dr. A. Sharma", 45, 1001, "Computer Science", 120000);
    TeachingAssistant ta1("Priya Desai", 25, 1923105, "CSE (AI-ML)", 85, 2005, "Artificial Intelligence", 35000);

    cout << "Student Details:" << endl;
    s1.display();
    cout << "\nFaculty Details:" << endl;
    f1.display();
    cout << "\nTeaching Assistant Details:" << endl;
    ta1.display();

    Administration admin;
    admin.displayDetails(s1, f1);

    return 0;
}
