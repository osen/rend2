#ifdef TEST_ARR
Array<int, 10> foos;

for(size_t ai = 0; ai < foos.size(); ai++)
{
  foos[ai] = 1;
}

int foo = foos[9];

#endif

#ifdef TEST_ARR_OOB
Array<int, 10> foos;

int foo = foos[10];

#endif

