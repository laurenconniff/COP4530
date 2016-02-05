// Lauren Conniff
// COP4530 Proect 3
// Stack Implementation

using namespace std;

// zero-argument constructor
template <typename T, typename myDS >
Stack<T, myDS>::Stack()
{} 	

// destructor
template <typename T, typename myDS >
Stack<T, myDS>::~Stack()
{} 

// copy constructor
template <typename T, typename myDS >
Stack<T, myDS>::Stack (const Stack<T, myDS> &rhs)
{
	object = rhs.object;
}

// move constructor	 
template <typename T, typename myDS >
Stack<T, myDS>::Stack(Stack<T, myDS> &&rhs)
{
	object = move(rhs.object);
}	

// copy assignment operator=		
template <typename T, typename myDS >
Stack<T, myDS> & Stack<T, myDS>::operator= (const Stack <T, myDS> & rhs)
{
	object = rhs.object;
	return *this;
} 

// move assignment operator=
template <typename T, typename myDS >
Stack<T, myDS> & Stack<T, myDS>::operator=(Stack<T, myDS> && rhs)
{
	object = move(rhs.object);
	return *this;

	cout << "move assignment operator is being used" << endl;
} 	

// returns true if the Stack contains no elements, and false otherwise.	
template <typename T, typename myDS >
bool Stack <T, myDS>::empty() const
{
	if (object.empty() == true){
		return true;
	}else{
		return false;
	}
}
 		
// delete all elements from the stack. 		  
template <typename T, typename myDS >
void Stack<T, myDS>::clear()
{
	object.clear();
} 

// adds x to the Stack. Copy version				
template <typename T, typename myDS >
void Stack<T, myDS>::push(const T& x)
{
	object.push_back(x);
}

// adds x to the Stack. Move version		
template <typename T, typename myDS >
void Stack<T, myDS>::push(T && x)
{
	object.push_back(move(x));
}

// removes and discards the most recently added element of the Stack 
template <typename T, typename myDS >
void Stack<T, myDS>::pop()
{
	object.pop_back();
}

// mutator that returns a reference to the most recently added element 				
template <typename T, typename myDS >
T& Stack<T, myDS>::top()
{
	return object.back();
}	

// accessor that returns the most recently added element of the Stack.  				
template <typename T, typename myDS >
const T& Stack<T, myDS>::top() const
{
	return object.back();
}	

// returns the number of elements stored in the Stack	
template <typename T, typename myDS >
int Stack<T, myDS>::size() const
{
	return object.size();
} 	

//print elements of Stack to ostream os		
template <typename T, typename myDS >
void Stack<T, myDS>::print(ostream& os, char ofc) const
{
	for (auto lvc = object.begin() ; lvc != object.end() ; ++lvc)
	{
		os << *lvc << ofc;
	}
}

// prints the Stack<T> a in the specified ostream  
template <typename T, typename myDS >
ostream& operator<< (ostream& os, const Stack<T, myDS>& a)
{
	a.print(os);
	return os;
}   

// returns true if the two compared Stacks have the same elements
template <typename T, typename myDS >
bool operator== (const Stack<T, myDS> &lhs, const Stack <T, myDS> &rhs)
{
	Stack<T, myDS> ls = lhs;
    Stack<T, myDS> rs = rhs;
    if (lhs.size() != rhs.size()){
            return false;
    }
    while (ls.empty() != true)
    {
	    if (ls.top() != rs.top()){
	    	return false;
	    }else{
	    	ls.pop();
	    	rs.pop();
	    }
    }
        return true;
}	

// opposite of operator==()
template <typename T, typename myDS >
bool operator!= (const Stack<T, myDS>&lhs, const Stack <T, myDS>&rhs)
{
	if (lhs == rhs){
		return false;
	}else{
		return true;
	}
}	 

// returns true if every element in Stack a is smaller than corresponding elements of Stack 
template <typename T, typename myDS >
bool operator< (const Stack<T, myDS>& a, const Stack <T, myDS>& b)	 
{
	Stack<T, myDS> ls = a;
    Stack<T, myDS> rs = b;

	while (!ls.empty())
	{
		if (ls.top() < rs.top()){
			ls.pop();
	        rs.pop();
		}else{
			return false;
		}

	}
	return true;
}


