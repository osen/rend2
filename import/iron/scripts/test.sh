CXX=c++
#CXX="g++ -fno-elide-constructors"

run()
{
  make

  exec_success VAL
  exec_success VAL_INIT
  exec_success VAL_ASSIGN
  exec_success VAL_ASSIGN_CONST
  exec_success VAL_RAW_PTR
  exec_success VAL_DEREFERENCE
  exec_success VAL_COPY_INITIALIZATION
  exec_success VAL_INCREMENT
  exec_success VAL_REF_INCREMENT
  compile_fail VAL_INVALID_PTR
  compile_fail VAL_CONST_ASSIGN_1
  compile_fail VAL_CONST_ASSIGN_2
  compile_fail VAL_CONST_ASSIGN_3
  compile_fail VAL_CONST_ASSIGN_4
  compile_fail VAL_CONST_ASSIGN_5
  compile_fail VAL_CONST_ASSIGN_6
  compile_fail UNIQUE_COPY_INITIALIZATION

  exec_success BOX
  exec_success BOX_INIT
  exec_success BOX_ASSIGN
  exec_success BOX_ASSIGN_CONST
  exec_success BOX_MOVE_REF
  exec_success BOX_IMPLICIT_CAST
  exec_fail BOX_MOVE_REF_DANGLING
  exec_fail BOX_TAKEN
  exec_fail BOX_DANGLING_THIS
  compile_fail BOX_ASSIGN_CONST_1
  compile_fail BOX_ASSIGN_CONST_2
  compile_fail BOX_ASSIGN_CONST_3
  compile_fail BOX_ASSIGN_CONST_4
  compile_fail BOX_CONST_ASSIGN_1
  compile_fail BOX_CONST_ASSIGN_3
  compile_fail BOX_CONST_ASSIGN_4
  compile_fail BOX_CONST_ASSIGN_6
  compile_fail BOX_INVALID_CAST

  exec_success VEC
  exec_success VEC_PUSH
  exec_success VEC_REF
  exec_success VEC_COPY
  exec_fail VEC_OOB
  exec_fail VEC_DANGLE_1
  exec_fail VEC_DANGLE_2
  exec_success ENABLE_REF
  exec_success FILE
}

exec_success()
{
  NAME="$1"
  echo "Running Test: $NAME"

  $CXX -Iinclude -DTEST_$NAME -otest src/test/main.cpp
  RES=$?

  if [ $RES != 0 ]; then
    echo "Error: Failed to compile [$NAME]"
    exit 1
  fi

  ./test
  RES=$?

  if [ $RES != 0 ]; then
    echo "Error: Failed to run [$NAME]"
    exit 1
  fi

  rm test
}

exec_fail()
{
  NAME="$1"
  echo "Running Test: $NAME"

  $CXX -Iinclude -DTEST_$NAME -otest src/test/main.cpp
  RES=$?

  if [ $RES != 0 ]; then
    echo "Error: Failed to compile [$NAME]"
    exit 1
  fi

  ./test >/dev/null 2>&1
  RES=$?

  if [ $RES = 0 ]; then
    echo "Error: A runtime error should have occurred [$NAME]"
    exit 1
  fi

  rm test
  rm test.core
}


compile_fail()
{
  NAME="$1"
  echo "Running Test: $NAME"

  $CXX -Iinclude -DTEST_$NAME -otest src/test/main.cpp >/dev/null 2>&1
  RES=$?

  if [ $RES = 0 ]; then
    echo "Error: A compile error should have occurred [$NAME]"
    exit 1
  fi
}

run

