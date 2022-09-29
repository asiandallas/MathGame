/***********************************************************                                                                                                                           
Kyrstn Hall                                                                                                                                                                            
CS211                                                                                                                                                                                  
10/06/2021                                                                                                                                                                             
Lab: queue.cpp                                                                                                                                                                          
                                                                                                                                                                                       
This program utilizes different functions used by a queue           
***********************************************************/
#include "queue.h"
#include "array.h"
#include <cstdlib>
using namespace std;

// constructor                                                                                                                                                                     
Queue::Queue()
{
  count = 0;
  rear = -1;
  front = 0;
}

// returns true if queue is empty, false if not                                                                                                                                        
bool Queue::isEmpty() const
{
  return (count == 0) ? true : false;
}

// returns true if queue is full, false if not                                                                                                                                         
bool Queue::isFull() const
{
  return (count==QUEUE_SIZE) ? true : false;
}

// if full, calls an emergency exit routine
// if not full, changes rear to the next slot and enters an element at rear
void Queue::add(el_t e)
{
  if(isFull())
    {
      queueError("Stack overflow");
    }
  else
    {
      rear = (rear+1) % QUEUE_SIZE; // ex. rear is at end, needs to wrap
      el[rear] = e;
      count++;
    }
}

// if empty, calls an emergency exit routine
// if not empty, remove(return) the front element and change front to the next slot
el_t Queue::remove()
{
  if(isEmpty())
    {
      queueError("stack underflow");
    }
  else
    {
      int front_before = front;
      
      // new front
      front = (front+1) % QUEUE_SIZE;
      count--;

      return el[front_before];                                                                                                  
    }
}

// if empty, calls an emergency exit routine
// if not empty, return the front element (but does not remove it)
el_t Queue::getFront() const
{
  if(isEmpty())
    {
      queueError("stack underflow");
    }
  else
    {
      return el[front];
    }
}

// if empty, calls an emergency exit routine
// if queue has just 1 element, does nothing
// if queue has more than 1 element, moves the front one to the rear
void Queue::goToBack()
{
  if(isEmpty())
    {
      queueError("stack underflow");
    }
  else if(count>1)
    {
      el_t front = getFront(); // stores current front
      remove();
      add(front);
    }
}

// Show an expr struct at once (e.g. 5 + 8) in queue.cpp before displayAll().
// This operator overloading function will be called from displayAll()
ostream& operator<<(ostream& o, const expr& e)
{
  o << e.oprd1 << " " << e.oprt << " " << e.oprd2;
  return o;
}

// display everything in the queue from front to rear
void Queue::displayAll() const
{
  if(isEmpty())
    {
      cout << "[empty]"; //empty
    }
  else
    {
      // not empty                                                                                                             
      if(front<=rear)
	{
	  for(int i=front; i<=rear; i++)
	    {
	      cout << "[" << el[i] << "]" << " ";
	    }
	}
      else// front>rear                                                                                                             
	{
	  int end = QUEUE_SIZE-1;
	  for(int i=front; i<=end; i++)
	    {
	      cout << "[" << el[i] << "]" << " ";
	      if(i==end)
		{
		  for(int x=0; x<=rear; x++)
		    {
		      cout << "[" << el[x] << "]" << " ";
		    }
		}
	    }
	}
    }
  cout << "\n" <<  endl;
}

// returns the current size
int Queue::getSize() const
{
  return count;
}

void Queue::queueError(string errorMsg) const
{
  cout << errorMsg << endl;
  exit(1);
}
