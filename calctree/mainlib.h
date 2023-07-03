#pragma once
#include <assert.h>
#include <iostream>
#include <memory>
#include <regex>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <variant>
#include <vector>
using std::cout;
using std::endl;
using std::get;
using std::move;
using std::regex;
using std::shared_ptr;
using std::stack;
using std::string;
using std::to_string;
using std::variant;
using std::vector;
// using std::clog;
// #define Debug
#ifdef Debug
#define Clog(x) std::clog << (x);
#define Clogs std::clog << ' ';
#define Clogln(x) std::clog << (x) << endl
#define Clogbase std::clog << __FILE__ << ':' << __LINE__ << "-> ";
#else
#define Clog(x)
#define Clogs
#define Clogln(x)
#define Clogbase
#endif
using valT = int;
// #include<compare>

struct calctree {
  virtual valT getv(valT (&)[256]) = 0;
  // virtual string getstr() = 0;
  virtual ~calctree() = 0;
  virtual void show() = 0;
  char op;
};

struct calcval : calctree {
  calcval();
  calcval(size_t v) : v(v){};
  virtual valT getv(valT (&)[256]) override;
  // virtual string getstr() override;
  virtual ~calcval();
  virtual void show() override;
  size_t v;
};

// struct calcneg : calctree {
//   calcneg();
//   calcneg(calctree *v) : v(v){};
//   virtual valT getv() override;
//   virtual string getstr() override;
//   virtual ~calcneg();
//   virtual void show() override;
//   calctree *v;
// };

struct calcbin : calctree {
  calcbin();
  calcbin(calctree *l, calctree *r, char op) : l(l), r(r), op(op){};
  virtual valT getv(valT (&)[256]) override;
  // virtual string getstr() override;
  virtual ~calcbin();
  virtual void show() override;
  shared_ptr<calctree> l, r;
  char op;
};

vector<variant<valT, char>> build(string &s);
shared_ptr<calctree> build(vector<variant<valT, char>> exp);

int level(char opt);

std::ostream &operator<<(std::ostream &, const variant<valT, char> &);
