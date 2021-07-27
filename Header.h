#ifndef _HASH_HEADER_H_
#define _HASH_HEADER_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Company{
    string name;
    string profit_tax;
    string address;

};

//Stuff
string getLastCharacter(string name, int character_number);
bool check (Company* list_company, long long index);

//Hashing Function
vector<Company> ReadCompany(string file_name);
long long HashString(string company_name);
Company* CreateHashTable (vector<Company> list_company);

#endif