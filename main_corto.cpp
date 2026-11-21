// Ventas semanales del colmado "Don Pepe" con arreglos unidimensionales
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int DIAS = 7;

int main() {
    string dias[DIAS] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};
    double ventas[DIAS], total = 0;
    int mayor = 0, menor = 0;

    // Pedir las ventas (se repite si es negativa o no es un numero)
    for (int i = 0; i < DIAS; i++) {
        cout << "Ventas del " << dias[i] << ": RD$ ";
        while (!(cin >> ventas[i]) || ventas[i] < 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Valor invalido. Repita: RD$ ";
        }
        total += ventas[i];
        if (ventas[i] > ventas[mayor]) mayor = i;
        if (ventas[i] < ventas[menor]) menor = i;
    }

    // Listado de ventas
    cout << fixed << setprecision(2) << "\n===== VENTAS DEL COLMADO DON PEPE =====\n";
    for (int i = 0; i < DIAS; i++)
        cout << dias[i] << ": RD$ " << ventas[i] << endl;

    // Dias sobre el promedio
    double promedio = total / DIAS;
    int cantidad = 0;
    string lista;
    for (int i = 0; i < DIAS; i++)
        if (ventas[i] > promedio)
            lista += (cantidad++ > 0 ? ", " : "") + dias[i];

    // Resumen
    cout << "---------------------------------------\n"
         << "Total semanal: RD$ " << total << "\n"
         << "Promedio diario: RD$ " << promedio << "\n"
         << "Mayor venta: " << dias[mayor] << " (RD$ " << ventas[mayor] << ")\n"
         << "Menor venta: " << dias[menor] << " (RD$ " << ventas[menor] << ")\n"
         << "Dias sobre el promedio: " << cantidad << " -> " << lista << endl;
    return 0;
}
