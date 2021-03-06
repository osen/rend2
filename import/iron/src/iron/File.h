/*
#include <stdio.h>

namespace iron
{

struct freader
{
  freader() { }

  freader(const char *path)
  {
    open(path);
  }

  ~freader()
  {
    close();
  }

  void close()
  {
    if(!fp.valid()) return;

    fclose(*fp);
    fp = Box<FILE *>();
  }

  void open(const char *path)
  {
    Box<FILE *> fp = Box<FILE *>::make();

    *fp = fopen(path, "r");

    if(!*fp)
    {
      throw std::exception();
    }

    close();
    this->fp = fp;
  }

  unsigned char readChar()
  {
    int rtn = fgetc(*fp);

    if(rtn == EOF)
    {
      throw std::exception();
    }

    return rtn;
  }

  bool eof()
  {
    //if(feof(*fp))
    //{
    //  return true;
    //}

    int c = fgetc(*fp);

    if(c == EOF)
    {
      return true;
    }

    ungetc(c, *fp);

    return false;
  }

private:
  Box<FILE *> fp;

};

}

*/
