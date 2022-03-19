/* Copyright Liam O'Brien December 2019 
   A C application that focuses primarily on algorithm and function structure
   Creates a simple course manager simulating a course selection environment
*/

#include <stdio.h>
#include <string.h>
#define MAXSTUDENT 1000
//---------------------------------------------------
int getId (int *pId);
int findStudent();
int searchStudent();
int studentExist(int cId);
int menu (int *menuPick);
void addClass(int x);
void deleteClass (int x);
char* displayName();
char menuOption(int x);
void showCurrentClasses(int x);
int checkNumberOfCourses (int numCourses);
int checkCourseNumber (int crn);
int checkClassNumber(int x);
int getCreditHours(int crn);
void printInvoiceLine (int crn, char* cr_Prefix, int cr_Hours, float cost);
void printInvoice (int id);
int cId, crn, crn1, crn2, crn3, crn4, creditHours, hr1, hr2, check2, check3, check27, counter, counter2, cHour, menuPick;
int pId = 0;
int i = 0;
char name[100];
typedef struct
{
	int crns;
	char course[50];
	int cHour;
	
} classes;
typedef struct
{
	int id;
	char name[50];
	int crns[4];
	int numberOfClasses;
	
} student; //new data type named "student"
float total;
classes cla[] = {{4587, "MAT 236", 4}, {4599, "COP 220", 3}, {8997, "GOL 124", 1}, {9696, "COP 100", 3},
				 {1232, "MAC 531", 5}, {9856, "STA 100", 2}, {8520, "TNV 400", 5}, {8977, "CMP 100", 1}};

