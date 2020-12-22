#pragma once
#include <exception>
#include <string>
using namespace std;


class PacManError : public logic_error
{
public:
	PacManError(const string& m) : logic_error(m) {};

};

