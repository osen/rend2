#ifdef TEST_STRING
  string foo;
#endif

#ifdef TEST_STRING_COPY_1
  string foo;
  string bar(foo);
  string const bang(foo);
#endif

#ifdef TEST_STRING_ASSIGN_1
  string foo;
  string bar;
  bar = foo;
#endif

#ifdef TEST_STRING_ASSIGN_2
  string foo = "foo";
  string bar = "bar";
  bar = foo;
  char bang = bar[0];
  bang = bar[2];
#endif

#ifdef TEST_STRING_APPEND_1
  string foo;
  foo.append('h');
  foo.append('e');
  foo.append('l');
  foo.append('o');

  char bar = foo[0];
  bar = foo[3];
#endif

#ifdef TEST_STRING_APPEND_2
  string foo = "foo";
  foo.append("bar");
  char bar = foo[0];
  bar = foo[5];
#endif

#ifdef TEST_STRING_APPEND_OOB
  string foo = "foo";
  foo.append("bar");
  char bar = foo[6];
#endif


#ifdef TEST_STRING_OOB
  string foo;
  foo.append('h');
  foo.append('e');
  foo.append('l');
  foo.append('o');

  char bar = foo[4];
#endif

#ifdef TEST_STRING_COPY_2
  string foo("hello");
  string bar(foo);
  char bang = foo[0];
  bang = foo[4];
#endif

#ifdef TEST_STRING_COPY_OOB
  string foo("hello");
  string bar(foo);
  char bang = foo[0];
  bang = foo[5];
#endif

