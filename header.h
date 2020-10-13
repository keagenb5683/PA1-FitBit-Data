#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Programmer: Keagen Brendle - 11630902
Class: CptS 122, Spring, 2020
Programming Assignment: PA1
Date: January 24, 2020
Description: This program scans through a .csv document full of data and organizes aforementioned data
*/

// 3 pts for correctly defining enum sleep
typedef enum sleep
{
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
}Sleep;

// 5 pts for correctly defining struct FitbitData
typedef struct fitbit
{
	char patient[10];
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;
}FitbitData;

FILE* openFile(char* fileName, char* mode);
