#include "../data_structure/array/array.h"

// swap_int / is_sorted_ascending / copy_array are define in
// "../data_structure/array/array.h"

array selection_sort(array* arr);
array insertion_sort(array* arr);

int main(void) {
    return 0;
}

array selection_sort(array* arr) {
    // Time Complexity : O(n²)

    array newArray = copy_array(arr);
    unsigned long n = arr->size;
    unsigned long min = 0;
    for (unsigned long i = 0; i < n - 2; i++) {
        min = i;
        for (unsigned long j = i + 1; j < n - 1; j++) {
            if (get(&newArray, j) < get(&newArray, min)) {
                min = j;
            }
        }
        swap_int(&newArray, i, min);
    }
    return newArray;
}


array insertion_sort(array* arr){
    
}