#include "types.h"
#include "calctree/mainlib.h"
#include <charconv>
#include <cwchar>
using namespace std;

static string item, val;
void unk(string s) {
  // cerr<<s<<"  unknow select"<<endl;
  cerr << s << endl;
  exit(1);
}
bool gettok(istream &ist) { // read conf
  regex conf("([a-z0-9]+):(.*)");
  smatch sm;
  string s;
  if (getline(ist, s)) {
    if (regex_match(s.cbegin(), s.cend(), sm, conf)) {
      // clog << "val: " << sm[1] << " = " << sm[2] << endl;
      item = sm[1], val = sm[2];
      if (item == "end") {
        return false;
      }
    } else {
      unk("not matched conf");
    }
    return true;
  } else {
    return false;
  }
}
bool cond::check(int x) {
  Clogbase Clog(l) Clog("~") Clog(r) Clogs Clog(x)
      Clogs Clogln(l <= x && x <= r);
  return l <= x && x <= r;
}
void init(types x) {
  for (int i = 0; i < 256; ++i) {
    x.vals[i].l = x.vals[i].r = x.calcvals[i] = x.is_def[i] = 0;
    x.calcval[i] = NULL;
  }
}
types::types() {
  // for (int i = 0; i < 256; ++i) {
  //   vals[i].l = vals[i].r = 0;
  //   calcval[i] = NULL;
  // }
  for (int i = 0; i <= 255; ++i) {
    this->is_def[i] = 0;
  }
  init(*this);
};
types::~types() {
  // clog<<"~types"<<endl;
}
bool types::check() {
  for (int i = 0; i < 256; ++i) {
    if (vals[i].l == 0 && vals[i].r == 0) {
      continue;
    }
    if (calcval[i]) {
      calcvals[i] = calcval[i]->getv(calcvals);
    }
    Clogbase Clog(i) Clog(":") Clogln(calcvals[i]);
    if (!vals[i].check(calcvals[i])) {
      return false;
    }
  }
  return true;
}
map<string, types> tps;
map<string, vector<size_t>> to_random;
void load(istream &ist) {
  // clog << "loading ..." << endl;
  bool in = false;
  shared_ptr<types> tmp;
  int to_def;

  while (gettok(ist)) {
    // clog<<item<<' '<<val<<endl;
    if (item == "type") {
      tmp = make_shared<types>();
      tmp->name = val;
      Clogbase Clog(val) Clogs Clogln(tmp->calcvals);
      // clog << "type: " << val << endl;
      in = true;
    } else if (isdigit(item[0]) && (item[1] == 'l' || item[1] == 'r')) {
      // clog << "item: " << item << " val: " << val << endl;
      if (item[1] == 'l') {
        tmp->vals[item[0] - '0'].l = stoi(val);
      } else if (item[1] == 'r') {
        tmp->vals[item[0] - '0'].r = stoi(val);
      }
      // cout << tmp.vals[item[0] - '0'].l << ' ' << tmp.vals[item[0] - '0'].r
      //      << endl;
    } else if (item == "def") {
      // clog << "val:" << val << endl;
      to_def = stoi(val);
      Clogbase Clog("todef ") Clogln(to_def);
    } else if (item == "equ") {
      tmp->is_def[to_def] = true;
      tmp->calcval[to_def] = build(build(val));
      Clogbase Clog("equ") Clogln(tmp->calcval[to_def]);
      // clog << "val:" << val << endl;
    } else if (item == "for") {
      tmp->format = val;
      // cout << "for:y" << val << endl;
    } else if (item == "endtype") {
      tps.insert({tmp->name, std::move(*tmp)});
    } else {
      unk("unknow: " + item + ":" + val);
    }
  }
  for (auto i : tps) {
    auto &sec = i.second;
    auto &fir = i.first;
    for (int i = 0; i < 256; ++i) {
      // cout<<sec.vals[i].l<<' '<<sec.vals[i].r<<endl;
      if (!(sec.vals[i].l == 0 && sec.vals[i].r == 0)) {
        // cout<<i<<','<<sec.is_def[i]<<endl;
        if (!sec.is_def[i]) {
          to_random[fir].push_back(i);
        }
      }
    }
  }
}

void show() {
  for (auto i : tps) {
    cout << "TYPE=> " << i.first << ":" << endl;

    auto &sec = i.second;
    auto &fir = i.first;
    for (int i = 0; i < 256; ++i) {
      if (!(sec.vals[i].l == 0 && sec.vals[i].r == 0)) {
        Clogbase Clog(i) Clog(" ->") Clog(sec.vals[i].l) Clog("~")
            Clogln(sec.vals[i].r);
        Clogbase Clog(sec.is_def[i]) Clog(' ') Clogln(sec.calcval[i].get());
        cout << i;
        if (sec.is_def[i]) {
          Clogbase Clogln("is_def");
          cout << " = {" << endl;
          sec.calcval[i].get()->show();
          cout << "}";
        }
        cout << endl;
      }
    }
    /*
        cout << "to rand:" << endl;
        for (auto i : to_random[fir]) {
          cout << i << ' ';
        }
        cout << endl;*/
  }
}
