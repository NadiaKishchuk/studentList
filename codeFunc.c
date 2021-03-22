#include "functions.h"
void readStudentListFromTheFile(struct studentList** first)
{
	struct studentList*startList = (struct studentList*)malloc(sizeof(struct studentList)), *Student = startList, *prevStudent = NULL;


	FILE* inFile = fopen("C:\\Users\\Íàä³ÿ\\Desktop\\çâ³òè\\â³ïç\\lab08\\lab08\\binarryFile", "rb");
	if (!inFile)
	{
		printf("the file hasn`t opened ");
		return;
	}
	while (!feof(inFile))
	{

		//fread(&el, sizeof(char), 1, inFile);
		fread(Student->student.s_surname, sizeof(char), 1, inFile);

		if (!feof(inFile))
		{
			fseek(inFile, -1, SEEK_CUR);

			/*fread(pt->s_name, sizeof(char), NAME, inFile);
			fread(pt->s_birth, sizeof(char), BIRTH, inFile);
			fread(pt->s_marks, sizeof(int), MARKS, inFile);*/
			fread(&(Student->student), sizeof(struct infoAboutStudent), 1, inFile);
			Student->next = (struct studentList*)calloc(1, sizeof(struct studentList));
			prevStudent = Student;
			Student = Student->next;
			Student->next = NULL;
		}
		else
		{
			Student->next = NULL;
			free(Student);
			Student = NULL;
			prevStudent->next = NULL;
			break;
		}
	}
	*first = startList;
	if (fclose(inFile) == EOF)
	{
		printf("the file hasn`t closed");
		return;
	}

}

void freeMemoryList(struct studentList** pHead)
{
	struct studentList*pTemp = NULL;
	pTemp = *pHead;

	while (pTemp)
	{
		*pHead = pTemp->next;
		free(pTemp);
		pTemp = NULL;
		pTemp = *pHead;
	}
	//free(pHead);
	pHead = NULL;
}

void printfStructStudent(struct studentList** pFirst)
{
	struct studentList*temp = *pFirst;
	while (temp != NULL)
	{
		printf("%-12s %-12s %-12s ", temp->student.s_surname, temp->student.s_name, temp->student.s_birth);


		for (int i = 0; i < MARKS; i++)
		{
			printf("%d ", (temp)->student.s_marks[i]);
		}
		temp = temp->next;
		printf("\n");
	}
}

void getNewStudentFromKeybord(struct studentList** first)
{
	int amountOfAddedStudent;
	printf("enter the amount of added student \n");
	scanf("%d", &amountOfAddedStudent);
	struct studentList*curStudent = NULL;

	if (amountOfAddedStudent)
	{
		*first = (struct studentList*)malloc(sizeof(struct studentList));
		curStudent = *first;
		for (int i = 0; i < amountOfAddedStudent; i++)
		{
			printf("Enter the surname, name, birthday of student and his/her marks");
			getchar();
			gets_s(curStudent->student.s_surname, SURNAME);
			gets_s(curStudent->student.s_name, NAME);
			gets_s(curStudent->student.s_birth, BIRTH);
			for (int j = 0; j < MARKS; j++)
			{
				scanf("%d", curStudent->student.s_marks + j);
			}
			if (i + 1 != amountOfAddedStudent)
			{

				curStudent->next = (struct studentList*)calloc(1, sizeof(struct studentList));
				curStudent = curStudent->next;
				curStudent->next = NULL;
			}
			curStudent->next = NULL;

		}
	}
}

int isStudentHasFourOrFive(struct studentList** student)
{
	int count = 0;
	for (int i = 0; i < MARKS; i++)
	{
		if ((*student)->student.s_marks[i] == 4 || (*student)->student.s_marks[i] == 5)
		{
			count++;
			break;
		}
	}
	return count;
}

void addNewStudent(struct studentList** StudentList, struct studentList** StudentListToAdd)
{
	struct studentList* curStudentToAdd = *StudentListToAdd, *tempListToAdd = NULL, *prevStudentInList = NULL, *nextStudentToAdd = NULL, *temp = NULL;

	while (curStudentToAdd)
	{
		curStudentToAdd->student.s_surname[0] = toupper(curStudentToAdd->student.s_surname[0]);
		tempListToAdd = *StudentList;
		nextStudentToAdd = curStudentToAdd->next;
		while ((tempListToAdd != NULL))
		{
			if (strcmp(tempListToAdd->student.s_surname, curStudentToAdd->student.s_surname) < 0)
			{
				prevStudentInList = tempListToAdd;
				tempListToAdd = tempListToAdd->next;
			}
			else
			{
				break;
			}
		}
		if (!prevStudentInList)
		{
			curStudentToAdd->next = *StudentList;
			*StudentList = curStudentToAdd;


		}
		else if (!tempListToAdd)
		{
			prevStudentInList->next = curStudentToAdd;
			prevStudentInList->next->next = NULL;

		}
		else
		{
			curStudentToAdd->next = prevStudentInList->next;
			prevStudentInList->next = curStudentToAdd;


		}
		curStudentToAdd = nextStudentToAdd;
	}

}
void deleteFirst(struct studentList** studentToDelete)
{
	struct studentList* temp = (*studentToDelete)->next;
	free(*studentToDelete);
	*studentToDelete = temp;
}

void deleteInsideList(struct studentList** prevStudent, struct studentList** studentToDelete)
{
	(*prevStudent)->next = (*studentToDelete)->next;
	free(*studentToDelete);
	*studentToDelete = (*prevStudent)->next;
}

void deleteLast(struct studentList** prevStudent, struct studentList** studentToDelete)
{
	(*prevStudent)->next = NULL;
	free(*studentToDelete);
	*studentToDelete = NULL;
}

void deleteStudent(struct studentList** StudentList)
{
	struct studentList* curStudent = *StudentList, *temp = NULL, *prevStudent = curStudent;
	while (curStudent)
	{
		if (!isStudentHasFourOrFive(&curStudent))
		{
			if (curStudent == *StudentList)
			{
				(*StudentList) = (*StudentList)->next;
				/*
				free(curStudent);
				curStudent = (*StudentList);*/

				deleteFirst(&curStudent);

			}
			else if (!curStudent->next)
			{
				/*prevStudent->next = NULL;
				free(curStudent);
				curStudent=NULL;*/
				deleteLast(&prevStudent, &curStudent);
			}
			else
			{
				/*prevStudent->next = curStudent->next;
				free(curStudent);
				curStudent = prevStudent->next;*/
				deleteInsideList(&prevStudent, &curStudent);
			}
		}
		else
		{
			prevStudent = curStudent;
			curStudent = curStudent->next;
		}

	}
}

