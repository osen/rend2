#ifdef TEST_VEC_DANGLE_3
void bar(Employee &emp, vec<Employee> &emps)
{
  emps.clear();
}
#endif

#ifdef TEST_STRING_DANGLE
void bar(char &c, string &str)
{
  str.append("Hello");
}
#endif

void run_misc()
{
#ifdef TEST_VEC_DANGLE_3
  vec<Employee> foos;
  foos.push(Employee());
  bar(foos[0], foos);
#endif

#ifdef TEST_STRING_DANGLE
  string foo = "hello";
  bar(foo[1], foo);
#endif
}
