#include <iostream>
#include <cassert>
#include "PolygonalMeshFunctions.hpp"
#include "Utils.hpp"

using namespace std;

int main() {
    // Creo un oggetto PolygonalMesh per contenere i dati della mesh
    PolygonalMesh mesh;

    // Carico la mesh
    if (!ImportMesh(mesh)) {
        cerr << "Errore durante il caricamento della mesh!" << endl;
        return -1;
    }

    // Verifico che ogni lato abbia una lunghezza non nulla
    for (unsigned int i = 0; i < mesh.NumberCell1D; i++) {
        double edgeLength = ComputeEdgeLength(mesh, i);
        assert(edgeLength > 0 && "La lunghezza del lato non può essere zero!");
        cout << "Lunghezza del lato " << i << ": " << edgeLength << endl;
    }

    // Verifico che ogni poligono abbia un'area non nulla
    for (unsigned int i = 0; i < mesh.NumberCell2D; i++) {
        double area = ComputeArea(mesh, i);
        assert(area > 0 && "L'area del poligono non può essere zero!");
        cout << "Area del poligono " << i << ": " << area << endl;
    }

    // Verifico che tutti i marker siano memorizzati correttamente
    for (const auto& pair : mesh.Cell0DMarkers) {
        unsigned int marker = pair.first;
        const list<unsigned int>& ids = pair.second;
        cout << "Marker " << marker << " associato ai seguenti ID: ";
        for (unsigned int id : ids) {
            cout << id << " ";
        }
        cout << endl;
    }

    cout << "Tutti i test sono passati con successo!" << endl;
    return 0;
}