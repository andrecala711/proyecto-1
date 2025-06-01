#include <iostream>
#include <cstdlib> // Para system()
using namespace std;

int main() {
    // Mostrar portada con nombres de autores
    system ("ctd");
    cout << "Programa de Cine CINEMAX\n";
    cout << "Autores:\n";
    cout << "Samuel José Rivas Montaño\n";
    cout << "Andrea Cala Vesga\n";
    cout << "Valentina Gomez Tapia\n";
    cout << "\nPresione ENTER para continuar...";
    cin.ignore();  // Para esperar que el usuario presione ENTER
    cin.get();     // Esperar la entrada

    struct Cliente {
        string nombre;
        int cedula;
        int monto;
        int cupo;
    };

    struct Silla {
        int fila; // 0-10 representan las filas A-K
        int numero; // 1-20
        string tipo; // General o Preferencial
        string estado; // Disponible, Reservada, Vendida
        int costo; // Costo de la boleta
    };

    int max_sillas_reserva = 8; // Capacidad máxima de reservas
    int max_clientes = 2000; // Capacidad máxima de clientes
    int total_sillas = 220; // Total de sillas en el cine

    struct Reserva {
        string nombre;
        Silla sillas[8]; // 8 porque es la cantidad maxima de reservas 
        int cantidadSillasReservadas;
        string pelicula; // la película que se escogera al hacer la reserva
    };

    Cliente clientes[2000]; 
    int numClientes = 0; // Contador de clientes
    
    Silla silleteria[11][20]; // 11 filas (A-K) y 20 columnas
    // Silleteria con detalles y costo según la fila escogida 
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 20; j++) {
            silleteria[i][j].fila = i; // filas como índice 0-10
            silleteria[i][j].numero = j + 1; // número 1-20
            
            if (i < 8) { // filas A-H son General
                silleteria[i][j].tipo = "General";
                silleteria[i][j].costo = 8000;
            } else { // filas I-K son Preferencial
                silleteria[i][j].tipo = "Preferencial";
                silleteria[i][j].costo = 11000;
            }
            silleteria[i][j].estado = "Disponible";
        }
    }

    Reserva reserva;
    reserva.cantidadSillasReservadas = 0;
    bool hayReserva = false;
    int dineroEnCaja = 0;

    // Lista de películas disponibles 
    string peliculas[5];
    peliculas[0] = "Lilo & Stitch";
    peliculas[1] = "Misión: Imposible La Sentencia Final";
    peliculas[2] = "Thunderbolts";
    peliculas[3] = "Destino Final: Lazos de Sangre";
    peliculas[4] = "Karate Kid: Leyendas";

    int num_peliculas = 5; // Número de películas

    cout << "Bienvenido a CINEMAX\n";

    // Pregunta si el usuario ya tiene tarjeta CINEMAX
    string tieneTarjeta;
    cout << "¿Ya tienes tarjeta CINEMAX? (si/no): ";
    cin >> tieneTarjeta;

    if (tieneTarjeta != "si" && tieneTarjeta != "Si") {
        cout << "Debes crear una tarjeta primero seleccionando la opción 1 en el menú.\n";
    }

    cout << "Selecciona una opcion" << endl;

    cout << "\n1. Crear una tarjeta nueva \n2. Recargar la tarjeta \n3. Crear una reserva \n4. Eliminar la reserva actual \n5. Pagar una reserva en efectivo \n6. Pagar la reserva con tarjeta CINEMAX \n7. Visualizar las sillas del cine \n8. Visualizar el dinero en caja\n9. Visualizar el cupo del cliente\n";

    int opcion;

    do {
        cout << "\nIngresa tu opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cout << "\nCrear una nueva tarjeta" << endl;

                // Se le informa al cliente de cuanto es la recarga mínima de la nueva tarjeta
                cout << "La recarga mínima de la nueva tarjeta es de $70,000. ¿Quieres continuar? (si/no): ";
                string continuar;
                cin >> continuar;

                if (continuar != "si" && continuar != "Si") {
                    cout << "la creacción de la tarjeta se ah cancelado." << endl;
                    break;
                }

                if (numClientes >= max_clientes) {
                    cout << "No se pueden registrar más clientes." << endl;
                    break;
                }

                Cliente nuevoCliente;

                cout << "Ingrese el nombre del cliente: ";
                cin >> nuevoCliente.nombre;

                cout << "Ingrese la cedula del cliente: ";
                cin >> nuevoCliente.cedula;
                
                // Verifica que no exista la cédula
                bool existe = false;
                for (int i = 0; i < numClientes; i++) {
                    if (clientes[i].cedula == nuevoCliente.cedula) {
                        existe = true;
                        break;
                    }
                }
                
                if (existe) {
                    cout << "Ya existe una tarjeta con esa cédula." << endl;
                    break;
                }

                // Se requiere una recarga inicial de 70000 al crear la tarjeta
                nuevoCliente.monto = 70000;
                nuevoCliente.cupo = 70000;

                // Se agrega el nuevo cliente 
                clientes[numClientes] = nuevoCliente;
                numClientes++;

                cout << "\nTarjeta creada exitosamente con recarga inicial de $70000:\n";
                cout << "Nombre: " << nuevoCliente.nombre << endl;
                cout << "Cedula: " << nuevoCliente.cedula << endl;
                cout << "Cupo: $" << nuevoCliente.cupo << endl;
                break;
            }

            case 2: {
                cout << "Recarga la tarjeta" << endl;

                string nombre;
                int cedula;
                int recarga;

                cout << "Ingrese su nombre completo: ";
                cin >> nombre;

                cout << "Ingrese su cedula: ";
                cin >> cedula;

                int cliente_index = -1;
                for (int i = 0; i < numClientes; i++) {
                    if (clientes[i].nombre == nombre && clientes[i].cedula == cedula) {
                        cliente_index = i;
                        break;
                    }
                }

                if (cliente_index == -1) {
                    cout << "No estás registrado, crea una tarjeta CINEMAX primero." << endl;
                    break;
                }
                do {
                    cout << "Ingrese el monto a recargar (mínimo $50000): ";
                    cin >> recarga;
                    if (recarga < 50000) {
                        cout << "Lo sentimos, intenta nuevamente. La recarga mínima es de $50000." << endl;
                    } 
                } while (recarga < 50000);

                clientes[cliente_index].cupo += recarga;

                cout << "\nRecarga exitosa" << endl;
                cout << "Nombre completo: " << clientes[cliente_index].nombre << endl;
                cout << "Cedula: " << clientes[cliente_index].cedula << endl;
                cout << "Monto recargado: $" << recarga << endl;
                cout << "Cupo actual: $" << clientes[cliente_index].cupo << endl;

                break;
            }

            case 3: {
                cout << "Crear una reserva" << endl;
                cout << "Ingresa tu nombre: ";
                string nombreReserva;
                cin >> nombreReserva;
                reserva.nombre = nombreReserva;
                reserva.cantidadSillasReservadas = 0;

                cout << "Ingrese su cedula: ";
                int cedReserva;
                cin >> cedReserva;

                bool clienteEncontrado = false;
                for (int i = 0; i < numClientes; i++) {
                    if (clientes[i].nombre == nombreReserva && clientes[i].cedula == cedReserva) {
                        clienteEncontrado = true;
                        break;
                    }
                }
                if (!clienteEncontrado) {
                    cout << "No estás registrado, crea una tarjeta CINEMAX primero." << endl;
                    hayReserva = false;
                    break;
                }

                cout << "Seleccione la película para quieres ver:" << endl;
                for (int i = 0; i < num_peliculas; i++) {
                    cout << (i + 1) << ") " << peliculas[i] << endl;
                }
                cout << "Ingrese el número de la película: ";
                int seleccionPelicula;
                cin >> seleccionPelicula;
                if (seleccionPelicula < 1 || seleccionPelicula > num_peliculas) {
                    cout << "Selección inválida. Intente de nuevo." << endl;
                    break;
                }
                reserva.pelicula = peliculas[seleccionPelicula-1];

                // Verifica si hay espacio en la sala
                if (reserva.cantidadSillasReservadas + total_sillas > 220) {
                    cout << "La sala está llena. Por favor, elige otra película." << endl;
                    break;
                }

                cout << "Ingrese el número de sillas a reservar (máximo 8): ";
                int numSillas;
                cin >> numSillas;

                if (numSillas > max_sillas_reserva) {
                    cout << "No se pueden reservar más de 8 sillas." << endl;
                    break;
                }

                for (int i = 0; i < numSillas; i++) {
                    int fila1, numero1;
                    cout << "Ingrese la fila (0-10, donde 0 = A,...,10 = K) y el número de silla (1-20): ";
                    cin >> fila1 >> numero1;
                    if (fila1 < 0 || fila1 > 10 || numero1 < 1 || numero1 > 20) {
                        cout << "Silla inválida. Intente de nuevo." << endl;
                        i--;
                        continue;
                    }
                    if (silleteria[fila1][numero1-1].estado != "Disponible") {
                        cout << "La silla " << numero1 << " en la fila " << fila1 << " no está disponible." << endl;
                        i--;
                        continue;
                    }

                    reserva.sillas[reserva.cantidadSillasReservadas] = silleteria[fila1][numero1-1];
                    reserva.cantidadSillasReservadas++;
                    silleteria[fila1][numero1-1].estado = "Reservada";
                }
                cout << "Reserva creada con éxito para la película: " << reserva.pelicula << endl;
                hayReserva = true;
                break;
            }

            case 4: {
                cout << "Eliminar la reserva actual" << endl;
                if (hayReserva) {
                    for (int i = 0; i < reserva.cantidadSillasReservadas; i++) {
                        int f = reserva.sillas[i].fila;
                        int c = reserva.sillas[i].numero - 1;
                        silleteria[f][c].estado = "Disponible"; 
                    }
                    cout << "Reserva eliminada para " << reserva.nombre << endl;
                    hayReserva = false;
                    reserva.cantidadSillasReservadas = 0;
                } else {
                    cout << "No hay ninguna reserva activa para eliminar." << endl;
                }
                break;
            }

            case 5: {
                cout << "Pagar una reserva en efectivo" << endl;
                if (hayReserva) {
                    int totalPago = 0;
                    for (int i = 0; i < reserva.cantidadSillasReservadas; i++) {
                        totalPago += reserva.sillas[i].costo;
                    }
                    dineroEnCaja += totalPago;
                    cout << "Reserva de " << reserva.nombre << " pagada en efectivo. Monto total: $" << totalPago << endl;
                    hayReserva = false;
                    reserva.cantidadSillasReservadas = 0;
                } else {
                    cout << "No hay una reserva activa para pagar." << endl;
                }
                break;
            }

            case 6: {
                cout << "Pagar la reserva con tarjeta CINEMAX" << endl;
                if (hayReserva) {
                    int totalPago = 0;
                    for (int i = 0; i < reserva.cantidadSillasReservadas; i++) {
                        totalPago += reserva.sillas[i].costo;
                    }
                    int cliente_index = -1;
                    for (int i = 0; i < numClientes; i++) {
                        if (clientes[i].nombre == reserva.nombre) {
                            cliente_index = i;
                            break;
                        }
                    }
                    if (cliente_index == -1) {
                        cout << "No estás registrado, crea una tarjeta CINEMAX primero." << endl;
                        break;
                    }
                    if (clientes[cliente_index].cupo >= totalPago * 0.9) {
                        clientes[cliente_index].cupo -= totalPago * 0.9;
                        cout << "Reserva de " << reserva.nombre << " pagada con tarjeta. Monto descontado: $" << totalPago * 0.9 << endl;
                        cout << "Cupo restante: $" << clientes[cliente_index].cupo << endl;
                        hayReserva = false;
                        reserva.cantidadSillasReservadas = 0;
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

                cout << "\nEstado actual de la silleteria:" << endl;

                for (int i = 0; i < 11; i++) {
                    for (int j = 0; j < 20; j++) {
                        if (silleteria[i][j].estado == "Reservada") {
                            cout << " # ";
                        } else if (silleteria[i][j].estado == "Vendida") {
                            cout << " # ";
                        } else {
                            cout << " O ";
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
                int cantidadClientes;
                cout << "Ingrese la cantidad de clientes: ";
                cin >> cantidadClientes;

                if (cantidadClientes > max_clientes) {
                    cout << "La cantidad máxima de clientes es " << max_clientes << endl;
                    cantidadClientes = max_clientes;
                }

                Cliente listaClientes[cantidadClientes];
                int totalCupos = 0;

                for (int a = 0; a < cantidadClientes; a++) {
                    cout << "Ingrese el nombre del cliente " << (a + 1) << ": ";
                    cin >> listaClientes[a].nombre;
                    cout << "Ingrese el cupo del cliente " << (a + 1) << ": ";
                    cin >> listaClientes[a].cupo;

                    totalCupos += listaClientes[a].cupo;
                }
                
                float promedioCupos = totalCupos / (float)cantidadClientes;
                cout << "El promedio de los cupos es: " << promedioCupos << endl;

                cout << "\nLista de clientes y sus cupos:\n";
                for (int a = 0; a < cantidadClientes; a++) {
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
