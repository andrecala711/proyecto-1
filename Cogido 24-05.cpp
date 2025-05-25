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
	const int MAX_CLIENTES = 20;
	Cliente clientes[MAX_CLIENTES] = {
		{"Valentina", 101310, 0, 0},
		{"Samuel", 102345, 0, 0},
		{"Andrea", 110232, 0, 0},
		{"Carlos", 123456, 0, 0},
		{"Mateo", 132435, 0, 0},
		{"Samara", 142356, 0, 0},
		{"Nicol", 178654, 0, 0},
		{"Veronica", 101312, 0, 0},
		{"Ivan", 176099, 0, 0},
		{"David", 187733, 0, 0}
	};
	int numClientes = 10;

	Cliente miCliente;
	Reserva reserva;
	bool hayReserva = false;
	int dineroEnCaja = 100000;

	cout << "Vamos a usar CINEMAX\n";
	cout << "Selecciona una opcion" << endl;

	cout << "\n1. Crea una tarjeta nueva \n2. Recarga la tarjeta \n3. Crear una reserva \n4. Elimina la reserva actual \n5. Paga una reserva en efectivo \n6. Paga la reserva con tarjeta CINEMAX \n7. Visualizar las sillas del cine \n8. Visualizar el dinero en caja\n9. Visualizar el cupo del cliente\n";

	int opcion;

	do {
		cout << "\nIngresa tu opcion: ";
		cin >> opcion;

		switch (opcion) {
		case 1: {
			cout << "\nCrear una nueva tarjeta" << endl;

			if (numClientes >= MAX_CLIENTES) {
				cout << "No se pueden registrar mas clientes." << endl;
				break;
			}

			cout << "Ingrese el nombre del cliente: ";
			cin >> clientes[numClientes].nombre;

			cout << "Ingrese la cedula del cliente: ";
			cin >> clientes[numClientes].cedula;

			cout << "Ingrese el monto de la tarjeta (maximo 50,000): ";
			cin >> clientes[numClientes].monto;

			if (clientes[numClientes].monto > 10000 && clientes[numClientes].monto <= 50000) {
				clientes[numClientes].cupo = clientes[numClientes].monto;
				cout << "\nTarjeta creada exitosamente:\n";
				cout << "Nombre: " << clientes[numClientes].nombre << endl;
				cout << "Cedula: " << clientes[numClientes].cedula << endl;
				cout << "Cupo: $" << clientes[numClientes].cupo << endl;
				numClientes++;
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

			cout << "Ingrese su cedula: ";
			cin >> cedula;

			int indiceCliente = -1;
			for (int i = 0; i < numClientes; i++) {
				if (clientes[i].nombre == NOMBRE && clientes[i].cedula == cedula) {
					indiceCliente = i;
					break;
				}
			}

			if (indiceCliente == -1) {
				cout << "No estas registrado, crea una tarjeta CINEMAX primero." << endl;
				break;
			}

			do {
				cout << "Ingrese el monto a recargar (mínimo $50,000): ";
				cin >> recarga;
				if (recarga < 50000) {
					cout << "Lo sentimos, intenta nuevamente. La recarga mínima es de $50,000." << endl;
				}
			} while (recarga < 50000);

			clientes[indiceCliente].cupo += recarga;

			cout << "\nRecarga exitosa" << endl;
			cout << "Nombre completo: " << clientes[indiceCliente].nombre << endl;
			cout << "Cedula: " << clientes[indiceCliente].cedula << endl;
			cout << "Monto recargado: $" << recarga << endl;
			cout << "Cupo actual: $" << clientes[indiceCliente].cupo << endl;

			break;
		}

		case 3: {
			cout << "Crear una reserva" << endl;
			cout << "Ingresa tu nombre: ";
			string nombreReserva;
			cin >> nombreReserva;

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
				cout << "No estas registrado, crea una tarjeta CINEMAX primero." << endl;
				hayReserva = false;
				break;
			}

			cout << "Ingrese el numero de asiento (1-64): ";
			int asiento;
			cin >> asiento;

			if (asiento < 1 || asiento > 64) {
				cout << "El numero de asiento debe estar entre 1 y 64" << endl;
				hayReserva = false;
			} else {
				reserva.nombre = nombreReserva;
				reserva.asiento = asiento;
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
				int indiceCliente = -1;
				for (int i = 0; i < numClientes; i++) {
					if (clientes[i].nombre == reserva.nombre) {
						indiceCliente = i;
						break;
					}
				}

				if (indiceCliente == -1) {
					cout << "No estas registrado, crea una tarjeta CINEMAX primero." << endl;
					break;
				}
				if (clientes[indiceCliente].cupo >= valorEntrada) {
					clientes[indiceCliente].cupo -= valorEntrada;
					cout << "Reserva de " << reserva.nombre << " en asiento " << reserva.asiento << " pagada con tarjeta.\n";
					cout << "Monto descontado: $" << valorEntrada << endl;
					cout << "Cupo restante: $" << clientes[indiceCliente].cupo << endl;
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

			cout << "Por favor ingresa una ubicacion para marcar como ocupada:" << endl;

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

			silleteria[fila][columna] = 1;

			cout << "Has ingresado la posición: fila " << fila + 1 << ", columna " << columna + 1 << endl;

			cout << "\nEstado actual de la silleteria:" << endl;

			for (int i = 0; i < 20; i++) {
				for (int j = 0; j < 20; j++) {
					if (silleteria[i][j] == 1) {
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

			if (cantidadClientes > MAX_CLIENTES) {
				cout << "La cantidad máxima de clientes es " << MAX_CLIENTES << endl;
				cantidadClientes = MAX_CLIENTES;
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
}
