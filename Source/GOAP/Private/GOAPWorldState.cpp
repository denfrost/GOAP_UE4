/**
	GOAP NPC: Goal-Oriented Action Planning for Non-Player Characters.

	Publishers/Authors:
		-	Diego Romero-Hombrebueno Santos.
		-	Mario Sanchez Blanco.
		-	Jose Manuel Sierra Ramos.

	Published on 2020.
 */
#include "GOAPWorldState.h"

GOAPWorldState::GOAPWorldState() {}

GOAPWorldState::~GOAPWorldState() {}

GOAPWorldState::GOAPWorldState(const std::map<FString, bool>& a) 
{
	atoms = a;
}

bool GOAPWorldState::operator==(GOAPWorldState  w) 
{
	return atoms.size() == w.getAtoms().size() && std::equal(atoms.begin(), atoms.end(), w.getAtoms().begin());
}

bool GOAPWorldState::isIncluded(GOAPWorldState w) 
{
	for (auto requirement : w.getAtoms()) 
	{
		auto it = atoms.find(requirement.first);
		if (it != atoms.end()) 
		{
			if (it->second != requirement.second)
				return false;
		}
		else return false;
	}
	return true;

}

const std::map<FString, bool>& GOAPWorldState::getAtoms() 
{
	return atoms;
}

void GOAPWorldState::setAtoms(const std::map<FString, bool>& a) 
{
	atoms = a;
}

void GOAPWorldState::addAtom(FString name, bool value) 
{
	atoms[name] = value;
}

void GOAPWorldState::cleanAtoms() 
{
	atoms.clear();
}

void GOAPWorldState::joinWorldState(GOAPWorldState w) 
{
	for (auto atom : w.getAtoms())
	{
		atoms[atom.first] = atom.second;
	}
}

bool GOAPWorldState::isEmpty() 
{
	return atoms.size() == 0;
}