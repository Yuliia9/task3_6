#ifndef TASK3_6_H_
#define TASK3_6_H_

/*
*@file		task3_6.h
*@brief		header file that defines prototypes of functions used in file task3_6.cpp
*/

#include "stdafx.h"

/*
* @brief				This function displays general information about program to users
* @param	void
* @return	void
*/
void Interface (void);


/*
* @brief					Function for inputing numbers into two dimension array
* @param	[in/out]		double*** d_array - a pointer to array of pointers for inputing data into 2D array
			[in]			unsigned int rows - a number of rows in array
			[in]			unsigned int columns - a number of columns in array
*
*@return	unsigned char	Return ERROR if error occurs while trying to allocate memory for array
							Return SUCCESS if numbers were inputed into array
*/
unsigned char Input(double*** d_array, unsigned int rows, unsigned int columns);


/**
* @brief					Function for displaying numbers from array
* @param	[in]			double** d_array - a pointer to 2D double array
			[in]			unsigned int rows - a number of rows in array
			[in]			unsigned int columns - a number of columns in array
* @return	unsigned char	Return ERROR if pointer to array of structures is NULL
							Return SUCCESS if data was displayed
*/
unsigned char Output(double** d_array, unsigned int rows, unsigned int columns);


/**
* @brief				Checking if data match requirements set to that data types or functions return values

* @param	[in]		unsigned char retCode - return value of other functions for checking if functions ended properly
			[in]		int val - number for checking if it's negative or zero
* @return	unsigned char		Return ERROR if data doesn't match requirements
								Return SUCCESS if inputed data match requirements
*/
unsigned char Type_checking(unsigned char retCode, int val);


/**
* @brief					Function for checking if inputed string presents double number
* @param	[in]			const char* pstr - pointer to, checking for numbers, string
* @return	unsigned char	Return ERROR if string isn't double number
							Return SUCCESS if string is double number
*/
unsigned char Is_double(const char* pstr);


/**
* @brief					Function sorts numbers in one dimension array
* @param	[in/out]		double point* one_array - pointer to 1D array 
			[in]			unsigned int size - size of array for sorting
* @return	unsigned char	Return ERROR if pointer to array is NULL
							Return SUCCESS if numbers in array were sorted
*/
unsigned char Sort(double* one_array, unsigned int size );

#endif