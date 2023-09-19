
void foo( int       *       ptr,
          int const *       ptr_to_const,
          int       * const const_ptr,
          int const * const const_ptr_to_const )
{
  *ptr = 0; // OK: modifies the pointee
  ptr  = 0; // OK: modifies the pointer
 
  *ptr_to_const = 0; // Error! Cannot modify the pointee
  ptr_to_const  = 0; // OK: modifies the pointer
 
  *const_ptr = 0; // OK: modifies the pointee
  const_ptr  = 0; // Error! Cannot modify the pointer
 
  *const_ptr_to_const = 0; // Error! Cannot modify the pointee
  const_ptr_to_const  = 0; // Error! Cannot modify the pointer
}


int main()
{
  return 0;
}


/*
 * gcc -Wall t.c
 * In function 'foo':
 *   14: error: assignment of read-only location '*ptr_to_const'
 *   18: error: assignment of read-only parameter 'const_ptr'
 *   20: error: assignment of read-only location '*const_ptr_to_const'
 *   21: error: assignment of read-only parameter 'const_ptr_to_const'
 */
