#include "common.h"

#ifdef OUTSIDE_BUNDLE
const QString FILE_PATH = OUTSIDE_BUNDLE;
#else
const QString FILE_PATH = "/";
#endif // OUTSIDE_BUNDLE
