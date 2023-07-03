#include "gen.h"
// #define HASLIB
// #undef HASLIB
#ifdef HASLIB
#include "genpdf.h"
#endif
#include "types.h"
#include <cstdlib>
#include <exception>
#include <fstream>
#include <functional>
#include <random>
#include <stdexcept>
#include <string>
// #if __has_include(<hpdf.h>)
// #include <hpdf.h>
// #define libharu 1
// #else
// #define libharu 0
// #endif
// #if libharu == 1
// #include <hpdf.h>
// #endif
using namespace std;
vector<string> selected;
vector<reference_wrapper<types>> selects;
int main() {
  load();
  // clog<<"====show===="<<endl;
  show();
  {
    string cmd = "";
    while (cmd != "q" && cin >> cmd) {
      cout << cmd << endl;
      if (tps.find(cmd) != tps.end()) {
        selected.push_back(cmd);
      } else {
        cout << "not find" << cmd << endl;
      }
    }
    // cout << "select: ";
    for (auto i : selected) {
      cout << i << ";";
      selects.push_back(tps[i]);
    }
    if (selected.size() == 0) {
      cout << "selected nothing" << endl;
    }
  }
  // for(int i=1;i<=25;++i){
  //   for(int j=1;j<=4;++j){

  //   }
  // }
  cout << endl
       << "selected " << selected.size() << " type(s)" << endl
       << "============" << endl;
  auto p = gen(100, selects);
#ifndef HASLIB
  cout << "writing to 1.txt..." << endl;
  int id = 0;
  ofstream fout("1.txt");
  for (auto i : p) {
    ++id;
    // cout<<i<<',';
    fout << i << "\t\t";
    if (id % 4 == 0) {
      fout << endl;
    }
  }
#else
  cout << "ok" << endl;
  genpdf(p);
#endif
}
// void handler(HPDF_STATUS error_no, HPDF_STATUS detail_no, void *user_data) {
//   char str[512] = {0};
//   sprintf(str, "ERROR: error_no=%04X, detail_no=%d\n", (unsigned
//   int)error_no,
//           (int)detail_no);
//   throw runtime_error(str);
// }
// void genpdf(const vector<string> &p) {
//   HPDF_Doc pdf;
//   try {
//     pdf = HPDF_New(handler, NULL);
//   } catch (const runtime_error &e) {
//     throw;
//   }
//   if (!pdf) {
//     HPDF_Free(pdf);
//     throw runtime_error("can't create pdfdoc obj");
//   }
//   HPDF_SetCompressionMode(pdf, HPDF_COMP_ALL);
//   HPDF_Font font = HPDF_GetFont(pdf, "Helvetica", NULL);
//   HPDF_SaveToFile(pdf, "1.pdf");
//   HPDF_Page page = HPDF_AddPage(pdf);
//   HPDF_Page_SetLineWidth(page, 1);
//   HPDF_Page_SetSize(page, HPDF_PAGE_SIZE_A4, HPDF_PAGE_LANDSCAPE);
//   HPDF_Page_Rectangle(page, 50, 50, HPDF_Page_GetWidth(page) - 30,
//                       HPDF_Page_GetHeight(page) - 30);
//   HPDF_Page_SetFontAndSize(page, font, 24);
//   HPDF_Page_BeginText(page);
//   HPDF_Page_TextOut(page, 30, 30, "hello");
//   HPDF_Page_EndText(page);
//   HPDF_Free(pdf);
// }
// #endif
