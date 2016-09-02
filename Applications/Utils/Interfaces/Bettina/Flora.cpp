/*
 * flora.cpp
 *
 *  Created on: Aug 30, 2016
 *      Author: waltherm
 */

#include <Flora.h>
#include <time.h>

Flora::Flora(Land &aLand) :
		_thisLand(aLand) {
	// TODO Auto-generated constructor stub
	initialPopulate();
}

Flora::~Flora() {
	// TODO Auto-generated destructor stub
}

void Flora::initialPopulate() {

	std::srand (std::time(NULL));

//	for (std::size_t i(0); i<200; i++)
//	{
//		double const x = std::rand() % 600;
//		double const y = std::rand() % 300;
//		double const z = 0;
//
//		GeoLib::Point const newPoint(x, y, z);
//		_aliveTrees.push_back(new Avicennia(newPoint, _aliveTrees.size()-1, _thisLand));
//	}

	GeoLib::Point const newPoint(31, 31, 0);
	_aliveTrees.push_back(
			new Avicennia(newPoint, _aliveTrees.size()-1, _thisLand));

	GeoLib::Point const newPointb(36, 36, 0);
	_aliveTrees.push_back(
			new Avicennia(newPointb, _aliveTrees.size()-1, _thisLand));

}

void Flora::recruitment() {
	for (auto &aliveTree : _aliveTrees) {
		aliveTree->recruitment();
	}
}

void Flora::competition() {

	//above ground competition
	_thisLand.resetAboveGroundCompetition();

	for (auto &aliveTree : _aliveTrees) {
		aliveTree->checkAboveGroundCompetition(_aliveTrees);
	}

	for (auto &aliveTree : _aliveTrees) {
		aliveTree->calcAboveGroundCompetition();
	}

	//below ground competition
	_thisLand.resetBelowGroundCompetition();

	for (auto &aliveTree : _aliveTrees) {
		aliveTree->checkBelowGroundCompetition();
	}

	_thisLand.invertBelowGroundCompetition();

	for (auto &aliveTree : _aliveTrees) {
		aliveTree->calcBelowGroundCompetition();
	}
}

void Flora::grow() {
	for (auto &aliveTree : _aliveTrees) {
		aliveTree->grow();
	}
}

void Flora::die() {

	for (auto & aliveTree : _aliveTrees) {
		if (aliveTree->getDeathFlag()) {
			_deadTrees.push_back(aliveTree); //copy aliveTrees with deathflag to deadTrees
			aliveTree = nullptr; //write nullpointer to aliveTree with deathflag
		}
	}
	_aliveTrees.erase( //remove element from vector from given begin (nullptr begin) to end (nullptr end)
			std::remove(_aliveTrees.begin(), _aliveTrees.end(), nullptr), //sort all nullptr elements to end of vector and return begin of nullptr elements
			_aliveTrees.end());

}

bool Flora::checkForActivePopulation() {
	if (_aliveTrees.empty()) {
		INFO("No alive trees left, exiting.");
		return false;
	} else
		return true;
}
