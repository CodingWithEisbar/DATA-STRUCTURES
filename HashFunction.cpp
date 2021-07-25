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
        getline(ss,temp.profit_tax, '|');
        getline(ss, temp.address, '|');
        res.push_back(temp);
        
    }
    input.close();
    return res;
}

long long HashString(string company_name)
{
    //Xin lỗi mn function này hơi fail :((
}