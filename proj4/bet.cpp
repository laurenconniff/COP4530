// Lauren Conniff
// COP4530
// Project 4
#include <iostream>
#include <string>
#include <sstream>  
#include <stack>

bool isOperator(string expression);
bool isOperand(string expression);
int precedence(string expression);

 // default zero-parameter constructor
BET::BET()
{
	begin = new BinaryNode;
}
			
// one-parameter constructor									
BET::BET(const string postfix)
{
	begin = new BinaryNode;
	buildFromPostfix(postfix);
}			 

 // copy constructor		
BET::BET(const BET& x)
{
	begin = nullptr;
	begin = clone(x.begin);
}	

// destructor
BET::~BET()
{
	makeEmpty(begin);
}	

//tree built based on the postfix expression								 
bool BET::buildFromPostfix(const string postfix)
{
	if (postfix.empty()){
		cout << "Please enter a valid postfix expression" << endl;
		return false;
	}

	string temp;
	int counter = 0;
	stack<BinaryNode*> myStack;  
	stringstream s(postfix);

	while (s >> temp){
		if (isOperand(temp)){
			BinaryNode *myNode = new BinaryNode(temp);
			myStack.push(myNode);
		}else if(isOperator(temp)){
			BinaryNode *myNode = new BinaryNode(temp);
			myNode->left = myStack.top();
			myStack.pop();
			myNode->right = myStack.top();
			myStack.pop();
			myStack.push(myNode);
		}
	}

	begin = myStack.top();
	
	//handle errors for returning false
	if (myStack.empty()){
		cout << "Error: Stack is empty" << endl;
		return false;
	}
	myStack.pop();
	if (!myStack.empty()){
		cout << "Error: Please enter a valid postfix expression" << endl;
		makeEmpty(begin);
		return false;
	}

	return true;
}  

// assignment operator
const BET & BET::operator=(const BET & x)
{
	this->begin = clone(x.begin);
	return *this;
}	

//print out the infix expression	
void BET::printInfixExpression()
{
	if (empty())
	{
		cout << "Tree is empty" << endl;
	} else {
		printInfixExpression(begin);
		cout << endl;
	}
}	

// print out the postfix expression			
void BET::printPostfixExpression()
{
	if (empty())
	{
		cout << "Tree is empty" << endl;
	} else {
		printPostfixExpression(begin);
		cout << endl;
	}
}	

// return the number of nodes in the tree
size_t BET::size()
{
	return size(begin);
}	

// return the number of leaf nodes in the tree						 
size_t BET::leaf_nodes()
{
	return leaf_nodes(begin);
}	

// return true if the tree is empty					 
bool BET::empty()
{
	if(begin->left == nullptr && begin->right == nullptr){
		return true;
	} return false;
}								 

// print infix expression to stdout
void BET::printInfixExpression(BinaryNode *n)
{
	bool close = false;
 	if(n != nullptr)
 	{
 		if (n->left == nullptr && n->right == nullptr)
 		{
 			cout << " " << n->data << " " ;
 		}
 		else{
 			if(isOperator(n->data) && isOperator(n->right->data) &&
 			   (precedence(n->data) > precedence(n->right->data) ||
               precedence(n->data) == precedence(n->right->data)))
 			{
 				if(n->data == "*" || n->data == "/"){
 					cout << "(";
 					close = true;
 				}
 			}
            printInfixExpression(n->right);
            if (close){
            	cout << ")";
            }
            close = false;
            cout << " " << n->data << " ";

            if(isOperator(n->data) && isOperator(n->left->data) &&
 			   (precedence(n->data) > precedence(n->left->data) ||
               precedence(n->data) == precedence(n->left->data)))
 			{
 				cout << "(";
 				close = true;
 			}
 			printInfixExpression(n->left);
            if (close){
            	cout << ")";
            }
        }
    }
}
// deletes all nodes in subtree
void BET::makeEmpty(BinaryNode* &t)
{
	 if( t != nullptr )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = nullptr;
}	

// clone all nodes in subtree
BET::BinaryNode * BET::clone(BinaryNode *t) const
{
	 if(t == nullptr)
            return nullptr;
     else
            return new BinaryNode{ t->data, clone( t->left ), clone( t->right ) };
}	

// print postfix expression to stdout
void BET::printPostfixExpression(BinaryNode *t)
{
	if (size(t) == 0){
		return;
	}
	if (begin->left == nullptr && begin->right == nullptr){
		cout << begin->data << endl;
	}else{
		printPostfixExpression(t->right);
		printPostfixExpression(t->left);
		cout << t->data << " ";
	}
}  

// returns number of nodes in subtree
size_t BET::size(BinaryNode *t)
{
	if (t == nullptr){
		return 0;
	}else{
		return size(t->right) + size(t->left) + 1;
	}
}		

// return number of leaf nodes in the subtree 		 
size_t BET::leaf_nodes(BinaryNode *t)
{
 if (t == nullptr)
        return 0;
    else if (t->right == nullptr && t->left == nullptr)
        return 1;
    else if (t->right == nullptr)
        return leaf_nodes(t->left);
     else if (t->left == nullptr)
        return leaf_nodes(t->right);
    else
        return leaf_nodes(t->left) + leaf_nodes(t->right);
}			 


bool isOperator(string expression)
{
	if (expression[0] == '+' || expression[0] == '-' || expression[0] == '*' || expression[0] == '/'){
		return true;
	} 		return false;
}

bool isOperand(string expression)
{
	if (isdigit(expression[0]) || isalpha(expression[0]) || expression[0] == '.' || expression[0] == '_'){
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

