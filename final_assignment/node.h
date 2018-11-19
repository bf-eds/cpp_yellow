//
// Created by human on 10.11.2018.
//

#pragma once

#include "date.h"
#include <memory>
enum class Comparison
{
    Less, LessOrEqual, Greater, GreaterOrEqual, Equal, NotEqual,
};

enum class LogicalOperation
{
    And, Or,
};

class Node
{
public:
    virtual bool Evaluate(const Date &date, const string &event) const = 0;
};

class EmptyNode : public Node
{
    bool Evaluate(const Date &date, const string &event) const override;
};

class EventComparisonNode : public Node
{
public:
    bool Evaluate(const Date &date, const string &event) const override;
public:
    EventComparisonNode(const Comparison cmp, const string &event) : cmp_(cmp), event_(event)
    {
    }

private:
    const Comparison cmp_;
    const string event_;
};

class DateComparisonNode : public Node
{
public:
    bool Evaluate(const Date &date, const string &event) const override;
public:
    DateComparisonNode(const Comparison cmp, const Date &date) : cmp_(cmp), date_(date)
    {
    }

private:
    const Comparison cmp_;
    const Date date_;
};

class LogicalOperationNode : public Node
{
public:
    bool Evaluate(const Date &date, const string &event) const override;
public:
    LogicalOperationNode(const LogicalOperation op, const shared_ptr<Node> &left, const shared_ptr<Node> &right) : op_(
            op), left_(left), right_(right)
    {
    }

private:
    const LogicalOperation op_;
    const shared_ptr<Node> left_;
    const shared_ptr<Node> right_;
};