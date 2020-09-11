#ifndef __ESCENARIO_HPP__
#define __ESCENARIO_HPP__
#define FIL 5
#define COL 5

class Arma
{
private:
	short cantBalas;
	char tipo;
public:
	Arma() { cantBalas = 5; tipo = 'p'; }
	Arma(short c, char t) { cantBalas = c; tipo = t; }
	~Arma() {}


};
//###################################################
class Inventario {
private:
	Arma* lista;
public:
	Inventario() {//Composicion:creo las armas
		lista = new Arma[5];
	}
	~Inventario() {
		delete lista;
	}
};
//###################################################

class Personaje {
private:
	short vidaActual;
	short vidaMaxima;
	short posicion;
	short ataqueBase;
	short defensaBase;
	short tipoPersonaje;
	Inventario* armamento;
public:
	Personaje() {
		vidaActual = 5;
		vidaMaxima = 10;
		posicion = 0;
		ataqueBase = defensaBase = 1;
		tipoPersonaje = 1;
		armamento = nullptr;
	}
	Personaje(short vidaActual, short vidaMaxima, short posicion, short ataqueBase, short defensaBase,
		short tipoPersonaje) {
		this->vidaActual = vidaActual;
		this->vidaMaxima = vidaMaxima;
		this->posicion = posicion;
		this->ataqueBase = ataqueBase;
		this->defensaBase = defensaBase;
		this->tipoPersonaje = tipoPersonaje;
	}
	void asignarArmamento(Inventario* inv) {//relacion de asociacion se realiza por métodos
		armamento = inv;
	}
	void retirarArmamento() {//quitar la relacion de asociacion
		armamento = nullptr;
	}
	void desplazarDerecha() {
		posicion++;
	}
	void desplazarIzquierda() {
		posicion--;
	}
	//TO-DO set get
	void mostrar() {
		cout << "vida Actual:" << vidaActual << endl;
		cout << "vidaMaxima:" << vidaMaxima << endl;
		cout << "posicion:" << posicion << endl;
		cout << "ataqueBase:" << ataqueBase << endl;
		cout << "defensaBase:" << defensaBase << endl;
		cout << "tipoPersonaje:" << tipoPersonaje << endl;
	}
};
//###################################################
class Escenario
{
private:
	char** imagen;
	Personaje* personajes;
public:
	/*Escenario() {//cuando se crea el escenario, se crea tambien los personajes
		imagen = new char*[FIL];
		for (int i = 0; i < FIL; ++i) {
			imagen[i] = new char[COL];
		}
		personajes = new Personaje[5];//relacion de composicion
	}*/
	Escenario(Personaje* p) {//para que se cree el escenario le paso los personajes
		imagen = new char* [FIL];
		for (int i = 0; i < FIL; ++i) {
			imagen[i] = new char[COL];
		}
		personajes = p;//relacion de agregación
	}
	~Escenario() {
		for (int i = 0; i < FIL; ++i) {
			delete imagen[i];
		}
		delete imagen;
		//delete personajes;//relacion de composicion
	}
	void setImagen(char** i) { imagen = i; }
	char** getImagen() { return imagen; }
};

//###################################################



#endif // !