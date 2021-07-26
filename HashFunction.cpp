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
        getline(ss, temp.address, '|');
        res.push_back(temp);
    }
    input.close();
    return res;
}


//Return ASCII value
{
    string temp;
    int n = name.size();
    for (int i = n; i > n-character_number; i--)
	{
		temp += name[i];
	}
    int sum = 0;
	for (int i = 0; i < temp.size(); i++)
	{
		sum = sum + temp[i];
	}
    return sum;
}

long long HashString(string company_name)
{   string temp;
    int p = 31, m = pow(10,9) + 9;
    if(company_name.size() > 20) {
        
    }
    
}