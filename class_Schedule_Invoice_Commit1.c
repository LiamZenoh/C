/* Copyright Liam O'Brien December 2019 
   A C application that focuses primarily on algorithm and function structure
   Creates a simple course manager simulating a course selection environment
*/

#include <stdio.h>
//---------------------------------------------------
void getId (int *pId);
int checkNumberOfCourses (int numCourses);
int checkCourseNumber (int crn);
int getCreditHours(int crn);
void printInvoiceLine (int crn, int creditHours);
void printInvoice (int id, int crn1, int crn2);
int crn, crn1, crn2, creditHours, hr1, hr2, check, check2, check3, check27, counter, counter2, cHour;
int pId = 0;
float total;
//---------------------------------------------------
int main()
{	
	int id = 0;
	int pId = 0;
	int numCourses = 0;
	getId (&pId);
	while (checkNumberOfCourses (numCourses) != 1)
	{
	}
	while (check == 2 && counter < 2)
	{
		checkCourseNumber (crn);
		hr1=getCreditHours(crn1);
		hr2=getCreditHours(crn2);
		check3 = 2;
	}
	while (check == 1 && counter < 1)
	{
		checkCourseNumber (crn);
		hr1=getCreditHours(crn1);
		check3 = 1;
		printInvoice (pId, crn1, crn2);
	}
	while (check == 0)
	{
		check3 = 0;
		printInvoice (pId, crn1, crn2);
	}
	getCreditHours(crn);
	printInvoice (pId, crn1, crn2);
	return 0;
}
//---------------------------------------------------
void getId (int *pId)
{
	printf("Enter the Students ID: \n\t");
	scanf("%d", &*pId);
}
int checkNumberOfCourses (int numCourses)
{
	printf("Enter how many courses taken(up to 2): \n\t");
	scanf("%d", &numCourses);
	if (numCourses == 0)
	{
		check = 0;
		return 1;
	}
	else if (numCourses == 1)
	{
		check = 1;
		return 1;
	}
	else if (numCourses == 2)
	{
		check = 2;
		return 1;
	}
	else
	{
		printf("Sorry you have not entered a valid number of classes.\n");
		return 0;
	}
}
int checkCourseNumber (int crn)
{
	printf("Enter the course number: \n\t");
	scanf("%d", &crn);
	if (crn == 4587 || crn == 4599 || crn == 8997 || crn == 9696)
	{
		if (counter >= 1)
		{
			crn2 = crn;
		}
		else
		{
			crn1 = crn;
		}
		counter++;
		return 1;
	}
	else
	{
		printf("Invalid course number. \n");	
		return 0;
	}
}
int getCreditHours(int crn)
{
	switch (crn)
	{
		case 4587 :
			{
				return 4;
				break;
			}
		case 4599 :
			{
				return 3;
				break;
			}
		case 8997 :
			{
				return 1;
				break;
			}
		case 9696 :
			{
				return 3;
				break;
			}			
	}
}
void printInvoiceLine (int crn, int creditHours)
{
	printf("\n\t\t%d\t\t%d\t\t$ %.2f", crn, creditHours, creditHours*120.25);
}
void printInvoice (int id, int crn1, int crn2)
{
	printf("\nThank You!");
	printf("\nPRESS ANY KEY TO CONTINUE . . .");
	getch();
	printf("\n\n\n\t\tVALENCE COMMUNITY COLLEGE\n\t\tORLANDO FL 10101\n\t\t****************************");
	printf("\n\n\t\tFee Invoice Prepared for Student V%d", id);
	printf("\n\n\t\t1 Credit Hour = $120.25");
	printf("\n\t\tCRN\t\tCredit Hours");
	if (check3 == 2)
	{
		printInvoiceLine ( crn1,  hr1);
		printInvoiceLine ( crn2,  hr2);
		total = (hr1*120.25) + (hr2*120.25) + 35;
	}
	else
	{
		printInvoiceLine ( crn1,  hr1);
		total = (hr1*120.25) + 35;
	}
	printf("\n\n\t\t\t\tHealth & id fees $ 35.00");
	printf("\n\n\t---------------------------------------------\n");
	printf("\t\t\t\tTotal Payments    $ %.2f", total);
}
