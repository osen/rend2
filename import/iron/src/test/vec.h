#ifdef TEST_VEC
  vec<Employee> a;
#endif

#ifdef TEST_VEC_PUSH
  vec<int> a;
  a.push(1);
  a.push(2);
  a.push(3);
  a[1] = 9;
#endif

#ifdef TEST_VEC_OOB
  vec<int> a;
  a.push(1);
  a.push(2);
  a.push(3);
  a[3] = 9;
#endif

#ifdef TEST_VEC_REF
  vec<Employee> a;
  a.push(Employee());
  a.push(Employee());
  a.push(Employee());
  ref<Employee> b(&a[2]);
#endif

#ifdef TEST_EXPERIMENTAL_VEC_REF_IMPLICIT
  vec<Employee> a;
  a.push(Employee());
  a.push(Employee());
  a.push(Employee());
  ref<Employee> b(&a[2]);
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
  vec<val<Employee> > a;
  a.push(Employee());
  a.push(Employee());
  a.push(Employee());
  ref<Employee> b(a[2]);
  a.clear();
#endif

#ifdef TEST_VEC_DANGLE_2
  vec<val<Employee> > a;
  a.push(Employee());
  a.push(Employee());
  a.push(Employee());
  ref<Employee> b(a[2]);
  a = vec<val<Employee> >();
#endif

#ifdef TEST_VEC_BOX
  vec<box<Employee> > a;
  a.push(box<Employee>::make());
  //a[0]->vec_sink(a);
  //a.clear();

  a.push(box<Employee>::make());
  a.push(box<Employee>::make());
  a[0]->id = 9;
  a[0]->id = 9;
  a[0]->id = 9;

  ref<Employee> b(a[0]);
  b->id = 9;
  //b->vec_sink(a);

  val<Employee> f;
  ref<Employee> g(f);
  g->id = 7;
#endif

