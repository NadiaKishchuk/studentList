#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define SURNAME 30
#define NAME 20 
#define BIRTH 15
#define MARKS 7
struct infoAboutStudent {
	char s_surname[SURNAME];
	char s_name[NAME];
	char s_birth[BIRTH];
	int s_marks[MARKS];
};
struct studentList
{
	struct infoAboutStudent student;
	struct studentList * next;
};
void readStudentListFromTheFile(struct studentList** first);
void printfStructStudent(struct studentList** pFirst);
void getNewStudentFromKeybord(struct studentList** first);
int isStudentHasFourOrFive(struct studentList** student);
void addNewStudent(struct studentList** StudentList, struct studentList** StudentListToAdd);
void deleteStudent(struct studentList** StudentList);
void deleteFirst(struct studentList** studentToDelete);
void deleteInsideList(struct studentList** prevStudent, struct studentList** studentToDelete);
void deleteLast(struct studentList** prevStudent, struct studentList** studentToDelete);
void freeMemoryList(struct studentList** pHead);




#endif
