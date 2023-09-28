#include "common.h"

const QString DEFAULT_IP_ADDRESS = "127.0.0.1";
const QString DEFAULT_PORT = "50000";

#ifdef OUTSIDE_BUNDLE
const QString WORKING_DIR = OUTSIDE_BUNDLE;
#else
const QString WORKING_DIR = ".";
#endif // OUTSIDE_BUNDLE