student std[MAXSTUDENT], std1, std2;
int courseExist(int courseNumber, student *std);
//---------------------------------------------------
int main()
{	
	int classCount = sizeof(cla)/sizeof(classes);
	int id = 0;
	int pId = 0;
	int i = 0;
	int numCourses = 0;
	printf("\tWelcome!\n\tChoose from the following options: \n\n");
	menu(&menuPick);
	
	while (menuPick != 0)
	{
		if(menuPick == 1) //add new course
		{
			getId(&pId);
			std1.id = pId;
			std[i] = std1;
			strcpy (std1.name, displayName());
			std[i] = std1;
			checkNumberOfCourses(numCourses);
			checkCourseNumber(crn);
			std[i] = std1;	
			i++;
			printf("\t\t\nStudent added successfully!\n\n--------------------------------------------\n\n");
		}
		else if(menuPick == 2) //add or delete a course
		{
			int a;
			char b;
			char yesOrNo = ' ';
			a = findStudent();
			showCurrentClasses(a);
			b = menuOption(a);
			if (b == 'a')
			{
				addClass(a);
				
			}
			else if (b == 'd')
			{
				deleteClass(a);
			}
			
			if (b != 'c')
			{
				while(yesOrNo != 'y' && yesOrNo != 'n')
				{
					printf("Would you like to print the new invoice? Y/N: ");
					fflush(stdin);
					scanf("%c", &yesOrNo);
					yesOrNo = tolower(yesOrNo);
					if(yesOrNo == 'y')
					{
						printInvoice(a);
					}
					else if (yesOrNo != 'n')
					{
						printf("Invalid Character.");
					}
				}
			}
		}
		else if(menuPick == 3) //search for a student
		{
			int x = searchStudent();
			if(x >= 0)
			{
				showCurrentClasses(x);
			}
		}
		else if(menuPick == 4) //print fee invoice
		{
			int x = searchStudent();
			if(x >= 0)
			{
				printInvoice(x);
			}
		}
		else if(menuPick != 0)
		{
			printf("Invalid Choice\n\n");
		}
		menu(&menuPick);
	}
	printf("Goodbye!");
	return 0;
}
//---------------------------------------------------
int menu (int *menuPick)
{
	printf("\t1- Add a new student \n\t");
	printf("2- Add/Delete a course for a student \n\t");
	printf("3- Search for a student \n\t");
	printf("4- Print fee invoice \n\t");
	printf("0- Exit program \n");
	printf("\nEnter your selection: ");
	scanf("%d", &*menuPick);
	
}
char menuOption(int x)
{
char option = ' ';
	while(option != 'a' &&
		  option != 'd' &&
		  option != 'c')
	{
		printf("\nChoose from:\n");
		printf("A- Add a new course for [%s]\n", std[x].name);
		printf("D- Delete a course from [%s]'s schedule\n", std[x].name);
		printf("C- Cancel operation\n\n");
		printf("Enter your selection: ");
		fflush(stdin);
		scanf("%c", &option);
		if(option != 'a' &&
		   option != 'd' &&
		   option != 'c')
		  {
		  	printf("\n\t\tError invalid character option (Must be a/d/c).\n\n");
		  }
	}
	return tolower(option);
}
int getId (int *pId)
{
	int done = 0;
	while(!done)
	{
		printf("\n\nEnter the Students ID: ");
		scanf("%d", &*pId);
		
		if(studentExist(*pId))
		{
			printf("Student already exists.");
		}
		else
		{
			done = 1;
		}
	}
	
}
int findStudent()
{
	
	int i;
	int found = 0;
	int cId = 0;
	while(!found)
	{
		i = 0;
		printf("\n\nEnter the Students ID: ");
		scanf("%d", &cId);
		while(!found && (i < MAXSTUDENT))
		{
			if(cId == std[i].id)
			{
				found = 1;
				
			}
			else
			{
				i++;
			}
		}
		if(!found)
		{
			printf("Sorry you have not entered a valid student number.");
		}
		
	}
	return i;	
}
int searchStudent()
{
		
	int i;
	int found = 0;
	int done = 0;
	int cId = 0;
	while(!found && !done)
	{
		i = 0;
		printf("\n\nEnter the Students ID: ");
		scanf("%d", &cId);
		while(!found && (i < MAXSTUDENT))
		{
			if(cId == std[i].id)
			{
				found = 1;
				done = 1;
				
				
			}
			else
			{
				i++;
			}
		}
		if(!found)
		{
			printf("Sorry you have not entered a valid student number.\n\n");
			done = 1; //allows for early exit and doesn't get stuck in an infininte loop
			i = -1;
		}
		
	}
	return i;	
}
int studentExist(int cId)
{
	int i;
	int found = 0;
	int done = 0;
	while(!found && !done)
	{
		i = 0;
		while(!found && (i < MAXSTUDENT))
		{
			if(cId == std[i].id)
			{
				found = 1;
				done = 1;
				
			}
			else
			{
				i++;
			}
		}
		if(!found)
		{
			done = 1; //allows for early exit and doesn't get stuck in an infininte loop
		}
		
	}
	return found;	
}
int courseExist(int courseNumber, student *std)
{
	int i;
	int found = 0;
	int done = 0;
	while(!found && !done)
	{
		i = 0;
		while(!found && (i < std->numberOfClasses))
		{
			
			if(courseNumber == std->crns[i])
			{
				found = 1;
				done = 1;
				
			}
			else
			{
				i++;
			}
		}
		if(found)
		{
			printf("%d is a duplicate class.\n", courseNumber);
			 //allows for early exit and doesn't get stuck in an infininte loop
		}
		done = 1;
		
	}
	return found;	
}

