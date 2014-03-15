/*
* @file			task3_6.cpp
* @brief		Program sorts rows in two dimensional array by ascending numbers

* Copyright 2014 by Yuliia Lyubchik Inc.,
*
* This software is the confidential and proprietary information
* of Yuliia Lyubchik. ("Confidential Information").  You
* shall not disclose such Confidential Information and shall use
* it only with permission from Yuliia.
*
*/
#include "stdafx.h"
#include "task3_6.h"
#include <stdlib.h>
#include <string.h>
#include <conio.h>

const unsigned char ERROR = 0;
const unsigned char SUCCESS = 1;
const unsigned char MAIN_SUCCESS = 0;


int main()
{
	Interface();
	unsigned char retCode;
	double** d_array;
	unsigned int rows, columns;
	unsigned int i;

	printf("Please enter the size of two dimension double array: \n");

	do
	{
		printf("number of rows = ");
		retCode = scanf("%u", &rows);
		fflush(stdin);
	} while (Type_checking(retCode, (int)rows) == ERROR);

	do
	{
		printf("number of columns = ");
		retCode = scanf("%u", &columns);
		fflush(stdin);
	} while (Type_checking(retCode, (int)columns) == ERROR);


	retCode = Input(&d_array, rows, columns);
	if (retCode == ERROR)
	{
		printf("Can't input data.\n");
		return (int)ERROR;
	}

	for (i = 0; i < rows; ++i)
	{
		retCode = Sort(d_array[i], columns);
		if (retCode == ERROR)
		{
			printf("Can't sort array.\n");
		}
	}

	printf("Sorted rows in array by ascending numbers: \n");
	retCode = Output(d_array, rows, columns);
	if (retCode == ERROR)
	{
		printf("Can't  display array.\n");
		free(*d_array);
		free(d_array);
		return (int)ERROR;
	}

	free(*d_array);
	free(d_array);
	_getch();
	return MAIN_SUCCESS;
}


void Interface(void)
{
	printf("------------------------------------------------------------------\n");
	printf("Hi! Welcome to the peculiar array sorter.\n");
	printf("Please enter double numbers into array \nand program will sort numbers in rows by ascending. \n");
	printf("Program made by Yuliia Lyubchik.\n");
	printf("------------------------------------------------------------------\n\n");
}


unsigned char Input(double*** d_array, unsigned int rows, unsigned int columns )
{
	unsigned int  i, j;
	unsigned char retCode;
	char temp[15];		/*temporary string for reading inputed numbers*/

	*d_array = (double**)calloc(rows, sizeof(double*));
	if (*d_array == NULL)
	{
		printf("Error occurs while trying to allocate memory for array.\n");
		return ERROR;
	}
	for (i = 0; i < rows; ++i)
	{
		(*d_array)[i] = (double*)calloc(columns, sizeof(double));
	}

	printf("Please enter numbers for the double array: \n");
	for ( i = 0; i < rows; ++i )
	{
		for ( j = 0; j < columns; ++j )
		{
			do 
			{
				printf("ar[%u][%u] = ", i, j);
				scanf("%s", &temp);
			} 
			while (Is_double(temp) == ERROR);
			(*d_array)[i][j] = atof(temp);
		}
	}
	return SUCCESS;
}


unsigned char Type_checking(unsigned char retCode, int val)
{
	if (retCode == ERROR)
	{
		printf("Type mismatch. Please next time check if you enter number. \n");
		return ERROR;
	}
	if (val <= 0)
	{
		printf("The value can not be negative or zero.\n");
		return ERROR;
	}
	return SUCCESS;
}


unsigned char Is_double(const char* pstr)
{
	if (pstr == NULL)
	{
		return ERROR;
	}
	unsigned int i;
	unsigned char krapka = 0;
	for (i = 0; i < strlen(pstr); ++i)
	{
		if (i == 0)
		{
			if (pstr[i] == '-')
			{
				continue;
			}
		}
		if (pstr[i] >= '0' && pstr[i] <= '9')
		{
			continue;
		}
		else if (pstr[i] == '.')
		{
			if (krapka == 0)
			{
				krapka = 1;
			}
			else
			{
				return ERROR;
			}
		}
		else
		{
			printf("Please check if you enter double number.\n");
			return ERROR;
		}
	}
	return SUCCESS;
}


unsigned char Sort(double* one_array, unsigned int size )
{
	if (one_array == NULL)
	{
		printf("Error occurs while trying to get access to data to sort numbers.\n");
		return ERROR;
	}
	unsigned int i, j;
	double temp;
	for (i = 0; i < size; ++i)
	{
		for (j = 0; j < size; ++j)
		{
			if (one_array[i] < one_array[j])
			{
				temp = one_array[i];
				one_array[i] = one_array[j];
				one_array[j] = temp;
			}
		}
	}
	return SUCCESS;
}


unsigned char Output(double** d_array, unsigned int rows, unsigned int columns)
{
	if (d_array == NULL)
	{
		printf("Error occurs while trying to get access to data to display it.\n");
		return ERROR;
	}

	unsigned int i, j;

	for (i = 0; i < rows; ++i)
	{
		printf("\n");
		for (j = 0; j < columns; ++j)
		{
			printf("%lf \t", d_array[i][j]);
		}
	}
	return SUCCESS;
}
