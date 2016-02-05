
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;
//init() function
template <typename T>
void List<T>::init()
{
	theSize = 0;
	head = new Node;
	tail = new Node;
	head->next = tail;
	tail->prev = head;
}
//List constructor
template <typename T>
List<T>::List()
{
   init();
}
//List Destructor
template <typename T>
List<T>::~List()
{
	clear();
	delete head;
	delete tail;
}
//Copy Constructor
template <typename T>
List<T>::List(const List &rhs)
{
	init( );
    for( auto & x : rhs )
       push_back( x );

}
//Move Constructor
template <typename T>
List<T>::List(List && rhs)
 : theSize{ rhs.theSize }, head{ rhs.head }, tail{ rhs.tail }
    {
        rhs.theSize = 0;
        rhs.head = nullptr;
        rhs.tail = nullptr;
    }
// num elements with value of val
template <typename T>
List<T>::List(int num, const T& val)
{
	init();
	for(int i=0; i<num; i++){
		push_front(val);
	}
	
}
// constructs with elements [start, end)
template <typename T>
List<T>::List(const_iterator start, const_iterator end)
{
	init();
	for(auto i=start; i != end; ++i){
		push_back(*i);
	}
}
// copy assignment operator
template <typename T>
const typename List<T>::List& List<T>::operator=(const List &rhs)
{
	 List copy = rhs;
     swap( *this, copy );
     return *this;
}
// move assignment operator
template <typename T>
typename List<T>::List & List<T>::operator=(List && rhs)
{
	swap( theSize, rhs.theSize );
    swap( head, rhs.head );
    swap( tail, rhs.tail );
        
    	return *this;
}
// number of elements
template <typename T>
int List<T>::size() const
{
	return theSize;
}
// check if list is empty
template <typename T>
bool List<T>::empty() const
{
	if (theSize == 0){
		return true;
	}return false;
}
// delete all elements
template <typename T>
void List<T>::clear() 
{
	while( !empty( ) )
        pop_front( );
}
// reverse the order of the elements
template <typename T>
void List<T>::reverse()
{
	Node * tleft = head;
    Node * tright = tail;
    Node * cleft = head;
    Node * cright = tail;
    
    tleft = tleft->next;
    tright = tright->prev;
    
    for (int i=0; i< size()/2; ++i)
    {
        cleft->next = tright;		
        tright = tright->prev;
        cleft->next->prev = cleft;

        cright->prev = tleft;
        tleft = tleft->next;
        cright->prev->next =cright;

        cleft = cleft->next;
        cright = cright->prev;
    }
    if (tleft == tright) 
    {
        cright->prev = tleft;
        cleft->next = tleft;
                
        tleft->prev = cleft;
        tleft->next = cright;
    }
    else
    {            
        cright->prev = cleft;
        cleft->next = cright;
    }
}
// reference to the first element
template <typename T>
T& List<T>::front()
{
	return head->next->data;
}
// reference to the first element const
template <typename T>
const T& List<T>::front() const
{
	return head->next->data;
}
// reference to the last element
template <typename T>
T& List<T>::back() 
{
	return tail->prev->data;
}
// reference to the last element const
template <typename T>
const T& List<T>::back() const
{
	return tail->prev->data;
}
// insert to the beginning
template <typename T>
void List<T>::push_front(const T & val) 
{
	insert( begin( ), val );
}
// move version of insert
template <typename T>
void List<T>::push_front(T && val) 
{
	insert( begin( ), val );
}
// insert to the end
template <typename T>
void List<T>::push_back(const T & val)
{
	insert( end( ), val );
}
//move version of insert
template <typename T>
void List<T>::push_back(T && val)
{
	insert( end( ), val );
}
// delete first element
template <typename T>
void List<T>::pop_front()
{
	erase(begin());
}
// delete last element
template <typename T>
void List<T>::pop_back()
{
	erase(--end());
} 
// remove all elements with value = val
template <typename T>
void List<T>::remove(const T &val)
{
	for (iterator i=begin(); i != end(); i++)
		{
			if (*i == val)
			erase(i);
		}

}
// print out all elements. ofc is deliminitor
template <typename T>
void List<T>::print(ostream& os, char ofc) const
{
	for (Node* n = head->next; n != tail; n = n->next)
	{
		cout << n->data;
		if (n->next != tail)
			cout << ofc;
	}
}
//const_iterator constructor
template <typename T>
List<T>::const_iterator::const_iterator()  : current(NULL){}
// operator*() to return element
template <typename T>
const T& List<T>::const_iterator::operator*() const
{
	return retrieve();
}
// increment prefix
template <typename T>
typename List<T>::const_iterator& List<T>::const_iterator::operator++()
{
	current = current->next;
    return *this;
}
//increment postfix
template <typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator++(int)
{
	const_iterator old = *this;
	++( *this );
	return old;
}
//decrement prefix
template <typename T>
typename List<T>::const_iterator& List<T>::const_iterator::operator--()
{
	current = current->prev;
    return *this;
}
//decrement postfix
template <typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator--(int)
{
	const_iterator old = *this;
	--( *this );
	return old;
}
// equal comparison operator
template <typename T>
bool List<T>::const_iterator::operator==(const const_iterator &rhs) const
{
	return current == rhs.current;	
}
// not equal comparison operator
template <typename T>
bool List<T>::const_iterator::operator!=(const const_iterator &rhs) const
{
	return !( *this == rhs );
}
// retrieve the element refers to
template <typename T>
T& List<T>::const_iterator::retrieve() const
{
	return current->data; 
}
// protected constructor
template <typename T>
List<T>::const_iterator::const_iterator(Node *p): current(p){}
// default zero-parameter contructor
template <typename T>
List<T>::iterator::iterator(){}
// operator*() to return element
template <typename T>
T& List<T>::iterator::operator*() 
{ 
	return const_iterator::retrieve( ); 
}
// operator*() to return element const
template <typename T>
const T& List<T>::iterator::operator*() const
{
	return const_iterator::operator*( ); 
}
//increment prefix
template <typename T>
typename List<T>::iterator& List<T>::iterator::operator++()
{
	this->current = this->current->next;
    return *this;
}
//increment postfix
template <typename T>
typename List<T>::iterator List<T>::iterator::operator++(int)
{
	iterator old = *this;
	++( *this );
	return old;
}
//decrement prefix
template <typename T>
typename List<T>::iterator& List<T>::iterator::operator--()
{
	this->current = this->current->prev;
    return *this;
}
//decrement postfix
template <typename T>
typename List<T>::iterator List<T>::iterator::operator--(int)
{
	iterator old = *this;
	--( *this );
	return old;
}
// pointer to node in List
template <typename T>
List<T>::iterator::iterator(Node *p) : const_iterator(p) {}
// iterator to first element
template <typename T>
typename List<T>::iterator List<T>::begin()
{
	return iterator( head->next ); 
}
// const iterator to first element
template <typename T>
typename List<T>::const_iterator List<T>::begin() const
{
	return const_iterator( head->next );
}
template <typename T>
typename List<T>::iterator List<T>::end()
{
	return iterator(tail);
}
template <typename T>
typename List<T>::const_iterator List<T>::end() const
{
	return const_iterator(tail);
}
// insert val ahead of itr
template <typename T>
typename List<T>::iterator List<T>::insert( iterator itr, const T & x )
{
	Node *temp = itr.current;
	theSize++;
	return iterator(temp->prev = temp->prev->next = new Node(x,temp->prev,temp));
}
// move version of insert
template <typename T>
typename List<T>::iterator List<T>::insert(iterator itr, T && val)
{
	 Node *temp = itr.current;
     ++theSize;
     return iterator(temp->prev = temp->prev->next = new Node( move(val), temp->prev, temp) );
} 
// erase one element
template <typename T>
typename List<T>::iterator List<T>::erase(iterator itr)
{
	Node *p = itr.current;
    iterator retVal( p->next );
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    --theSize;
    return retVal;
}
// erase [start, end)
template <typename T>
typename List<T>::iterator List<T>::erase(iterator start, iterator end)
{
 for(iterator itr = start; itr != end;)
        itr = erase(itr);

    return end;
}
//== operator overload
template <typename T>
bool operator==(const List<T> & lhs, const List<T> &rhs)
{
	auto ls = lhs.begin();
	auto rs = rhs.begin();
	if (lhs.size() != rhs.size()){
		return false;
	}
	while (ls != lhs.end() && rs != rhs.end())
	{
		if (*ls != *rs)
		return false;
		ls++; 
		rs++;
	}
	return true;
}
//!= operator overload
template <typename T>
bool operator!=(const List<T> & lhs, const List<T> &rhs)
{
	
	typename List<T>::const_iterator ls = lhs.begin();
	typename List<T>::const_iterator rs = rhs.begin();
	while (ls != lhs.end() && rs != rhs.end())
	{
		if (*ls != *rs)
		return true;
		ls++; 
		rs++;
	}
	return false;
}
// overloading output operator
template <typename T>
ostream & operator<<(ostream &os, const List<T> &l)
{
	// os << l.print();
	l.print(os, ' ');
	return os;
}
