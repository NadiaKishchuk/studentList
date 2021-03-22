#include "functions.h"

int main()
{
	struct studentList*start = NULL;
	struct studentList*startAddedStudent = NULL;
	readStudentListFromTheFile(&start);
	getNewStudentFromKeybord(&startAddedStudent);
	printfStructStudent(&start);
	printf("\n\n");
	addNewStudent(&start, &startAddedStudent);
	printfStructStudent(&start);
	deleteStudent(&start);
	printf("\n\n");
	printfStructStudent(&start);
	freeMemoryList(&start);
	
	return 0;
}







/*void addFirst(struct studentList**firstStudent, struct studentList**addedStudent)
{
	(*addedStudent)->next = *firstStudent;
	*firstStudent = *addedStudent;
}*/




