#ifdef TEST_STRING
  String foo;
#endif

#ifdef TEST_STRING_COPY_1
  String foo;
  String bar(foo);
  String const bang(foo);
#endif

#ifdef TEST_STRING_ASSIGN_1
  String foo;
  String bar;
  bar = foo;
#endif

#ifdef TEST_STRING_ASSIGN_2
  String foo = "foo";
  String bar = "bar";
  bar = foo;
  char bang = bar[0];
  bang = bar[2];
#endif

#ifdef TEST_STRING_APPEND_1
  String foo;
  foo.append('h');
  foo.append('e');
  foo.append('l');
  foo.append('o');

  char bar = foo[0];
  bar = foo[3];
#endif

#ifdef TEST_STRING_APPEND_2
  String foo = "foo";
  foo.append("bar");
  char bar = foo[0];
  bar = foo[5];
#endif

#ifdef TEST_STRING_APPEND_OOB
  String foo = "foo";
  foo.append("bar");
  char bar = foo[6];
#endif


#ifdef TEST_STRING_OOB
  String foo;
  foo.append('h');
  foo.append('e');
  foo.append('l');
  foo.append('o');

  char bar = foo[4];
#endif

#ifdef TEST_STRING_COPY_2
  String foo("hello");
  String bar(foo);
  char bang = foo[0];
  bang = foo[4];
#endif

#ifdef TEST_STRING_COPY_OOB
  String foo("hello");
  String bar(foo);
  char bang = foo[0];
  bang = foo[5];
#endif

