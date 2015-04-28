#include "linkedlist_test.h"
#include "strings_test.h"
#include "arrays_test.h"
#include "graphs_test.h"
#include "logics_test.h"

int main() {
#ifdef TEST_DONE
   logics::Test_Logics();
   graphs::Test_Graphs();
#endif
   //linkedlist::Test_LinkedLists();
   arrays::Test_Arrays();
   //strings::Test_Strings();
   return 0;
}
