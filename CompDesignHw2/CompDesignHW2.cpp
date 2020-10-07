//Group names: Lopez,Gabe and Noel
// Assignment: No.2
//   Due Date: September 16th
//	Purpose: This program reads an expression in postfix form, 
//			 evaluates the expression and displays its value

//using stack and iosteam libraries 
#include<iostream>
#include<list>
#include<string>
using namespace std;

/* function to evaluate a string and return if it contains eithera operation, space or digit */
bool isOp(string s);
bool isSpace(string s);
bool isDigit(string s);

int main() {

	//stack list
    list <string> s;
    list<int> i;

	//while statement connected to continue question at the end
	bool contin = true;
	while (contin) {
		
		//int values that will be used to store
		//data that is gonna be computed 
		int x, y;

		//input character and prompt user to enter info
		string input;
		cout << "Enter a postfix expression with $ at the end: ";
		
		//push only the inputed data into a string list
		while (cin>>input && input!="$" && !isSpace(input)) {
			//cout<<"input"<<endl;
            s.push_back(input);
		}

        //loops through the string list
        while(!s.empty()){

            //if the front string of the string list is a digit, push it into the int list
            if(isDigit(s.front())){
                //cout<<"digit"<<endl;
                i.push_front(stoi(s.front()));

            //if the string is not a digit and if it is a operation, 
            //perform that operation 
            }else if(isOp(s.front())){
                //cout<<"op"<<endl;
                //store and pop the first two integers from
                //the integer list
                x= i.front();
                i.pop_front();
                y= i.front();
                i.pop_front();

                //makeshift switch statement for pushing operation back into the 
                //integer stack
                if(s.front() == "+"){
                    i.push_front(x+y);
                }else if(s.front() == "-"){
                    i.push_front(y-x);
                }else  if(s.front() == "/"){
                    i.push_front(x/y);
                }else if(s.front() == "*"){
                    i.push_front(x*y);
                }

                /* if it is not a digit or a operation it will be assumed 
                to be a variable and the value of the variable will be asked
                for, and pushed into the integer list */
            }else{
                cout<<"Enter the value of "<<s.front()<<endl;
                int val;cin>>val;i.push_front(val);
            }
            //pop the front of string list to continue the loop
            s.pop_front();
        }

		//When escape key is entered, the calculated value will be displayed
		//and the stack poped off the last element
		cout << "\tValue: "<<i.front()<<endl;
		i.pop_front();

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

//return false if it is not a space and true if it is all a space
bool isSpace(string s){
    for(int i =0; i< s.length(); i++){
        if(!isspace(s[i])){return false;}
    }
    return true;
}

//returns false if the string is not a digit and true if it is all digits
bool isDigit(string s){
    for(int i =0; i< s.length(); i++){
        if(!isdigit(s[i])){return false;}
    }
    return true;
}

//returns true if string matches the 4 operation symbols
bool isOp(string s){
    if(s == "+" ||s == "-" ||s == "*" ||s == "/"){return true;}
    return false;
}

/* Enter a postfix expression with $ at the end: 20 num1 45 + tom - * $
Enter the value of num1
10 
Enter the value of tom
5
        Value: 1000
CONTINUE(y/n) y
Enter a postfix expression with $ at the end: myscore yourscore 45 + 100 + * $
Enter the value of myscore
3
Enter the value of yourscore
5
        Value: 450
CONTINUE(y/n) n
Press any key to continue . . .  */