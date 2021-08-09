#include <stdio.h>
#include "fileInput.h"
#include <string.h>


//Prototypes are all defined here

void initializeArrayToZero(int count[26], double normalizeCount[26]);   //Prototype for function that initializes count array elements to zero
void processArray(char str[],int count[26]);
int leastAndMostCommon(int count[26]);
void normalize(int max_count, int count[26], double normalizedCount[26]);
void printHistogram(double normalizedCount[26], int count[26]);

int count[26];          //Array of integers to store the required count of alphabets

double normalizedCount[26];    //Array of double type to store normalized values of count

int main(int argc, char** argv) {

	char str[MAX_FILE];

	int len = readFile("Assignment 1\\wonder.txt", str);  //I put the text file and main source file in Assignment 1 folder

	if (len == -1) {

		printf("An error occurred\n");
	}

	else

	{


		initializeArrayToZero(count,normalizedCount);   //call to the method to initialize both arrays(Count and normalized count) to zero. Otherwise wrong output may occur

		processArray(str,count);                       //call to the method that counts the initial letter count

		int max_count=leastAndMostCommon(count);      //call to the method to find out leat and most common letters

		normalize(max_count, count, normalizedCount); //Call to the method to normalize counts

		printHistogram(normalizedCount,count);       //Call to the method to print the Histogram


	}







	return 0;
}//end of main function

//This method initializes the two arrays, count and normalizedCount to zero to avoid dangers of uninitialized variables
void initializeArrayToZero(int count[26], double normalizedCount[26]) {

	for(int i=0; i<26; i++) {

		count[i]=0;
		normalizedCount[i]=0;
	}

}

//This method processes the text from the file. It finds out the count of each alphabet and stores it in the count array
void processArray(char str[],int count[26]) {

	int wordLength=0;

	for(int i=0; str[i]!='\0'; i++) {

		if( (str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z') ) {

			wordLength++;

			//These two variables are used to avoid repeating if-else loops
			//and provide a better algorithm to get the count of initial alphabets
			char checkSmall='a';
			char checkBig='A';

			int j=0;

			while(wordLength==1) {

				if(str[i]==checkSmall||str[i]==checkBig) {

					count[j]++;
					break;
				}

				//These incrementations are necessary for loop logic.
				//They change the alphabet value to the next alphabet to keep the loop's logic.
				//This is important to avoid repeating if-else ladders
				checkSmall++;
				checkBig++;
				++j;

			}


		}

		else {
			wordLength=0;
		}
	}
}

//This method finds out the leat and most common initial letters.
//It also returns the max_Count which is used to calculate the scaling_factor
//The method automatically makes sure that in case there are equal counts of two letters, 
//the letter alphabetically earlier is the Most or least common.
int leastAndMostCommon(int count[26]) {

	int max=count[0];
	int min=count[0];

	char mostCommon='a';
	char leastCommon='a';
	char temp='a';

	for(int i=0; i<25; i++) {

		temp++;     //This variable is used to change the alphabet as the 'i' in outer for loop is incremented

		//By the loop's logic, count[i+1] here refers to the count of the alphabet in temp
		if(count[i+1]>max) {

			max=count[i+1];
			mostCommon=temp;
		}
        //Used to simultaneously calculate leastCommon initial letter
		else if(count[i+1]<min) {
		
			leastCommon=temp;
		}
				
	}

	printf("Most common initial letter is: %c\nThe least common initial letter is: %c\n\n", mostCommon, leastCommon);

	return max;

}

//This is the method used for normalizing the count by calculating the scaling_factor
void normalize(int maxCount, int count[26], double normalizedCount[26]) {

	double scaling_factor;

	if(maxCount>70) {

		scaling_factor=70.00/maxCount;
	}

	else {
		scaling_factor=1;
	}

	for(int i=0; i<26; i++) {

		normalizedCount[i]=count[i]*scaling_factor;
	}
}

//This method prints the actual Histogram.
//The loops in the function uses the almost same logic or algorithm as the processArray funcion
void printHistogram(double normalizedCount[26], int count[26]) {

	char printing_letter='A';
	int j=0;

	printf("Initial letter counts in Histogram:\n");

	while(j<26) {

		for(int i=0; i<normalizedCount[j]; i++) {

			printf("%c",printing_letter);

		}

		printf(" %d\n", count[j]);

		//Incrementations necessary to print the alphabets according to their respective counts without the duplicate use of if-else
		//These change the current alphabet being printed to the next alphabet and changes the count to the count of the next alphabet
		j++;
		printing_letter++;
	}
}






