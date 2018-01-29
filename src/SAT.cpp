#include "SAT.h"
/******************/
/**   CLASE SAT  **/
/******************/

SAT::SAT() {
	numVariables = 0;
	numClausulas = 0;
};

void SAT::setNumVariables(int n) {
	numVariables = n;
};

int SAT::getNumVariables() {
	return numVariables;
};

int SAT::getNumClausulas() {
	return clausulas.size();
};

vector<int> SAT::getClausula(int n) {
	return clausulas.at(n);
};

int SAT::getNumLiteralesClausula(int n) {
	return clausulas.at(n).size();
};


//Cuando leemos por fichero la liena la guardamos en un string
//esto separa cada int de la linea leida
vector<int> SAT::separarInt(string v) {
	vector<int> vector;
	string item;
	char delim = ' ';
	stringstream aux(v);

	while (getline(aux, item, delim)) {
		vector.push_back(atoi(item.c_str()));
	}

	return vector;
};

//Cuando leemos por fichero la linea la guardamos en un string
//esto separa cada palabra de la linea leida
vector<string> SAT::separarString(string v) {
	vector<string> vector;
	string item;
	char delim = ' ';
	stringstream aux(v);

	while (getline(aux, item, delim)) {
		vector.push_back(item);
	}

	return vector;
};

void SAT::pushClausula(vector<int> clausula) {
	clausulas.push_back(clausula);
};

//Leemos del fichero

ifstream &operator>>( ifstream  &fich, SAT &S ) {
	string line =" ";
	getline(fich,line);

	//Si es un comentario ignoramos la linea
	while(line[0] == 'c' && line[1] == ' ') {
		getline(fich,line);
	}

	//El fichero tiene que tener el formato CNF que es p cnf si no es asi, dara error
	if(line[0]!= 'p') {
		throw invalid_argument( "Falta p (ERROR Formato CNF)" );
	} else {
		vector<string> read = S.separarString(line);

		if (read.size() != 4) {
			throw invalid_argument( "Falta cnf (ERROR Formato CNF)" );
		}

		//Despues del formato nos dan el numero de variables y clausulas

		S.numVariables = atoi(read[2].c_str());
		S.numClausulas = atoi(read[3].c_str());

		vector<int> clausula;
		//En cada linea ira una nueva clausula, y acabara en cero, si no es asi error de formato
		while(getline(fich,line)) {
			clausula = S.separarInt(line); // Separamos el string en int
			if(clausula.at(clausula.size()-1) == 0)
				S.pushClausula(clausula); //Anadimos esta clausula a nuestro SAT
			else
				throw invalid_argument( "Falta 0 (ERROR Formato CNF)" );
		}
	}
	return fich;
}

//En el nuevo fichero meteremos el formato
ofstream &operator<<( ofstream  &of, SAT &S ) {
	of << "c COMENTARIO" << endl;
	of << "p cnf " << S.getNumVariables() << " " << S.getNumClausulas() << endl;
	for(int i  = 0; i< S.getNumClausulas(); i++) {
		for(int j= 0; j <  S.getNumLiteralesClausula(i); j++) {
			of << S.clausulas[i][j] << " ";
		}
		of << 0;
		of << endl;
	}
	return of;
}

//Nos muestra por pantalla el resultado (igual formato que en fichero)
ostream &operator<<( ostream  &os, SAT &S ) {
	os << "c COMENTARIO" << endl;
	os << "p cnf " << S.getNumVariables() << " " << S.getNumClausulas() << endl;
	for(int i  = 0; i< S.getNumClausulas(); i++) {
		for(int j= 0; j <  S.getNumLiteralesClausula(i); j++) {
			os << S.clausulas[i][j] << " ";
		}
		os << 0;
		os << endl;
	}
	return os;
}
