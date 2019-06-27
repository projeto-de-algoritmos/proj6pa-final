#ifndef SUBJECT_HPP
#define SUBJECT_HPP
#include <bits/stdc++.h>
using namespace std; 

class Subject{
    public:
    string name;
    int code;
    int credits;
    int quantity_prerequisites;
    set<Subject*> prerequisites;
    Subject();
    Subject(string subject_name, int code, int credits);
    ~Subject();
    void insert_prerequisite(Subject *subject);
    void remove_prerequisite(Subject *subject);
    void show_prerequisites();
    void show_subject();
    void count_prerequisites(Subject *subject);
    bool operator<(const Subject &subject) const;
};
#endif