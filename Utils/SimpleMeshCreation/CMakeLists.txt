IF(TARGET VtkVis)

	INCLUDE_DIRECTORIES(
		${CMAKE_SOURCE_DIR}
		${CMAKE_SOURCE_DIR}/BaseLib
		${CMAKE_SOURCE_DIR}/FileIO
		${CMAKE_SOURCE_DIR}/FileIO/Legacy
		${CMAKE_SOURCE_DIR}/GeoLib
		${CMAKE_SOURCE_DIR}/MathLib
		${CMAKE_SOURCE_DIR}/MeshLib
		${CMAKE_SOURCE_DIR}/Gui/VtkVis
	)

	ADD_EXECUTABLE( generateStructuredQuadMesh generateStructuredQuadMesh.cpp )
	SET_TARGET_PROPERTIES( generateStructuredQuadMesh PROPERTIES FOLDER Utils)
	TARGET_LINK_LIBRARIES( generateStructuredQuadMesh
		MeshLib
		FileIO
		GeoLib
		MathLib
		VtkVis
		${VTK_LIBRARIES}
		${QT_LIBRARIES}
	)

	ADD_EXECUTABLE(  createMeshElemPropertiesFromASCRaster createMeshElemPropertiesFromASCRaster.cpp )
	SET_TARGET_PROPERTIES( createMeshElemPropertiesFromASCRaster PROPERTIES FOLDER Utils)
	TARGET_LINK_LIBRARIES( createMeshElemPropertiesFromASCRaster
		MeshLib
		FileIO
		VtkVis
		zlib
		${VTK_LIBRARIES}
		${QT_LIBRARIES}
	)

ENDIF() # VtkVis-target is existing
