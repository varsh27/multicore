#ifndef TEST_H
#define TEST_H

#include<string>
using namespace std;

class Test {
private:
  string path;
public:
  void Array(int op);
  void ForwardList(int op);
  void Dequeue(int op);
  void List(int op);
  void Stack(int op);
};

#endif
