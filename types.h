#include<string>
#include<map>
#pragma once
#include<regex>
#include<iostream>
#include<fstream>
#include"calctree/mainlib.h"
using std::map;
using std::regex;
using std::string;
using std::cerr;
using std::cin;
using std::move;
using std::istream;
//using std::clog;
void load(istream&);
void show();
void unk(string s);
struct cond{
  cond() : l(0), r(0){};
  cond(int l, int r) : l(l), r(r){};
  bool check(int x);
  int l, r;
};
struct types{
  types();
  ~types();
  bool check();
  cond vals[256];
  shared_ptr<calctree> calcval[256];
  valT calcvals[256];
  int is_def[256];
  string format;
  string name;
};

extern map<string, types> tps;
extern map<string, vector<size_t> >to_random;
// void cleanup();
