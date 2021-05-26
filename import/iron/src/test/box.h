#ifdef TEST_BOX
  box<int> a;
  box<int> const b;
  box<int const> c;
  box<int const> const d;

  box<Employee> e;
  box<Employee> const f;
  box<Employee const> g;
  box<Employee const> const h;
#endif

#ifdef TEST_BOX_INIT
  box<int> a = box<int>::make();
  box<int> const b = box<int>::make();
  box<int const> c = box<int>::make();
  box<int const> const d = box<int>::make();

  if(!d.valid()) abort();

  box<Employee> e = box<Employee>::make();
  box<Employee> const f = box<Employee>::make();
  box<Employee const> g = box<Employee const>::make();
  box<Employee const> const h = box<Employee const>::make();

  if(!h.valid()) abort();

#endif

#ifdef TEST_BOX_ASSIGN
  box<int> a = box<int>::make();
  box<int> b; b = a;
  box<int const> c; c = a;

  box<Employee> f = box<Employee>::make();
  box<Employee> g; g = f;
  box<Employee const> h; h = f;
#endif

#ifdef TEST_BOX_CONST_ASSIGN_1
  box<int> a = box<int>::make();
  box<int> const c; c = a;
#endif
#ifdef TEST_BOX_CONST_ASSIGN_3
  box<int> a = box<int>::make();
  box<int const> const e; e = a;
#endif

#ifdef TEST_BOX_CONST_ASSIGN_4
  box<Employee> f = box<Employee>::make();
  box<Employee> const h; h = f;
#endif
#ifdef TEST_BOX_CONST_ASSIGN_6
  box<Employee> f = box<Employee>::make();
  box<Employee const> const j; j = f;
#endif

#ifdef TEST_BOX_ASSIGN_CONST
  box<int> const a = box<int>::make();
  box<int> d; d = a;

  box<Employee> const e = box<Employee>::make();
  box<Employee> h; h = e;
#endif

#ifdef TEST_BOX_ASSIGN_CONST_1
  box<int const> a = box<int>::make();
  box<int> d; d = a;
#endif
#ifdef TEST_BOX_ASSIGN_CONST_2
  box<Employee const> a = box<Employee>::make();
  box<Employee> h; h = a;
#endif
#ifdef TEST_BOX_ASSIGN_CONST_3
  box<int const> const a = box<int>::make();
  box<int> d; d = a;
#endif
#ifdef TEST_BOX_ASSIGN_CONST_4
  box<Employee const> const a = box<Employee>::make();
  box<Employee> h; h = a;
#endif

#ifdef TEST_BOX_MOVE_REF
  box<int> dat = box<int>::make();
  box<int> dat2;
  ref<int> d = dat;
  dat2 = dat;
  d = 9;
#endif

#ifdef TEST_BOX_MOVE_REF_DANGLING
  box<int> dat = box<int>::make();
  ref<int> d = dat;
  box<int> dat2;
  dat2 = dat;
#endif

#ifdef TEST_BOX_TAKEN
  box<int> dat = box<int>::make();
  box<int> dat2 = dat;
  int c = *dat;
#endif

#ifdef TEST_BOX_IMPLICIT_CAST
  box<Manager> a = box<Manager>::make();
  box<Employee> b = a;
  b->id = 9;
#endif

#ifdef TEST_BOX_INVALID_CAST
  box<Employee> a = box<Manager>::make();
  box<Manager> b = a;
#endif

#ifdef TEST_BOX_DANGLING_THIS
  box<Employee> a = box<Manager>::make();
  a->box_sink(a);
#endif

