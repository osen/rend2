#ifdef TEST_VAL
  val<int> a;
  val<int> const b;
  val<int const> c;
  val<int const> const d;

  val<Employee> e;
  val<Employee> const f;
  val<Employee const> g;
  val<Employee const> const h;
#endif

#ifdef TEST_VAL_INIT
  val<int> a = 1;
  val<int> const b = 2;
  val<int const> c = 3;
  val<int const> const d = 4;

  val<Employee> e = Employee();
  val<Employee> const f = Employee();
  val<Employee const> g = Employee();
  val<Employee const> const h = Employee();
#endif

#ifdef TEST_VAL_ASSIGN
  val<int> a = 1;
  val<int> b; b = a;

  val<Employee> f = Employee();
  val<Employee> g; g = f;
#endif

#ifdef TEST_VAL_CONST_ASSIGN_1
  val<int> a = 1;
  val<int> const c; c = a;
#endif
#ifdef TEST_VAL_CONST_ASSIGN_2
  val<int> a = 1;
  val<int const> d; d = a;
#endif
#ifdef TEST_VAL_CONST_ASSIGN_3
  val<int> a = 1;
  val<int const> const e; e = a;
#endif

#ifdef TEST_VAL_CONST_ASSIGN_4
  val<Employee> f = Employee();
  val<Employee> const h; h = f;
#endif
#ifdef TEST_VAL_CONST_ASSIGN_5
  val<Employee> f = Employee();
  val<Employee const> i; i = f;
#endif
#ifdef TEST_VAL_CONST_ASSIGN_6
  val<Employee> f = Employee();
  val<Employee const> const j; j = f;
#endif

#ifdef TEST_VAL_ASSIGN_CONST
  val<int> const a = 1;
  val<int const> b = 1;
  val<int const> const c = 1;
  val<int> d; d = a;
  d = b;
  d = c;

  val<Employee> const e = Employee();
  val<Employee const> f = Employee();
  val<Employee const> const g = Employee();
  val<Employee> h; h = e;
  h = f;
  h = g;
#endif

#ifdef TEST_VAL_RAW_PTR
  val<Employee *> a = new Employee();
  ref<Employee *> b = a;
  (*a).id = 9;
  (*b).id = 8;
  delete b; a = NULL;
#endif

#ifdef TEST_VAL_INVALID_PTR
  val<Employee *> a = 1;
#endif

