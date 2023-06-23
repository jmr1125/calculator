#include "mainlib.h"
#include <cctype>
#include <regex>

calctree::~calctree() {}

calcval::calcval() { v = -1; }
valT calcval::getv(valT (&vals)[256]) {
  Clogbase Clogln(v);
  return vals[v];
}
// string calcval::getstr() { return to_string(*v); }
void calcval::show() { cout << "val: " << v << endl; }
calcval::~calcval() {}

// calcneg::calcneg() { v = NULL; }
// valT calcneg::getv() { return -v->getv(); }
// string calcneg::getstr() { return "-" + v->getstr(); }
// void calcneg::show() { cout << "neg: " << v << endl; }
// calcneg::~calcneg() { delete v; }

calcbin::calcbin() { l = r = NULL; }
valT calcbin::getv(valT (&vals)[256]) {
  Clogbase Clogln(op);
  auto a = l->getv(vals);
  auto b = r->getv(vals);
  Clogbase Clog("a,b = ") Clog(a) Clog(" , ") Clogln(b);
  if (op == '+') {
    return a + b;
  }
  if (op == '-') {
    return b - a;
  }
  if (op == '*') {
    return a * b;
  }
  if (op == '/') {
    return b / a;
  }
  return 0;
}
void calcbin::show() {
  Clogbase Clogln("zzz  d  aaa");
  Clogbase cout << "op: " << this->op << endl;
  Clogbase cout << "left:" << endl;
  l->show();
  Clogbase cout << "right:" << endl;
  r->show();
  Clogbase cout << "end" << endl;
}
// string calcbin::getstr() {
//   string ans = "";
//   if (level(l->op) < level(this->op)) {
//     ans += "(";
//   }
//   ans += l->getstr();
//   if (level(l->op) < level(this->op)) {
//     ans += ")";
//   }
//   ans += op;
//   if (level(r->op) < level(this->op)) {
//     ans += "(";
//   }
//   ans += r->getstr();
//   if (level(r->op) < level(this->op)) {
//     ans += ")";
//   }
//   return ans;
// }
calcbin::~calcbin() {
  // if (l) {
  //   delete l;
  // }
  // if (r) {
  //   delete r;
  // }
}

shared_ptr<calctree> build(vector<variant<valT, char>> exp) {
  stack<shared_ptr<calctree>> num;
  for (auto i : exp) {
    if (i.index() == 0) {
      shared_ptr<calcval> tmp(new calcval);
      Clogbase Clog("val: ") Clogln(get<valT>(i));
      tmp->v = get<valT>(i);
      num.push(tmp);
    } else {
      shared_ptr<calcbin> tmp(new calcbin);
      tmp->l = num.top();
      num.pop();
      tmp->r = num.top();
      num.pop();
      tmp->op = get<char>(i);
      num.push(tmp);
    }
  }
  Clogbase Clogln("+++++++++++++++++++++");
#ifdef Debug
  num.top()->show();
#endif
  Clogbase Clogln("++++++++++++++++");
  return move(num.top());
}

static regex tok(
    R"(((?:[0-9]+)|(?:[-\+\*/])))"); // https://gcc.gnu.org/bugzilla/show_bug.cgi?id=77469
// static regex tok(R"(([0-9]+).*)");
static valT tovalT(string s) {
  std::stringstream ss;
  ss << s;
  valT v;
  ss >> v;
  return v;
};
vector<variant<valT, char>> build(string &s) {
  Clogbase Clog("building ") Clogln(s);
  vector<variant<valT, char>> res;
  std::regex_iterator<string::iterator> endit;
  for (std::regex_iterator<string::iterator> it(s.begin(), s.end(), tok);
       it != endit; ++it) {
    string s = it->str();
    // cout << "tok: " << s << endl;
    if (isdigit(s[0])) {
      // cout << "is 0-9" << endl;
      res.push_back(tovalT(s));
    } else {
      // cout << " is +-*/" << endl;
      assert(s.size() == 1);
      res.push_back(s[0]);
    }
  }
  Clogbase Clogln("display the vec");
  for (auto i : res) {
    if (i.index() == 0) {
      Clogbase Clogln(get<valT>(i));
    } else {
      Clogbase Clogln(get<char>(i));
    }
  }
  return res;
}
int level(char opt) {
  if (opt == '(')
    return 0;
  if (opt == '+')
    return 1;
  if (opt == '-')
    return 1;
  if (opt == '*')
    return 2;
  if (opt == '/')
    return 2;
  if (opt == ')')
    return 4;
  throw 0x7f;
}

std::ostream &operator<<(std::ostream &ost, const variant<valT, char> &x) {
  if (x.index() == 0) {
    cout << get<valT>(x);
  } else {
    cout << get<char>(x);
  }
  return ost;
}
