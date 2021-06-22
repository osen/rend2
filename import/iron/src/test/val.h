#ifdef TEST_VAL
  Value<int> a;
  Value<int> const b;
  Value<int const> c;
  Value<int const> const d;

  Value<Employee> e;
  Value<Employee> const f;
  Value<Employee const> g;
  Value<Employee const> const h;
#endif

#ifdef TEST_VAL_INIT
  Value<int> a = 1;
  Value<int> const b = 2;
  Value<int const> c = 3;
  Value<int const> const d = 4;

  Value<Employee> e = Employee();
  Value<Employee> const f = Employee();
  Value<Employee const> g = Employee();
  Value<Employee const> const h = Employee();
#endif

#ifdef TEST_VAL_ASSIGN
  Value<int> a = 1;
  Value<int> b; b = a;

  Value<Employee> f = Employee();
  Value<Employee> g; g = f;
#endif

#ifdef TEST_VAL_CONST_ASSIGN_1
  Value<int> a = 1;
  Value<int> const c; c = a;
#endif
#ifdef TEST_VAL_CONST_ASSIGN_2
  Value<int> a = 1;
  Value<int const> d; d = a;
#endif
#ifdef TEST_VAL_CONST_ASSIGN_3
  Value<int> a = 1;
  Value<int const> const e; e = a;
#endif

#ifdef TEST_VAL_CONST_ASSIGN_4
  Value<Employee> f = Employee();
  Value<Employee> const h; h = f;
#endif
#ifdef TEST_VAL_CONST_ASSIGN_5
  Value<Employee> f = Employee();
  Value<Employee const> i; i = f;
#endif
#ifdef TEST_VAL_CONST_ASSIGN_6
  Value<Employee> f = Employee();
  Value<Employee const> const j; j = f;
#endif

#ifdef TEST_VAL_ASSIGN_CONST
  Value<int> const a = 1;
  Value<int const> b = 1;
  Value<int const> const c = 1;
  Value<int> d; d = a;
  d = b;
  d = c;

  Value<Employee> const e = Employee();
  Value<Employee const> f = Employee();
  Value<Employee const> const g = Employee();
  Value<Employee> h; h = e;
  h = f;
  h = g;
#endif

#ifdef TEST_VAL_RAW_PTR
  Value<Employee *> a = new Employee();
  Ref<Employee *> b = a;
  (*a).id = 9;
  (*b).id = 8;
  delete b; a = NULL;
#endif

#ifdef TEST_VAL_INVALID_PTR
  Value<Employee *> a = 1;
#endif

#ifdef TEST_VAL_DEREFERENCE
  Value<Employee> a;
  Value<Employee *> b(&a);
  Value<Employee> c;
  Value<Employee *> d(&c);
  Box<Employee> e = Box<Employee>::make();
  Ref<Employee> f = a;
  Ref<Employee *> g(b);

  a->id = 9;
  (*b).id = 9;
  c->id = 9;
  (*d).id = 9;
  e->id = 9;
  f->id = 9;
  (*g).id = 9;
#endif

#ifdef TEST_VAL_COPY_INITIALIZATION
  Value<int> b = 9;
#endif

#ifdef TEST_VAL_INCREMENT
  Value<int> a = 8;
  a++;
  if(a != 9) panic("Invalid result");
#endif

#ifdef TEST_VAL_REF_INCREMENT
  Value<int> a = 8;
  Ref<int> b = a;
  b++;
  a++;
  if(a != 10) panic("Invalid result");
  if(b != 10) panic("Invalid result");
#endif

