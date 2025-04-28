#include "Utils.hpp"
#include <cmath>

using namespace Eigen;

double ComputeEdgeLength(const PolygonalMesh& mesh, unsigned int edgeId)
{
    Vector2i vertices = mesh.Cell1DVertices[edgeId];
    Vector2d point1 = mesh.Cell0DCoordinates[vertices(0)];
    Vector2d point2 = mesh.Cell0DCoordinates[vertices(1)];

    return (point1 - point2).norm();
}

double ComputeArea(const PolygonalMesh& mesh, unsigned int cell2DId)
{
    const VectorXi& vertices = mesh.Cell2DVertices[cell2DId];
    double area = 0.0;

    for (int i = 0; i < vertices.size(); i++)
    {
        Vector2d p1 = mesh.Cell0DCoordinates[vertices(i)];
        Vector2d p2 = mesh.Cell0DCoordinates[vertices((i + 1) % vertices.size())];
        area += (p1(0) * p2(1) - p2(0) * p1(1));
    }

    return std::abs(area) * 0.5;
}