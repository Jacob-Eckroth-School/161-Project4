
#include <iostream>
#include <string>
#include <cmath>
#include "helper_functions.h"
using namespace std;


/******************************
 ** Function: check_range()
 ** Description: Tests if value is within a range
 ** Parameters: lower_bound, upper_bound, test_value
 ** pre_conditions: takes in 3 int parameters
 ** Post conditions: returns a bool to tell if value is within the range
*******************************/
bool check_range(int lower_bound, int upper_bound, int test_value){
	if(lower_bound <= test_value && test_value <= upper_bound){
		return true;
	}else{
		return false;
	}
}

/******************************
 ** Function: is_capital()
 ** Description: Tests if given character is a capital letter
 ** Parameters: letter
 ** pre_conditions: takes in 1 char letter
 ** Post conditions: returns a bool to tell if the letter is capital or not
*******************************/
bool is_capital(char letter){
	
		
	if(65<=letter && letter <= 90){
		return true;
	}else{
		return false;
	}
}

/******************************
 ** Function: is_even()
 ** Description: Tests if an integer is even or not
 ** Parameters: 1 integer
 ** pre_conditions: takes in 1 integer num
 ** Post conditions: returns a bool to tell if the number is even or not
*******************************/
bool is_even(int num){
	if(num % 2 == 0){
		return true;
	}else{
		return false;
	}
}

/******************************
 ** Function: is_odd()
 ** Description: Tests if an integer is odd or not
 ** Parameters: 1 integer
 ** pre_conditions: takes in 1 integer num
 ** Post conditions: returns a bool to tell if the number is odd or not
*******************************/
bool is_odd(int num){
	if(num % 2 == 0){
		return false;
	}else{
		return true;
	}
}

/******************************
 ** Function: equality_test()
 ** Description: Tests if an 2 integers are the same, returns 0 if they are, returns -1 if the first is less than the second, returns 1 if the second is higher than the first
 ** Parameters: 2 integers
 ** pre_conditions: takes in 2 integers num1, and num2
 ** Post conditions: returns an int to say if the number1 is greater, less than, or equal to number 2
*******************************/
int equality_test(int num1, int num2){
	if(num1==num2){
		return 0;
	}else if(num1 > num2){
		return 1;
	}else{
		return -1;
	}
}

/******************************
 ** Function: float_is_equal()
 ** Description: tests if num1 and num2 are equal to eachother within a certain precision
 ** Parameters: 2 floats numbers and 1 float precision
 ** pre_conditions: takes in 2 floats as numbers as one float as a precision range
 ** Post conditions: Returns a bool saying if the numbers are equal within the precision range
*******************************/
bool float_is_equal(float num1, float num2, float precision){
	int difference = abs(num1-num2);
	if(precision>=difference){
		return true;
	}else{
		return false;
	}
}

/******************************
 ** Function: is_int()
 ** Description: takes in a string and tests if the given string is an integer
 ** Parameters: a string
 ** pre_conditions: Takes in one string called string num
 ** Post conditions: Returns true if the string is an integer. Returns false if the string is not 
*******************************/
bool is_int(string num){
	for(int i = 0; i < num.length(); i++){
		if(num[i] < 48 ||57 < num[i] )
			if(num[i] == 45){
				if(i !=0){
					return false;
				}
			}else if(num[i]!= 45 ){
				return false;
			}
			
	}
	return true;
}

/******************************
 ** Function: numbers_present()
 ** Description: Indicates if the string contains numbers
 ** Parameters: a string
 ** pre_conditions: Takes in a string that may or may not have numbers
 ** Post conditions: Returns true if the string contains numbers. Returns false if the string does not 
*******************************/
bool numbers_present(string intstring){
	for(int i = 0; i < intstring.length(); i++){
		if(48 <= intstring[i] && intstring[i] <= 57){
			return true;
		}
	}
	return false;
}	

