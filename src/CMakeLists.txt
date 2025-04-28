
# Lista dei file header
list(APPEND polygonalMesh_headers
    ${CMAKE_CURRENT_SOURCE_DIR}/PolygonalMesh.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/PolygonalMeshFunctions.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Utils.hpp
)

# Lista dei file source
list(APPEND polygonalMesh_sources
    ${CMAKE_CURRENT_SOURCE_DIR}/PolygonalMeshFunctions.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Utils.cpp
)

# Include directory
list(APPEND polygonalMesh_includes
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Esportiamo le variabili al CMake superiore
set(polygonalMesh_headers ${polygonalMesh_headers} PARENT_SCOPE)
set(polygonalMesh_sources ${polygonalMesh_sources} PARENT_SCOPE)
set(polygonalMesh_includes ${polygonalMesh_includes} PARENT_SCOPE)