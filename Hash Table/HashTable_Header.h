#ifndef _HASH_HEADER_H_
#define _HASH_HEADER_H_

#include <cmath>
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
long long HashCalculate(int p, int i, int m);
bool check (Company* list_company, long long index);

//Hashing Function
vector<Company> ReadCompany(string file_name);
long long hashString(string company_name);
Company* CreateHashTable (vector<Company> list_company);
void Insert(Company *list_company, Company ins_company);
Company *Search(Company *hash_table, string company_name);

#endif