/**
 * \file   OGSNamespaceDoc.h
 * \author Karsten Rink
 * \date   2014-02-12
 * \brief  Documentation of namespaces.
 *
 * \copyright
 * Copyright (c) 2013, OpenGeoSys Community (http://www.opengeosys.org)
 *            Distributed under a Modified BSD License.
 *              See accompanying file LICENSE.txt or
 *              http://www.opengeosys.org/project/license
 *
 */

#error Documentation only

#ifndef OGSNAMESPACEDOC_H_
#define OGSNAMESPACEDOC_H_

namespace AssemblerLib {
	namespace detail {
	}
}

/**
 * @namespace BaseLib
 * Basic algorithms and helper functions provided for all other libraries.
 */
namespace BaseLib {
}

/**
 * @namespace FileIO
 * Contains the interfaces for all file types that can be read and/or written using
 * OpenGeoSys.
 *
 * \sa GMSH
 * \sa Legacy
 */
namespace FileIO {

	/**
	 * @namespace FileIO::GMSH
	 * Sub-namespace containing all functionality needed for reading and writing GMSH files.
	 *
	 * \sa GMSHInterface
	 */
	namespace GMSH {
	}
	
	/**
	 * @namespace FileIO::Legacy
	 * Includes the interfaces to OGS legacy file formats (OGS-5 and below).
	 */
	namespace Legacy {
	}
}

/**
 * @namespace FiniteElement
 */
namespace FiniteElement {
}

/**
 * @namespace GeoLib
 * Contains all functionality concerned with defining and obtaining information
 * about geometric objects such as points, (poly-)lines, polygones, surfaces, etc.
 * Also includes additional algorithms for modifying such data.
 */ 
namespace GeoLib {
}

/**
 * @namespace MathLib
 * Contains all mathematical functionality used in OpenGeoSys, from defining a vector
 * or calculating a norm to integration schemes and matrix preconditioners.
 *
 * \sa detail
 */ 
namespace MathLib {
	/**
	 * @namespace MathLib::detail
	 */
	namespace detail {
	}
}

/**
 * @namespace MeshLib
 * Contains all functionality concerned with defining and obtaining information
 * about meshes and their components (nodes, elements). Also includes additional
 * algorithms for generating and modifying meshes and elements.
 *
 * \sa MeshGenerator
 */ 
namespace MeshLib {
	/**
	 * @namespace MeshLib::MeshGenerator
	 * Functionality for generating meshing.
	 */
	namespace MeshGenerator {
	}
}

/**
 * @namespace NumLib
 * The numerical algorithms used in OpenGeoSys
 */
namespace NumLib {
	/**
	 * @namespace NumLib::detail
	 */	
	namespace detail {
	}
}



#endif /* OGSNAMESPACEDOC_H_ */
