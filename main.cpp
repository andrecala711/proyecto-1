#include <iostream>
using namespace std;
int main()
{
int a;
   
     cout <<"ingresa un digito de 1 a 8"<<endl;
    cin>>a;
    switch (a)
    {
        case 1:{
        cout<<"Crear una nueva tarjeta"<<endl;
        break;
        }
        case 2:{
        cout<<"recargar una tarjeta"<<endl;
        break;
       }
        case 3:{
        cout<<"crear una reserva"<<endl;
        break;
        }
        case 4:{
        cout<<"eliminar la reserva actual"<<endl;
        break;
        }
        case 5:{
        cout<<"pagar una reserva en efetivo"<<endl;
        break;
        }
        case 6:{
        cout<<"pagar la reserva con tarjeta cinemax"<<endl;
        break;
        }
        case 7:{
        cout<<"visualizar las sillas del cine"<<endl;
        break;
        }
        case 8:{
        cout<<"visualizar el dinero en caja"<<endl;
        break;
        }
        
    }
}