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
            res = res + temp[i] * pow((p%m),i);
        }
        return res;
    }
    else {
        for (int i = 0; i < company_name.size(); i++)
        {
            res = res + temp[i] * pow((p%m),i);
        }
        return res;
    }
}