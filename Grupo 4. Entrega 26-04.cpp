#include <iostream>
#include <string>

using namespace std;

struct Cliente {
    string nombre;
    int cupo;
};

int main() {
    cout << "Vamos a usar CINEMAX\n";
    cout << "selecciona una opción" << endl;

    cout << "\n1. crea una tarjeta nueva \n2. Recarga la tarjeta \n3. crear una reserva \n4. elimina la reserva actual \n5. Paga una reserva en efectivo \n6. Paga la reserva con tarjeta CINEMAX \n7. Visualizar las sillas del cine \n8. Visualizar el dinero en caja\n9. Visualizar el cupo del cliente\n";

    int opcion;

    do {
        cout << "Ingresa tu opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "crea una tarjeta nueva" << endl;
                break;
            case 2:
                cout << "Recarga la tarjeta" << endl;
                break;
            case 3:
                cout << "crear una reserva" << endl;
                break;
            case 4:
                cout << "elimina la reserva actual" << endl;
                break;
            case 5:
                cout << "Paga una reserva en efectivo" << endl;
                break;
            case 6:
                cout << "Paga la reserva con tarjeta CINEMAX" << endl;
                break;
            case 7:
                cout << "Visualizar las sillas del cine" << endl;
                break;
            case 8:
                cout << "Visualizar el dinero en caja" << endl;
                break;
            case 9:
                cout << "Visualizar el cupo del cliente" << endl;
                ;{
                int i;
                cout << "Ingrese la cantidad de clientes: ";
                cin >> i;

                Cliente listaClientes[i];

                // Variable 
                int totalCupos = 0;

                for (int a = 0; a < i; a++) {
                    cout << "Ingrese el nombre del cliente " << (a + 1) << ": ";
                    cin >> listaClientes[a].nombre;
                    cout << "Ingrese el cupo del cliente " << (a + 1) << ": ";
                    cin >> listaClientes[a].cupo;

                    totalCupos += listaClientes[a].cupo;
                }

                float promedioCupos = totalCupos / (float)i; 
                cout << "El promedio de los cupos es: " << promedioCupos << endl;
                
                cout << "\nLista de clientes y sus cupos:\n";
                for (int a = 0; a < i; a++) {
                    cout << "Cliente: " << listaClientes[a].nombre << ", Cupo: " << listaClientes[a].cupo << endl;
                }
                break;
            }
            default:
                cout << "intenta nuevamente" << endl;
        }
    } while (opcion != 9);

    cout << "\nGracias por usar CINEMAX" << endl;
    
}