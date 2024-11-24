/* 
Descripción: 
Programa que recibe una serie de puntos que interpreta como segmentos y te indica si existe o no una intersección
entre cada par de segmentos. Esta implementación hace uso de una librería llamada "The Computational Geometry Algorithms Library",
esta librería nos facilitó todo el proceso para saber si los segmentos se intersectan. 

Autores: 
Gael Venegas Gómez - A01642913
Arturo Ramos Martínez - A01643269 

Fecha: 07/Nov/2024

*/
#include <CGAL/Simple_cartesian.h>
#include <CGAL/Segment_2.h>
#include <vector>
#include <iostream>
using namespace std;

typedef CGAL::Simple_cartesian<double> Kernel;
typedef Kernel::Point_2 Point_2;
typedef Kernel::Segment_2 Segment_2;

/*
crearSegmento crea un segmento con ayuda de cgal 
el cual nos ofrece la función Segment_2 y Point_2 para indicar los puntos que conforman el segmento. 
 */

Segment_2 crearSegmento(double x1, double y1, double x2, double y2) {
    return Segment_2(Point_2(x1, y1), Point_2(x2, y2));
}

/* 
verificarIntersecion es donde se evalúa si existe o no la intersección entre los segmentos,
la función recibe los 8 puntos que representan los dos segmentos, estos puntos se pasan a crearSegmento para crearlos
y por último se pasan los segmentos a CGAL::do_intersect() para verificar si se intersectan.
 */
bool verificarIntersecion(double x1, double y1, double x2, double y2,
                               double x3, double y3, double x4, double y4) {
    Segment_2 s1 = crearSegmento(x1, y1, x2, y2);
    Segment_2 s2 = crearSegmento(x3, y3, x4, y4);
    return CGAL::do_intersect(s1, s2);
}

/* 
procesarSegmentos nos ayuda a hacer el código más entendible, ya que recibe el array de puntos, y va separando 
cada par de segmentos, acá es donde se crea el array de resultados y donde se manda a llamar a verificarIntersecion
para cada par. 
 */
vector<bool> procesarSegmentos(const vector<vector<double>>& segments) {
    vector<bool> results;
    int len = segments.size();
    for (int i = 0; i < len; i++){
        bool intersection = verificarIntersecion(segments[i][0], segments[i][1], segments[i][2], segments[i][3], segments[i][4],  
        segments[i][5], segments[i][6], segments[i][7]);
        results.push_back(intersection);
    }
    return results;
}

int main() {
    int n;
    cin >> n;
    
    if (n % 4 != 0) {
        cout << "Error: n tiene que ser multiplo de 4" << endl;
        return 1;
    }

    vector<vector<double>> segments (n/4, vector<double>(8)); 

    for(int i = 0; i < n/4; i++){
        for(int j = 0; j < 8; j++){
            cin >> segments[i][j];
        }
    }
    
    vector<bool> intersections = procesarSegmentos(segments);
    
    for (bool intersects : intersections) {
        if(intersects){
            cout << "True ";
        }else{
            cout << "False ";
        }
    }
    cout << endl;
    
    return 0;
}