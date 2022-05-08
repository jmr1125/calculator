#include<variant>
#include<vector>
#include<stack>
//#include<compare>
using std::variant;
using std::vector;
using std::stack;
using std::get;

struct calctree{
  calctree();
  ~calctree();
  variant<int,char> val;
  calctree *l,*r;
};

calctree* build(vector<variant<int,char> >);

int level(char opt);
