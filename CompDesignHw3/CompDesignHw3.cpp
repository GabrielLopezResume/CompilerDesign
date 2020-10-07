//Group names: Lopez,Gabe and Noel
// Assignment: No.3.1
//   Due Date: September 23rd
//	Purpose: This program reads a list of string from a text document and determines if the string
//           is a number, identifier or reserved word
#include<fstream>
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;



/* function to evaluate a string and return if it contains eithera operation, space or digit */
string isRes(string s);
string isDigit(string s);
string isId(string s);
bool isSpace(string s);



int main(){

    //reads a string from a file couts the result of a few functions
    string s;
    fstream f("input.txt",fstream::in);
    cout<<std::left<<std::setw(8)<<"Token"<<"\t"<<"Number\tIdentifier\tReserved Word"<<endl;

    while(!f.fail()&& f>>s){
        if(!isSpace(s)){
            cout<<std::left<<std::setw(8)<<s<<"\t"<<isDigit(s)<<"\t"<<isId(s)<<"\t"<<isRes(s)<<endl;
        }
    }
    system("pause");
    return 0;
}

//return false if it is not a space and true if it is all a space
bool isSpace(string s){
    for(int i =0; i< s.length(); i++){
        if(!isspace(s[i])){return false;}
    }
    return true;
}

//returns false if the string is not a digit and true if it is all digits
string isDigit(string s){
    for(int i =0; i< s.length(); i++){
        if(!isdigit(s[i])){return "no";}
    }
    return "yes";
}

//returns true if string matches the 4 operation symbols
string isRes(string s){
    if(s == "while" ||s == "for" ||s == "switch" ||s == "do"||s == "return"){return "yes";}
    return "no";
}

//returns false if the string is not a identifier and true if it is 
string isId(string s){
    if(!islower(s[0]) && s[0] != '_'){
        for(int i =1; i< s.length(); i++){
            if(!isalpha(s[i])){
                return "no";
            }
        }
    }

    return "yes";
}

/* Token           Number  Identifier      Reserved Word
K-mart          no      no      no
23andMe         no      no      no
456             yes     no      no
Tax             no      yes     no
2018            yes     no      no
While           no      yes     no
switch          no      yes     yes
do_it           no      yes     no
_Fall_20        no      yes     no
_Jan            no      yes     no
19              yes     no      no
Press any key to continue . . .  */