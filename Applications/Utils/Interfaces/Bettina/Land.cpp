/*
 * land.cpp
 *
 *  Created on: Aug 29, 2016
 *      Author: waltherm
 */

#include <iostream>
#include <boost/optional.hpp>
#include <numeric>

#include <Land.h>

#include "MeshLib/IO/readMeshFromFile.h"

#include "MeshGeoToolsLib/MeshNodeSearcher.h"

#include "Flora.h"

Land::Land(std::string const &fileName,
		std::string const &salinityPropertyString,
		std::string const &aboveGroundCompetitionString,
		std::string const &belowGroundCompetitionString) :
		_salinityPropertyString(salinityPropertyString), _aboveGroundCompetitionString(
				aboveGroundCompetitionString), _belowGroundCompetitionString(
				belowGroundCompetitionString), _subsurface(
				MeshLib::IO::readMeshFromFile(fileName)), _searchLength(
				_subsurface->getMinEdgeLength()), _meshSearcher(*_subsurface,
				_searchLength) {

	//readMesh(fileName);
	checkPropertyExists(_salinityPropertyString);
	checkPropertyExists(_aboveGroundCompetitionString);
	checkPropertyExists(_belowGroundCompetitionString);

	initializeAboveGroundCompetition();
}

Land::~Land() {
	delete _subsurface;
}

void Land::readMesh(std::string const &fileName) {
	_subsurface = MeshLib::IO::readMeshFromFile(fileName);
}

void Land::initializeAboveGroundCompetition() {

	_aboveGroundCompetition.resize(_subsurface->getNumberOfNodes());
	resetAboveGroundCompetition();

	auto* const pv = _subsurface->getProperties().createNewPropertyVector<
			std::size_t>("treePointer", MeshLib::MeshItemType::Node, 1);
	pv->resize(_subsurface->getNumberOfNodes());
	std::fill(pv->begin(), pv->end(), -1);

}

void Land::checkPropertyExists(std::string propertyString) const {
	bool propCheck(false);
	for (auto &propName : _subsurface->getProperties().getPropertyVectorNames()) {
		if (propName == propertyString)
			propCheck = true;
	}
	if (!propCheck) {
		ERR("There is no property named '%s' in the mesh. Exiting.",
				propertyString.c_str());
		std::abort();
	}
}

double Land::getSalinityAtNodeID(std::size_t nodeID) const {
	return getPropertyAtNodeID<double>(nodeID, _salinityPropertyString);
}

Tree* Land::getAboveGroundCompetitionAtNodeID(std::size_t nodeID) const {
	return _aboveGroundCompetition[nodeID];
}

double Land::getBelowGroundCompetitionAtNodeID(std::size_t nodeID) const {
	return getPropertyAtNodeID<double>(nodeID, _belowGroundCompetitionString);
}

void Land::resetAboveGroundCompetition() {
	resetPropertyValues(-1.0, _aboveGroundCompetitionString);
	std::fill(_aboveGroundCompetition.begin(), _aboveGroundCompetition.end(),
			nullptr);
}

void Land::resetBelowGroundCompetition() {
	resetPropertyValues(0.0, _belowGroundCompetitionString);
}

void Land::setAboveGroundCompetition(Tree* aTree, std::size_t nodeID) {
	_aboveGroundCompetition[nodeID] = aTree;
}

void Land::setAboveGroundCompetition(double value, std::size_t nodeID) {
	setPropertyAtNodeID(value, nodeID, _aboveGroundCompetitionString);
}

void Land::setBelowGroundCompetition(double value, std::size_t nodeID) {
	setPropertyAtNodeID(value, nodeID, _belowGroundCompetitionString);
}

void Land::incrementBelowGroundCompetition(std::size_t nodeID) {
	setBelowGroundCompetition(getBelowGroundCompetitionAtNodeID(nodeID) + 1,
			nodeID);
}

void Land::invertBelowGroundCompetition() {
	// calc inverse if belowGroundCompetition > 1

	MeshLib::PropertyVector<double>* property(
			_subsurface->getProperties().getPropertyVector<double>(
					_belowGroundCompetitionString));

	if (property == nullptr) {
		ERR("There is no property named '%s' in the mesh. Exiting.",
				_belowGroundCompetitionString.c_str());
		std::abort();
	}

	for (auto & v : *property) {
		if (v > 1)
			v = 1 / v;
	}

}

std::vector<std::size_t> Land::findNodesInRadius(double radius,
		GeoLib::Point const &position) {
	double searchLength(radius);
	if (radius == -1.0)
		//searchLength = _subsurface->getMinEdgeLength();	//this may fail, if tree is exactly in middle of element or in big element
		searchLength = _subsurface->getMaxEdgeLength() * 100;

	//MeshGeoToolsLib::SearchLength const searchLength(searchLengthTemp);
	_meshSearcher.setSearchLength(searchLength);
	std::vector<std::size_t> idVector(_meshSearcher.getMeshNodeIDs(position));
	return idVector;
}