/******************************
 ** Function: letters_present()
 ** Description: Indicates if a string contains letters
 ** Parameters: a string
 ** pre_conditions: Takes in a string that may or may not have letters
 ** Post conditions: Returns true if the string contains letters. Returns false if the string does not 
*******************************/
bool letters_present(string sentence){
	for(int i = 0; i < sentence.length(); i++){
		if(65 <= sentence[i] && sentence[i] <= 90 || 97 <= sentence[i] && sentence[i] <= 122){
			return true;
		}
	}
	return false;
} 

/******************************
 ** Function: contains_sub_string()
 ** Description: Indicates if a string contains a substring
 ** Parameters: a string and a substring
 ** pre_conditions: Takes in a string that may or may not contain a substring that the user also inputs
 ** Post conditions: Returns true if the string contains the substring. Returns false if the string does not 
*******************************/
bool contains_sub_string(string sentence, string sub_string){   //note that this function was hard as shit to make
	int substringlocation = 0;  //initializes the position within the substring as 0
	string teststring = ""; //makes a string that we will compare to the substring
	for(int i = 0; i < sentence.length(); i++){ //runs through the string
		if(sentence[i] == sub_string[substringlocation]){ /*tests if the letter in the sentence is equal
 to the first letter in the substring*/
			for(int j = i; j< sentence.length(); j++){ //runs through the letters to see if they're all there
				teststring += sentence[j];
				
				if(sub_string[substringlocation] != sentence[j]){ /*breaks out in case it stops
 being equivalent so it doesn't have to run through whole sentence*/
					break;
				}
				if (teststring == sub_string){
					return true;
				}
				substringlocation++;
			}
			
		}			
		substringlocation = 0;
		teststring = "";
	}
	return false;
}

/******************************
 ** Function: word_count()
 ** Description: Provides the number of words within a string 
 ** Parameters: a string
 ** pre_conditions: Takes in a string that may or may not have multiple words
 ** Post conditions: Returns an int that says how many words *letters with spaces after them* there are in the string 
*******************************/
int word_count(string sentence){
	int wordcount = 0;
	sentence += " "; //adds a space to the end to make sure the last word gets tested
	for(int i = 0; i < sentence.length()-1; i++){ //sentence length -1 because the last symbol is a space
		if(sentence[i] != 32 && sentence[i+1] ==32){
			wordcount ++;
		}
	}
	return wordcount;
}

/******************************
 ** Function: to_upper()
 ** Description: makes all lowercase characters within a string uppercase 
 ** Parameters: a string
 ** pre_conditions: Takes in a string that can have multiple types of symbols
 ** Post conditions: Returns the string with all the characters uppercase. 
*******************************/
string to_upper(string sentence){
	string newsentence= "";
	for(int i = 0; i < sentence.length(); i++){
		if( 97 <= sentence[i] && sentence[i] <= 122){
			newsentence += sentence[i] - 32;
		}else{
			newsentence += sentence[i];
		}
	}
	return newsentence;
}

/******************************
 ** Function: to_lower()
 ** Description: makes all uppercase characters within a string lowercase 
 ** Parameters: a string
 ** pre_conditions: Takes in a string that can have multiple types of symbols
 ** Post conditions: Returns the string with all the characters lowercase. 
*******************************/
string to_lower(string sentence){
	string newsentence = "";
	for(int i = 0; i < sentence.length(); i++){
		if (65 <= sentence[i] && sentence[i] <= 90){
			newsentence += sentence[i] + 32;
		}else{
			newsentence += sentence[i];
		}	
	}
	return newsentence;
}


