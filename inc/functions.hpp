#ifndef FUNCOES_HPP
#define FUNCOES_HPP

priority_queue<Subject> bfs_changed(Subject desired_subject);
void show_schedule(priority_queue<Subject> subjects_order, vector<Subject> *subjects_to_do, int max_subjects);
queue<Subject> complete_schedule(queue<Subject> semester_subjects, vector<Subject> *subjects_to_do, set<int> *concluded_subjects, int total_credits, int max_subjects);

#endif