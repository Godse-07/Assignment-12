//Write a program which accepts names, rolls and marks of 10 students in 6 subjects stores it in an array of structures. Write a separate function which prints in ascending order the rank list (roll, name, average) based on the average of 6 subjects.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    int marks[6];
    float avg;
};

void printRankList(struct Student arr[], int n) {
    // calculate average for each student
    for (int i = 0; i < n; i++) {
        float sum = 0;
        for (int j = 0; j < 6; j++) {
            sum += arr[i].marks[j];
        }
        arr[i].avg = sum / 6.0;
    }

    // sort the array in ascending order based on average marks
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].avg > arr[j+1].avg) {
                struct Student temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // print the rank list
    printf("Rank\tRoll\tName\tAverage\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%s\t%.2f\n", i+1, arr[i].roll, arr[i].name, arr[i].avg);
    }
}

int main() {
    struct Student students[10];

    // read input for 10 students
    for (int i = 0; i < 10; i++) {
        printf("Enter details for student %d:\n", i+1);
        printf("Roll: ");
        scanf("%d", &students[i].roll);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Enter marks in 6 subjects: ");
        for (int j = 0; j < 6; j++) {
            scanf("%d", &students[i].marks[j]);
        }
    }

    
    printRankList(students, 10);

    return 0;
}
