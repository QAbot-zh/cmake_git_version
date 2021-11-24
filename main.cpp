#include <iostream>
#include "version.hh"

using namespace my_app;

int main()
{
    std::cout << "building hash   : " << Version::GIT_HASH << std::endl;
    std::cout << "building branch : " << Version::GIT_BRANCH << std::endl;
    std::cout << "building date   : " << Version::GIT_DATE << std::endl;
    return 0;
}