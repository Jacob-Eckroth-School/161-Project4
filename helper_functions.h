#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

bool check_range(int,int,int);
bool is_capital(char);
bool is_even(int);
bool is_odd(int);
int equality_test(int,int);
bool float_is_equal(float, float, float);
bool is_int(string);
bool numbers_present(string);
bool letters_present(string);
bool contains_sub_string(string,string);
int word_count(string);
string to_upper(string);
string to_lower(string);
int get_int(string); 
bool to_lowest_terms(int &, int &);
int g_c_d(int,int);
void printfraction(int,int);
void inputnumdem(int &,int &);
void inputnum(int &);
#endif
