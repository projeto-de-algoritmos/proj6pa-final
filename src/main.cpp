#include "subject.hpp"
#include "functions.hpp"
#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;
void list_subejcts2(priority_queue<Subject> subjects_to_do);
void list_subejcts(vector<Subject> subjects);
vector<Subject> subject_generate();

int main(){
    while(1){
        system("clear");
        // O teste está com base de que o estudante deseja pegar no máximo
        // 6 matérias por semestre. Para alterar esse valor, basta mudar o
        // último argumento passado na função show_schedule

        vector<Subject> subjects = subject_generate();

        
        sort(subjects.begin(), subjects.end());
        reverse(subjects.begin(), subjects.end());  
        /*cerr << "_------------------------------------------------_\n";
        for(auto subj : subjects){
            cerr << subj.name << " Credits = " << subj.credits << " Qnt pre = " << subj.quantity_prerequisites << endl;
        }
        cerr << "_------------------------------------------------_\n\n\n";*/
        int i;
        list_subejcts(subjects);
        while(1){
            char in[50];
            cout << "\x1B[47m\x1B[30mInsira o ID da matéria desejada. Digite 'exit' para sair."<<endl;
            cout<<"ID: \033[0m";
            cin >> in;
            getchar();
            i = atoi(in);
            if(!strcmp(in, "exit"))
                return 0;
            if(i>0&&i<=int(subjects.size())){
                system("clear");
                break;
            }
            else{
                cout << "\x1B[41m\x1B[37mEste ID não é válido." << "Tente novamente.\033[0m"<<endl;
            }
        }
        cout <<"\x1B[44m\x1B[37m"<< "Matéria desejada:" << subjects[i-1].name <<" \033[0m"<< endl << endl;
        priority_queue<Subject> subject_order = bfs_changed(subjects[i-1]);
        
        show_schedule(subject_order, &subjects, 6);
        cout<<endl;
        cout<<"\x1B[42m\x1B[30mPressione ENTER para continuar...\033[0m"<<endl;
        getchar();
    }
  
    return 0;
}

void show(){
    
}

void list_subejcts(vector<Subject> subjects){
    for (int i = 0; i < 75; i++){
        cout<<"\x1B[44m  \033[0m";
    }
    cout<<"\x1B[44m \033[0m"<<endl;
    cout<<"\x1B[44m                                                             \033[0m";
    cout<<"\x1B[40mFLUXO MAKER\033[0m";
    cout<<"\x1B[44m                                                                               \033[0m"<<endl;
    for (int i = 0; i < 75; i++){
        cout<<"\x1B[44m  \033[0m";
    }
    cout<<"\x1B[44m \033[0m"<<endl;

    int i, coluna2 = 20;
    string texto(64, ' '); //= "                                                           ";
    string texto2(64, ' '); //= "                                                           ";
    //const char *c_texto = texto.c_str();
    //const char *c_texto2 = texto2.c_str();
    for(i = 0; coluna2<subjects.size() and i < 20; ++i, coluna2++){
        texto = subjects[i].name;
        int begin = texto.size();
        while (begin < 64){
            texto.push_back(' ');
            begin++;
        }

        texto2 = subjects[coluna2].name;
        begin = texto2.size();
        while (begin < 46){
            texto2.push_back(' ');
            begin++;
        }
        texto2[begin] = '\0';
        cout << "\x1B[44m  \033[0m\t\x1B[37m" << setw(2) << setfill('0') << i+1 << " - " << texto <<"\t"<<coluna2+1<< " - "<< texto2<<"\033[0m\t\x1B[44m               \033[0m"<<endl;
    }
    cout<<"\x1B[44m  \033[0m                                                          \x1B[37m"<<"\t\t\t"<<coluna2+1<< " - "<<subjects[coluna2].name<<"\033[0m\t\t\t\t\x1B[44m               \033[0m"<<endl;
    for (int i = 0; i < 75; i++){
        cout<<"\x1B[44m  \033[0m";
    }
    cout<<"\x1B[44m \033[0m"<<endl;
}

