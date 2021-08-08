#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

struct Company{
    string name;
    string tax;
    string address;
};

vector<Company> readCompanyList(string file_name)
{
    ifstream input(file_name);
    string sample, name, tax, address;
    getline(input, sample);
    Company after_string_token;
    vector<Company> companyList;
    while (!input.eof())
    {
        getline(input, sample);
        stringstream ss(sample);
        getline(ss, name, '|');
        getline(ss, tax, '|');
        getline(ss, address);
        after_string_token.name = name;
        after_string_token.tax = tax;
        after_string_token.address = address;
        companyList.push_back(after_string_token);
    }
    input.close();
    return companyList;
}

long long hashCalculate(int p, int i, int m)
{
    long long result = 1;
    for (int j = 0; j < i; j++)
    {
        result *= p;
        result = result % m;
    }
    return result;
}

long long hashString(string company_name)
{   
    int len = company_name.size() > 20 ? 20 : company_name.size();
    int begin = company_name.size() > 20 ? company_name.size() - 20 : 0;
    long long m = pow(10, 9) + 9;
    long long hashValue = 0;
    for (int i = begin; i < (begin + len); i++)
    {
        hashValue += int(company_name[i]) * hashCalculate(31, i - begin, m);
        hashValue = hashValue % m;
    }
    return hashValue;
}

/*Company *createHashTable(vector<Company> list_company)
{
    Company* pC = new Company[2000];
    for(int i = 0; i<2000; i++){
        pC[i]={"", "", ""};
    }
    for(int i = 0; i<list_company.size();i++){
        int hval = hashString(list_company[i].name);
        if(pC[hval % 2000].name == ""){
            pC[hval % 2000] = {list_company[i].name, list_company[i].tax, list_company[i].address};
        }
        else{
            int temp = hashString(list_company[i].name) % 2000 + 1;
            while(pC[temp].name != ""){
                temp = (temp+1) % 2000; 
            }
            pC[temp] = {list_company[i].name, list_company[i].tax, list_company[i].address};
        }
    }
    return pC;
}*/


Company *createHashTable(vector<Company> list_company)
{
    Company *pCompany = new Company[2000];
    for (int i = 0; i < 2000; i++)
    {
        pCompany[i] = {"", "", ""};
    }
    for (int i = 0; i < list_company.size(); i++)
    {
        int hashValue = hashString(list_company[i].name);
        if (pCompany[hashValue % 2000].name == "")
        {
            pCompany[hashValue % 2000] = {list_company[i].name, list_company[i].tax, list_company[i].address};
        }
        else
        {
            int temp = hashString(list_company[i].name) % 2000 + 1;
            while (pCompany[temp].name != "")
            {
                temp = (temp + 1) % 2000;
            }
            pCompany[temp] = {list_company[i].name, list_company[i].tax, list_company[i].address};
        }
    }
    return pCompany;
}

void Insert(Company *hash_table, Company ins_company)
{
    int hashValue = hashString(ins_company.name);
    if (hash_table[hashValue % 2000].name == "")
    {
        hash_table[hashValue % 2000] = {ins_company.name, ins_company.tax, ins_company.address};
    }
    else
    {
        int temp = hashString(ins_company.name) % 2000 + 1;
        while (hash_table[temp].name != "")
        {
            temp = (temp + 1) % 2000;
        }
        hash_table[temp] = {ins_company.name, ins_company.tax, ins_company.address};
    }
}

Company *Search(Company *hash_table, string company_name)
{
    int hashValue = hashString(company_name) % 2000;
    while (hash_table[hashValue].name != company_name)
    {
        if (hash_table[hashValue].name == "")
            return NULL;
        hashValue = (hashValue + 1) % 2000;
    }
    return &hash_table[hashValue];
}

int main()
{
    Company *pC = createHashTable(readCompanyList("MST.txt"));

    for (int i = 0; i < 2000; i++)
    {
        if (pC[i].name != "")
        {
            cout << i << "  " << pC[i].name << endl;
        }
    }
    delete []pC;
    return 0;
}