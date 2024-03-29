#include "gen.h"
#include "calctree/mainlib.h"
static int Random(int a, int b) {
  ++b;
  static bool init = false;
  if (!init) {
    srand(time(0));
    init = true;
  }
  return a + ((double)rand() / (RAND_MAX / (b - a)));
}
vector<string> gen(int count, vector<reference_wrapper<types>> selects) {
  const auto size = selects.size();
  vector<string> res;
  res.reserve(count);
  for (int i = 1; i <= count; ++i) {
    types &sel = selects[Random(0, size - 1)];
    Clogbase Clog(sel.name) Clogs Clogln(sel.calcvals);
    // cout << sel.name << endl;
    bool ok = false;
    while (!ok) {
      for (auto i : to_random[sel.name]) {
        Clogbase Clog(i) Clog(" -- ") Clog(sel.vals[i].l) Clog(',')
            Clogln(sel.vals[i].r);
        sel.calcvals[i] = Random(sel.vals[i].l, sel.vals[i].r);
        Clogbase Clog(i) Clog(" <- ") Clog(&sel.calcvals[i])
            Clogs Clogln(sel.calcvals[i]);
        // cout<<i<<' '<<sel.calcvals[i]<<endl;
      }
      Clogbase Clogln("check-------");
      ok = sel.check();
    }
    string form = sel.format;
    // cout<<"form:"<<form<<endl;
    for (int i = 0; i < 256; ++i) {
      string ii = '$' + to_string(i);
      auto len = ii.size();
      size_t t = form.find(ii);
      while (t != -1) {
        form.replace(t, len, to_string(sel.calcvals[i]));
        t = form.find(ii, t);
      }
    }
    Clogbase Clogs Clog("res======= "); Clogln(form);
    res.push_back(form);
  }
  // clog << "===clean===" << endl;
  // cleanup();
  return res;
}
