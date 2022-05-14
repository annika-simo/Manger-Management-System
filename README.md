# Manger-Management-System
CS1021 Lab 12

## Introduction
spca.png	The number of companion animals that transit the shelter system every year is staggering. As of 2019, [6.3 million animals enter pet shelters every year](https://www.aspca.org/helping-people-pets/shelter-intake-and-surrender/pet-statistics). Of those, [4.1 million are adopted](https://www.aspca.org/helping-people-pets/shelter-intake-and-surrender/pet-statistics). As you can imagine, most of the pets that are rescued and adopted are dogs and cats. That said, there are a significant number of [turtles](https://www.tortoise.com/turtle-rescue-centers-in-usa.html) who make their way through [shelters](https://www.cincyherps.com/), too. For a shelter, accepting and documenting rescues alone is a daunting task. Add to that the shelter's work to match rescues with good homes and you have the recipe for a paperwork disaster.

That's where the Manger Management System (*MMS*) comes in! The software that you write in this lab will help shelters around the country manage their inventory of rescued dogs, cats and [turtles](https://i-question-this.github.io/turtles_all_the_way_down/). The shelters track information about every *adoptable*, an animal that is up for adoption. They track

1. The first and last name of the adoptable;
2. The weight (in pounds) of the adoptable;
3. Whether the adoptable has had their shots;
4. The restrictions (if there are any) that a person must meet before being allowed to adopt;
5. The date that the adoptable entered the shelter; and
6. The type of the adoptable.

*MMS* handles three types of adoptables -- dogs, cats and turtles. Dogs and cats can be adopted by anyone. In other words, there are no restrictions on who can adopt a dog or a cat. Turtle adopters, on the other hand, must be at least 21 years old -- turtles require [maturity](https://en.wikipedia.org/wiki/Teenage_Mutant_Ninja_Turtles)!

In this lab, you are going to write the [MVP](https://en.wikipedia.org/wiki/Minimum_viable_product) of *MMS*. This version of *MMS* will have the ability to:

1. Track adoptables (and their associated information) in the shelter;
2. Report the number of each type of adoptable in the shelter;
3. Report the total number of adoptables in each shelter;
4. Report the total number of adoptables in each shelter that have adoption restrictions; and
5. Report the total number of adoptables in each shelter that have had their shots.

In order to build such a system, you must implement several classes. First, you will implement classes for each of the types of adoptables. The adoptables will have member variables that correspond to each of the attributes given above. The adoptables will have getter methods for the adoptable's first name (`getFirstName`), last name (`getLastName`), type (`getType`), whether they are vaccinated (`hasShot`) and whether they have adoption restrictions (`hasRestrictions`).

Second, you will implement the *MMS* class. For this class you will implement methods for counting the shelter's inventory according to various parameters.

Take charge of your code for this lab -- [don't let the tail wag the dog.](https://en.wikipedia.org/wiki/Wag_the_Dog)

## Program Design Task
As my dad always said, “[Slow and steady wins the race](https://read.gov/aesop/025.html).” Before you start coding, please write or draw the inheritance hierarchy for adoptables.

## Program Design Requirements
Remember that there are three different types of adoptables. Your inheritance hierarchy must meet the following criteria:

1. Each of the adoptables must be a member of the hierarchy.
2. The hierarchy must be only two levels deep.
3. Entities in the hierarchy must be labeled with their attributes -- place the attributes in the most general place in the hierarchy to reduce the amount of code that you have to write!

## Programming Task
Your programming task is to implement a class to hold adoptables (and derived classes for cats, dogs and turtles) and a class for the *MMS*.

You will name your adoptables base class `Adoptable`. You will name the derived classes `Dog`, `Cat` and `Turtle`.

The adoptables have the following *private* named attributes:

- `weight`: a `double` that holds the adoptable's weight;
- `has_shots`: a `bool` that holds the adoptable's vaccination status;
- `first_name`: a `std::string` that holds the adoptable's first name;
- `last_name`: a `std::string` that holds the adoptable's last name;
- `adoptable_since`: a `Date` that holds the date when the adoptable entered the shelter;
- `type`: an `AdoptableType` that holds the type of the adoptable.

Declare these classes with these attributes in the file `adoptable.h`.

A `Date` is a `class` with three *public* member variables:

`day` (an `int`)
`month` (an `int`)
`year` (an `int`)

Declare this class in the file `date.h`.

An `AdoptableType` is an enumerated value with only four possible values: `ALL`, `TURTLE`, `CAT`, `DOG`. Declare this enumerated value in the file `adoptable.h`.

Each adoptable must have a public non-default constructor that takes the following parameters in the following order:

1. `weight`: a `double`
2. `has_shots`: a `bool`
3. `adoptable_since`: a `Date`
4. `first_name`: a `std::string`
5. `last_name`: a `std::string`

Each adoptable must have the following methods:

| Name	| Parameters |	Return Value |	Semantics |
| --- | --- | --- | --- |
| `hasRestrictions`	| 1. (out) `restrictions`: a `std::string` that the function populates with the adoption restrictions for this adoptable. | A `bool`. `true` if there are restrictions; `false`, otherwise.	| Only the turtle has adoption restrictions. When this method is invoked on an instance of a Turtle, restrictions is set to "Adopter must be at least 21 years old." and the function returns true. Otherwise, the function returns false and the value of restrictions is unchanged. |
| `getType`	| None	| An `AdoptableType`. |	If this method is invoked on an instance of a `Dog` adoptable, then the return value is `DOG`. If this method is invoked on an instance of a `Cat` adoptable, then the return value is `CAT`. If this method is invoked on an instance of a `Turtle` adoptable, then the return value is `TURTLE`. |
| `hasShot`	| None	| A `bool`.	| If the adoptable has had their shots, the function returns `true`. Otherwise, the function returns `false`. |
| `getFirstName`	| None	| A `std::string`. |	The function returns the first name of the adoptable. |
| `getLastName`	| None	| A `std::string`.	| The function returns the last name of the adoptable. |

Implement these functions in the file `adoptable.cpp`.

You are provided with an implementation of the following methods in the `Adoptable` class in the skeleton code with this lab:

| Name	| Parameters |	Return Value |	Semantics |
| --- | --- | --- | --- |
| `print`	| None	| None	| This function will print out a nicely formatted description of the instance of the adoptable upon which it is invoked. This may be useful for your debugging. |

The *MMS* class does not require that you add any additional member variables. The *MMS* class code provided with the skeleton for this lab defines the following member variable:

1. `adoptables`: a `std::vector` of `std::unique_ptrs` to the adoptables being tracked. Use this member variable in order to implement the functions specified below.

The *MMS* class provided with the skeleton for this lab defines the following methods:

| Name	| Parameters |	Return Value |	Semantics |
| --- | --- | --- | --- |
| `addAdoptable`	| A `std::unique_ptr` to an adoptable.	| None	| The adoptable passed as a parameter is added to the `adoptables` member variable. You will *not* need to call this function. |
| `print`	| None	| None	| This method will invoke the `print` method on each of the adoptables being tracked in the `adoptables` member variable. This function may be useful for debugging. |

You are required to implement the following methods for the *MMS* class:

| Name	| Parameters |	Return Value |	Semantics |
| --- | --- | --- | --- |
| `inventorySize`	| None	| `int`	| This function returns the total number of adoptables in the *MMS*. In other words, it will return the size of the `adoptables` member variable `std::vector`. |
| `inventorySizeByShots`	| 1. `has_shots`: a `bool` that defaults to `true`. | `int`	| If `has_shots` is `true`, this function returns the number of adoptables in the shelter that have had their shots. If `has_shots` is `false`, this function returns the number of adoptables in the shelter that have not had their shots. |
| `inventorySizeByType`	| 1. `type`: an `AdoptableType` that defaults to `ALL`. | `int`	| If type is `ALL`, this function returns the total number of adoptables in the *MMS*. For any other value of type, this function returns the number of adoptables in the *MMS* with that type. |
| `inventorySizeByRestrictions`	| 1. `has_restrictions`: a `bool` that defaults to `true`. | `int`	| If `has_restrictions` is `true`, this function returns the number of adoptables in the *MMS* that have adoption restrictions. If `has_restrictions` is `false`, this function returns the number of adoptables in the *MMS* that do not have adoption restrictions. |
| `animalsInInventory`	| None	| `std::vector<std::string>`	| This function will return a `std::vector` of `std::string`s -- one for each adoptable in the *MMS*. The contents of the `std::strings` in the `std::vector` will be the names of the adoptables -- their first and last names separated by a space. |

Implement these functions in the file `mms.cpp`.

All methods that you write must be commented. You must comment the methods at their declaration (i.e., in the .h files) according to the following specification:

```cpp
/*
 * <function name>
 *
 * <short description of what the function does>
 *
 * input: <short description of all input parameters>
 * output: <short description of all output parameters
 *          and the return value>
 */
 ``` 
 
In this lab, you will not write a main function. A main function has already been provided for you in the skeleton for this lab. The main file contains unit tests. When those unit tests pass, you can feel confident that your implementation is correct.

## Programming Requirements
If you are a Windows user, start with the skeleton .zip in this repository. You must use this skeleton to successfully complete this lab.

## Critical Thinking Task
There is no Critical Thinking Task for this lab.

## Deliverables
1. The written or drawn inheritance hierarchy used in the *MMS* application in PDF format (named `design.pdf`).
2. The C++ source code for the *MMS* application (`date.h`, `mms.h`, `mms.cpp`, `adoptable.h`, `adoptable.cpp`).

## Related Learning Objectives
1. Declaring, defining and implementing classes (including member variables and [virtual] methods).
2. Declaring, defining and accessing members of simple data structures (classes).
