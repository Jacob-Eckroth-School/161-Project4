/***************************
 ** Program: assignment4.cpp
 ** Author: Jacob Eckroth
 ** Date: 11/24/2019
 ** Description: Has 3 different tests which parse through a cstring thtat the user inputs. Test for palindrome, test for frequency of all words, and test for inputs of user words.
 ** Inputs: lots of cstrings for user arrays, and ints corresponding to amounts of words.
 ** Outputs: Strings saying the result of the test
 **************************/
#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
#include <cstdlib>
#include <cmath>
#include "helper_functions.h"

using namespace std;

bool is_palindrome (char *str);
char * purge_string(char *str);
void get_user_input(char*);
int getchoice();
void palindromechoice(char *);
void frequencychoice(char *);
void givenfrequencychoice(char *);
bool runagain();
int getintinput();
void frequencylist(string *, int*, int);
bool palindromecompare(char *, char*, int);
int wordcounter(char *);

int main(){
	bool another = false;
	do{
		cout<<endl;
		int choice = 0;
		char *userarray = new char[1024];	
		get_user_input(userarray);


		choice = getchoice();

		if(choice == 1){
			palindromechoice(userarray);
		}else if(choice == 2){
			frequencychoice(userarray);
		}else{
			givenfrequencychoice(userarray);
		}
		delete [] userarray;
		another = runagain();
	}while(another == true);
	return 0;
}
/*************************************
 ** Function: purge_string()
 ** Description: Makes all characters in a string lowercase, and removes all characters that aren't letters. It does keep spaces.
 ** Parameters: char *str
 ** Pre_conditions: Takes in a pointer to a cstring that exists on the heap
 ** Post_conditions: Changes the array where the pointer is point to to remove all special characters and make all letters lowercase.
 *************************************/
char * purge_string (char *str){
	char *purgedarray = new char[1024];
	for(int i = 0; i < 1023; i++){
		purgedarray[i] = ' ';
	}
	int purgedarrayloc = 0;
	for(int i = 0; i < strlen(str); i++){

		if(str[i] >= 97 && str[i] <= 122){
			purgedarray[purgedarrayloc] = str[i];
			purgedarrayloc++;
		}else if(str[i] >=65 && str[i] <= 90){
			purgedarray[purgedarrayloc] = str[i] +32;
			purgedarrayloc++;
		}else if(str[i] == 32){
			purgedarray[purgedarrayloc] = str[i];
			purgedarrayloc++;
		}
	}
	return purgedarray;
}

/*************************************
 ** Function: is_palindrome()
 ** Description: tests if a string is a palindrome. ignores special characters and spaces. 
 ** Parameters: char *str
 ** Pre_conditions: takes in a pointer to a cstring that exists on the heap
 ** Post_conditions: returns true if the string is a palindrome, returns false if it's not.
 ***********************************/
bool is_palindrome(char *str){
	int palindromelength = 0;
	int currentposition = 0;		
	for(int i = 0; i < strlen(str); i++){
		if(str[i] != 32 && str[i] >=97 && str[i] <= 122){ //ignoring garbage values
			palindromelength++;

		}
	}	
	char *palindrome = new char[palindromelength];//makes the 2 test strings with room for null character
	char *emordnilap = new char[palindromelength];	
	for(int i = 0; i < strlen(str); i++){
		if(str[i] != 32 && str[i] >=97 && str[i] <= 122){
			palindrome[currentposition++] = str[i];
		}
	}
	currentposition = palindromelength-1; //This works don't remove it or everything will break
	for(int i = 0; i <palindromelength; i++){
		emordnilap[currentposition--] = palindrome[i];
	}
	delete[]str;
	return palindromecompare(palindrome,emordnilap,palindromelength);

}

/*************************************
 ** Function: get_user_input()
 ** Description: Prompts the user for an entry and then stores that entry using a pointer to a cstring
 ** Parameters: char *array
 ** Pre_conditions: takes in a pointer to a cstring that exists on the heap
 ** Post_conditions: Changes the cstring that is being pointed to to have the user input in it.
 ***********************************/
void get_user_input(char *array){
	for(int i = 0; i < 1023; i++){
		array[i] = ' ';
	}
	cout<<"Please enter a sentence less than 1024 letters." <<endl;
	cin.getline(*&array,1023);
}

