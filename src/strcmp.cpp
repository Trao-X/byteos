#include <stddef.h>

// strcmp from embeddedartistry.github.io (MIT) (for byteos kernel)
// credits: v3x, embeddedartistry.github.io


int strcmp(const char *s1, const char *s2) {
  int r = -1;

  if (s1 == s2) {
    // short circuit - same string
    return 0;
  }

  // I don't want to panic with a NULL ptr - we'll fall through and fail w/ -1
  if (s1 != NULL && s2 != NULL) {
    // iterate through strings until they don't match or s1 ends (null-term)
    for (; *s1 == *s2; ++s1, ++s2) {
      if (*s1 == 0) {
        r = 0;
        break;
      }
    }

    // handle case where we didn't break early - set return code.
    if (r != 0) {
      r = *(const char *)s1 - *(const char *)s2;
    }
  }

  return r;
}
