#pragma once
#include <string>
#include <stdexcept>
#include "checkML.h"
using namespace std;


class PacManError : public logic_error
{
public:
	PacManError(const string& m) : logic_error(m) {};
};

