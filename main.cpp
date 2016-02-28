#include "linkedlist_test.h"
#include "strings_test.h"
#include "arrays_test.h"
#include "graphs_test.h"
#include "logics_test.h"
#include "dynamic_test.h"
#include "threads_test.h"
#include "hashmaps_test.h"
#include "bits_test.h"

int main() {
#ifdef TEST_DONE
   logics::Test_Logics();
   threads::Test_Threads();
#endif
   bits::Test_Bits();
   linkedlist::Test_LinkedLists();
   graphs::Test_Graphs();
   arrays::Test_Arrays();
   hashmaps::Test_HashMaps();
   dynamic::Test_Dynamic();
   strings::Test_Strings();
   return 0;
}
