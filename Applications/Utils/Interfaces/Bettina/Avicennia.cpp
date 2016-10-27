/*
 * avicennia.cpp
 *
 *  Created on: Aug 29, 2016
 *      Author: waltherm
 */

#include <Avicennia.h>
#include "NearestNodeTable.h"

Avicennia::Avicennia(GeoLib::Point const &point, Land &aLand, double age) :
		Tree(point, aLand, getIniStemHeight(), getIniCrownHeight(),
				getIniRootDepth(), getIniCrownRadius(),
				getIniFineRootPermeability(), getIniMinimumLeafWaterPotential(),
				getIniXylemConductivity(), getIniHalfMaxHeightGrowthWeight(),
				getIniMaintenanceFactor(), age) {
//	(GeoLib::Point const &point, unsigned int id, Land const &aLand,
//	double stemHeight, double crownHeight, double rootDepth,
//	double crownRadius, double fineRootPermeability,
//	double minimumLeafWaterPotential, double xylemConductivity,
//	double halfMaxHeightGrowthWeight, double maintanceFactor)

// TODO Auto-generated constructor stub

	_crownRadiusNodeTable = new NearestNodeTable(this, NearestNodeTableClass::Crown);
	_rootRadiusNodeTable = new NearestNodeTable(this, NearestNodeTableClass::Root);
	_vicinityNodeTable = new NearestNodeTable(this, NearestNodeTableClass::Vicinity);

}

Avicennia::~Avicennia() {
	// TODO Auto-generated destructor stub
}


