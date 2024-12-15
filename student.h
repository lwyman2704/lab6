#ifndef STUDENT_H
#define STUDENT_H

typedef struct Info {

    char name[1024];
    int ID;
    float grade;

} Info;

typedef struct Idk {

    int count;
    Info *info;

} Idk;

void studentData(Idk *idk, int *numOfStudents);
void functionRepeater(Idk *idk, int *numOfStudents);
void calculationFunction(Idk *idk, Info *info);

#endif