#include "linkedlist_test.h"
#include "strings_test.h"
#include "arrays_test.h"
#include "graphs_test.h"
#include "logics_test.h"
#include "dynamic_test.h"
#include "threads_test.h"

int main() {
#ifdef TEST_DONE
   logics::Test_Logics();
   dynamic::Test_Dynamic();
   graphs::Test_Graphs();
   threads::Test_Threads();
#endif
   arrays::Test_Arrays();
   strings::Test_Strings();
   linkedlist::Test_LinkedLists();
   return 0;
}
