#include "iostream"
#include "header/Sort.h"
#include <vector>
int main(){
   algorithm::Sort sort_instance = algorithm::Sort();
   std::vector<double> test_vec = sort_instance.RandVec(100);
   // sort_instance.BubbleSort(test_vec);
   // test_vec = sort_instance.RandVec(10);
   // sort_instance.SelectSort(test_vec);
   // test_vec = sort_instance.RandVec(10);
   // sort_instance.InsertSort(test_vec);
   // test_vec = sort_instance.RandVec(10);
   // sort_instance.MergeSort(test_vec);
   // sort_instance.MergeSortRecursion(test_vec);
   sort_instance.QucikSort(test_vec);
   system("Pause");
   return 0;
}