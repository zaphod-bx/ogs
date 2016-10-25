/*
 * rhizophora.cpp
 *
 *  Created on: Aug 29, 2016
 *      Author: waltherm
 */

#include <Rhizophora.h>
#include "NearestNodeTable.h"

Rhizophora::Rhizophora(GeoLib::Point const &point, Land &aLand, double age) :
		Tree(point, aLand, getIniStemHeight(), getIniCrownHeight(),
				getIniRootDepth(), getIniCrownRadius(),
				getIniFineRootPermeability(), getIniMinimumLeafWaterPotential(),
				getIniXylemConductivity(), getIniHalfMaxHeightGrowthWeight(),
				getIniMaintenanceFactor(), this, age) {
// TODO Auto-generated constructor stub
}

Rhizophora::~Rhizophora() {
	// TODO Auto-generated destructor stub
}

