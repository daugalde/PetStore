#include <iostream>
#include <fstream>

using namespace std;

//CLASE NODO BINARIO ===========================================================
class NodoBinario{
  public:
  	int num_cliente;
  	int id_animal;
	string nombre;
	string tipo_mascota;
	string raza;
	string dia_n; 
	string mes_n; 
	string year_n; 
	string sexo; 	
	string color; 
	string castrado;
	string dia_v; 
	string mes_v; 
	string year_v;
	
	NodoBinario* Hizq;
	NodoBinario* Hder;
	int FB;
  	
  	
  	
    NodoBinario(int num_c, int id, string nom, string tipo, string raza, string dia_n, string mes_n, string year_n, string sexo, string color, string castrado, string dia_v, string mes_v, string year_v ) {
        num_cliente = num_c;
        id_animal = id;
        nombre = nom;
        tipo_mascota = tipo;
        this->raza = raza;
        this->dia_n = dia_n;
        this->mes_n = mes_n;
        this->year_n = year_n;
        this->sexo = sexo;
        this->color = color;
        this->castrado = castrado;
        this->dia_v = dia_v;
        this->mes_v = mes_v;
        this->year_v = year_v;

        Hizq = NULL;
        Hder = NULL;
        FB = 0;
    }

    friend class Binario;

};

typedef NodoBinario* pNodoBinario;


//CLASE DEL ARBOL AVL ===========================================================
class Binario{
public:
	NodoBinario* raiz;
    bool Hh = false;
    Binario() { raiz = NULL; }

    void InsertarBalanceado(NodoBinario* &ra, bool &Hh, int num_c, int id, string nom, string tipo, string raza, string dia_n, string mes_n, string year_n, string sexo, string color, string castrado, string dia_v, string mes_v, string year_v);
    void RotacionDobleIzquierda(NodoBinario *n1, NodoBinario *n2);
    void RotacionDobleDerecha(NodoBinario *n1, NodoBinario *n2);
    void RotacionSimpleIzquierda(NodoBinario *n1, NodoBinario *n2);
    void RotacionSimpleDerecha(NodoBinario *n1, NodoBinario *n2);
    
    void buscar(NodoBinario* raiz, int num);
    bool Repetido(int dato, NodoBinario* raiz);
    void MostrarArbol(NodoBinario* raiz);
    void Modificar(int dato, string nuevo_nombre, string nuevo_dato2 ,NodoBinario* raiz);
    
    friend class NodoBinario;
};



void Binario::InsertarBalanceado(NodoBinario* &ra, bool &Hh, int num_c, int id, string nom, string tipo, string raza, string dia_n, string mes_n, string year_n, string sexo, string color, string castrado, string dia_v, string mes_v, string year_v){
	pNodoBinario n1;
	
    if(ra == NULL){
        ra = new NodoBinario(num_c, id, nom, tipo, raza, dia_n, mes_n, year_n, sexo, color, castrado, dia_v, mes_v, year_v);
        Hh = true;
        
    }else{
        if(id <= ra->id_animal){
            InsertarBalanceado(ra->Hizq, Hh, num_c, id, nom, tipo, raza, dia_n, mes_n, year_n, sexo, color, castrado, dia_v, mes_v, year_v);
			
        if(Hh){
            switch(ra->FB){
                case 1: 
					ra->FB=0;
	                Hh = false;
	                break;
                case 0: 
					ra->FB  = -1;
	                break;
                case -1: 
					n1 = ra->Hizq;
	                if(n1->FB =-1){
	                    RotacionSimpleIzquierda(ra, n1);
	                }else{
	                    RotacionDobleIzquierda(ra,n1);
	                }
	            Hh = false;
	            break;
            }
        }
        }else{
            if(id > ra->id_animal){
                InsertarBalanceado(ra->Hder, Hh, num_c,id, nom, tipo, raza, dia_n, mes_n, year_n, sexo, color, castrado, dia_v, mes_v, year_v);

                if(Hh){
                    switch(ra->FB){
                        case -1: 
							ra->FB=0;
	                        Hh = false;
	                        break;
                        case 0: 
							ra->FB=1;
	                        break;
                        case 1:
							n1=ra->Hder;
	                        if(n1->FB=1){
	                            RotacionSimpleDerecha(ra, n1);
	                        }else{
	                            RotacionDobleDerecha(ra, n1);
	                        }
	                        Hh=false;
	                        break;
                    	}	
                	}
           	 	}
        	}
    	}
	}

void Binario::RotacionDobleIzquierda(NodoBinario* n, NodoBinario* n1){
    NodoBinario *n2;
    n2=n1->Hder;
    n->Hizq = n2->Hder;
    n2->Hder=n;
    n1->Hder=n2->Hizq;
    n2->Hizq=n1;

    if(n2->FB==1){
        n1->FB=-1;
    }else{
        n1->FB=0;
    }
    if(n2->FB==-1){
        n->FB=1;
    }else{
        n->FB=0;
    }
    n2->FB=0;
    n=n2;
}

void Binario::RotacionDobleDerecha(NodoBinario* n, NodoBinario* n1){
    NodoBinario *n2;
    n2=n1->Hizq;
    n->Hder = n2->Hizq;
    n2->Hizq=n;
    n1->Hizq=n2->Hder;
    n2->Hder=n1;

    if(n2->FB==1){
        n->FB=-1;
    }else{
        n->FB=0;
    }
    if(n2->FB==-1){
        n1->FB=1;
    }else{
        n1->FB=0;
    }
    n2->FB=0;
    n=n2;
}

