/**
 * Mohammed Alfarra, 6368950, COP 4338 Assignment 1
*/

#define MAX_LEN 100
#include<stdio.h>


void main(void){

	printf("This is a 7-segment display! Press \"Enter\" after providing any number in keyboard.\n");
	int segment_width;//width of horizontal segments in the 7-segment display
	int input_error;//flag to show whether some error is detected in user's input
	char string[MAX_LEN + 1];//placeholder to hold user's input from keyboard

	// Gets and validates user input for length of horizontal segments
    while(1)
	{
		printf("Please enter the length of horizontal segments (from 3 to 40):\n");
		input_error = segment_width = 0;
		for(int i = 0; i < MAX_LEN;i++){
			if(i == 3){//Given input must be a 1 or 2-digit positive integer.
				input_error = 1;
				break;
			}
			string[i] = getchar();
			if(string[i] == '\n'){//end of user's input
				string[i] = '\0';
				break;
			}else if(string[i] < '0' || string[i] > '9'){//not a digit is given by user
				input_error = 1;
				break;
			}else
				segment_width = 10 * segment_width //accounts for previously entered digits...
					+ (string[i] - '0')//converting ASCII code of string[i] to its numerical value...
					;//converting the number entered by user to an integer...
		}
		if(input_error)//if an error found in user's input
			while(getchar()!= '\n');//gets rid of the remaining of user's input in the same line
		if(segment_width < 3 || segment_width > 40 || input_error)
			printf("The given value is not acceptable!\n");
		else
			break;
	}
	
    int segment_length;//length of vertical segments in the 7-segment display
	// Gets and validates user input for length of vertical segments
	while(1)
	{
		printf("Now, please enter the length of vertical segments (from 3 to 40):\n");
		input_error = segment_length = 0;
		for(int i = 0; i < MAX_LEN;i++){
			if(i == 3){//Given input must be a 1 or 2-digit positive integer.
				input_error = 1;
				break;
			}
			string[i] = getchar();
			if(string[i] == '\n'){//end of user's input
				string[i] = '\0';
				break;
			}else if(string[i] < '0' || string[i] > '9'){//not a digit is given by user
				input_error = 1;
				break;
			}else
				segment_length = 10 * segment_length //accounts for previously entered digits...
					+ (string[i] - '0')//converting ASCII code of string[i] to its numerical value...
					;//converting the number entered by user to an integer...
		}
		if(input_error)//if an error found in user's input
			while(getchar()!= '\n');//gets rid of the remaining of user's input in the same line
		if(segment_length < 3 || segment_length > 40 || input_error || segment_length > (2 * segment_width) || segment_length < (0.5 * segment_width))
			printf("The given value is not acceptable!\n");
		else
			break;
	}

	// Gets and validates the number entered by the user
	while (1)
	{
		printf("Enter a positive integer: ");
		int input_error = 0;
		char string[MAX_LEN + 1];

        if (scanf("%100s", string) == EOF) {
			printf("\n");
            break;
        }

		if (strspn(string, "0123456789") != strlen(string)) // Verify all characters are digits
		{
			printf("The user input is not acceptable!\n");
			input_error = 1;
		}

		if (!input_error)
		{
			printf("\n");
			printSegments(string, segment_width, segment_length); // Calls the printSegments function and passes the three inputs entered by the user
		}
	}
	printf("END\n");
}


/**
 * Function that prints the seven segment representation of the number requested by the user using the horizontal width and
 * the vertical length requested by the user
*/
void printSegments(char* numberString, int horizontal, int vertical) {

	int digits[MAX_LEN]; // Array of int
	int numDigits = 0; // Counter for number of digits in the integer entered
	
	// For loop that converts the char to int and stores it in the int array
	for (int i = 0; numberString[i] != '\0'; i++) {
		digits[i] = numberString[i] - '0';
		numDigits++;
	}

	// For loop that prints the first horizontal srgment for each number in the user input
	for (int i = 0; i < numDigits; i++) {
		printHorizontalFirst(digits[i], horizontal); // Calls the function that prints the first row of the first horizontal segment
		int ctr = 0;
		ctr++;
		for (int j = 0; j < ctr; j++) {
			printf("  ");
		}
	}
	printf("\n"); // Prints a new line

	for (int i = 0; i < numDigits; i++) {
		printHorizontalFirst(digits[i], horizontal); // Calls the function that prints the second row of the first horizontal segment
		int ctr = 0;
		ctr++;
		for (int j = 0; j < ctr; j++) {
		   printf("  ");
		}
	}
	printf("\n"); // Prints a new empty line

	// For loop that prints the first vertical left and vertical right segments for each number in the user input
	for (int i = 0; i < vertical; i++)
	{
		for (int j = 0; j < numDigits; j++)
		{
			printVerticalFirst(digits[j], horizontal, vertical); // Calls the function that prints the vertical left and vertical right segments
		}
		printf("\n");
	}
	
	// For loop that prints the second horizontal srgment for each number in the user input
	for (int i = 0; i < numDigits; i++) {
		   printHorizontalSecond(digits[i], horizontal); // Calls the function that prints the first row of the second horizontal segment
		   int ctr = 0;
		   ctr++;
		   for (int j = 0; j < ctr; j++) {
		   printf("  ");
		   }
	}
	printf("\n");
	for (int i = 0; i < numDigits; i++) {
		printHorizontalSecond(digits[i], horizontal); // Calls the function that prints the second row of the second horizontal segment
		int ctr = 0;
		ctr++;
		for (int j = 0; j < ctr; j++) {
		   printf("  ");
		}
	}
	printf("\n");  // Prints a new empty line

	// For loop that prints the second vertical left and vertical right segments for each number in the user input
	for (int i = 0; i < vertical; i++)
	{
		for (int j = 0; j < numDigits; j++)
		{
			printVerticalSecond(digits[j], horizontal, vertical); // Calls the function that prints the vertical left and vertical right segments
		}
		printf("\n");
	}

	// For loop that prints the third horizontal srgment for each number in the user input
	for (int i = 0; i < numDigits; i++) {
		   printHorizontalThird(digits[i], horizontal); // Calls the function that prints the first row of the third horizontal segment
		   int ctr = 0;
		   ctr++;
		   for (int j = 0; j < ctr; j++) {
		   printf("  ");
		   }
	}
	printf("\n");
	for (int i = 0; i < numDigits; i++) {
		printHorizontalThird(digits[i], horizontal); // Calls the function that prints the second row of the third horizontal segment
		int ctr = 0;
		ctr++;
		for (int j = 0; j < ctr; j++) {
		   printf("  ");
		}
	}
	printf("\n"); // Prints a new empty line
}

