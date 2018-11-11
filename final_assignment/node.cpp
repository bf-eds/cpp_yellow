//
// Created by human on 10.11.2018.
//

#include "node.h"


bool DateComparisonNode::Evaluate(const Date &date, const string &event)
{
    switch (cmp_)
    {
        case Comparison::Less:
            return date < date_;
        case Comparison::LessOrEqual:
            return date <= date_;
        case Comparison::Greater:
            return date > date_;
        case Comparison::GreaterOrEqual:
            return date >= date_;
        case Comparison::Equal:
            return date == date_;
        case Comparison::NotEqual:
            return date != date_;
        default:
            return true;
    }
}

bool LogicalOperationNode::Evaluate(const Date &date, const string &event)
{
    switch (op_)
    {
        case LogicalOperation::And :
            return left_->Evaluate(date, event) && right_->Evaluate(date, event);
        case LogicalOperation::Or :
            return left_->Evaluate(date, event) || right_->Evaluate(date, event);
        default:
            return true;
    }
}

bool EventComparisonNode::Evaluate(const Date &date, const string &event)
{
    switch (cmp_)
    {
        case Comparison::Less:
            return event < event_;
        case Comparison::LessOrEqual:
            return event <= event_;
        case Comparison::Greater:
            return event > event_;
        case Comparison::GreaterOrEqual:
            return event >= event_;
        case Comparison::Equal:
            return event == event_;
        case Comparison::NotEqual:
            return event != event_;
        default:
            return true;
    }
}

bool Node::Evaluate(const Date &date, const string &event)
{
    return true;
}
