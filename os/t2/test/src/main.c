#include "array.h"
#include "double_linked_list.h"

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

   int _Count;

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

   for (_Count = 0; _Count < double_linked_list_size(&_List); ++_Count) printf("%d\n", **(int**)double_linked_list_at(&_List, _Count));

   double_linked_list_free(&_List);

}

int main()
{

   test_double_linked_list();

   return 0;

}
