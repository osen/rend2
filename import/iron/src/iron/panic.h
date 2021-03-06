#include <stdio.h>
#include <stdlib.h>

namespace iron
{

template <typename T>
void _panic(const char *message)
{
  printf("Panic: %s\n", message);

  abort();
}

#define panic _panic<int>

}

