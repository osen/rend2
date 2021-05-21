#ifdef TEST_FILE

freader f;

f.open("Makefile");

freader f2 = f;
f2.open("Makefile");
f = freader("Makefile");

//f.close();

while(!f.eof())
{
  char c = f.getc();

  printf("%c", c);
}

#endif
