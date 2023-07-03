#include"genpdf.h"
#include "calctree/mainlib.h"
#include <memory>
struct pointstring{
  string getstr(){
    return (string)"BT /F1 "+to_string(size)+" Tf "+to_string(x)+" "+to_string(y)+" Td ("+s+") Tj ET\n";
  }
  string s;
  int x,y;
  int size;
};
static string getstring(vector<pointstring> v){
  string res;
  for(auto i : v){
    res+=i.getstr();
  }
  return res;
}
void genpdf(const vector<string> &p,string file) {
  QPDF pdf;
  pdf.emptyPDF();
  QPDFObjectHandle font = pdf.makeIndirectObject("<<"
                                                 " /Type /Font"
                                                 " /Subtype /Type1"
                                                 " /Name /F1"
                                                 " /BaseFont /Helvetica"
                                                 " /Encoding /WinAnsiEncoding"
                                                 ">>"_qpdf);
  QPDFObjectHandle procset =
      pdf.makeIndirectObject(QPDFObjectHandle::parse("[/PDF /Text]"));
  // QPDFObjectHandle contents =
  //     pdf.newStream((string) "BT /F1 24 Tf 10 612 Td (" + "hi" + ") Tj ET");
  QPDFObjectHandle contents;
  {
  vector<pointstring> ps;
  ps.resize(p.size());
  for(int i=0;i<p.size();++i){
    ps[i].x=72+130*(i%4);
    ps[i].y=720-27*(i/4);
    ps[i].s=p[i];
    ps[i].size=18;
  }
  contents=pdf.newStream(getstring(ps));
  }
  QPDFObjectHandle mediabox = QPDFObjectHandle::parse("[0 0 612 792]");
  QPDFObjectHandle rfont = QPDFObjectHandle::newDictionary();
  rfont.replaceKey("/F1", font);

  QPDFObjectHandle resources = QPDFObjectHandle::newDictionary();
  resources.replaceKey("/ProcSet", procset);
  resources.replaceKey("/Font", rfont);

  QPDFObjectHandle page =
      pdf.makeIndirectObject(QPDFObjectHandle::newDictionary());
  page.replaceKey("/Type", QPDFObjectHandle::newName("/Page"));
  page.replaceKey("/MediaBox", mediabox);
  page.replaceKey("/Contents", contents);
  page.replaceKey("/Resources", resources);

  QPDFPageDocumentHelper(pdf).addPage(page, true);

  QPDFWriter w(pdf, file.c_str());
  w.write();
}
