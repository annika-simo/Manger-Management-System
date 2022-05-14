#include "adoptable.h"
#include <string>

/*
 * hasRestrictions
 *
 * returns false if the adoptable is not a turtle
 *
 * input: restrictions (string)
 * output: bool
 */

bool Adoptable::hasRestrictions(std::string &restrictions) { return false; }

/*
 * hasRestrictions
 *
 * returns true if the adoptable is  a turtle
 *
 * input: restrictions as a string
 * output: bool
 */

bool Turtle::hasRestrictions(std::string& restrictions) {
    restrictions = "Adopter must be at least 21 years old.";
    return true;
}

/*
 * getType
 *
 * gets the adoptable type
 *
 * input: none
 * output: type as AdoptableType
 */

AdoptableType Adoptable::getType() const {
    return type;
}

/*
 * hasShot
 *
 * returns true is the adoptable has shots
 *
 * input: none
 * output: bool
 */

bool Adoptable::hasShot() const {
    return has_shots;
}

/*
 * getFirstName
 *
 * gets the adoptable's first name
 *
 * input: none
 * output: first name as string
 */

std::string Adoptable::getFirstName() const {
    return first_name;
}

/*
 * getLastName
 *
 * gets the adoptable's last name
 *
 * input: none
 * output: last name as string
 */

std::string Adoptable::getLastName() const {
    return last_name;
}

/*
 * print
 *
 * formats and prints the adoptable's information
 *
 * input: none
 * output: none
 */

void Adoptable::print() {
  std::string restrictions{""};
  std::cout << "First name: " << first_name << "\n";
  std::cout << "Last name: " << last_name << "\n";
  std::cout << "Has Shots?: " << (has_shots ? "Yes" : "No") << "\n";
  std::cout << "Adoptable Since: " << adoptable_since << "\n";
  if (hasRestrictions(restrictions)) {
    std::cout << "Restrictions: " << restrictions << "\n";
  }
}