/**
 * Function that prints the first horizontal segment of each number
*/
void printHorizontalFirst(int num, int horizontal) {
	// If the number is one of the following then it prints asteriks for the first horizontal segment
	if (num == 2 || num == 3 || num == 5 || num == 6 || num == 7 || num == 8 || num == 9 || num == 0) {
	    printf("  ");
	    for (int i = 0; i < horizontal; i++) {
		   printf("*");
	    }	
	}
	// Else it prints empty spaces for the first horizontal segment
	else {
		printf("  ");
		for (int i = 0; i < horizontal; i++) {
			printf(" ");
		}
	}
	printf("  ");
}

/**
 * Function that prints the second horizontal segment of each number
*/
void printHorizontalSecond(int num, int horizontal) {
	// If number is one of the following then it prints asteriks for the second horizontal segment
	if (num == 2 || num == 3 || num == 4 || num == 5 || num == 6 || num == 8 || num == 9) {
	    printf("  ");
	    for (int i = 0; i < horizontal; i++) {
		   printf("*");
	    }
	}
	// Else it prints empty spacrs for the second horizontal segment
	else {
		printf("  ");
		for (int i = 0; i < horizontal; i++) {
			printf(" ");
		}
	}
	printf("  ");
}

/**
 * Function that prints the third horizontal segment of each number
*/
void printHorizontalThird(int num, int horizontal) {
	// If number is one of the following then it prints asteriks for the third horizontal segment
	if (num == 2 || num == 3 || num == 5 || num == 6 || num == 8 || num == 9 || num == 0) {
	    printf("  ");
	    for (int i = 0; i < horizontal; i++) {
		   printf("*");
	    }
	}
	// Else it prints empty spacrs for the third horizontal segment
	else {
		printf("  ");
		for (int i = 0; i < horizontal; i++) {
			printf(" ");
		}
	}
	printf("  ");
}

/**
 * Function that prints the first vertical left and vertical right segments of each number
*/
void printVerticalFirst(int num, int horizontal, int vertical) {
	// If number is one of the following then it prints a vertical left segment
	if (num == 4 || num == 5 || num == 8 || num == 9 || num == 0 || num == 6)
	{
		printf("**");
	}
	// Else print empty space
	else
	{
		printf("  ");
	}
	// For loop that creates a gap between the vertical left and vertical right segments
	for (int i = 0; i < horizontal; i++)
	{
		printf(" ");
	}
	// If number is one of the following then it prints a vertical right segment
	if (num == 1 || num == 2 || num == 3 || num == 4 || num == 7 || num == 8 || num == 9 || num == 0)
	{
		printf("**  ");
	}
	// Else print empty spaces
	else
	{
		printf("    ");
	}
}

/**
 * Function that prints the second vertical left and vertical right segments of each number
*/
void printVerticalSecond(int num, int horizontal, int vertical) {
	// If number is one of the following then it prints a vertical left segment
	if (num == 0 || num == 2 || num == 6 || num == 8 || num == 0)
	{
		printf("**");
	}
	// Else print empty spaces
	else
	{
		printf("  ");
	}
	// For loop that creates a gap between the vertical left and vertical right segments
	for (int i = 0; i < horizontal; i++)
	{
		printf(" ");
	}
	// If number is one of the following then it prints a vertical right segment
	if (num == 1 ||  num == 5 || num == 3 || num == 6|| num == 4 || num == 7 || num == 8 || num == 9 || num == 0)
	{
		printf("**  ");
	}
	// Else print empty spaces
	else
	{
		printf("    ");
	}
}



