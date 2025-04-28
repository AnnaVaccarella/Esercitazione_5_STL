#include "PolygonalMeshFunctions.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;
using namespace Eigen;

bool ImportMesh(PolygonalMesh& mesh)
{
    if (!ImportCell0Ds(mesh))
    {
        cerr << "Errore durante l'importazione delle celle 0D" << endl;
        return false;
    }

    if (!ImportCell1Ds(mesh))
    {
        cerr << "Errore durante l'importazione delle celle 1D" << endl;
        return false;
    }

    if (!ImportCell2Ds(mesh))
    {
        cerr << "Errore durante l'importazione delle celle 2D" << endl;
        return false;
    }

    return true;
}

bool ImportCell0Ds(PolygonalMesh& mesh)
{
    ifstream file("./Cell0Ds.csv");
    if (file.fail())
        return false;

    list<string> listLines;
    string line;
    while (getline(file, line))
    {
        replace(line.begin(), line.end(), ';', ' ');
        listLines.push_back(line);
    }
    file.close();

    listLines.pop_front();
    mesh.NumberCell0D = listLines.size();
    if (mesh.NumberCell0D == 0)
        return false;

    for (const string& line : listLines)
    {
        istringstream converter(line);
        unsigned int id, marker;
        Vector2d coord;

        converter >> id >> marker >> coord(0) >> coord(1);

        mesh.Cell0DId.push_back(id);
        mesh.Cell0DCoordinates.push_back(coord);

        if (marker != 0)
            mesh.Cell0DMarkers[marker].push_back(id);
    }

    return true;
}

bool ImportCell1Ds(PolygonalMesh& mesh)
{
    ifstream file("./Cell1Ds.csv");
    if (file.fail())
        return false;

    list<string> listLines;
    string line;
    while (getline(file, line))
    {
        replace(line.begin(), line.end(), ';', ' ');
        listLines.push_back(line);
    }
    file.close();

    listLines.pop_front();
    mesh.NumberCell1D = listLines.size();
    if (mesh.NumberCell1D == 0)
        return false;

    for (const string& line : listLines)
    {
        istringstream converter(line);
        unsigned int id, marker;
        Vector2i vertices;

        converter >> id >> marker >> vertices(0) >> vertices(1);

        mesh.Cell1DId.push_back(id);
        mesh.Cell1DVertices.push_back(vertices);

        if (marker != 0)
            mesh.Cell1DMarkers[marker].push_back(id);
    }

    return true;
}

bool ImportCell2Ds(PolygonalMesh& mesh)
{
    ifstream file("./Cell2Ds.csv");
    if (file.fail())
        return false;

    list<string> listLines;
    string line;
    while (getline(file, line))
    {
        replace(line.begin(), line.end(), ';', ' ');
        listLines.push_back(line);
    }
    file.close();

    listLines.pop_front();
    mesh.NumberCell2D = listLines.size();
    if (mesh.NumberCell2D == 0)
        return false;

    for (const string& line : listLines)
    {
        istringstream converter(line);
        unsigned int id, marker, numVertices, numEdges;
        converter >> id >> marker >> numVertices;

        VectorXi vertices(numVertices);
        for (unsigned int i = 0; i < numVertices; i++)
            converter >> vertices(i);

        converter >> numEdges;
        VectorXi edges(numEdges);
        for (unsigned int i = 0; i < numEdges; i++)
            converter >> edges(i);

        mesh.Cell2DId.push_back(id);
        mesh.Cell2DVertices.push_back(vertices);
        mesh.Cell2DEdges.push_back(edges);
    }

    return true;
}

