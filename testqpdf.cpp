#include <qpdf/Pl_DCT.hh>
#include <qpdf/Pl_RunLength.hh>
#include <qpdf/PointerHolder.hh>
#include <qpdf/QIntC.hh>
#include <qpdf/QPDF.hh>
#include <qpdf/QPDFObjectHandle.hh>
#include <qpdf/QPDFPageDocumentHelper.hh>
#include <qpdf/QPDFPageObjectHelper.hh>
#include <qpdf/QPDFWriter.hh>
#include <qpdf/QUtil.hh>
using namespace std;
int main() {
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
  string text = "hello";
  QPDFObjectHandle contents = // 612 - 72*2 = 540 = 135 * 4
      pdf.newStream((string) "BT /F1 17 Tf 72 720 Td (" + text + ") Tj ET\n" +
                    "BT /F1 17 Tf 207 720 Td (" + text + ") Tj ET\n" +
                    "BT /F1 17 Tf 342 720 Td (" + text + ") Tj ET\n" +
                    "BT /F1 17 Tf 477 720 Td (" + text + ") Tj ET\n" +
                    "BT /F1 15 Tf 36 700 Td (" + text + ") Tj ET\n" +
                    "BT /F1 15 Tf 36 680 Td (" + text + ") Tj ET\n" +
                    "BT /F1 15 Tf 36 660 Td (" + text + ") Tj ET\n" +
                    "BT /F1 15 Tf 36 640 Td (" + text + ") Tj ET\n");
  /*                    beginText   size    x  y          text         endText*/
  QPDFObjectHandle mediabox =
      QPDFObjectHandle::parse("[0 0 612 792]"); // 22.5*27.2 30
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

  QPDFWriter w(pdf, "1.pdf");
  w.write();
}
