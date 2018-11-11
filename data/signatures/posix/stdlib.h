
long      a64l(const char *s);
void      abort(void);
int       abs(int i);
int       atexit(atexitfunc func);
double    atof(const char *str);
int       atoi(const char *str);
long      atol(const char *str);
void *bsearch(const void *key, const void *base,
              size_t num, size_t size,
              comparfunc compar);
void     *calloc(size_t nelem, size_t elsize);
div_t     div(int numer, int denom);
double    drand48(void);
char     *ecvt(double value, int ndigit, int *decpt, int *sign);
double    erand48(unsigned short xsubi[3]);
void      exit(int status);
char     *fcvt(double value, int ndigit, int *decpt, int *sign);
void      free(void *ptr);
char     *gcvt(double value, int ndigit, char *buf);
char     *getenv(const char *name);
int       getsubopt(char **optionp, char **tokens, char **valuep);
int       grantpt(int fildes);
char     *initstate(unsigned int seed, char *state, size_t size);
long      jrand48(unsigned short xsubi[3]);
char     *l64a(long value);
long      labs(long i);
void      lcong48(unsigned short param[7]);
ldiv_t    ldiv(long numer, long denom);
long      lrand48(void);
void     *malloc(size_t size);
int       mblen(const char *s, size_t n);
size_t    mbstowcs(wchar_t *pwcs, const char *s, size_t n);
int       mbtowc(wchar_t *pwc, const char *s, size_t n);
char     *mktemp(char *template);
int       mkstemp(char *template);
long      mrand48(void);
long      nrand48(unsigned short xsubi[3]);
char     *ptsname(int fildes);
int       putenv(char *string);
void qsort(void *base, size_t num, size_t size, comparfunc compar);
int       rand(void);
int       rand_r(unsigned int *seed);
long      random(void);
void     *realloc(void *ptr, size_t size);
char     *realpath(const char *file_name, char *resolved_name);
unsigned  short seed48(unsigned short seed16v[3]);
void      setkey(const char *key);
char     *setstate(const char *state);
void      srand(unsigned int seed);
void      srand48(long seedval);
void      srandom(unsigned seed);
double    strtod(const char *str, char **endptr);
long      strtol(const char *str, char **endptr, int base);
unsigned long strtoul(const char *str, char **endptr, int base);
int       system(const char *command);
int       ttyslot(void);
int       unlockpt(int fildes);
void     *valloc(size_t size);
size_t    wcstombs(char *s, const wchar_t *pwcs, size_t n);
int       wctomb(char *s, wchar_t wchar);
