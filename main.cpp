#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <iomanip>
#pragma warning(disable : 4996)
using namespace std;

string nombre_producto[100],tem;
int n=0,cantidad_producto[100],compra_dia[100][100]={},devolucion_dia[100][100]={},venta_dia[100][100]={},op,cod,cant,cont,d;
bool dia=true,sw;

int main() {

  	cout << "Antes de iniciar, Ingrese productos por favor."<<endl;
    cout << "Leer producto # "<< n+1 <<endl;

    while (getline(cin,tem)){
        if(tem.length()<=1) break;

  		nombre_producto[n]=tem;
  		cout <<"Digite cantidad del Producto"<<endl;
  		cin  >> cantidad_producto[n];
  		cin.ignore();
  		cout << "Se han añadido "<< cantidad_producto[n] <<" unidades de "<< nombre_producto[n]<<" al inventario."<< endl;
        n++;
        cout << "Leer producto # "<< n+1 << " O deje el espacio en blanco para finalizar"<<endl;
  	}

/*    nombre_producto[0]="Lana";
    nombre_producto[1]="Varilla";
    nombre_producto[2]="Cemento";
    nombre_producto[3]="Losas";
    cantidad_producto[0]=4;
    cantidad_producto[1]=5;
    cantidad_producto[2]=34;
    cantidad_producto[3]=23;
    n=4;*/
  	system("cls");
    d=0;
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    while(dia){
        cout << setw (16);
        mktime(now);
        cout << (now->tm_year + 1900) << '-'
             << (now->tm_mon + 1) << '-'
             <<  now->tm_mday
             << endl;
        cout << setw (20);
        cout << "Opciones"<<endl;
        cout << "1. Listar Productos."<<endl;
        cout << "2. Ingresar Nuevos Productos."<<endl;
        cout << "3. Reportar Compra de Productos en inventario."<<endl;
        cout << "4. Reportar Devolución de Productos en inventario."<<endl;
        cout << "5. Reportar Venta de Productos en inventario."<<endl;
        cout << "6. Finalizar dia."<<endl;
        cout << "7. Salir del inventario."<<endl;

        cout << "Digite la opción deseada."<<endl;
        cin  >> op;

        switch (op){
        case 1:
            cout << "Los productos y su catidad son: "<<endl;
            for (int j=0;j<n;j++){
                cout <<j+1<<". "<<nombre_producto[j]<< setw (20-nombre_producto[j].length())<< cantidad_producto[j]<<endl;
            }
            break;

        case 2:
            cin.ignore();
            cout <<"Digite el nombre del producto:"<<endl;
                    getline(cin,nombre_producto[n]);
            cout <<"Digite Cantidad:"<<endl;
            cin  >> cantidad_producto[n];
            n++;
            cout <<"Producto añadido de manera exitosa"<<endl;
            break;
        case 3:
            system("cls");
            sw=true;
            while (sw){
                cout <<"Digite el codigo del producto que se compró:"<<endl;
                cin  >>cod;
                cout <<"Digite la cantidad del producto:"<<endl;
                cin  >> cant;
                cantidad_producto[cod-1] += cant;
                compra_dia[d][cod-1]     += cant;
                cout <<"Se han añadido "<<cant<< " unidades de "<<nombre_producto[cod-1]<<" exitosamente."<<endl;
                cout <<"¿Desea continuar? 0 para contiunar, 1 para salir."<<endl;
                cin  >>cont;
                if(cont!=0){sw=false;}
            }
            system("cls");
            break;

        case 4:
            system("cls");
            sw=true;
            while (sw){
                cout <<"Digite el codigo del producto que se va a devolver:"<<endl;
                cin  >>cod;
                cout <<"Digite la cantidad de producto:"<<endl;
                cin  >> cant;
                if(cant<=cantidad_producto[cod-1]){
                    cantidad_producto[cod-1] -= cant;
                    devolucion_dia[d][cod-1] += cant;
                    cout <<"Se han retirado "<<cant<< " unidades de "<<nombre_producto[cod-1]<<" exitosamente."<<endl;
                }else{
                    cout <<"ERROR: La cantidad de producto ingresado es mayor a la del inventario"<<endl;
                }
                cout <<"¿Desea continuar? 0 para contiunar, 1 para salir."<<endl;
                cin  >>cont;
                if(cont!=0){sw=false;}
            }
            system("cls");
            break;

        case 5:
            system("cls");
            sw=true;
            while (sw){
                cout <<"Digite el codigo del producto que se va a vender:"<<endl;
                cin  >>cod;
                cout <<"Digite la cantidad de producto:"<<endl;
                cin  >> cant;
                if(cant<=cantidad_producto[cod-1]){
                    cantidad_producto[cod-1] -= cant;
                    venta_dia[d][cod-1]      += cant;
                    cout <<"Se han vendido "<<cant<< " unidades de "<<nombre_producto[cod-1]<<" exitosamente."<<endl;
                }else{
                    cout <<"ERROR: La cantidad de producto a vendido es mayor a la del inventario"<<endl;
                }
                cout <<"¿Desea continuar? 0 para contiunar, 1 para salir."<<endl;
                cin  >>cont;
                if(cont!=0){sw=false;}
            }
            system("cls");
            break;

        case 6:
            for (int i=0;i<n;i++){
               cout <<"Producto: "          <<nombre_producto[i]  <<endl;
               cout <<"Cantidad comprada: " <<compra_dia[d][i]    <<endl;
               cout <<"Cantidad vendida: "  <<venta_dia[d][i]     <<endl;
               cout <<"Cantidad regresada: "<<devolucion_dia[d][i]<<endl;
               cout <<""<<endl;
            }
            d++;
            now->tm_mday++;
            system("pause");
            system("cls");
            break;
        case 7:
            cout <<"BAI"<<endl;
            dia=false;
            break;
        }
    }
 	return 0;
}
