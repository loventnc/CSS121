#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

void printStudent (struct Students student);

struct Students
{
    char name[50];
    int score;
    char grade[1];
};

double MaxStudent(Students student[],int size){
    int max_score = student[0].score;
    for(int i=0; i<size; i++){
        if(max_score < student[i].score or i==0){
            max_score = student[i].score;
        }
    }
    return max_score;
}
string MaxStudentName(Students student[],int size){
    int max_score = student[0].score;
    string name;
    for(int i=0; i<size; i++){
        if(max_score < student[i].score or i==0){
            max_score = student[i].score;
            name = student[i].name;
        }
    }
    return name;
}

double MinStudent(Students student[],int size){
    int min_score = MaxStudent(student,size);
    for(int i=0; i<size; i++){
        if(student[i].score < min_score or i == 0){
            min_score = student[i].score;
        }

    }
    return min_score;
}
string MinStudentName(Students student[],int size){
    int min_score = MaxStudent(student,size);
    string student_name;
    for(int i=0; i<size; i++){
        if(student[i].score < min_score or i == 0){
            min_score = student[i].score;
            student_name = student[i].name;
        }

    }
    return student_name;
}

double AvrScore(Students student[],int size){
    double avr_score = 0;
    for(int i=0; i<size; i++){
        avr_score+=student[i].score;
    }
    return avr_score/size;
}

double ModeScore(Students student[],int size){
    double score_list[size];
    int size_list = sizeof(score_list)/sizeof(score_list[0]);
    for(int i=0; i<size;i++){
        score_list[i] = student[i].score;
    }
    sort(score_list,score_list+size_list);
    int max_mode = 1, most_num = score_list[0], count = 1;
    for(int i=1; i<size ; i++){
        if(score_list[i]==score_list[i-1]){
            count++;
        }
        else{
            if(count>max_mode){
                max_mode = count;
                most_num = score_list[i-1];
            }
            count = 1;
        }
    }
    if(count>max_mode){
        most_num = score_list[size-1];
    }
    return most_num;
}

double MedianScore(Students student[],int size){
    double score_list[size];
    int size_list = sizeof(score_list)/sizeof(score_list[0]);
    for(int i=0; i<size; i++){
        score_list[i] = student[i].score;
    }
    sort(score_list,score_list+size_list);
    return (size_list%2==0)? (score_list[(size_list/2)-1]+score_list[size_list/2])/2 : score_list[size_list/2];
}

double SDScore(Students student[],int size){
    double x_bar = AvrScore(student,size), sum = 0;
    for(int i=0; i<size; i++){
        sum += pow((student[i].score - x_bar),2);
    }
    return sqrt(sum/(size-1));
}

void GradeStudent(Students student[], int size) {
    double avr = AvrScore(student, size);
    double sd = SDScore(student, size);
    for (int i = 0; i < size; i++) {
        if (student[i].score > avr + (2 * sd)) {
            cout << student[i].name << " Grade = A" << endl;
        } else if (student[i].score < avr + (2 * sd) && student[i].score > avr + sd) {
            cout << student[i].name << " Grade = B" << endl;
        } else if (student[i].score < avr + sd && student[i].score > avr) {
            cout << student[i].name << " Grade = C" << endl;
        } else if (student[i].score < avr && student[i].score > avr - sd) {
            cout << student[i].name << " Grade = D" << endl;
        } else {
            cout << student[i].name << " Grade = F" << endl;
        }
    }
}

int main()
{
    Students student[10];
    student[0] = {"Luffy", 75};
    student[1] = {"Zoro", 89};
    student[2] = {"Sanji", 61};
    student[3] = {"Law", 81};
    student[4] = {"Ace", 77};
    student[5] = {"Franky", 60};
    student[6] = {"Nami", 59};
    student[7] = {"Usopp", 47};
    student[8] = {"Chopper", 72};
    student[9] = {"Robin", 56};
    int size = sizeof(student)/sizeof(student[0]);

    cout << "Max score: " << MaxStudentName(student,size) << " = " << MaxStudent(student,size) << endl;
    cout << "Min score: " << MinStudentName(student,size) << " = " << MinStudent(student,size) << endl;
    cout << "Average score: " << AvrScore(student,size) << endl;
    cout << "Mode score: " << ModeScore(student,size) << endl;
    cout << "Median score: " << MedianScore(student,size) << endl;
    cout << "SD score: " << SDScore(student,size) << endl;
    GradeStudent (student,size);

    return 0;
}