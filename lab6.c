#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void studentData(Idk *idk, int *numOfStudents){

    printf("Enter the number of students: ");
    scanf("%d", numOfStudents);
    printf("\n");

    idk -> count = *numOfStudents;
    idk -> info = malloc(sizeof(Info) * idk -> count); //make the dynamic memory

    if (idk -> info == NULL){ // some error handling
        printf("memory allocation failed.\n");
    }

    for (int i = 0; i < idk -> count; i++){

        printf("Entering data for student %d\n", i + 1);

        printf("Enter student Name: ");
        scanf("%s", idk -> info[i].name);

        printf("Enter student ID: ");
        scanf("%d", &idk -> info[i].ID); 

        printf("Enter student grade: ");
        scanf("%f", &idk -> info[i].grade);
        printf("\n");
    }
}

void functionRepeater(Idk *idk, int *numOfStudents){

    studentData(idk, numOfStudents); //this is supposed to repeat the studentdata function
}

void calculationFunction(Idk *idk, Info *info){

    float sumOfGrades = 0; //initializing the variable for the sumofgrades
    printf("Student Information:\n");

    for (int i = 0; i < idk -> count; i++){ //so that i can stay DRY and not wet i used this for loop to just iterate and print the names 

        printf("Name: %s, ID: %d, Grade: %.2f\n", idk -> info[i].name, idk -> info[i].ID, idk -> info[i].grade);

        sumOfGrades += idk -> info[i].grade; //add up all the grades before doing the average
        printf("The Sum of all grades is %.2f\n", sumOfGrades);
    }
    printf("\n");
    
    float avgGrade = (sumOfGrades / idk -> count);
    printf("Average Grade: %.2f\n", avgGrade);
}

int main (int argc, char **argv){

    Idk idk; //the Idk struct
    Info info; // the Info struct (has all the names, grades and IDs)
    int numOfStudents;
    
    functionRepeater(&idk, &numOfStudents); //calling the functions in here with the struct variables
    calculationFunction(&idk, &info);

    free(idk.info);
    return 0;
}