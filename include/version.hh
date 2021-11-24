#pragma once

#include <string>

namespace my_app
{
  struct Version
  {
    static const std::string GIT_HASH;
    static const std::string GIT_BRANCH;
    static const std::string GIT_DATE;
  };
}
