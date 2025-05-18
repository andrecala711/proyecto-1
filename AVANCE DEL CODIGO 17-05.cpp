#include <iostream>
using namespace std;

struct Cliente 
{
    string nombre;
    int cedula;
    int monto;
    int cupo;
};

struct Reserva {
    string nombre;
    int asiento;
};

int main() {
    Cliente miCliente;
    Reserva reserva;
    bool hayReserva = false;
    int dineroEnCaja = 100000;

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
                    miCliente.cupo = miCliente.monto;
                    cout << "\nTarjeta creada exitosamente:\n";
                    cout << "Nombre: " << miCliente.nombre << endl;
                    cout << "Cédula: " << miCliente.cedula << endl;
                    cout << "Cupo: $" << miCliente.cupo << endl;
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

            case 3: {
                cout << "Crear una reserva" << endl;
                cout << "Ingresa tu nombre: ";
                cin >> reserva.nombre;

                cout << "Ingrese el número de asiento (1-64): ";
                cin >> reserva.asiento;

                if (reserva.asiento < 1 || reserva.asiento > 64) {
                    cout << "El número de asiento debe estar entre 1 y 64" << endl;
                    hayReserva = false;
                } else {
                    cout << "Reserva para " << reserva.nombre << " en el asiento " << reserva.asiento << endl;
                    hayReserva = true;
                }
                break;
            }

            case 4: {
                cout << "Eliminar la reserva actual" << endl;
                if (hayReserva) {
                    cout << "Reserva eliminada para " << reserva.nombre << " en asiento " << reserva.asiento << endl;
                    hayReserva = false;
                } else {
                    cout << "No hay ninguna reserva activa para eliminar." << endl;
                }
                break;
            }

            case 5: {
                cout << "Pagar una reserva en efectivo" << endl;
                if (hayReserva) {
                    int valorEntrada = 15000;
                    dineroEnCaja += valorEntrada;
                    cout << "Reserva de " << reserva.nombre << " en asiento " << reserva.asiento << " pagada en efectivo.\n";
                    cout << "Monto pagado: $" << valorEntrada << endl;
                    hayReserva = false;
                } else {
                    cout << "No hay una reserva activa para pagar." << endl;
                }
                break;
            }

            case 6: {
                cout << "Pagar la reserva con tarjeta CINEMAX" << endl;
                if (hayReserva) {
                    int valorEntrada = 15000;
                    if (miCliente.cupo >= valorEntrada) {
                        miCliente.cupo -= valorEntrada;
                        cout << "Reserva de " << reserva.nombre << " en asiento " << reserva.asiento << " pagada con tarjeta.\n";
                        cout << "Monto descontado: $" << valorEntrada << endl;
                        cout << "Cupo restante: $" << miCliente.cupo << endl;
                        hayReserva = false;
                    } else {
                        cout << "Cupo insuficiente para pagar la reserva." << endl;
                    }
                } else {
                    cout << "No hay una reserva activa para pagar." << endl;
                }
                break;
            }

            case 7: {
                cout << "Visualizar las sillas del cine" << endl;

                int silleteria[20][20] = {0};
                int fila, columna;

                // Pedir ubicación de un asiento 
                cout << "Por favor ingresa una ubicación para marcar como ocupada:" << endl;

                cout << "Ingresa la fila (0-19): ";
                cin >> fila;
                while(fila < 0 || fila > 19) {
                    cout << "Fila inválida, debe ser entre 0 y 19. Intenta de nuevo: ";
                    cin >> fila;
                }

                cout << "Ingresa la columna (0-19): ";
                cin >> columna;
                while(columna < 0 || columna > 19) {
                    cout << "Columna inválida, debe ser entre 0 y 19. Intenta de nuevo: ";
                    cin >> columna;
                }

                silleteria[fila][columna] = 1; // Marcar silla ocupada

                cout << "Has ingresado la posición: fila " << fila + 1 << ", columna " << columna + 1 << endl;

                cout << "\nEstado actual de la silleteria:" << endl;

                // Mostrar silleteria
                for (int i = 0; i < 20; i++) {
                    for (int j = 0; j < 20; j++) {
                        if (silleteria[i][j] == 1) {
                            cout << " # "; // silla ocupada
                        } else {
                            cout << " O "; // silla disponible
                        }
                    }
                    cout << endl;
                }

                break;
            }

            case 8: {
                cout << "Visualizar el dinero en caja" << endl;
                cout << "El dinero en caja es: $" << dineroEnCaja << endl;
                break;
            }

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
    return 0;
}

