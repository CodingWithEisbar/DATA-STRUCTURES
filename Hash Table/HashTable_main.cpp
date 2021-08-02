#include "HashTable_Header.h""


int main(){
    vector<Company> list;
    list = ReadCompany("MST.txt");
    for (int i = 0; i < list.size(); i++)
    {
        cout<<"Company Name: "<<list[i].name<<endl;
        cout<<"Tax number: "<<list[i].profit_tax<<endl;
        cout<<"Address: "<<list[i].address<<endl;
        cout<<"______________________________________________________________"<<endl;
    }

    return 0;
}