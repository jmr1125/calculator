#include<vector>
#include<stack>
#include<memory>
#include<utility>
#include<variant>
//#include<compare>

struct calctree{
  virtual int getv() = 0;
  virtual string getstr() = 0;
  virtual ~calctree();
};

struct calcval:calctree{
  calcval();
  calcval(int v):v(v){};
  virtual int getv()override;
  virtual string getstr()override;
  virtual ~calcval();
  double v;
};

struct calcneg:calctree{
  calcval();
  calcval(calctree* v):v(v){};
  virtual int getv()override;
  virtual string getstr()override;
  virtual ~calcneg();
  calctree *v;
};

struct calcbin:calctree{
  calcval();
  calcval(calctree* l,calctree* r,char op):l(l),r(r),op(op){};
  virtual int getv()override;
  virtual string getstr()override;
  virtual ~calcbin();
  calctree* l,*r;
  char op;
}

calctreeP build(vector<variant<int,char> >);

int level(char opt);
