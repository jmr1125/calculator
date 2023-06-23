#include<hpdf.h>
#include<cstdio>
#include<exception>
#include <stdexcept>
void handler(HPDF_STATUS error_no, HPDF_STATUS detail_no, void *user_data) {
  char str[512] = {0};
  sprintf(str, "ERROR: error_no=%04X, detail_no=%d\n", (unsigned int)error_no,
          (int)detail_no);
  throw std::runtime_error(str);
}
int main() {
  HPDF_Doc pdf;
  pdf = HPDF_New(handler, NULL);
  HPDF_Free(pdf);
}
