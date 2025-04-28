#pragma once

#include "PolygonalMesh.hpp"

// Funzione che calcola la lunghezza di un lato
double ComputeEdgeLength(const PolygonalMesh& mesh, unsigned int edgeId);

// Funzione che calcola l'area di un poligono
double ComputeArea(const PolygonalMesh& mesh, unsigned int cell2DId);