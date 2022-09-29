#ifndef QUEUE_H
#define QUEUE_H

#include <string>
using namespace std;

enum op {ADD, SUB, MULT, DIVI};

struct expr
{
  //  ostream& operator<<(ostream& o, const expr& e);
int oprd1;
op oprt;
int oprd2;
};
ostream& operator<<(ostream& o, const expr& e);


typedef expr el_t;
const int QUEUE_SIZE = 10;

class Queue
{
 private:
  el_t el[QUEUE_SIZE];                                                                                               
  int count;
  int front;
  int rear;
  void queueError(string errorMsg) const;

 public:
  Queue();
  bool isEmpty() const;
  bool isFull() const;
  void add(el_t e);
  el_t remove();
  el_t getFront() const;
  void goToBack();
  void displayAll() const;
  int getSize() const;
};

#endif
