#include <iostream>
#include "subject.hpp"
Subject::Subject(){ 
 
}
Subject::Subject(string subject_name, int code, int credits){
	quantity_prerequisites = 0;
	
    this->name = subject_name;
    this->code = code;
    this->credits = credits;
}
Subject::~Subject(){
    //tenho que passar por todos os galhos para verificar a presença da matéria removida
}
void Subject::insert_prerequisite(Subject *subject){
    if(subject){
    	prerequisites.insert(subject);
	}
    //tenho que passar por todas os galhos para verificar a presença da matéria removida
}

void Subject::remove_prerequisite(Subject *subject){
	if(subject){
		if(prerequisites.count(subject)!=0){
			prerequisites.erase(subject);
		}
	}
}

void Subject::show_prerequisites(){
    for(auto prerequisite: prerequisites){
    	prerequisite->show_subject();
    }
}

void Subject::show_subject(){
	cout << "Name: " << name << endl;
	cout << "Code: " << code << endl;
	cout << "Credits: " << credits << endl << endl;
}

void Subject::count_prerequisites(Subject *subject){
	set<Subject*> visited_subjects;
	queue<Subject*> to_visit;
	to_visit.push(subject);
	visited_subjects.insert(subject);

	while(!to_visit.empty()){
		auto subj = to_visit.front();
		to_visit.pop();
		for(auto prerequisite : subj->prerequisites){
			if(visited_subjects.count(prerequisite) == 0){
				visited_subjects.insert(prerequisite);
				to_visit.push(prerequisite);
			}
		}
	}
	quantity_prerequisites = visited_subjects.size()-1;
}

bool Subject::operator<(const Subject &subject) const{
	if(quantity_prerequisites==subject.quantity_prerequisites){
		return credits < subject.credits;
	}
	return quantity_prerequisites > subject.quantity_prerequisites;
}