#include "HashTable_Header.h"

vector<Company> ReadCompany(string file_name)
{
    fstream input(file_name);
    string sample, name, tax, address;
    getline(input, sample); // Bỏ qua dòng đầu tiên
    Company after_string_token;
    vector<Company> companies;
    while (!input.eof())
    {
        getline(input, sample);
        stringstream ss(sample);
        getline(ss, name, '|');
        getline(ss, tax, '|');
        getline(ss, address);
        after_string_token.name = name;
        after_string_token.profit_tax = tax;
        after_string_token.address = address;
        companies.push_back(after_string_token);
    }
    input.close();
    return companies;
}

long long HashCalculate(int p, int i, int m)
{
    long long result = p;
    for(int j=1; j < i; j++){
        result = result * p;
        result = result % m;
    }
    return result;
}

long long HashString(string company_name)
{
    int length = (company_name.size() > 20) ? 20 : company_name.size(); //Condition Operators
    int begin = (company_name.size() > 20) ? company_name.size() - 20 : 0;
    long long m = pow(10,9)+9;
    long long hashValue = 0;
    for(int i = begin; i < (begin + length - 1);i++){
        hashValue = hashValue + int(company_name[i]) * HashCalculate(31, i - begin, m);
        hashValue = hashValue % m;
    }
    return hashValue;
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
        while (check(hashTable, index)) //Collision Solution
        {
            index++;
            if (index >= 2000)
                index = 0;
            if (index == cap_index)
                return NULL;
        }
        hashTable[index] = i;
    }
    return hashTable;
}

void Insert(Company *list_company, Company ins_company)
{
    long long index = HashString(ins_company.name);
    long long cap_index = index;
    while (check(list_company, index))
    {
        index++;
        if (index >= 2000)
            index = 0;
        if (index == cap_index)
        {
            cout << "Full\n";
            return;
        }
    }
    list_company[index] = ins_company;
}

Company *Search(Company *hash_table, string company_name)
{
    long long index = HashString(company_name);
    while (hash_table[index].name != company_name && !check(hash_table, index))
        index++;
    if (hash_table[index].name != company_name)
        return NULL;
    return &hash_table[index];
}