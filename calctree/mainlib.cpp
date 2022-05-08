#include<variant>
#include<vector>
#include<compare>
using std::variant;
using std::vector;

struct calctree{
  calctree();
  ~calctree();
  variant<int,char> val;
  calctree *l,*r;
};

calctree* build(vector<variant<int,char> >);

int level(char opt);
