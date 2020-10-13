#include "header.h"

int main(void)
{
	// 3 pts for correctly opening "FitbitData.csv" for mode read
	FILE* infile = NULL;
	infile = openFile("FitbitData.csv", "r");

	// 2 pts for correctly checking the success of the file opening operation
	if (infile == NULL)
	{
		return 1;
	}

	FitbitData records[1441] = { 0 };

	int i = 0, floorsTotal = 0, heartTotal = 0, stepsTotal = 0, stepsMax = 0, stepsTime = 0;
	char line[100], *token, rangeBegin[10], rangeEnd[10];
	double caloriesTotal = 0, distanceTotal = 0, heartAvg = 0;

	// 10 pts for correctly reading each record in the file as a string, one line at a time
	while (!feof(infile))
		// This while loops scans every line until the very end of the file
	{
		fgets(line, 100, infile);

		token = strtok(line, ",");

		// 15 pts for correctly cleaning the data and parsing each record into the corresponding fields
			// Each of these if-statements are ordered in a manner to correctly place each data piece into the correct field in the records array
			// If the token is NULL (the data is not clean) a 0 is placed into that field instead
			// The program will read-in a string until it hits a comma, once it reaches a comma it stores the data as a string which is then converted
		if (token != NULL)
		{
			strcpy(records[i].patient, token);
		}

		token = strtok(NULL, ",");
		if (token != NULL)
		{
			strcpy(records[i].minute, token);
		}

		token = strtok(NULL, ",");
		if (token != NULL)
		{
		// 5 pts for correctly converting the strings to the field types
		// 5 pts for correctly storing the fields into the FitbitData array
			records[i].calories = atof(token);
			// atof and atoi take the recorded strings, and store them correctly as integers and doubles in the records array
			caloriesTotal += records[i].calories;
		// 3 pts for correctly computing the total calories burned
		}

		token = strtok(NULL, ",");
		if (token != NULL)
		{
				records[i].distance = atof(token);
				distanceTotal += records[i].distance;
		// 3 pts for correctly computing the total distance walked
		}

		token = strtok(NULL, ",");
		if (token != NULL)
		{
			records[i].floors = atoi(token);
			floorsTotal += records[i].floors;
		// 3 pts for correctly computing the total floors walked
		}

		token = strtok(NULL, ",");
		if (token != NULL)
		{
			records[i].heartRate = atoi(token);
			heartTotal += records[i].heartRate;
			
		}

		token = strtok(NULL, ",");
		if (token != NULL)
		{
			records[i].steps = atoi(token);
			stepsTotal += records[i].steps;
			
		// 3 pts for correctly computing the total steps taken
			if (stepsMax < records[i].steps)
			{
				stepsMax = records[i].steps;
				stepsTime = i;
			}
		}

		token = strtok(NULL, ",");
		if (token != NULL)
		{
			records[i].sleepLevel = atoi(token);
		}

		i++;
		if (i == 1441)
		{
			goto theResults;
		}
	}
	
	theResults:
	printf("Total Calories: %.2lf\n", caloriesTotal);
	printf("Total Distance: %.2lf\n", distanceTotal);
	printf("Total Floors: %d\n", floorsTotal);
	printf("Total Heart Rate: %d\n", heartTotal);
	printf("Total Steps: %d\n", stepsTotal);
	printf("Maximum Steps: %d at Time: %s\n", stepsMax, records[stepsTime].minute);

	// 4 pts for correctly computing the average heartrate over the 24-hour period
	heartAvg = ((double)heartTotal / 1441);
	printf("Average Heart Rate: %.2lf", heartAvg);
	printf("\n\nThese results have been output to Result.csv.\n\nClosing program...\n");

	// 3 pts for correctly opening "Results.csv" for mode write
	FILE* outfile = NULL;
	outfile = openFile("Result.csv", "w");

	// 8 pts for correctly formatting and outputting the data
	fprintf(outfile, "Total Calories  | %.2lf\n", caloriesTotal);
	fprintf(outfile, "Total Distance  | %.2lf\n", distanceTotal);
	fprintf(outfile, "Total Floors    | %d\n", floorsTotal);
	fprintf(outfile, "Total Steps     | %d\n", stepsTotal);
	fprintf(outfile, "Maximum Steps   | %d at Time: %s\n", stepsMax, records[stepsTime].minute);
	fprintf(outfile, "Avg. Heartrate  | %.2lf\n", heartAvg);

	// 2 pts for correctly closing the "FitbitData.csv"
	fclose(infile);

	// 2 pts for correctly closing the "Results.csv"
	fclose(outfile);

	return 0;
}