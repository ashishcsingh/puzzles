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
   linkedlist::Test_LinkedLists();
#endif
   hashmaps::Test_HashMaps();
   threads::Test_Threads();
   arrays::Test_Arrays();
   graphs::Test_Graphs();
   return 0;
}
