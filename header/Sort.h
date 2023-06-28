#pragma once
#include <vector>
#include "iostream"

namespace algorithm{
    class Sort
    {
    private:
    public:
        Sort();
        ~Sort();

        template <typename T>
        void swap(T& a, T& b){
            T c = a;
            a = b;
            b = c; 
        }

        template <typename T>
        void Print(T& nums){
            int length = nums.size();
            for (size_t i = 0; i < length; i++)
            {
                std::cout<<nums[i]<<std::endl;
            }
        }

        std::vector<double> RandVec(int length){
            std::vector<double> ret;
            for (size_t i = 0; i < length; i++)
            {
               ret.push_back(rand());
            }
            return ret;
        }

        template <typename T>
        void BubbleSort(T& nums){
            int length = nums.size();
            int left = 0;
            int right = length - 1;
            while(left < right){
                int ptr = left;
                while (ptr<right)
                {
                   if (nums[ptr] > nums[ptr+1]){
                    swap(nums[ptr], nums[ptr+1]);
                   }
                   ptr += 1;
                }
                right -= 1;
            }
            Print(nums);
        }

        template <typename T>
        void SelectSort(T& nums){
            int length = nums.size();
            int left = 0;
            int right = length - 1;
            while(left < right){
                int ptr = left;
                int min_num_index = left;
                while (ptr <= right)
                {
                   if (nums[ptr] < nums[min_num_index]){
                    min_num_index = ptr;
                   }
                   ptr += 1;
                }
                swap(nums[left], nums[min_num_index]);
                left += 1;
            }
            Print(nums);
        }

    };
}
