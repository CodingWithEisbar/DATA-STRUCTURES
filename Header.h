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

vector<Company> ReadCompany(string file_name);
long long HashString(string company_name);


#endif