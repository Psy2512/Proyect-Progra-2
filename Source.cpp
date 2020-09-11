#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include "Clases.hpp"
int main() {
	short v;
	Personaje* p = new Personaje[5];
	/*cout << "Ingrese Vida Actual";
	cin >> v;*/
	p[0] = Personaje(1, 4, 2, 3, 1, 1);
	p[1] = Personaje();
	p[2] = Personaje(1, 4, 2, 3, 1, 1);
	p[3] = Personaje();
	p[4] = Personaje(1, 4, 2, 3, 1, 1);
	Escenario* e = new Escenario(p);//relacion de agregacion
	Inventario* i1 = new Inventario();//composicion(automaticamente creará las armas)
	p[0].asignarArmamento(i1);//relacion de asociacion(asignar)
	p[0].retirarArmamento();//relacion de asociacion(quitar)
	//generando movimiento del objeto
	p[0].desplazarDerecha();
	for (int i = 0; i < 5; ++i) {
		p[i].mostrar();
	}
	cin.get();
	return 0;
}