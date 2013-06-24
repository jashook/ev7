#include "algorithm.h"
#include "bn_tree.h"
#include "array.h"
#include "double_linked_list.h"
#include "hash_table.h"
#include "queue.h"
#include "stack.h"
#include "vector.h"

int compare(void* _First, void* _Second)
{

   if (*((int*)_First) < *((int*)_Second)) return -1;
   else if (*((int*)_First) > *((int*)_Second)) return 1;

   else return 0;

}

void test_array()
{

   array _Array;

   int _Count;

   int** _Pointer;

   int* _S = malloc(sizeof(int));

   *_S = 100;

   int* _Int = malloc(sizeof(int));

   *_Int = 5;

   array_create(&_Array, 100);

   array_push_back(&_Array, _Int);

   *_Int = 10;

   array_push_front(&_Array, _Int);

   *_Int = 15;

   _Pointer = (int**)array_at(&_Array, 2);

   *_Pointer = _Int;

   ++_Array.m_size;

   array_empty(&_Array);

   array_push_front(&_Array, _Int);
 
   array_insert(&_Array, 0, _S);

   array_pop_back(&_Array);

   for (_Count = 0; _Count < array_size(&_Array); ++_Count) printf("%d\n", **(int**)array_at(&_Array, _Count));

}

void test_double_linked_list()
{

   int _Count, _Size;

   double_linked_list _List;

   int** _Pointer;

   int* _S = malloc(sizeof(int));

   *_S = 5;

   int* _Int = malloc(sizeof(int));

   *_Int = 10;

   double_linked_list_create(&_List);

   double_linked_list_push_back(&_List, _Int);

   double_linked_list_push_front(&_List, _S);

   _Pointer = (int**)double_linked_list_at(&_List, 2);

   *_Pointer = malloc(sizeof(int));

   **_Pointer = 100;

   ++_List.m_size;

   _Pointer = (int**)double_linked_list_front(&_List);

   **_Pointer = 222222;

   double_linked_list_clear(&_List);

   double_linked_list_push_front(&_List, _S);

   double_linked_list_push_back(&_List, _Int);

   _Pointer = (int**)double_linked_list_back(&_List);

   **_Pointer = 105;

   for (_Count = 0, _Size = double_linked_list_size(&_List); _Count < _Size; ++_Count) printf("%d\n", *(int*)double_linked_list_pop_front(&_List));

   double_linked_list_free(&_List);

}

size_t test_hash_function(void* _Item)
{

   int _Integer = *((int*)_Item);

   return _Integer * 1031;

}

void test_hash_table()
{

   hash_table _HashTable;

   hash_table_create(&_HashTable, 1000);

   int* _Pointer = malloc(sizeof(int));

   int* _Int = malloc(sizeof(int));

   *_Pointer = 5;

   *_Int = 100;

   hash_table_insert(&_HashTable, _Pointer, _Pointer, &test_hash_function);

   printf("%d\n", hash_table_contains(&_HashTable, _Pointer, &compare ,&test_hash_function));

   hash_table_clear(&_HashTable);

   printf("%d\n", hash_table_contains(&_HashTable, _Pointer, &compare, &test_hash_function));

}

void test_merge_sort(int _Size)
{

   int SIZE = _Size;

   int _Index;

   int* _Array = malloc(sizeof(int) * SIZE);

   int _Count = SIZE;

   for (_Index = 0; _Index < SIZE; ++_Index, --_Count) _Array[_Index] = _Count;

   merge_sort(_Array, SIZE, sizeof(int), &compare);

   for (_Index = 0; _Index < SIZE; ++_Index) printf("%d ", _Array[_Index]);

   printf("\n");

   free(_Array);

}

void test_merge_sorted()
{

   int _Index;

   int* _Array = malloc(sizeof(int) * 6);

   int* _Array2 = malloc(sizeof(int) * 5);

   int* _Array3 = malloc(sizeof(int) * 11);

   _Array[0] = 100;
   _Array[1] = 200;
   _Array[2] = 300;
   _Array[3] = 400;
   _Array[4] = 600;
   _Array[5] = 700;

   _Array2[0] = 5;
   _Array2[1] = 500;
   _Array2[2] = 1050;
   _Array2[3] = 1150;
   _Array2[4] = 1250;
   
   merge_sorted(_Array3, _Array, _Array2, 6, 5, sizeof(int), &compare);

   for (_Index = 0; _Index < 11; ++_Index) printf("%d ", _Array3[_Index]);

   printf("\n");

   free(_Array);
   free(_Array2);
   free(_Array3);

}

void test_queue()
{

   int _Count, _Size;

   int* _S = malloc(sizeof(int));

   int* _Int = malloc(sizeof(int));

   *_S = 10;

   *_Int = 100;

   queue _Queue;

   queue_create(&_Queue);

   queue_push(&_Queue, _S);

   queue_push(&_Queue, _Int);

   for (_Count = 0, _Size = queue_size(&_Queue); _Count < _Size; ++_Count) printf("%d\n", *(int*)queue_pop(&_Queue));

   queue_free(&_Queue);

   free(_S);
   free(_Int);

}

void test_stack()
{

   int _Count, _Size;

   int* _S = malloc(sizeof(int));

   int* _Int = malloc(sizeof(int));

   *_S = 10;

   *_Int = 100;

   stack _Stack;

   stack_create(&_Stack);

   stack_push(&_Stack, _S);

   stack_push(&_Stack, _Int);

   for (_Count = 0, _Size = stack_size(&_Stack); _Count < _Size; ++_Count) printf("%d\n", *(int*)stack_pop(&_Stack));

   stack_free(&_Stack);

   free(_S);

   free(_Int);

}

void test_vector()
{

   int _Count, _Size;

   vector _Vector;

   int** _Pointer;

   int* _S = malloc(sizeof(int));

   int* _Int = malloc(sizeof(int));

   *_S = 10;

   *_Int = 100;

   vector_create(&_Vector, 100);

   vector_push_back(&_Vector, _S);

   vector_push_back(&_Vector, _Int);

   _Pointer = (int**)vector_front(&_Vector);

   **_Pointer = 25;

   *(*(_Pointer + 1)) = 301;

   vector_clear(&_Vector);

   for (_Count = 0, _Size = 100; _Count < _Size; ++_Count)
   {

      int* _Point = malloc(sizeof(int));

      *_Point = _Count;

      vector_push_back(&_Vector, _Point);

   }

   for (_Count = 0, _Size = vector_size(&_Vector); _Count < _Size; ++_Count) 
   {

      int* _Point = (int*)vector_pop_back(&_Vector);

      printf("%d\n", *_Point);

      free(_Point);

   }

   vector_free(&_Vector);

   free(_Int);

   free(_S);

}

int main(int argc, char** _Argv)
{

   test_merge_sort(atoi(_Argv[1]));

   return 0;

}
