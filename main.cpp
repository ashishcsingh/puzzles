#include "linkedlist_test.h"
#include "strings_test.h"
#include "arrays_test.h"
#include "graphs_test.h"
#include "logics_test.h"
#include "dynamic_test.h"

int main() {
#ifdef TEST_DONE
   logics::Test_Logics();
   linkedlist::Test_LinkedLists();
   strings::Test_Strings();
   arrays::Test_Arrays();
#endif
   graphs::Test_Graphs();
   dynamic::Test_Dynamic();
   return 0;
}
