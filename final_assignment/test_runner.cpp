//
// Created by human on 11.11.2018.
//

//
// Created by human on 10.11.2018.
//

#include "test_runner.h"

#include <string>
#include <iostream>
#include <sstream>

using namespace std;


TestRunner::~TestRunner()
{
    if (fail_count > 0)
    {
        cerr << fail_count << " unit tests failed. Terminate" << endl;
        exit(1);
    }
}

void Assert(bool b, const string &hint)
{
    AssertEqual(b, true, hint);
}