//Group names: Lopez,Gabe and Noel
// Assignment: No.3.2
//   Due Date: September 23rd
//	Purpose: This program accepts a string and can check it against the grammar system 
//             that was specificly chosen

#include<iostream>
#include<string>
using namespace std; 

struct State{struct State *a=NULL,*b=NULL,*c=NULL;bool final = false;}S,B,C,D;

int main(){
    bool contin = true;
	while (contin) {
        //Setting up the system based on the grammar provided
        S.a=&S;
        S.b=&B;
        S.c=&C;

        B.a=&C;
        B.b=&B;
        B.c=&D;
        B.final=true;

        C.a=&S;
        C.b=&D;
        C.c=&D;
        C.final=true;

        D.a=&B;
        D.b=&D;
        D.c=&C;

        cout<<"Input a string to check if it works with programed grammar: ";
        string s;
        State *test = new State;
        test = &S;
        cin>>s;
        for(int i =0; i<s.length();i++){
            switch(s[i]){
                case 'a':
                test=test->a;
                break;
                case 'b':
                test=test->b;
                break;
                case 'c':
                test=test->c;
                break;
                default:
                    cout<<"Default"<<endl;
            }
        }

        if(test->final){
            cout<<"Accepted"<<endl;
        }else{
            cout<<"Not Accepted"<<endl;
        }

        //The user is prompted is they want to continue
		cout << "CONTINUE(y/n) ";
		char ans;
		cin >> ans;
		if ('n' == tolower(ans)) {
			break;
		}
    }

    system("pause");
    return 0;
}

/* Input a string to check if it works with programed grammar: ccccbbb
Not Accepted
CONTINUE(y/n) y
Input a string to check if it works with programed grammar: ac
Accepted
PS C:\Users\Owner\Desktop\CompilerDesign\CompDesignHw3> ./a.exe
Input a string to check if it works with programed grammar: abbbcaaa
Not Accepted  
CONTINUE(y/n) y
Input a string to check if it works with programed grammar: ccccbbb
Not Accepted  
CONTINUE(y/n) y
Input a string to check if it works with programed grammar: aabbcbbb
Not Accepted  
CONTINUE(y/n) y
Input a string to check if it works with programed grammar: aaaabca
Accepted
CONTINUE(y/n) n
Press any key to continue . . .  */