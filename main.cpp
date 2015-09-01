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
   linkedlist::Test_LinkedLists();
   strings::Test_Strings();
   arrays::Test_Arrays();
   dynamic::Test_Dynamic();
   graphs::Test_Graphs();
#endif
   threads::Test_Threads();
   return 0;
}
