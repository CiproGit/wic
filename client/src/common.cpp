#include "common.h"

const QString DEFAULT_PORT = "50000";
const QString DEFAULT_TIMEOUT = "30000";

#ifdef OUTSIDE_BUNDLE
const QString WORKING_DIR = OUTSIDE_BUNDLE;
#else
const QString WORKING_DIR = ".";
#endif // OUTSIDE_BUNDLE
