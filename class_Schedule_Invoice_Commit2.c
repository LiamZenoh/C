/* Copyright Liam O'Brien December 2019 
   A C application that focuses primarily on algorithm and function structure
   Creates a simple course manager simulating a course selection environment
*/

#include <stdio.h>

int main()
{
	int studentID = 0;
	int courseNum = 0;
	int firstCRN = 0;
	int secondCRN = 0;
	int cHour = 0;
	int cHour2 = 0;
	int cont = 0; //0 false, 1 true
	int cont2 = 0; //0 false, 1 true
	float x = 0;
	float y = 0;
	float firstCredit = 0;
	float secondCredit = 0;
	float creditHourCost = 120.25;
	float healthFee = 35.00;
	printf("Enter the Students ID: \n\t");
	scanf("%d",&studentID);
	printf("Enter how many courses taken(up to 2): \n\t");
	scanf("%d", &courseNum);
	while (courseNum < 0 || courseNum > 2)
	{
		printf("Invalid number of courses.\n");
		printf("Please re-enter how many courses (up to 2): \n\t");
		scanf("%d", &courseNum);
	}
	if (courseNum == 0)
	{
		printf("\nThank You!");
		printf("\nPRESS ANY KEY TO CONTINUE . . .");
		getch();
		printf("\n\n\n\t\tVALENCE COMMUNITY COLLEGE\n\t\tORLANDO FL 10101\n\t\t****************************");
		printf("\n\n\t\tFee Invoice Prepared for Student V%d", studentID);
		printf("\n\n\t\t\t\tHealth & id fees $ %.2f", healthFee);
		printf("\n\n\t---------------------------------------------\n");
		printf("\t\t\t\tTotal Payments    $ %.2f", healthFee);
	}
	else if (courseNum == 1)
	{
		printf("Enter the course number: \n\t");
		scanf("%d", &firstCRN);
		while(firstCRN != 4587 && firstCRN != 4599 && firstCRN != 8997 && firstCRN != 9696)
			{
				printf("Please enter a valid course number.\n");
				scanf("%d", &firstCRN);
				
			}
			switch(firstCRN)
			{
			
				case 4587 :
				{
				printf("\nThank You!");
				printf("\nPRESS ANY KEY TO CONTINUE . . .");
				getch();
				printf("\n\n\n\t\tVALENCE COMMUNITY COLLEGE\n\t\tORLANDO FL 10101\n\t\t****************************");
				printf("\n\n\t\tFee Invoice Prepared for Student V%d", studentID);
				printf("\n\n\t\t1 Credit Hour = $%g", creditHourCost);
				printf("\n\t\tCRN\t\tCredit Hours");
				printf("\n\t\t%d\t\t4\t\t$ 481.00", firstCRN );
				printf("\n\n\t\t\t\tHealth & id fees $ 35.00");
				printf("\n\n\t---------------------------------------------\n");
				printf("\t\t\t\tTotal Payments    $ %.2f", 481.00+35);
				break;
				}
				case 4599 :
				{
				printf("\nThank You!");
				printf("\nPRESS ANY KEY TO CONTINUE . . .");
				getch();
				printf("\n\n\n\t\tVALENCE COMMUNITY COLLEGE\n\t\tORLANDO FL 10101\n\t\t****************************");
				printf("\n\n\t\tFee Invoice Prepared for Student V%d", studentID);
				printf("\n\n\t\t1 Credit Hour = $%g", creditHourCost);
				printf("\n\t\tCRN\t\tCredit Hours");
				printf("\n\t\t%d\t\t3\t\t$ 360.75", firstCRN );
				printf("\n\n\t\t\t\tHealth & id fees $ 35.00");
				printf("\n\n\t---------------------------------------------\n");
				printf("\t\t\t\tTotal Payments    $ %.2f", 360.75+35);
				break;
				}
				case 8997 :
				{
				printf("\nThank You!");
				printf("\nPRESS ANY KEY TO CONTINUE . . .");
				getch();
				printf("\n\n\n\t\tVALENCE COMMUNITY COLLEGE\n\t\tORLANDO FL 10101\n\t\t****************************");
				printf("\n\n\t\tFee Invoice Prepared for Student V%d", studentID);
				printf("\n\n\t\t1 Credit Hour = $%g", creditHourCost);
				printf("\n\t\tCRN\t\tCredit Hours");
				printf("\n\t\t%d\t\t1\t\t$ 120.25", firstCRN );
				printf("\n\n\t\t\t\tHealth & id fees $ 35.00");
				printf("\n\n\t---------------------------------------------\n");
				printf("\t\t\t\tTotal Payments    $ %g", 120.25+35);
				break;
				}
				case 9696 :
				{
				printf("\nThank You!");
				printf("\nPRESS ANY KEY TO CONTINUE . . .");
				getch();
				printf("\n\n\n\t\tVALENCE COMMUNITY COLLEGE\n\t\tORLANDO FL 10101\n\t\t****************************");
				printf("\n\n\t\tFee Invoice Prepared for Student V%d", studentID);
				printf("\n\n\t\t1 Credit Hour = $%g", creditHourCost);
				printf("\n\t\tCRN\t\tCredit Hours");
				printf("\n\t\t%d\t\t3\t\t$ 360.75", firstCRN );
				printf("\n\n\t\t\t\tHealth & id fees $ 35.00");
				printf("\n\n\t---------------------------------------------\n");
				printf("\t\t\t\tTotal Payments    $ %.2f", 360.75+35);
				break;
				}
				
			
			}
			
		
	}
	else if (courseNum == 2)
		{
		
		printf("Enter the 2 course numbers separated by - :(like 2356-8954) \n\t");
		scanf("%d-%d", &firstCRN, &secondCRN);
		if (firstCRN == 4587)
		{
			cHour = 4;
			cont = 1;
			if (secondCRN == 4599)
			{
				cHour2 = 3;
				cont2 = 1;
			}
			else if (secondCRN == 8997)
			{
				cHour2 = 1;
				cont2 = 1;
			}
			else if (secondCRN == 9696)
			{
				cHour2 = 3;
				cont2 = 1;
			}
		}
		else if (firstCRN == 4599)
		{
			cHour = 3;
			cont = 1;
			if (secondCRN == 4587)
			{
				cHour2 = 4;
				cont2 = 1;
			}
			else if (secondCRN == 8997)
			{
				cHour2 = 1;
				cont2 = 1;
			}
			else if (secondCRN == 9696)
			{
				cHour2 = 3;
				cont2 = 1;
			}
		}
		else if (firstCRN == 8997)
		{
			cHour = 1;
			cont = 1;
			if (secondCRN == 4599)
			{
				cHour2 = 3;
				cont2 = 1;
			}
			else if (secondCRN == 4587)
			{
				cHour2 = 4;
				cont2 = 1;
			}
			else if (secondCRN == 9696)
			{
				cHour2 = 3;
				cont2 = 1;
				
			}
		}
		else if (firstCRN == 9696)
		{
			cHour = 3;
			cont = 1;
			if (secondCRN == 4599)
			{
				cHour2 = 3;
				cont2 = 1;
			}
			else if (secondCRN == 8997)
			{
				cHour2 = 1;
				cont2 = 1;
			}
			else if (secondCRN == 4587)
			{
				cHour2 = 4;
				cont2 = 1;
			}
		}
		while (cont == 0 || cont2 == 0)
		{
			printf("\nSorry invalid course number(s).\n");
			printf("Enter the 2 course numbers separated by - :(like 2356-8954) \n\t");
			scanf("%d-%d", &firstCRN, &secondCRN);
			if (firstCRN == 4587)
		{
			cHour = 4;
			cont = 1;
			if (secondCRN == 4599)
			{
				cHour2 = 3;
				cont2 = 1;
			}
			else if (secondCRN == 8997)
			{
				cHour2 = 1;
				cont2 = 1;
			}
			else if (secondCRN == 9696)
			{
				cHour2 = 3;
				cont2 = 1;
			}
		}
		else if (firstCRN == 4599)
		{
			cHour = 3;
			cont = 1;
			if (secondCRN == 4587)
			{
				cHour2 = 4;
				cont2 = 1;
			}
			else if (secondCRN == 8997)
			{
				cHour2 = 1;
				cont2 = 1;
			}
			else if (secondCRN == 9696)
			{
				cHour2 = 3;
				cont2 = 1;
			}
		}
		else if (firstCRN == 8997)
		{
			cHour = 1;
			cont = 1;
			if (secondCRN == 4599)
			{
				cHour2 = 3;
				cont2 = 1;
			}
			else if (secondCRN == 4587)
			{
				cHour2 = 4;
				cont2 = 1;
			}
			else if (secondCRN == 9696)
			{
				cHour2 = 3;
				cont2 = 1;
				
			}
		}
		else if (firstCRN == 9696)
		{
			cHour = 3;
			cont = 1;
			if (secondCRN == 4599)
			{
				cHour2 = 3;
				cont2 = 1;
			}
			else if (secondCRN == 8997)
			{
				cHour2 = 1;
				cont2 = 1;
			}
			else if (secondCRN == 4587)
			{
				cHour2 = 4;
				cont2 = 1;
			}
		}
			
		}
		if (cont == 1 && cont2 == 1)
		{
			
			printf("\nThank You!");
			printf("\nPRESS ANY KEY TO CONTINUE . . .");
			getch();
			printf("\n\n\n\t\tVALENCE COMMUNITY COLLEGE\n\t\tORLANDO FL 10101\n\t\t****************************");
			printf("\n\n\t\tFee Invoice Prepared for Student V%d", studentID);
			printf("\n\n\t\t1 Credit Hour = $%g", creditHourCost);
			printf("\n\t\tCRN\t\tCredit Hours");
			x = cHour*creditHourCost;
			printf("\n\t\t%d\t\t%d\t\t$ %.2f", firstCRN, cHour, cHour*120.25);
			y = cHour2*creditHourCost;
			printf("\n\t\t%d\t\t%d\t\t$ %.2f", secondCRN, cHour2, cHour2*120.25);
			printf("\n\n\t\t\t\tHealth & id fees $ 35.00");
			printf("\n\n\t---------------------------------------------\n");
			printf("\t\t\t\tTotal Payments    $ %.2f", x+y+35);
		}
	
	}
	
	return 0;
}