char* displayName()
{
	char name[100];
	printf("Enter name: ");
	fflush(stdin);
    gets(name); 
}
void showCurrentClasses(int x)
{
	int i, z;
	printf("\n\t\tHere are the courses [%s] is taking: \n", std[x].name);
	printf("\t\t\tCRN\tPREFIX\t\tCR. HOURS\n");
	for(i = 0; i < std[x].numberOfClasses; i++)
	{
		z = checkClassNumber(std[x].crns[i]);
		printf("\t\t\t%d\t%s\t\t%d\n", cla[z].crns, cla[z].course, cla[z].cHour);
	}
	printf("\n\n");
}
int checkNumberOfCourses (int numCourses)
{
	printf("Enter how many courses [%s] is taking (up to 4 courses)? \n\t", std1.name);
	scanf("%d", &numCourses);
	while(numCourses != 0 && 
	      numCourses != 1 && 
		  numCourses != 2 && 
		  numCourses != 3 && 
		  numCourses != 4)
	{
		printf("Sorry you have not entered a valid number of classes.\n");
		printf("Enter how many courses [%s] is taking (up to 4 courses)? \n\t", std1.name);
		scanf("%d", &numCourses);
	}
	if (numCourses == 0)
	{
		std1.numberOfClasses = 0;
		return 1;
	}
	else if (numCourses == 1)
	{
		std1.numberOfClasses = 1;
		return 1;
	}
	else if (numCourses == 2)
	{
		std1.numberOfClasses = 2;
		return 1;
	}
	else if (numCourses == 3)
	{
		std1.numberOfClasses = 3;
		return 1;
	}
	else if (numCourses == 4)
	{
		std1.numberOfClasses = 4;
		return 1;
	}
	
}
int checkCourseNumber (int crn)
{ 
	int done = 0;
	
	printf("\n\tALL CLASSES\n\tCRN \tCourse\t\tCredit Hours");
	printf("\n\t4587 \tMAT 236\t\t4");
	printf("\n\t4599 \tCOP 220\t\t3");
	printf("\n\t8997 \tGOL 124\t\t1");
	printf("\n\t9696 \tCOP 100\t\t3");
	printf("\n\t1232 \tMAC 531\t\t5");
	printf("\n\t9856 \tSTA 100\t\t2");
	printf("\n\t8520 \tTNV 400\t\t5");
	printf("\n\t8977 \tCMP 100\t\t1\n\n");
	
	while (!done)
	{
		int i = 0;
		for(i = 0; i < 4; i++)
		{
			std1.crns[i] = 0;
		}
		done = 1;
		if (std1.numberOfClasses == 1)
		{
			printf("Enter the %d course number: \n\t", std1.numberOfClasses);
			scanf("%d", &crn1);
			if(checkClassNumber(crn1) < 0)
			{
				done = 0;
			}
			else
			{
				std1.crns[0] = crn1;
			}
			
		}
		else if (std1.numberOfClasses == 2)
		{
			printf("Enter the %d course number(s): \n\t", std1.numberOfClasses);
			scanf("%d %d", &crn1, &crn2);
			if(checkClassNumber(crn1) < 0 || 
			   checkClassNumber(crn2) < 0)
			{
				done = 0;
			}
			else
			{
				std1.crns[0] = crn1;
				if(!courseExist(crn2, &std1))
				{
					std1.crns[1] = crn2;
				}
				else
				{
					done = 0;
				}
			}
		}
		else if (std1.numberOfClasses == 3)
		{
			printf("Enter the %d course number(s): \n\t", std1.numberOfClasses);
			scanf("%d %d %d", &crn1, &crn2, &crn3);
			if(checkClassNumber(crn1) < 0 || 
			   checkClassNumber(crn2) < 0 || 
			   checkClassNumber(crn3) < 0)
			{
				done = 0;
			}
			else
			{
				std1.crns[0] = crn1;
				if(!courseExist(crn2, &std1))
				{
					std1.crns[1] = crn2;
				}
				else
				{
					done = 0;
				}
				
				if(!courseExist(crn3, &std1))
				{
					std1.crns[2] = crn3;
				}
				else
				{
					done = 0;
				}
			}
		}
		else if (std1.numberOfClasses == 4)
		{
			printf("Enter the %d course number(s): \n\t", std1.numberOfClasses);
			scanf("%d %d %d %d", &crn1, &crn2, &crn3, &crn4);
			if(checkClassNumber(crn1) < 0 || 
			   checkClassNumber(crn2) < 0 || 
			   checkClassNumber(crn3) < 0 || 
			   checkClassNumber(crn4) < 0)
			{
				done = 0;
			}
			else
			{
				std1.crns[0] = crn1;
				if(!courseExist(crn2, &std1))
				{
					std1.crns[1] = crn2;
				}
				else
				{
					done = 0;
				}
				
				if(!courseExist(crn3, &std1))
				{
					std1.crns[2] = crn3;
				}
				else
				{
					done = 0;
				}
				
				if(!courseExist(crn4, &std1))
				{
					std1.crns[3] = crn4;
				}
				else
				{
					done = 0;
				}
			}
		}
		if (done == 0)
		{
			printf("Invalid course number(s)\n");
		}
	}
}

