#include "array.h"

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

int main()
{

   test_array();

   return 0;

}
