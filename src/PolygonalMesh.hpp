#pragma once

#include <vector>
#include <map>
#include <list>
#include <Eigen/Eigen>

// Struttura dati che rappresenta una mesh poligonale
struct PolygonalMesh
{
    unsigned int NumberCell0D = 0;
    std::vector<unsigned int> Cell0DId;
    std::vector<Eigen::Vector2d> Cell0DCoordinates;
    std::map<unsigned int, std::list<unsigned int>> Cell0DMarkers;

    unsigned int NumberCell1D = 0;
    std::vector<unsigned int> Cell1DId;
    std::vector<Eigen::Vector2i> Cell1DVertices;
    std::map<unsigned int, std::list<unsigned int>> Cell1DMarkers;

    unsigned int NumberCell2D = 0;
    std::vector<unsigned int> Cell2DId;
    std::vector<Eigen::VectorXi> Cell2DVertices;
    std::vector<Eigen::VectorXi> Cell2DEdges;
};