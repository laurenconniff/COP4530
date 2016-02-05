// Lauren Conniff
// COP4530
// Project 3

#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <list>

using namespace std;
namespace cop4530{

template <typename T, typename myDS = list<T> >
class Stack
{	
	public:
		Stack(); 							// zero-argument constructor.   
		~Stack (); 							// destructor.  
		Stack (const Stack<T, myDS>&);		// copy constructor.   
		Stack(Stack<T, myDS> &&); 			// move constructor.
		Stack<T, myDS>& operator= (const Stack <T, myDS>&); // copy assignment operator=.
		Stack<T, myDS> & operator=(Stack<T, myDS> &&); 		// move assignment operator=
		
		bool empty() const; 		// returns true if the Stack contains no elements, and false otherwise.  
		void clear(); 				// delete all elements from the stack.
		void push(const T& x); 		// adds  x  to the Stack.   copy version.
		void push(T && x); 			// adds x to the Stack. move version.
		void pop(); 				// removes and discards the most recently added element of the Stack.  
		T& top();					// mutator that returns a reference to the most recently added element.
		const T& top() const;		// accessor that returns the most recently added element of the Stack.  
		int size() const; 			// returns the number of elements stored in the Stack.
		void print(std::ostream& os, char ofc = ' ') const;

	private:
		myDS object;
};
	template <typename T, typename myDS >
	ostream& operator<< (ostream& os, const Stack<T, myDS>& a); // prints the Stack<T> a in the specified ostream    
	
	template <typename T, typename myDS >
	bool operator== (const Stack<T, myDS>&, const Stack <T, myDS>&); 	 // returns true if the two compared Stacks have the same elements
	
	template <typename T, typename myDS >
	bool operator!= (const Stack<T, myDS>&, const Stack <T, myDS>&); 	 // opposite of operator==().
	
	template <typename T, typename myDS >
	bool operator< (const Stack<T, myDS>& a, const Stack <T, myDS>& b); 	 // returns true if every element in Stack a is smaller than corresponding elements of Stack b
	
	#include "stack.hpp"
} //end of namespace

#endif
