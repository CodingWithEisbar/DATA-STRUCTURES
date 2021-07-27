#include "Header.h"

vector<Company> ReadCompany(string file_name)
{
    fstream input(file_name.c_str());
    vector<Company> res;
    string company;
    while (!input.eof())
    {

        getline(input, company);
        stringstream ss(company);
        Company temp;
        getline(ss, temp.name, '|');
        getline(ss, temp.profit_tax, '|');
        getline(ss, temp.address, '\n');
        res.push_back(temp);
    }
    input.close();
    return res;
}

string getLastCharacter(string name, int character_number)
//Return ASCII value
{
    string temp;
    int n = name.size();
    for (int i = n; i > n - character_number; i--)
    {
        temp += name[i];
    }
    return temp;
}

long long HashString(string company_name)
{
    string temp;
    int p = 31, m = pow(10, 9) + 9;
    long long res = 0;
    if (company_name.size() > 20)
    {
        temp = getLastCharacter(company_name, 20);
        for (int i = temp.size(); i > 0; i--)
        {
            res = res + (temp[i] * pow((p % m), i));
        }
        return res;
    }
    else
    {
        for (int i = 0; i < company_name.size(); i++)
        {
            res = res + (temp[i] * pow((p % m), i));
        }
        return res;
    }
}

bool check(Company *list_company, long long index)
//Check the existence list element
{
    if (list_company[index].name == "" && list_company[index].profit_tax == "" && list_company[index].address == "")
        return 0;
    return 1;
}

Company *CreateHashTable(vector<Company> list_company)
{
    Company *hashTable = new Company[2000];
    for (auto i : list_company)
    {
        //Take the for-each-loop to go through the list_company
        long long index = HashString(i.name);
        long long cap_index;
        while (check(hashTable, index))
        {
            index++;
            if (index >= 2000) index = 0;
            if (index == cap_index) return;
        } hashTable[index]=i;
    }
    return hashTable;
}
