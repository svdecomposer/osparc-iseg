#
# Define how to use third party, i.e. 
# - include directory
# - library
# - preprocessor definitions needed by package
#
if(NOT BOOST_ROOT)
	set(BOOST_ROOT "not defined" CACHE PATH "path to Boost root folder")	
	message(FATAL_ERROR "Please define Boost root folder")
endif(NOT BOOST_ROOT)
if (BOOST_ROOT STREQUAL "not defined")
	message(FATAL_ERROR "Please define Boost root folder")
endif(BOOST_ROOT STREQUAL "not defined")

#set(Boost_DEBUG on)
#set(Boost_DETAILED_FAILURE_MSG on)
set(Boost_USE_MULTITHREADED on)
FIND_PACKAGE(Boost 1.64 REQUIRED COMPONENTS filesystem thread unit_test_framework date_time random chrono timer ${BOOST_REQUIRED_LIBS})
if(NOT Boost_FOUND)
	message(FATAL_ERROR "Boost library not found!")
endif(NOT Boost_FOUND)
if(MSVC)
	SET(BOOST_DEFINITIONS "/D BOOST_ALL_DYN_LINK")
elseif(APPLE)
	SET(BOOST_DEFINITIONS "-DBOOST_TEST_DYN_LINK")
endif()

MACRO(USE_BOOST)
	INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
	LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
	ADD_DEFINITIONS(${BOOST_DEFINITIONS})

	LIST( APPEND MY_EXTERNAL_LINK_LIBRARIES ${Boost_LIBRARIES} )
	REMEMBER_TO_CALL_THIS_INSTALL_MACRO( INSTALL_RUNTIME_LIBRARIES_BOOST )
ENDMACRO()

MACRO(INSTALL_RUNTIME_LIBRARIES_BOOST)
	MESSAGE( STATUS "--> ThirdPartyBoost: installing boost library ..." )
	IF(MSVC)
		FOREACH(BUILD_TYPE ${CMAKE_CONFIGURATION_TYPES})
			STRING(TOLOWER ${BUILD_TYPE} build_type)
				IF(${build_type} MATCHES rel*)
					FILE(COPY ${Boost_LIBRARY_DIR_RELEASE}/
						DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${BUILD_TYPE}
						FILES_MATCHING PATTERN "*.dll" PATTERN ".svn" PATTERN "*-gd-*" EXCLUDE )
				ELSE()
					FILE(COPY ${Boost_LIBRARY_DIR_DEBUG}/
						DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${BUILD_TYPE}
						FILES_MATCHING PATTERN "*-gd-*.dll" PATTERN ".svn" EXCLUDE )
				ENDIF()
		ENDFOREACH()
	ENDIF()
ENDMACRO()
