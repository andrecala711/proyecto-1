#include <iostream>
using namespace std;

int main() {
    cout << "Vamos a usar CINEMAX\n";
    cout << "selecciona una opción" << endl;

    cout << "\n1. crea una tarjeta nueva \n2. Recarga la tarjeta \n3. crear una reserva \n4. elimina la reserva actual \n5. Paga una reserva en efectivo \n6. Paga la reserva con tarjeta CINEMAX \n7. Visualizar las sillas del cine \n8. Visualizar el dinero en caja\n";

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
            default:
                cout << "intenta nuevamente" << endl;
        }
    } while (opcion != 8);

    cout << "\nGracias por usar CINEMAX" << endl;
    return 0;
}