// Lauren Conniff
// COP 4530
// Project 4
#ifndef BET_H
#define BET_H
#include <iostream>
#include <string>
#include <sstream>  
#include <stack>
#include <utility>

using namespace std;

class BET
{
	public:		
		BET();										 // default zero-parameter constructor
		BET(const string postfix);					 // one-parameter constructor
		BET(const BET&);							 // copy constructor
		~BET();										 // destructor
		bool buildFromPostfix(const string postfix); // tree built based on the postfix expression 
		const BET & operator=(const BET &);			 // assignment operator
		void printInfixExpression();				 // print out the infix expression
		void printPostfixExpression();				 // print out the postfix expression
		size_t size();								 // return the number of nodes in the tree
		size_t leaf_nodes();						 // return the number of leaf nodes in the tree
		bool empty();								 // return true if the tree is empty

		struct BinaryNode{							 // nested Binary tree structure containing node info
			string data;
            BinaryNode *left;
            BinaryNode *right;


  	    BinaryNode(const string & d = string{}, BinaryNode *l = nullptr, BinaryNode *r = nullptr) 
	            : data{d}, left{l}, right{r} {}
            BinaryNode(string & d, BinaryNode *l = nullptr, BinaryNode *r = nullptr)
	            : data{d}, left{l}, right{r} {}

            BinaryNode(string && d, BinaryNode *l = nullptr, BinaryNode *r = nullptr)
	            : data{std::move(d)}, left{l}, right{r} {}
  		};

	private:
  		BinaryNode *begin;							 // root
		void printInfixExpression(BinaryNode *n);	 // print infix expression to stdout
		void makeEmpty(BinaryNode* &t);				 // deletes all nodes in subtree
		BinaryNode * clone(BinaryNode *t) const;	 // clone all nodes in subtree
		void printPostfixExpression(BinaryNode *t);  // print postfix expression to stdout
		size_t size(BinaryNode *t);					 // returns number of nodes in subtree
		size_t leaf_nodes(BinaryNode *t);			 // return number of leaf nodes in the subtree 

};

#include "bet.cpp"
#endif
