#include "gprLoader.h"
#include "Graph.h"

int main() {
	int menu;
	Graph * graph = new Graph();


	do {
		cout << "-----------------------------------------------------------------" << endl
			<< "Bonjour, choisissez l'une des options suivantes :" << endl
			<< "1 : Charger un fichier gpr" << endl
			<< "2 : Lecture du graphe en memoire" << endl
			<< "3 : Algorithmes" << endl
			<< "4 : Credits" << endl
			<< "5 : Quitter le programme" << endl
			<< "-----------------------------------------------------------------" << endl;
		do {
			cin >> menu;
			if (menu < 0 || menu > 5)
				cout << " ----- " << endl
				<< "Le choix doit être compris entre 1 et 5" << endl
				<< " ----- " << endl;
		} while (menu < 0 || menu > 5);
		switch (menu) {
		case 1:
			break;
		case 2:
			if (graph) == 0 && graph->nbrEdge() == 0) {
				cout << " ----- " << endl
					<< "Le graphe n'est pas initialise, impossible d'afficher" << endl
					<< " ----- " << endl;
				system("pause");
			}
			else
				cout << graph->toString(*graph) << endl;
			break;
		case 3:
			break;
		case 4:
			cout << " ----- " << endl
				<< "Projet realise par :" << endl
				<< "- BRANSTETT Tim" << endl
				<< "- MERI-ALVAREZ Yanice" << endl
				<< "- ROGARD-COAT Emmanuel" << endl
				<< endl
				<< "Dans le cadre de l'unite Recherche Operatoire : Modelisation" << endl
				<< "Annee 2017-2018" << "-" << "L3-Informatique" << endl
				<< " ----- " << endl;
			system("pause");
			break;
		case 5:
			break;
		}

	} while (menu != 5);
	cout << endl;
	system("pause");

	return 0;
}