vector<Subject> subject_generate(){
    Subject *rs, *pi2, *eps, *tppe, *ts, *mds, *oo, *apc, *comp, *ed1, *pp, *ads, *gces, *fse, *fso, *fac, *ted_ped, *ial, *pspd, *ed2, *frc, *sbd2, *sbd1, *md2, *md1, *pa, *qs, *gpq, *ee, *ihc, *diac, *hc, *mne, *c2, *c1, *f1, *f1e, *peae, *ea, *ie, *pi1;
    set<Subject *> inicial_subjects;
    vector<Subject> final_subjects;
    //cadastro de matérias
    inicial_subjects.insert(pi2 = new Subject("Projeto Integrador 2", 208175, 6));
    inicial_subjects.insert(eps = new Subject("Engenharia de Produto de Software", 203874, 4));
    inicial_subjects.insert(tppe = new Subject("Técnicas de Programação em Plataformas Emergentes", 206601, 4));
    inicial_subjects.insert(ts = new Subject("Testes de Software", 206580, 4));
    inicial_subjects.insert(mds = new Subject("Métodos de Desenvolvimento de Software", 193640, 4));
    inicial_subjects.insert(oo = new Subject("Orientação a Objetos", 195341, 4));
    inicial_subjects.insert(apc = new Subject("Algoritmos e Programação de Computadores", 12345, 6));
    inicial_subjects.insert(comp = new Subject("Compiladores 1", 101095, 4));
    inicial_subjects.insert(ed1 = new Subject("Estrutura de Dados 1", 193704, 4));
    inicial_subjects.insert(pp = new Subject("Paradigmas de Programação", 203904, 4));
    inicial_subjects.insert(ads = new Subject("Arquitetura e Desenho de Software", 203882, 4));
    inicial_subjects.insert(gces = new Subject("Gerência de configuração e evolução de software", 206598, 4));
    inicial_subjects.insert(fse = new Subject("Fundamentos de Sistemas Embarcados", 127701, 4));
    inicial_subjects.insert(fso = new Subject("Fundamentos de Sistemas Operacionais", 201286, 4));
    inicial_subjects.insert(fac = new Subject("Fundamentos e Arquitetura de Computadores", 193674, 4));
    inicial_subjects.insert(ted_ped = new Subject("Teoria e Prática de Eletrônica Digital 1", 119482, 6));
    inicial_subjects.insert(ial = new Subject("Introdução a Álgebra Linear", 113093, 4));
    inicial_subjects.insert(pspd = new Subject("Programação para Sistemas Paralelos e Distribuídos", 206610, 4));
    inicial_subjects.insert(ed2 = new Subject("Estrutura de Dados 2", 103209, 4));
    inicial_subjects.insert(frc = new Subject("Fundamentos de Redes de Computadores", 203912, 4));
    inicial_subjects.insert(sbd2 = new Subject("Sistemas de Banco de Dados 2", 115576, 4));
    inicial_subjects.insert(sbd1 = new Subject("Sistemas de Banco de Dados 1", 193631, 4));
    inicial_subjects.insert(md2 = new Subject("Matemática Discreta 2", 127698, 4));
    inicial_subjects.insert(md1 = new Subject("Matemática Discreta 1", 120669, 4));
    inicial_subjects.insert(pa = new Subject("Projeto de Algoritmos", 130508, 4));
    inicial_subjects.insert(qs = new Subject("Qualidade de Software", 208698, 4));
    inicial_subjects.insert(gpq = new Subject("Gestão da Produção e Qualidade", 201626, 4));
    inicial_subjects.insert(ee = new Subject("Engenharia Econômica", 193321, 4));
    inicial_subjects.insert(ihc = new Subject("Interação Humano Computador", 201316, 4));
    inicial_subjects.insert(diac = new Subject("Desenho Industrial Assistido por computador", 199176, 6));
    inicial_subjects.insert(hc = new Subject("Humanidades e Cidadania", 199133, 4));
    inicial_subjects.insert(mne = new Subject("Métodos Numéricos para Engenharia", 195413, 4));
    inicial_subjects.insert(c2 = new Subject("Cálculo 2", 113042, 6));
    inicial_subjects.insert(c1 = new Subject("Cálculo 1", 113034, 6));
    inicial_subjects.insert(f1 = new Subject("Física 1", 118001, 4));
    inicial_subjects.insert(f1e = new Subject("Física 1 Experimental", 118010, 2));
    inicial_subjects.insert(peae = new Subject("Probabilidade e Estatística Aplicada à Engenharia", 195332, 4));
    inicial_subjects.insert(ea = new Subject("Engenharia e Ambiente", 198005, 4));
    inicial_subjects.insert(ie = new Subject("Introdução a Engenharia", 198013, 2));
    inicial_subjects.insert(pi1 = new Subject("Projeto Integrador de Engenharia 1", 193861, 4));
    inicial_subjects.insert(rs = new Subject("Requisitos de Software", 201308, 4));

    //inserção de pré-requisitos
    pi2->insert_prerequisite(eps);
    eps->insert_prerequisite(tppe);
    gces->insert_prerequisite(ts);
    tppe->insert_prerequisite(ts);
    tppe->insert_prerequisite(ads);
    pp->insert_prerequisite(comp);
    pp->insert_prerequisite(oo);
    fse->insert_prerequisite(fso);
    pspd->insert_prerequisite(frc);
    qs->insert_prerequisite(ihc);
    qs->insert_prerequisite(gpq);
    ts->insert_prerequisite(mds);
    ads->insert_prerequisite(rs);
    frc->insert_prerequisite(fso);
    sbd2->insert_prerequisite(sbd1);
    pa->insert_prerequisite(ed1);
    pa->insert_prerequisite(c1);
    ihc->insert_prerequisite(mds);
    ihc->insert_prerequisite(diac);
    rs->insert_prerequisite(mds);
    sbd1->insert_prerequisite(md2);
    fso->insert_prerequisite(fac);
    comp->insert_prerequisite(ed1);
    ed2->insert_prerequisite(ed1);
    gpq->insert_prerequisite(ee);
    mds->insert_prerequisite(oo);
    ed1->insert_prerequisite(apc);
    fac->insert_prerequisite(ted_ped);
    md2->insert_prerequisite(md1);
    pi1->insert_prerequisite(oo);
    mne->insert_prerequisite(c2);
    ted_ped->insert_prerequisite(ial);
    oo->insert_prerequisite(apc);
    c2->insert_prerequisite(c1);
    peae->insert_prerequisite(c1);

    for(auto subject : inicial_subjects){
        //cerr << subject->name << " na main\n";
        subject->count_prerequisites(subject);
        final_subjects.push_back(*subject);
    }

    return final_subjects;
}