void Binario::RotacionSimpleDerecha(NodoBinario* n, NodoBinario* n1){
    n->Hder=n1->Hizq;
    n1->Hizq=n;

    if(n1->FB==1){
        n->FB=0;
        n1->FB=0;
    }else{
        n->FB=1;
        n1->FB=-1;
    }
    n=n1;
}

void Binario::RotacionSimpleIzquierda(NodoBinario* n, NodoBinario* n1){
    n->Hizq=n1->Hder;
    n1->Hder=n;

    if(n1->FB==-1){
        n->FB=0;
        n1->FB=0;
    }else{
        n->FB=-1;
        n1->FB=-1;
    }
    n=n1;
}


bool Binario::Repetido(int dato, NodoBinario* raiz) {
    if (raiz == NULL) {
        return false;
    }
    if (dato == raiz->id_animal) {
        return true;
    }
    if (dato < raiz->id_animal) {
        return Repetido(dato, raiz->Hizq);
    }
    return Repetido(dato, raiz->Hder);
}

void Binario::buscar(NodoBinario* raiz, int num){ 
    if (raiz == NULL) {
       	return; // El nodo no está en el árbol
    }
    if (num == raiz->num_cliente) {
        cout<<"Numero del cliente: "<<raiz->num_cliente<<endl<<"Nombre de la mascota: "<<raiz->nombre<<endl; // El nodo ha sido encontrado
    }
    if (num <= raiz->num_cliente) {
        return buscar(raiz->Hizq, num); // Buscar en el subárbol izquierdo
    } else {
        return buscar(raiz->Hder, num); // Buscar en el subárbol derecho
    }
}

void Binario::MostrarArbol(NodoBinario* raiz){
    if (raiz != NULL){
        MostrarArbol(raiz->Hizq);
        cout << "ID: " << raiz->id_animal << ", Nombre: " << raiz->nombre << endl;
        MostrarArbol(raiz->Hder);
    }
}

void Binario::Modificar(int dato, string nuevo_nombre, string nuevo_dato2 ,NodoBinario* raiz) {
    if (raiz == NULL) {
        return;
    }
    if (dato == raiz->id_animal) {
        raiz->nombre = nuevo_nombre;
        raiz->castrado = nuevo_dato2;
        cout<<"Nuevo nombre: "<<raiz->nombre<<", Castrado: "<<raiz->castrado<<endl;
        return;
    }
    if (dato < raiz->id_animal) {
        return Modificar(dato, nuevo_nombre, nuevo_dato2, raiz->Hizq);
    }
    return Modificar(dato, nuevo_nombre, nuevo_dato2, raiz->Hder);
}

//FUNCIONES ===========================================================


int ConvertirEntero(string str){
    int numero = 0;
    int largo = str.length();
    int factor = 1;

    for (int i = largo - 1; i >= 0; i--){
        int digito = str[i] - '0';
        numero += digito * factor;
        factor *= 10;
    }
    return numero;
}

void leerAVL(char nombre[16], Binario &arbol){
	ifstream archivo(nombre);
	string linea;
	
    while (!archivo.eof()){
        getline(archivo, linea);
        
        string dato = "";
		string dato2 = "";
		string dato3 = "";
		string dato4 = "";
		string dato5 = "";
		string dato6 = "";
		string dato7 = "";
		string dato8 = "";
		string dato9 = "";
		string dato10 = "";
		string dato11 = "";
		string dato12 = "";
		string dato13 = "";
		string dato14 = "";
		
		int contador = 0;
        
        if(linea != ""){
			for (int i = 0; i<linea.size(); i++){
				if(linea[i]==';')
					contador ++;
				else{
					switch(contador){
						case 0:
							dato = dato + linea[i];
							break;
						case 1:
							dato2 = dato2 + linea[i];
							break;
						case 2:
							dato3 = dato3 + linea[i];
							break;
						case 3:
							dato4 = dato4 + linea[i];
							break;
						case 4:
							dato5 = dato5 + linea[i];
							break;
						case 5:
							dato6 = dato6 + linea[i];
							break;
						case 6:
							dato7 = dato7 + linea[i];
							break;
						case 7:
							dato8 = dato8 + linea[i];
							break;
						case 8:
							dato9 = dato9 + linea[i];
							break;
						case 9:
							dato10 = dato10 + linea[i];
							break;		
						case 10:
							dato11 = dato11 + linea[i];
							break;
						case 11:
							dato12 = dato12 + linea[i];
							break;
						case 12:
							dato13 = dato13 + linea[i];
							break;
						default:
							dato14 = dato14 + linea[i];
						}
					}
				}
			
			int dato1 = ConvertirEntero(dato);
			int d2 = ConvertirEntero(dato2);
			
			

			if(!arbol.Repetido(d2, arbol.raiz)){ //a;adir validar si el numero del cliente esta en arbol de clientes 
				arbol.InsertarBalanceado(arbol.raiz, arbol.Hh, dato1, d2, dato3,dato4, dato5, dato6, dato7, dato8, dato9, dato10, dato11, dato12, dato13, dato14);	
			}
		}
		
    }
    archivo.close();
}





/*int main(){
	Binario arbol;
	leerAVL("Mascotas.txt", arbol);
	arbol.MostrarArbol(arbol.raiz);
	cout<<endl;
	arbol.buscar(arbol.raiz, 1);
	cout<<endl;
	arbol.Modificar(23,"Luna", "no",arbol.raiz);


	return 0;
}*?