/*************************************
 ** Function: getchoice()
 ** Description: Asks the user for the input to run a program, and error handles if the input is not 1-3
 ** Parameters: No parameters
 ** Pre_conditions: No preconditions
 ** Post_conditions: Returns a integer between 1-3 depending on the user input
 ************************************/
int getchoice(){
	string userinput = "2";
	cout<<"Please enter the number for the test you want to run."<<endl;
	cout<<"If you want to test if your entry is a palindrome enter 1"<<endl;
	cout<<"If you want to count the frequency of all words enter 2"<<endl;
	cout<<"If you want to count the frequency of specific words enter 3: ";
	do{
		if(!get_int(userinput) || !(get_int(userinput) >=1) || !(get_int(userinput) <=3)){

			cout<<endl<<"Invalid input. Please enter a whole number between 1 and 3: ";
		}
		getline(cin,userinput);
	}while(!get_int(userinput) || !(get_int(userinput) >= 1) || !(get_int(userinput) <=3));
	return get_int(userinput);
}

/*************************************
 ** Function: palindromechoice()
 ** Description: Tests whether an input is a palindrome and couts if it is or not
 ** Parameters: char *userarray
 ** Pre_conditions: A pointer that points to a cstring
 ** Post_conditions: Couts whether it's a palindrome.
 ************************************/
void palindromechoice(char *userarray){
	char *purgedarray = purge_string(userarray);


	if(is_palindrome(purgedarray)){
		cout <<"Your entry was a palindrome!"<<endl;
	}else{
		cout<<"Your entry was not a palindrome"<<endl;
	}



}
/*************************************
 ** Function: frequencychoice()
 ** Description: Tests how many time each word in a sentence appears
 ** Parameters: char *userarray
 ** Pre_conditions: A pointer that points to a cstring
 ** Post_conditions: Couts a frequency list saying how often each word appears in a sentence.
 ************************************/
//This is just over 15 lines because of all the nested loops I needed to have, and the code here isn't reused anywhere so it'd be kinda pointless to make a function just for the sake of making a function
void frequencychoice(char *userarray){
	char *purgedarray = purge_string(userarray);
	it wordcount = wordcounter(purgedarray);
	string stringarray[256];
	bool alreadyword = true;
	int intarray[256];
	string userinput = "";
	int position = 0;
	int differentwords = 0;
	for(int i = 0; i < strlen(purgedarray)+1; i++){
		if(purgedarray[i] >=97 && purgedarray[i] <= 122 ){	
			userinput += purgedarray[i];
		}else if(purgedarray[i] == ' '  && purgedarray[i-1] !=' ' || purgedarray[i] == 0 && purgedarray[i-1] != ' '){ //Tests if it's the end of a word, or the end of the c string

			for(int i = 0; i < wordcount; i++){

				if(stringarray[i] == userinput){
					intarray[i]++;
					userinput = "";
					alreadyword = true;
					break;
				}else{
					alreadyword = false;
				}

			}
			if(!alreadyword){
				stringarray[position] = userinput;
				userinput = "";
				intarray[position] = 1;
				position++;
				differentwords++;
			}
		}
	}
	frequencylist(stringarray,intarray,differentwords);
	delete [] purgedarray;
}

/*************************************
 ** Function: givenfrequencychoice()
 ** Description: Tests how many time given words from the user appears in a cstring
 ** Parameters: char *userarray
 ** Pre_conditions: A pointer that points to a cstring
 ** Post_conditions: couts a frequency list that lists how many times the user chosen words appear in the cstring
 ************************************/
