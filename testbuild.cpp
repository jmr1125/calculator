#include "calctree/mainlib.h"
#include <iostream>
int main() {
  string expr;
  expr = "1 2 +";
  cout<<"hello";
  cout<<expr<<endl;
  valT vals[256];
  vals[1]=1;
  vals[2]=2;
  auto vec = build(expr);
  for (const variant<valT,char> i : vec) {
    std::cout << i <<' ';
  }
  cout<<endl;
  auto root = build(vec);
  root->show();
  cout<<"val:"<<root->getv(vals)<<endl;
  // cout<<"str:"<<root->getstr()<<endl;
}
