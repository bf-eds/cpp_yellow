//
// Created by human on 05.11.2018.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
public:
    Person(const string &type_, const string &name_) : type_(type_), name_(name_)
    {
    }

    const string &getName_() const
    {
        return name_;
    }

    virtual void Walk(const string &destination) const
    {
        cout << getPrompt() << " walks to: " << destination << endl;
    }

    const string &getType_() const
    {
        return type_;
    }

    const string getPrompt() const
    {
        return getType_() + ": " + getName_();
    }

private:
    const string type_;
    const string name_;
};

class Student : public Person
{
public:
    Student(const string &name_, const string &favouriteSong_, const string &type_ = "Student") : Person(type_, name_),
                                                                                                  favouriteSong_(
                                                                                                          favouriteSong_)
    {
    }

    void Learn() const
    {
        cout << getPrompt() << " learns" << endl;
    }

    void Walk(const string &destination) const override
    {
        Person::Walk(destination);
        SingSong();
    }

    void SingSong() const
    {
        cout << getPrompt() << " sings a song: " << favouriteSong_ << endl;
    }

public:
    const string favouriteSong_;
};


class Teacher : public Person
{
public:
    Teacher(const string &name_, const string &subject_, const string &type_ = "Teacher") : Person(type_, name_),
                                                                                            subject_(subject_)
    {
    }

    void Teach() const
    {
        cout << getPrompt() << " teaches: " << subject_ << endl;
    }

public:
    const string subject_;
};


class Policeman : public Person
{
public:
    Policeman(const string &name_, const string &type_ = "Policeman") : Person(type_, name_)
    {
    }

    void Check(const Person &p) const
    {
        cout << getPrompt() << " checks " << p.getType_() << ". " << p.getType_() << "'s name is: " << p.getName_()
             << endl;
    }
};


void VisitPlaces(const Person &t, const vector<string> &places)
{
    for (auto &p : places)
    {
        t.Walk(p);
    }
}

int main()
{
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
