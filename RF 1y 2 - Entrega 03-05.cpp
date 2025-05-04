#include <iostream>
using namespace std;

struct Cliente 
{
    string nombre;
    int cedula;
    int monto;
    int cupo;
};

int main() {
    Cliente miCliente;  

    cout << "Vamos a usar CINEMAX\n";
    cout << "Selecciona una opción" << endl;

    cout << "\n1. Crea una tarjeta nueva \n2. Recarga la tarjeta \n3. Crear una reserva \n4. Elimina la reserva actual \n5. Paga una reserva en efectivo \n6. Paga la reserva con tarjeta CINEMAX \n7. Visualizar las sillas del cine \n8. Visualizar el dinero en caja\n9. Visualizar el cupo del cliente\n";

    int opcion;

    do {
        cout << "\nIngresa tu opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cout << "\nCrear una nueva tarjeta" << endl;

                cout << "Ingrese el nombre del cliente: ";
                cin >> miCliente.nombre;

                cout << "Ingrese la cédula del cliente: ";
                cin >> miCliente.cedula;

                cout << "Ingrese el monto de la tarjeta (máximo 50,000): ";
                cin >> miCliente.monto;

                if (miCliente.monto > 10000 && miCliente.monto <= 50000) {
                    cout << "\nTarjeta creada exitosamente:\n";
                    cout << "Nombre: " << miCliente.nombre << endl;
                    cout << "Cédula: " << miCliente.cedula << endl;
                    cout << "Cupo: $" << miCliente.monto << endl;
                } else {
                    cout << " Error: El cupo debe estar entre 10,000 y 50,000\n";
                }
                break;
            }

            case 2: {
                cout << "Recarga la tarjeta" << endl;

                string NOMBRE;
                int cedula;
                int recarga;

                cout << "Ingrese su nombre completo: ";
                cin >> NOMBRE;

                cout << "Ingrese su cédula: ";
                cin >> cedula;

                do {
                    cout << "Ingrese el monto a recargar: ";
                    cin >> recarga;
                    if (recarga <= 0 || recarga > 50000) {
                        cout << "El monto debe ser mayor a 0 y menor o igual a $50.000" << endl;
                    }
                } while (recarga <= 0 || recarga > 50000);

                cout << "\nRecarga exitosa" << endl;
                cout << "Nombre completo: " << NOMBRE << endl;
                cout << "Cédula: " << cedula << endl;
                cout << "Monto recargado: $" << recarga << endl;
                break;
            }

            case 3:
                cout << "Crear una reserva" << endl;
                break;

            case 4:
                cout << "Elimina la reserva actual" << endl;
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

            case 9: {
                cout << "Visualizar el cupo del cliente" << endl;
                int i;
                cout << "Ingrese la cantidad de clientes: ";
                cin >> i;

                Cliente listaClientes[i];
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
                cout << "Intenta nuevamente" << endl;
        }

    } while (opcion != 9);

    cout << "\nGracias por usar CINEMAX" << endl;
}
