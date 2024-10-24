#include <iostream>
#include<string.h>
#include<algorithm>
using namespace std;
class PhoneBook{
private:
    string *names;
    string *phones;
    int phoneBookSize;
    int num=0;
public:
    void setSize(int);
    void copyPB(const PhoneBook&);
    bool addEntry(string ,string);
    bool displayEntryAtIndex(int);
    void displayEntryAtIndices(int*);
    void displayAll();
    int* findByName(string);
    string findByPhone(string);
    bool updateNameAt(string, int);
    bool updatePhoneAt(string, int);
    void clear();
};
void PhoneBook :: copyPB(const PhoneBook& obj){
    phoneBookSize=obj.phoneBookSize;
    names=new string[phoneBookSize];
    phones=new string[phoneBookSize];
    for(int i=0;i<phoneBookSize;i++)
    {
        names[i]=obj.names[i];
        phones[i]=obj.phones[i];
    }
}
void PhoneBook::setSize(int s)
{
    phoneBookSize=s;
    names=new string[phoneBookSize];
    phones=new string[phoneBookSize];
}
bool isNameValid(string s){
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==' ')
            return true;
    }
    return false;
}
bool isPhoneValid(string s){
    if(s.length()!=11)
        return false;
    for(int i=0;i<s.length();i++){
        if(s[i]!='0' && s[i]!='1' && s[i]!='2' && s[i]!='3' && s[i]!='4' && s[i]!='5' && s[i]!='6' && s[i]!='7' && s[i]!='8' && s[i]!='9')
        {
            return false;
        }
    }
    return true;
}
bool PhoneBook :: addEntry(string n,string p)
{
    if(isNameValid(n) && isPhoneValid(p))
    {
        names[num]=n;
        phones[num]=p;
        num++;
        return true;
    }
    else{
        cout<<"Your Name or phone number is not valid, please enter them again."<<endl;
        cout<<"================================================================"<<endl;
        return false;}
}
bool PhoneBook :: displayEntryAtIndex(int i){
    if(i<1 || i>phoneBookSize ) {
        cout<<"index is not in range"<<endl;
        cout<<"====================="<<endl;
        return false;
    }
    else {
        cout << names[i - 1] << " -> " << phones[i - 1] << endl;
        cout<<"======================"<<endl;
        return true;
    }
}
void PhoneBook :: displayEntryAtIndices(int* arr){
    for(int i=0;i<phoneBookSize;i++)
    {
        if(arr[i]==1)
        {
            cout<<names[i]<<" -> "<<phones[i]<<endl;
            cout<<"--------------------"<<endl;
        }
    }
    cout<<"======================"<<endl;
}
void PhoneBook :: displayAll(){
    for(int i=0;i<phoneBookSize;i++)
    {
        cout<<names[i]<<" -> "<<phones[i]<<endl;
        cout<<"--------------------"<<endl;
    }
    cout<<"======================"<<endl;
}
int* PhoneBook :: findByName(string s){
    int *Parameterarr;
    Parameterarr=new int[phoneBookSize];
    for(int i=0;i<phoneBookSize;i++)
    {
        for(int j=0;j<s.length();j++)
        {
            if(s[j]!=names[i][j])
            {
                Parameterarr[i]=0;
                break;
            }
            else if(j==s.length()-1 && s[j]==names[i][j]){
                Parameterarr[i]=1;
            }
        }
    }
    return Parameterarr;
}
string PhoneBook :: findByPhone(string phnum){
    for(int i=0;i<phoneBookSize;i++)
    {
        if(phnum==phones[i])
        {
            return names[i];
        }
    }
    return "not found";
}
bool PhoneBook :: updateNameAt(string s, int i){
    if(i<1 || i>phoneBookSize ) {
        cout<<"index is not in range"<<endl;
        cout<<"====================="<<endl;
        return false;
    }
    else {
        names[i-1]=s;
        cout<<"name is updated successfully"<<endl;
        cout<<"============================"<<endl;
        return true;
    }
}
bool PhoneBook :: updatePhoneAt(string s, int i){
    if(i<1 || i>phoneBookSize ) {
        cout<<"index is not in range"<<endl;
        cout<<"====================="<<endl;
        return false;
    }
    else {
        phones[i-1]=s;
        cout<<"phone number is updated successfully"<<endl;
        cout<<"===================================="<<endl;
        return true;
    }
}
void PhoneBook :: clear(){
    delete [] names;
    delete [] phones;
}
int main()
{
    PhoneBook pb;
    cout<<"Enter the size of your phone book : ";
    int s,choice;
    cin>>s;
    pb.setSize(s);
    string name,phone;
    for(int i=1;i<=s;i++)
    {
        do {
            cout << "Enter name " << i << " : ";
            cin.ignore(1,'\n');
            getline(cin,name);

            cout << "Enter phone " << i << " : ";
            cin >> phone;
        }
        while(!pb.addEntry(name,phone));
    }


    do{
        cout<<"Choose an option from the following options:"<<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"1- Display all phone book"<<endl;
        cout<<"------------------------------------------------------"<<endl;
        cout<<"2- Search for entry/entries by name"<<endl;
        cout<<"------------------------------------------------------"<<endl;
        cout<<"3- Search for entry/entries by phone"<<endl;
        cout<<"------------------------------------------------------"<<endl;
        cout<<"4- Find an entry by index"<<endl;
        cout<<"------------------------------------------------------"<<endl;
        cout<<"5- Update name by index"<<endl;
        cout<<"------------------------------------------------------"<<endl;
        cout<<"6- Update phone by index"<<endl;
        cout<<"------------------------------------------------------"<<endl;
        cout<<"7- Copy phone book to another and display entries of the new phone book"<<endl;
        cout<<"------------------------------------------------------"<<endl;
        cout<<"8- Exit"<<endl;
        cout<<"------------------------------------------------------"<<endl;
        cin>>choice;
        if(choice==1)
        {
            pb.displayAll();
        }
        else if(choice==2)
        {
            string PartOfName;
            cin.ignore(1,'\n');
            cout<<"Enter Part of the name or the full name : ";
            getline(cin,PartOfName);
            int *parr=pb.findByName(PartOfName);
            pb.displayEntryAtIndices(parr);
        }
        else if(choice==3)
        {
            string phoneNum;
            cout<<"Enter the phone number : ";
            cin>>phoneNum;
            cout<<"The contact of this phone number is "<<pb.findByPhone(phoneNum)<<endl;
            cout<<"==================================================="<<endl;
        }
        else if(choice==4){
            int in;
            cout<<"Enter the index : ";
            cin>>in;
            pb.displayEntryAtIndex(in);
        }
        else if(choice==5)
        {
            int in;
            string newn;
            cout<<"Enter the index : ";
            cin>>in;
            cin.ignore(1,'\n');
            cout<<"Enter the new name : ";
            getline(cin,newn);
            pb.updateNameAt(newn,in);
        }
        else if(choice==6)
        {
            int in;
            string newp;
            cout<<"Enter the index : ";
            cin>>in;
            cout<<"Enter the new phone number : ";
            cin>>newp;
            pb.updatePhoneAt(newp,in);
        }
        else if(choice==7)
        {
            PhoneBook newpb;
            newpb.copyPB(pb);
            cout<<"The new phone book "<<endl;
            newpb.displayAll();
        }
        else if(choice==8)
        {
            pb.clear();
            cout<<"* Exiting the phone book *";
        }
    }
    while(choice!=8);
}