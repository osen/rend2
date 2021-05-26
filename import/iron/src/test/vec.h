#ifdef TEST_VEC
  vec<Employee> a;
#endif

#ifdef TEST_VEC_PUSH
  vec<Employee> a;
  a.push(Employee());
  a.push(Employee());
  a.push(a[1]);
  ref<Employee> b = a[1];
#endif

#ifdef TEST_VEC_REF
  vec<int> c;
  c.push(9);
  c.push(8);
  c.push(7);
  ref<int> d = c[2];
  d = 3;
  c[2] = 2;
  d = ref<int>();
#endif

#ifdef TEST_VEC_COPY
  vec<int> a;
  a.push(9);
  a.push(8);
  a.push(7);
  vec<int> b = a;
  b[2] = 3;
  b = a;
  a.clear();
#endif

#ifdef TEST_VEC_DANGLE_1
  vec<int> a;
  a.push(9);
  a.push(8);
  a.push(7);
  ref<int> b = a[2];
  a.clear();
#endif

#ifdef TEST_VEC_DANGLE_2
  vec<int> a;
  a.push(9);
  a.push(8);
  a.push(7);
  ref<int> b = a[2];
  a = vec<int>();
#endif

//#ifdef TEST_VEC_BOX
  vec<box<Employee> > a;
  a.push(box<Employee>::make());
  //a[0]->vec_sink(a);
  //a.clear();

  a.push(box<Employee>::make());
  a.push(box<Employee>::make());
  a[0]->id = 9;
  a[0]->id = 9;
  a[0]->id = 9;

  ref<Employee> b = a[0];
  b->id = 9;
  //b->vec_sink(a);

  val<Employee> f;
  ref<Employee> g = f;
  g->id = 7;

//#endif
