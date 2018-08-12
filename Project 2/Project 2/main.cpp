//
//  main.cpp
//  Project 2
//
//  Created by Brian Yao on 7/17/18.
//  Copyright © 2018 Brian Yao. All rights reserved.
//

/*
#include <iostream>
#include "CoachingStaff.h"
#include <cassert>

using namespace std;

int main()
{
 
}

*/

/*
#include "CoachingStaff.h"
#include <type_traits>
#define CHECKTYPE(f, t) { auto p = (t)(f); (void)p; }
static_assert(std::is_default_constructible<CoachingStaff>::value,"Map must be default-constructible.");
static_assert(std::is_copy_constructible<CoachingStaff>::value,"Map must be copy-constructible.");
void ThisFunctionWillNeverBeCalled()
{
    CHECKTYPE(&CoachingStaff::operator=,CoachingStaff&(CoachingStaff::*)(const CoachingStaff&));
    CHECKTYPE(&CoachingStaff::noCoaches, bool(CoachingStaff::*)() const);
    CHECKTYPE(&CoachingStaff::numberOfCoaches, int(CoachingStaff::*)() const);
    CHECKTYPE(&CoachingStaff::hireCoach, bool (CoachingStaff::*)(const std::string&, const std::string&, const IType&));
    CHECKTYPE(&CoachingStaff::renameCoach, bool(CoachingStaff::*)(const std::string&, const std::string&,const IType&));
    CHECKTYPE(&CoachingStaff::hireOrRename, bool(CoachingStaff::*)(const std::string&, const std::string&,const IType&));
    CHECKTYPE(&CoachingStaff::fireCoach, bool (CoachingStaff::*)(const std::string&, const std::string&));
    CHECKTYPE(&CoachingStaff::coachOnStaff, bool(CoachingStaff::*)(const std::string&, const std::string&)const);
    CHECKTYPE(&CoachingStaff::findCoach, bool (CoachingStaff::*)(const std::string&, const std::string&, IType&) const);
    CHECKTYPE(&CoachingStaff::whichCoach, bool(CoachingStaff::*)(int, const std::string&, const std::string&, IType&)const);
    CHECKTYPE(&CoachingStaff::changeStaff, void(CoachingStaff::*)(CoachingStaff&));
    CHECKTYPE(mergeStaffs, bool (*)(const CoachingStaff&, const CoachingStaff&, CoachingStaff&));
    CHECKTYPE(searchStaff, void (*)(const std::string&,const std::string&, const CoachingStaff&, CoachingStaff&));
}
int main() {}
 
 */

/*
#include "CoachingStaff.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;
void test() {
    CoachingStaff wgym;
    assert(wgym.hireCoach("Valerie", "Kondos", "vkondos@athletics.ucla.edu"));
    assert(wgym.hireCoach("Chris", "Waller", "cwaller@athletics.ucla.edu"));
    assert(wgym.numberOfCoaches() == 2);
    string first, last, e;
    assert(wgym.whichCoach(0, first, last, e) && e == "vkondos@athletics.ucla.edu");
    assert(wgym.whichCoach(1,first, last, e) && (first == "Chris" && e == "cwaller@athletics.ucla.edu"));
    return; }
int main() {
    test();
    cout << "Passed all tests" << endl;
    return 0;
}
 */

#include "CoachingStaff.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;
void test() {
    CoachingStaff mwp;
    assert(mwp.hireCoach("Adam", "Wright", 41));
    assert(mwp.hireCoach("Jason", "Falitz", 37));
    assert(mwp.numberOfCoaches() == 2);
    string first, last;
    int a;
    assert(mwp.whichCoach(0, first, last, a) && a == 37);
    assert(mwp.whichCoach(1, first, last, a) && (first == "Adam" && a == 41));
    return; }
    int main() {
        test();
        cout << "Passed all tests" << endl;
        return 0;
    };


