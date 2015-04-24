#include "linkedlist_test.h"
#include "strings_test.h"
#include "arrays_test.h"
#include "graphs_test.h"
#include "logics_test.h"

int main() {
#ifdef TEST_DONE
   graphs::Test_Graphs();
   linkedlist::Test_LinkedLists();
   logics::Test_Logics();
   arrays::Test_Arrays();
#endif
   strings::Test_Strings();
   return 0;
}