/******************************
 ** Function: get_int()
 ** Description: Takes a string, tests whether it's an integer, return the integer if it is 
 ** Parameters: a string
 ** pre_conditions: Takes in a string that can have multiple types of symbols but can also be an integer
 ** Post conditions: Returns an integer if the integer exists
*******************************/
int get_int(string integer){
	
	bool isnegative = false;
	int newint = 0;
	if(integer[0] == 45){
		isnegative=true;
	}
	for(int i = 0; i < integer.length(); i++){
		if(48 <= integer[i] && integer[i] <= 57){
			
			newint += (integer[i]-48)* pow(10,integer.length()-i-1);
		}else if(integer[i] == 45){
			if(i != 0){
				return 0;
			}
		}else{
			return 0;
		}
		
	}
	if(isnegative){
		newint *= -1;	
	}
	return newint; 
}
/**************************************
** Function: to_lowest_terms()
** Description: tests for valid input and if input is valid reduces the numerator and denominator
** Parameters: int numerator, int denominator
** Pre-conditions: takes in 2 numbers
** Post-conditions: Either returns false or updates the numerator and denominator to lowest terms and returns true
*************************************/
bool to_lowest_terms(int &numerator, int &denominator){

	if(denominator == 0){
		cout<<"The denominator cannot be 0, please try again."<<endl;
		return false;
	}else{
		int gcd = g_c_d(numerator,denominator);
		numerator = numerator / gcd;
		denominator = denominator / gcd;
		return true;
	}
}
/************************************
** Function:g_c_d()
** Description: finds the greatest common denominator for 2 integers
** Parameters: int num1, int num2
** Pre-conditions: takes in 2 integers
** Post-conditions: Returns the greatest common denominator for the 2 numbers
***********************************/
int g_c_d(int num1, int num2){
	int gcd = 1;
	for(int i = 1; i <= abs(num1); i++){
		if(((num1)%i == 0) &&((num2)%i == 0)){
			gcd = i;
		}
	}
	return gcd;
}

/***********************************
** Function: printfraction()
** Description: Prints the fraction using the numerator and denominator
** Parameters: int number, int denominator
** Pre-conditions: takes in 2 integers
** Post-conditions: Returns the fraction in fractino form, with the negative signs in the right place
***********************************/
void printfraction(int numerator, int denominator){
	if(numerator<0 && denominator < 0){
		numerator = abs(numerator);
		denominator = abs(denominator);
	}
	if(numerator > 0 && denominator < 0){
		numerator *= -1;
		denominator *= -1;
	}
	if(denominator == 1){
		cout <<"This fraction simplified is: "<<numerator<<endl;
	}else if(numerator == 0){
		cout<<"This fraction simplified is: 0"<<endl;
	}else{
		cout<<"This fraction simplified is: "<<numerator << "/" <<denominator << endl;
	}
}

/***********************************
** Function: inputnumdem()
** Description: Gets the inputs for a numerator and denominator and tests to make sure they are legit inputs
** Parameters: int number, int denominator
** Pre-conditions: points to 2 integers
** Post-conditions: Sets the pointer integers to the values inputted into them. Void function otherwise.
***********************************/
void inputnumdem(int &numerator, int &denominator){	
	string denstring= "1";
	inputnum(numerator);
	do{
		do{
			if(!get_int(denstring) && denstring != "0"){
				cout<<"Invalid input, enter whole numbers only!"<<endl;
			}
			cout<<"Enter your denominator: ";
			getline(cin,denstring);
			if(denstring =="0"){
				break;
			}
		}while(!get_int(denstring));	
		denominator = get_int(denstring);
	}while(!to_lowest_terms(numerator,denominator));
}

/***********************************
** Function: inputnum()
** Description: Gets the input for a numerator and tests to make sure it is avlid
** Parameters: An integer
** Pre-conditions: The int being passed to it exists
** Post-conditions: Sets the numerator to the input 
***********************************/
void inputnum(int &numerator){
	string numstring = "2";
	do{	
		if(numstring == "0"){
			break;
		}
		if(!get_int(numstring)){
			cout<<"Invalid input, enter whole numbers only!"<<endl;
		}
		cout <<"Enter your numerator: ";
		getline(cin,numstring);
	}while(!get_int(numstring));
	numerator = get_int(numstring);
}