int checkClassNumber(int x)
{
	int count = sizeof(cla)/sizeof(classes);
	for(i = 0; i < count; i++)
	{
		if (x == cla[i].crns)
		{
			return i;
		}
	}
	return -1;
}
void addClass(int x)
{
	int done = 0;
	int a = 0;
	int c = 0;
	while(!done)
	{
		printf("Enter course number to add: ");
		scanf("%d", &a);
		
		c = checkClassNumber(a);
		
		if (c != -1)
		{
			if (std[x].numberOfClasses >= 4)
			{
				printf("Sorry you can not take more than 4 classes.\n");
				done = 1;
			}
			else
			{
				std[x].crns[std[x].numberOfClasses] = cla[c].crns;
				std[x].numberOfClasses++;
				done = 1;
				printf("[%d %s] is added successfully!\n\n", cla[c].crns, cla[c].course);
			}
			
		}
		else
		{
			printf("\nCourse number is invalid.\n");
		}
	}
	
}
void deleteClass(int x)
{
	int a = 0;
	int c = 0;
	int i = 0;
	int position;
	int found = 0;
	int done = 0;
	while(!done)
	{
		printf("Enter course number to delete: ");
		scanf("%d", &a);
		
		c = checkClassNumber(a);
		
		if (c != -1)
		{
			if (std[x].numberOfClasses <= 0)
			{
				printf("Sorry you can not delete anymore classes.\n");
				done = 1;
			}
			else
			{
				for(i = 0; i < std[x].numberOfClasses; i++)
				{
					if(std[x].crns[i] == a)
					{
						position = i;
						found = 1;
						
					}
					if(found == 1)
					{
						std[x].crns[position] = std[x].crns[position+1];
						position++;
					}
				}
				if(found)
				{
					std[x].numberOfClasses--;
					done = 1;
					printf("[%d %s] is deleted successfully!\n\n", cla[c].crns, cla[c].course);
					
					showCurrentClasses(x);
				}
				else
				{
					printf("Student is not taking this class.\n");
				}
				
			}
			
		}
		else
		{
			printf("\nCourse number is invalid.\n");
		}
	}
}

void printInvoiceLine (int crn, char* cr_Prefix, int cr_Hours, float cost)
{
	
	printf("\n\t\t%d\t\t%s\t\t%d\t $%.2f", crn, cr_Prefix, cr_Hours, cost);
}
void printInvoice (int id)
{
	int x = 0;
	int i = 0;
	float cost = 0;
	float total = 35;
	printf("\nThank You!");
	printf("\nPRESS ANY KEY TO CONTINUE . . .");
	getch();
	printf("\n\n\n\t\tVALENCE COMMUNITY COLLEGE\n\t\tORLANDO FL 10101\n\t\t****************************");
	printf("\n\n\t\tFee Invoice Prepared for Student: \n\t\t%d-%s",std[id].id, std[id].name);
	printf("\n\n\t\t1 Credit Hour = $120.25");
	printf("\n\t\tCRN\t\tCR_PREFIX\tCR_HOURS");
	for(i = 0; i < std[id].numberOfClasses; i++)
	{
		x = checkClassNumber(std[id].crns[i]);
		cost = cla[x].cHour*120.25;
		printInvoiceLine(cla[x].crns, cla[x].course, cla[x].cHour, cost);
		total = total + cost;
	}
	
	
	
	
	printf("\n\n\t\t\t\tHealth & id fees $ 35.00");
	printf("\n\n\t---------------------------------------------\n");
	printf("\t\t\t\tTotal Payments    $ %.2f", total);
	printf("\n\n\n");
}
