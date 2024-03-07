cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(SimulationBeta)

find_package(Geant4 REQUIRED ui_all vis_all)

include(${Geant4_USE_FILE})

file(GLOB sources ${PROJECT_SOURCE_DIR}/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/*.hh)

file(GLOB MACRO_FILES
	"*.mac"
)

file(COPY ${MACRO_FILES} DESTINATION ${PROJECT_BINARY_DIR})

add_executable(simBeta simBeta.cc ${sources} ${headers})
target_link_libraries(simBeta ${Geant4_LIBRARIES})

add_custom_target(SimulationBeta DEPENDS simBeta)
