#ifdef TEST_VEC
  Vector<Employee> a;
#endif

#ifdef TEST_VEC_PUSH
  Vector<int> a;
  a.push(1);
  a.push(2);
  a.push(3);
  a[1] = 9;
#endif

#ifdef TEST_VEC_OOB
  Vector<int> a;
  a.push(1);
  a.push(2);
  a.push(3);
  a[3] = 9;
#endif

#ifdef TEST_VEC_REF
  Vector<Employee> a;
  a.push(Employee());
  a.push(Employee());
  a.push(Employee());
  Ref<Employee> b(&a[2]);
#endif

#ifdef TEST_EXPERIMENTAL_VEC_REF_IMPLICIT
  Vector<Employee> a;
  a.push(Employee());
  a.push(Employee());
  a.push(Employee());
  Ref<Employee> b(&a[2]);
#endif

#ifdef TEST_VEC_COPY
  Vector<int> a;
  a.push(9);
  a.push(8);
  a.push(7);
  Vector<int> b = a;
  b[2] = 3;
  b = a;
  a.clear();
#endif

#ifdef TEST_VEC_DANGLE_1
  Vector<Value<Employee> > a;
  a.push(Employee());
  a.push(Employee());
  a.push(Employee());
  Ref<Employee> b(a[2]);
  a.clear();
#endif

#ifdef TEST_VEC_DANGLE_2
  Vector<Value<Employee> > a;
  a.push(Employee());
  a.push(Employee());
  a.push(Employee());
  Ref<Employee> b(a[2]);
  a = Vector<Value<Employee> >();
#endif

#ifdef TEST_VEC_BOX
  Vector<Box<Employee> > a;
  a.push(Box<Employee>::make());
  //a[0]->vec_sink(a);
  //a.clear();

  a.push(Box<Employee>::make());
  a.push(Box<Employee>::make());
  a[0]->id = 9;
  a[0]->id = 9;
  a[0]->id = 9;

  Ref<Employee> b(a[0]);
  b->id = 9;
  //b->vec_sink(a);

  Value<Employee> f;
  Ref<Employee> g(f);
  g->id = 7;
#endif

