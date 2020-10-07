//Group names: Lopez,Gabe and Noel
// Assignment: No.1
//   Due Date: September 9th
//	Purpose: This program reads an expression in postfix form, 
//			 evaluates theexpression and displays its value

//using stack and iosteam libraries 
#include<iostream>
#include<stack>
using namespace std;


int main() {
	//constant values
	const int a = 5, b = 7, c = 2, d = 4;

	//stack list
	stack<int> s;

	//while statement connected to continue question at the end
	bool contin = true;
	while (contin) {
		
		//int values that will be used to store
		//data that is gonna be computed 
		int x, y;

		//input character and prompt user to enter info
		char input;
		cout << "Enter a postfix expression with $ at the end: ";
		
		//switch statement inside a while loop
		//that will break when the exit character is entered
		while (cin>>input) {
			if (input == '$') { break; }
			switch (input) {

			//if the switch reads a variable->push it
			// if a operation then perform it
			case 'a':
				s.push(a);
				break;
			case 'b':
				s.push(b);
				break;
			case 'c':
				s.push(c);
				break;
			case 'd':
				s.push(d);
				break;
			case '-':
				//get top variable
				x = s.top();
				//pop top variable
				s.pop();
				//get new top variable
				y = s.top();
				//pop top variable
				s.pop();
				//push result of operation back into the stack
				s.push(y - x);
				//break case
				break;
			case '+':
				x = s.top();
				s.pop();
				y = s.top();
				s.pop();
				s.push(y + x);
				break;
			case '*':
				x = s.top();
				s.pop();
				y = s.top();
				s.pop();
				s.push(y * x);
				break;
			case '/':
				x = s.top();
				s.pop();
				y = s.top();
				s.pop();
				s.push(y / x);
				break;
			default:
				cout << "Default";
			}
		}

		//When escape key is entered, the calculated value will be displayed
		//and the stack poped off the last element
		cout << "\tValue: "<<s.top()<<endl;
		s.pop();

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