#include<iostream>
#include<memory>
using namespace std;
auto create(){
  return make_unique<int>(1125);
}
int main(){
  cout<<*create();
  return 0;
}
