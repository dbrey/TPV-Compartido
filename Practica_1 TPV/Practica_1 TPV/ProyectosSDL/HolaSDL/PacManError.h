#pragma once
#include <string>
#include <stdexcept>
#include "checkML.h"
using namespace std;


class PacManError : public logic_error
{
public:
	PacManError(string const m) : logic_error("Error:" + m) {};
};

