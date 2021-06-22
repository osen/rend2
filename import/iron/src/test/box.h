#ifdef TEST_BOX
  Box<int> a;
  Box<int> const b;
  Box<int const> c;
  Box<int const> const d;

  Box<Employee> e;
  Box<Employee> const f;
  Box<Employee const> g;
  Box<Employee const> const h;
#endif

#ifdef TEST_BOX_INIT
  Box<int> a = Box<int>::make();
  Box<int> const b = Box<int>::make();
  Box<int const> c = Box<int>::make();
  Box<int const> const d = Box<int>::make();

  if(!d.valid()) abort();

  Box<Employee> e = Box<Employee>::make();
  Box<Employee> const f = Box<Employee>::make();
  Box<Employee const> g = Box<Employee const>::make();
  Box<Employee const> const h = Box<Employee const>::make();

  if(!h.valid()) abort();

#endif

#ifdef TEST_BOX_ASSIGN
  Box<int> a = Box<int>::make();
  Box<int> b; b = a;
  Box<int const> c; c = a;

  Box<Employee> f = Box<Employee>::make();
  Box<Employee> g; g = f;
  Box<Employee const> h; h = f;
#endif

#ifdef TEST_BOX_CONST_ASSIGN_1
  Box<int> a = Box<int>::make();
  Box<int> const c; c = a;
#endif
#ifdef TEST_BOX_CONST_ASSIGN_3
  Box<int> a = Box<int>::make();
  Box<int const> const e; e = a;
#endif

#ifdef TEST_BOX_CONST_ASSIGN_4
  Box<Employee> f = Box<Employee>::make();
  Box<Employee> const h; h = f;
#endif
#ifdef TEST_BOX_CONST_ASSIGN_6
  Box<Employee> f = Box<Employee>::make();
  Box<Employee const> const j; j = f;
#endif

#ifdef TEST_BOX_ASSIGN_CONST
  Box<int> const a = Box<int>::make();
  Box<int> d; d = a;

  Box<Employee> const e = Box<Employee>::make();
  Box<Employee> h; h = e;
#endif

#ifdef TEST_BOX_ASSIGN_CONST_1
  Box<int const> a = Box<int>::make();
  Box<int> d; d = a;
#endif
#ifdef TEST_BOX_ASSIGN_CONST_2
  Box<Employee const> a = Box<Employee>::make();
  Box<Employee> h; h = a;
#endif
#ifdef TEST_BOX_ASSIGN_CONST_3
  Box<int const> const a = Box<int>::make();
  Box<int> d; d = a;
#endif
#ifdef TEST_BOX_ASSIGN_CONST_4
  Box<Employee const> const a = Box<Employee>::make();
  Box<Employee> h; h = a;
#endif

#ifdef TEST_BOX_MOVE_REF
  Box<int> dat = Box<int>::make();
  Box<int> dat2;
  Ref<int> d(dat);
  dat2 = dat;
  d = 9;
#endif

#ifdef TEST_BOX_MOVE_REF_DANGLING
  Box<int> dat = Box<int>::make();
  Ref<int> d(dat);
  Box<int> dat2;
  dat2 = dat;
#endif

#ifdef TEST_BOX_TAKEN
  Box<int> dat = Box<int>::make();
  Box<int> dat2 = dat;
  int c = *dat;
#endif

#ifdef TEST_BOX_IMPLICIT_CAST
  Box<Manager> a = Box<Manager>::make();
  Box<Employee> b = a;
  b->id = 9;
#endif

#ifdef TEST_BOX_INVALID_CAST
  Box<Employee> a = Box<Manager>::make();
  Box<Manager> b = a;
#endif

#ifdef TEST_BOX_DANGLING_THIS
  Box<Employee> a = Box<Manager>::make();
  a->box_sink(a);
#endif

