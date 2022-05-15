#include<variant>
#include<vector>
#include<stack>
#include<memory>
#include<utility>
//#include<compare>
using std::variant;
using std::vector;
using std::stack;
using std::get;
using std::unique_ptr;
using std::make_unique;
using std::unique;
using std::shared_ptr;
using std::swap;
using std::make_shared;
//using std::as_const;
using std::move;
template<typename _T>
const _T as_const(_T);

struct calctree;
using calctreeP = shared_ptr<calctree>;

struct calctree{
  calctree();
  calctree(const calctree&);
  calctree(const calctree&&);
  ~calctree();
  variant<int,char> val;
  //calctree *l,*r;
  calctreeP l,r;
};

calctreeP build(vector<variant<int,char> >);

int level(char opt);
