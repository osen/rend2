#ifdef TEST_ENABLE_REF
  Employee a;
  ref<Employee> b(&a);
  b->id = 7;
  ref<Employee> c;
  c.bind(&a);
  b->id = 3;
  c = b;

  if(c->id != 3) panic("Invalid value");
#endif

