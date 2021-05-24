#ifdef TEST_ENABLE_REF
  Employee a;
  ref<Employee> b = ref<Employee>::bind(&a);
  b->id = 7;
  ref<Employee> c = ref<Employee>::bind(&a);
  c = b;
#endif
