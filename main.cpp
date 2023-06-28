#include "iostream"
#include "header/Sort.h"
#include <vector>
int main(){
   algorithm::Sort sort_instance = algorithm::Sort();
   std::vector<int> test_vec = {6,5,4,8,111,10,-1,999, 333};
   sort_instance.BubbleSort(test_vec);
   test_vec = {6,5,4,8,111,10,-1,999, 333};
   sort_instance.SelectSort(test_vec);
   system("Pause");
   return 0;
}