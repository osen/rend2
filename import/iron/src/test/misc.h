#ifdef TEST_VEC_DANGLE_3
void bar(Employee& emp, Vector<Employee>& emps)
{
  emps.clear();
}
#endif

#ifdef TEST_STRING_DANGLE
void bar(char& c, String& str)
{
  str.append("Hello");
}
#endif

void run_misc()
{
#ifdef TEST_VEC_DANGLE_3
  Vector<Employee> foos;
  foos.push(Employee());
  bar(foos[0], foos);
#endif

#ifdef TEST_STRING_DANGLE
  String foo = "hello";
  bar(foo[1], foo);
#endif
}
