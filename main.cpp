#include "linkedlist_test.h"
#include "strings_test.h"
#include "arrays_test.h"
#include "graphs_test.h"
#include "logics_test.h"
#include "dynamic_test.h"
#include "threads_test.h"
#include "hashmaps_test.h"

int main() {
#ifdef TEST_DONE
   logics::Test_Logics();
   dynamic::Test_Dynamic();
   strings::Test_Strings();
   hashmaps::Test_HashMaps();
   threads::Test_Threads();
#endif
   arrays::Test_Arrays();
   graphs::Test_Graphs();
   linkedlist::Test_LinkedLists();
   return 0;
}