//This is 16 just because I needed to delete all my arrays.
void givenfrequencychoice(char *userarray){
	int amountofwords = getintinput();
	string *stringarray = new string[amountofwords];
	int *intarray = new int[amountofwords];
	for(int i = 0; i < amountofwords; i++){
		cout<< "Please enter case-sensitive word #"<<i+1<<": ";
		getline(cin,stringarray[i]);

		intarray[i] = 0;
	}
	string teststring = "";
	char *purgedarray = purge_string(userarray);
	for(int i = 0; i < strlen(purgedarray)+1; i++){
		if(purgedarray[i] >=97 && purgedarray[i] <= 122 ){ //if is a lowercase letter
			teststring += purgedarray[i];
		}else if(purgedarray[i] == ' ' || purgedarray[i] == 0){ //If it's a space, or a null
			for(int i = 0; i < amountofwords; i++){ //test if it's equivalent to any of the previous ones
				if(teststring == stringarray[i]){
					intarray[i]++;
				}
			}
			teststring = "";	
		}
	}
	frequencylist(stringarray,intarray,amountofwords);
	delete[]purgedarray;
	delete[]stringarray;
	delete[]intarray;
}

/*************************************
 ** Function: runagain()
 ** Description: Tests if the user wants to run the program again
 ** Parameters: None
 ** Pre_conditions: None
 ** Post_conditions: Returns true if they want to run it again, returns false if they do not
 ************************************/
bool runagain(){
	string userinput = "0";
	cout<<"Do you want to run the program again?(0=no, 1=yes): ";
	do{
		if(userinput !="0" && userinput != "1"){
			cout<<"Invalid input, please enter either 0 or 1: ";
		}
		getline(cin,userinput);	
	}while(userinput != "0" && userinput != "1");	
	return get_int(userinput);
}

/*************************************
 ** Function: getintinput()
 ** Description: Gets how many words the user wants to input in the given frequency choice. Error handling
 ** Parameters: None
 ** Pre_conditions: None
 ** Post_conditions: Returns an int 1 or higher depending on what the user inputs
 ************************************/
int getintinput(){
	cout<<"Please enter the number of words you want to test for: ";
	string userinput = "5";
	do{
		if(!get_int(userinput) || get_int(userinput) <=0){
			cout<<endl<<"Invalid input. Please enter a positive whole number: ";
		}
		getline(cin,userinput);

	}while(!get_int(userinput) || get_int(userinput) <=0);
	return(get_int(userinput));
}

/*************************************
 ** Function: frequencylist()
 ** Description: Couts a list of how often words appear in a cstring
 ** Parameters: string *stringarray, int *intarray, int differentwords
 ** Pre_conditions: stringarray has an amount of strings, intarray has arrays corresponding to the stringarray, different words is a positive int
 ** Post_conditions: couts a list of how many times each word appears in the stringarray.
 ************************************/
void frequencylist(string *stringarray, int *intarray, int differentwords){
	cout<<"Frequency List";
	for(int i = 0; i < differentwords; i++){
		cout<<endl<<stringarray[i]<<": "<<intarray[i];
	}
	cout<<endl;
}

/*************************************
 ** Function: palindromecomapre()
 ** Description: Tests if 2 cstrings are the same as eachother.
 ** Parameters: char *palindrome, char *emordnilap, int wordlength
 ** Pre_conditions: char *palindrome exists, char *emordnilap exists and they each have int wordlength characters that matter in it.
 ** Post_conditions: Returns true if the cstrings are the same, false if they're not.
 ************************************/
bool palindromecompare( char *palindrome, char*emordnilap, int wordlength){
	char palindromestring[wordlength+1];
	char emordnilapstring[wordlength+1];
	for(int i = 0; i < wordlength; i++){
		palindromestring[i] = palindrome[i];
		emordnilapstring[i] =emordnilap[i];
	}
	delete []palindrome;
	delete []emordnilap;
	palindromestring[wordlength] = '\0';
	emordnilapstring[wordlength] = '\0';

	if(strcmp(palindromestring,emordnilapstring) ==0){
		return true;
	}
	return false;
}

/*************************************
 ** Function: wordcounter()
 ** Description: Counts the amount of words in a cstring
 ** Parameters: char *purgedarray
 ** Pre_conditions: purgedarray exists and is pointed to using a carray. Purgedarray has been purged
 ** Post_conditions: Returns an integer that contains how many words the cstring has.
 ************************************/
int wordcounter(char*purgedarray){
	int wordcount = 0;
	for(int i = 0; i < strlen(purgedarray); i++){
		if(purgedarray[i] == ' ' && purgedarray[i-1] != ' '|| (purgedarray[i+1] == '\0' && purgedarray[i] != ' ') ){
			wordcount++;
		}
	}
	return wordcount;
}
