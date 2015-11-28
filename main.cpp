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
   dynamic::Test_Dynamic();
   strings::Test_Strings();
   threads::Test_Threads();
   linkedlist::Test_LinkedLists();
#endif
   graphs::Test_Graphs();
   hashmaps::Test_HashMaps();
   arrays::Test_Arrays();
   bits::Test_Bits();
   return 0;
}
