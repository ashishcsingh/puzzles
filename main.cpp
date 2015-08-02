#include "linkedlist_test.h"
#include "strings_test.h"
#include "arrays_test.h"
#include "graphs_test.h"
#include "logics_test.h"

int main() {
#ifdef TEST_DONE
   logics::Test_Logics();
   linkedlist::Test_LinkedLists();
   strings::Test_Strings();
   graphs::Test_Graphs();
#endif
   arrays::Test_Arrays();
   return 0;
}
