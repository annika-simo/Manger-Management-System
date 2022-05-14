
#include "mms.h"
#include <string>
#include <vector>

/*
 * inventorySize
 *
 * return the size of the inventory
 *
 * input: none
 * output: inventory size as integer
 */

int MMS::inventorySize() {
	return adoptables.size();
}

/*
 * inventorySizeByShots
 *
 * return the number of adoptables in the inventory with or without shots
 *
 * input: has_shots as desired as bool
 * output: inventory size as integer
 */

int MMS::inventorySizeByShots(bool has_shots) const {
	int k{0};
	if (has_shots) {
		for (auto &adoptable : adoptables) {
			if (adoptable->hasShot()) {
				k += 1;
			}
		}
	}

	else {
		for (auto &adoptable : adoptables) {
			if (!adoptable->hasShot()) {
				k += 1;
			}
		}
	}

	return k;
}

/*
 * inventorySizeByType
 *
 * return the number of adoptables in the inventory by type
 *
 * input: desired type as AdoptableType
 * output: inventory size as integer
 */

int MMS::inventorySizeByType(AdoptableType type) const {
	int k{0};
	if (type == ALL) {
		return adoptables.size();
	}

	for (auto &adoptable : adoptables) {
		if (adoptable->getType() == type) {
			k += 1;
		}
	}

	return k;
}

/*
 * inventorySizeByRestrictions
 *
 * return the number of adoptables in the inventory with or without restrictions
 *
 * input: has_restrictions as desired as bool
 * output: inventory size as integer
 */

int MMS::inventorySizeByRestrictions(bool has_restrictions) const {
	int k{0};
	std::string restrictions{ "" };
	if (has_restrictions) {
		for (auto &adoptable : adoptables) {
			if (adoptable->hasRestrictions(restrictions) == true) {
				k += 1;
			}
		}
	}
	else {
		for (auto &adoptable : adoptables) {
			if (adoptable->hasRestrictions(restrictions) == false) {
				k += 1;
			}
		}
	}

	return k;
}

/*
 * animalsInInventory
 *
 * return the first and last names of each animal
 *
 * input: has_shots
 * output: vector of the first and last names of each animal
 */

std::vector<std::string> MMS::animalsInInventory() const {
	std::vector<std::string> inventory;
	std::string animal;
	for (auto &adoptable : adoptables) {
		animal = adoptable->getFirstName() + " " + adoptable->getLastName();
		inventory.push_back(animal);
	}

	return inventory;
}