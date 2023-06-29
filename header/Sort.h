#pragma once
#include <vector>
#include "iostream"
#include "algorithm"

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
            std::cout<<"----------------------------------------------"<<std::endl;
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

        template <typename T>
        void InsertSort(T& nums){
            int length = nums.size();
            int left = 1;
            int right = length - 1;
            while(left <= right){
                int ptr = left;
                while (ptr > 0)
                {
                   if (nums[ptr] < nums[ptr-1]){
                    swap(nums[ptr], nums[ptr-1]);
                    ptr -= 1;
                   }
                   else{
                    break;
                   }
                }
                left += 1;
            }
            Print(nums);
        }


        template <typename T>
        void MergeSortInternal(T& nums, int left, int middle, int right, T& vec){
            int ptr_left = left;
            int ptr_right = middle;
            int index = left;
            while (ptr_left<middle || ptr_right<right)
            {
                if (ptr_left>=middle){
                    vec[index] = nums[ptr_right++];
                }
                else if (ptr_right>=right)
                {
                    vec[index] = nums[ptr_left++];
                }else{
                    vec[index] = nums[ptr_left]<nums[ptr_right]?nums[ptr_left++]:nums[ptr_right++];
                }
                ++index;
            }

            for (int i = left; i < right; i++)
            {
                nums[i] = vec[i];
            }
            
            
        }

        template <typename T>
        void MergeSort(T& nums){
            T vec(nums.size());
            int length = nums.size();
            int ceil_len = 1;
            while(ceil_len < length){
                for (int i = 0; i<length, i+ceil_len<length; i+=ceil_len*2)
                {
                    int left = i;
                    int middle = i + ceil_len;
                    int right = std::min(middle + ceil_len, length);
                    MergeSortInternal(nums, left, middle, right, vec);
                }
                ceil_len *= 2;
            }
            Print(nums);
        }

        template <typename T>
        void MergeSortRecursionInternal(T& nums, int left, int right, T& vec){
            if (left+1 >= right){
                return;
            }
            MergeSortRecursionInternal(nums, left, (left+right)/2, vec);
            MergeSortRecursionInternal(nums, (left+right)/2, right, vec);
            MergeSortInternal(nums, left, (left+right)/2, right, vec);
        }

        template <typename T>
        void MergeSortRecursion(T& nums){
            T vec(nums.size());
            MergeSortRecursionInternal(nums, 0, nums.size(), vec);
            Print(nums);
        }

        template <typename T>
        void QuickSortInternal(T& nums, int left, int right){
            if (left >= right){
                return;
            }
            int left_ptr = left-1;
            int right_ptr = right+1;
            int middle_ptr = left;
            int middle_val = nums[left];
            while(middle_ptr < right_ptr){
                if(nums[middle_ptr] == middle_val){
                    ++middle_ptr;
                }
                if(nums[middle_ptr] > middle_val){
                    swap(nums[middle_ptr], nums[--right_ptr]);
                }
                if(nums[middle_ptr] < middle_val){
                    swap(nums[middle_ptr++], nums[++left_ptr]);
                }
            }
            QuickSortInternal(nums, left, left_ptr);
            QuickSortInternal(nums, right_ptr, right);

        }

        template <typename T>
        void QucikSort(T& nums){
            QuickSortInternal(nums, 0, nums.size()-1);
            Print(nums);
        }

    };
}
