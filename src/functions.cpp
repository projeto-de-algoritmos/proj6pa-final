#include "subject.hpp"
#include "functions.hpp"
#include <bits/stdc++.h>
#include <typeinfo>
#define debug(x) cerr << #x << ": " << x << endl;
#define debug_sub(x) cerr << #x << ": " << x.name << " " << x.code << " " << x.credits << " " << x.quantity_prerequisites << endl;

const int MAX_CREDITS = 32;

using namespace std;

priority_queue<Subject> bfs_changed(Subject desired_subject){
	set<Subject> visited_subjects;
	priority_queue<Subject> subjects_order;
	queue<Subject> to_visit;
	to_visit.push(desired_subject);
	visited_subjects.insert(desired_subject);
	subjects_order.push(desired_subject);

	while(!to_visit.empty()){
		auto subject = to_visit.front();
		to_visit.pop();
		for(auto prerequisite : subject.prerequisites){
			if(visited_subjects.count(*prerequisite) == 0){
				visited_subjects.insert(*prerequisite);
				to_visit.push(*prerequisite);
				subjects_order.push(*prerequisite);
			}
		}
	}

	return subjects_order;
}

void show_schedule(priority_queue<Subject> subjects_order, vector<Subject> *subjects_to_do, int max_subjects){
	set<int> concluded_subjects;
	for(int semester = 1; !subjects_order.empty()&&semester <= 10; semester++){
		bool prerequisites_concluded = true;
		int total_credits = 0;
		queue<Subject> semester_subjects;
		queue<Subject> over_credit;
		while(prerequisites_concluded&&!subjects_order.empty()){
			auto subject = subjects_order.top();
			for(auto prerequisite : subject.prerequisites){
				if(concluded_subjects.count(prerequisite->code) == 0){
					//cerr << "Prerequisito true\n";
					//debug_sub((*prerequisite));
					prerequisites_concluded = false;
				}
			}
			if(prerequisites_concluded){
				if(concluded_subjects.count(subject.code)==0&&
				   total_credits + subject.credits <= MAX_CREDITS){
				   	//debug_sub(subject);
				   	//cerr << "Entrou pro semestre\n";
					semester_subjects.push(subject);
					total_credits += subject.credits;
				}
				else if(concluded_subjects.count(subject.code)==0){
					//debug_sub(subject);
				   	//cerr << "Não entrou pro semestre\n";
					over_credit.push(subject);
				}else{
					//debug_sub(subject);
				   	//cerr << "Entrou pra nada\n";
				}
				subjects_order.pop();
			}
		}

		while(!over_credit.empty()){
			subjects_order.push(over_credit.front());
			over_credit.pop();
		}

		/*cerr << "DEBUG SEMESTER SUBJECTS\n";
		for(int i=0; i<semester_subjects.size(); ++i){
			auto a = semester_subjects.front();
			debug_sub(a);
			semester_subjects.pop();
			semester_subjects.push(a);
		}*/

		semester_subjects = complete_schedule(semester_subjects, subjects_to_do, &concluded_subjects, total_credits, max_subjects);
		if(semester == 1)
			cout << "--------------------------------------------------\n";
		total_credits = 0;
		cout << semester << "º semester:\n";
		while(!semester_subjects.empty()){
			auto subject = semester_subjects.front();
			cout << subject.name << endl;
			concluded_subjects.insert(subject.code);
			total_credits+= subject.credits;
			semester_subjects.pop();
		}
		cout << "Total credits: " << total_credits << endl;
		cout << "--------------------------------------------------\n";
	}
}

queue<Subject> complete_schedule(queue<Subject> semester_subjects, vector<Subject> *subjects_to_do, set<int> *concluded_subjects, int total_credits, int max_subjects){
	set<int> choosed_subjects;
	for(int i=0; i<int(semester_subjects.size()); ++i){
		choosed_subjects.insert(semester_subjects.front().code);
		semester_subjects.push(semester_subjects.front());
		semester_subjects.pop();
	}
/*
	cerr << "DEBUG CHOOSED\n";
	for(auto a : choosed_subjects){
		debug(a);
	}

	cerr << "DEBUG CONCLUDED\n";
	for(auto a : *concluded_subjects){
		debug(a);
	}
*/
	auto subjects = *subjects_to_do;
	for(auto subject : subjects){
		//debug_sub(subject);
		bool prerequisites_concluded = true;

		if(int(semester_subjects.size())==max_subjects && prerequisites_concluded){
			break;
		}

		for(auto prerequisite : subject.prerequisites){
			if(concluded_subjects->count(prerequisite->code) == 0){
				prerequisites_concluded = false;
			}
		}
		//debug(prerequisites_concluded);
	/*	debug(total_credits);
		debug(MAX_CREDITS);
		debug((concluded_subjects->count(subject.code)==0));
		debug((choosed_subjects.count(subject.code)==0));
		debug((total_credits + subject.credits <= MAX_CREDITS));

		debug_sub(subject);

		cerr << "DEBUG CHOOSED\n";
		for(auto a : choosed_subjects){
			debug(a);
		}

		debug(choosed_subjects.count(subject.code));*/

		if(prerequisites_concluded){
			if(concluded_subjects->count(subject.code)==0&&
			   choosed_subjects.count(subject.code)==0&&
			   total_credits + subject.credits <= MAX_CREDITS){
				//cerr << "Heree\n";
				//debug_sub(subject);
				semester_subjects.push(subject);
				total_credits += subject.credits;
			}
		}
	}

	while(int(semester_subjects.size()) < max_subjects){
		semester_subjects.push(Subject("Matéria optativa", 0, 0));
	}

	return semester_subjects;
}