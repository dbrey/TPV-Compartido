#pragma once
#include "checkML.h"
#include <string>
#include <stdexcept>
using namespace std;


class PacManError : public logic_error
{
public:
	PacManError(const string& m) : logic_error(m) {};
};

