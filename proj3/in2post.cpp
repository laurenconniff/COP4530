#include <iostream>
#include <cstdlib>
#include "stack.h"
#include <string>
#include <cstring>
#include <cctype>
#include <sstream>

using namespace std;
using namespace cop4530;

bool isOperator(string, int);
bool isOperand(string, int);
string getOperand(string, int &);
string getOperator(string, int &);
bool nextOperator(string, int);
int precedence(string);
int postfixEval();
int getInt(string);
int calculate(string, int, int);
void convertResult();
bool checkExp(string);

string currExp;
bool higherOp;
string currVar; 

Stack<string> pStack;
Stack<string> results;
Stack<int> postfix;
Stack<string> operators;
Stack<string> resStack;

int main() {

bool command = true;

do{

string expression;
cout << "Enter infix expression (\"exit\" to quit): ";
getline(cin, expression);
if (expression == "exit"){
	return 0;
}


int lvc = 0;
bool prevOperand = false;
bool prevOperator = false;
bool newOp = false;

if(isOperator(expression,lvc)){
	cout << "Error: Missing operands in the expression" << endl;
	return 1;
}
string temp;

while (lvc < expression.length()){
	currVar = expression[lvc];
	if (isOperand(expression, lvc))
	{
		temp = getOperand(expression, lvc);
		results.push(temp);
	}
	if (expression[lvc] == '(')
	{
		if(isOperator(expression,lvc+2)){
			cout << "Error: Missing operands in the expression" << endl;
			break;
		}
		temp = getOperator(expression, lvc);
		pStack.push(temp);
	}
	if (expression[lvc] == ')')
	{
		while ( !pStack.empty() && pStack.top() != "("){
			results.push(pStack.top());
			pStack.pop();
		}
		pStack.pop();
	}
	if (isOperator(expression, lvc)){
		while(!pStack.empty() && precedence(pStack.top()) >= precedence(currVar))
		{
			results.push(pStack.top());
			pStack.pop();
		}
		pStack.push(currVar);
	}
	lvc+=1;	
}
while(!pStack.empty())
{
	results.push(pStack.top());
	pStack.pop();
}

cout << endl << "Postfix expression: " << results << endl;

if (checkExp(expression))
{
	cout << "Postfix evaluation: " << results << endl;
	postfix.clear();
	resStack.clear();
	results.clear();
	pStack.clear();
	operators.clear();
} else {
	convertResult();
	int pf = postfixEval();
	postfix.clear();
	resStack.clear();
	results.clear();
	pStack.clear();
	operators.clear();
}

}while(command == true);


return 0;
}

bool isOperator(string expression, int lvc)
{
	if (expression[lvc] == '+' || expression[lvc] == '-' || expression[lvc] == '*' || expression[lvc] == '/'){
		return true;
	} 		return false;
}

bool isOperand(string expression, int lvc)
{
	if (isdigit(expression[lvc]) || isalpha(expression[lvc]) || expression[lvc] == '.' || expression[lvc] == '_'){
		return true;
	} 		
	return false;
}

string getOperand(string expression, int &lvc)
{
	string temp;
	while (isOperand(expression, lvc))
	{
		temp.push_back(expression[lvc]);
		lvc++;
	}
	return temp;
}

string getOperator(string expression, int &lvc)
{
	string temp;
	temp.push_back(expression[lvc]);
	return temp;
}

bool nextOperator(string expression, int lvc)
{
	if (expression[lvc] == '*' || expression[lvc] == '/' ){
		return true;
	}
	return false;
}

int precedence(string expression)
{
	string temp;
	temp = expression;
    if(temp == "*" || temp == "/")
    {
        return 2;
    }
    if(temp == "+" || temp == "-")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int postfixEval()
{
	string temp;
	int temp2;
	int val;
	int left;
	int right;
	int calc;
	while (!resStack.empty())
	{
		temp = resStack.top();
		val = getInt(temp);

		if (val != -1)
		{
			postfix.push(val);
			resStack.pop();
			//continue;
		}
		if (val == -1)
		{
			operators.push(temp);
			resStack.pop();
			right = postfix.top();
			postfix.pop();
			left = postfix.top();
			postfix.pop();
			calc = calculate(temp, left, right);
			postfix.push(calc);
 		}
	}
	if (postfix.size() > 1){
		postfix.pop();
	}
	cout << "Postfix evaluation: " << postfix << endl;
	return 1;
}

int getInt(string str)
{
	string temp;
	int Result;
	if (isOperator(str, 0)){
		return -1;
	}
	stringstream convert(str); 
	convert >> Result;
	return Result;
}

int calculate(string op, int left, int right)
{
	if (op == "+"){
		return left + right;
	} else if (op == "-"){
		return left - right;
	} else if (op == "*"){
		return left * right;
	} else if (op == "/"){
		return left / right;
	} else
		return -1;
}

void convertResult()
{
	string temp;
	while (!results.empty())
	{
		temp = results.top();
		resStack.push(temp);
		results.pop();
	}
}

bool checkExp(string expression)
{
	for (int i = 0; i < expression.length(); i++)
	{
		if (isalpha(expression[i]) || expression[i] == '_'){
			return true;
		}
	}

	return false;
}
