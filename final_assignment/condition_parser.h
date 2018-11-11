//
// Created by human on 10.11.2018.
//

#pragma once

#include "node.h"

#include <memory>
#include <iostream>

using namespace std;

shared_ptr<Node> ParseCondition(istream &is);

void TestParseCondition();
