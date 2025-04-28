#pragma once

#include "PolygonalMesh.hpp"

// Funzione che importa tutta la mesh
bool ImportMesh(PolygonalMesh& mesh);

// Funzione che importa le celle 0D
bool ImportCell0Ds(PolygonalMesh& mesh);

// Funzione che importa le celle 1D
bool ImportCell1Ds(PolygonalMesh& mesh);

// Funzione che importa le celle 2D
bool ImportCell2Ds(PolygonalMesh& mesh);