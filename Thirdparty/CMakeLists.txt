ADD_SUBDIRECTORY(VTK/GUISupport)
ADD_SUBDIRECTORY(GDCM)
ADD_SUBDIRECTORY(GeometricPredicates)
ADD_SUBDIRECTORY(OpenThinning)

IF(PLUGIN_GRAPHCUT)
	ADD_SUBDIRECTORY(Gc)
ENDIF()