#include<variant>

struct calctree{
  calctree();
  variant<int,char> val;
  calctree *l,*r;
};

calctree* build(vector<variant<int,char> >);
