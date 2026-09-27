#pragma once

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "v5.h"
#include "v5_vcs.h"

#include "robot-config.hpp"
#include "global.hpp"
#include "PID/global-pid.hpp"

// START V5 MACROS
#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)
// END V5 MACROS