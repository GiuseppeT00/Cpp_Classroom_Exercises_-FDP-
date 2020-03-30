#include "LLinkedBased_List.h"
#include "MyFunctions.h"
#include <fstream>
#include <sstream>

struct dishes {
	int code;
	string descr;
	string ingr1_code;
	int qnt1;
	string ingr2_code;
	int qnt2;
};

struct products {
	string code;
	string descr;
	int qnt;
};

inline void productsReadInsert(List<Product>&);

inline void ricettesReadInsert(List<Dish>&);

inline void cookDish(List<Dish>&, List<Product>&, int);

int main() {
	
	LList<Product> Dispensa;
	LList<Dish> Ricette;

	productsReadInsert(Dispensa);
	ricettesReadInsert(Ricette);
	
	cout << "'Dispensa' list :" << endl;
	cout << "Format :  ( ID ; DESCRIPTION ; QUANTITY ) ." << endl;
	cout << "/ means -> not instered." << endl;
	listPrint(Dispensa);

	cout << "'Ricette' list :" << endl;
	cout << "Format :  ( ID ; DESCRIPTION ; (INGR_1 ; QUANTITY_INGR_1) ; (INGR_2 ; QUANTITY_INGR_2) ) ." << endl;
	cout << "/ means -> not instered." << endl;
	listPrint(Ricette);

	int dish_to_control;

	do {
		cout << "\n\nWhat number of dish do you want to control? (0 to stop.) ";
		cin >> dish_to_control;

		if (dish_to_control > 0 && dish_to_control <= Ricette.length()) {
			cookDish(Ricette, Dispensa, dish_to_control);
			listPrint(Dispensa); cout << endl; listPrint(Ricette);
		}
		else if(dish_to_control != 0) cout << "Invalid dish's number...!" << endl;

	} while (dish_to_control != 0);

	return 0;
}

void productsReadInsert(List<Product>& Dispensa) {
	ifstream dispensa("dispensa.txt");
	string temp;
	products prodotti;

	if (dispensa.is_open()) {

		while (getline(dispensa, prodotti.code, ';')) {

			getline(dispensa, prodotti.descr, ';');
			getline(dispensa, temp);
			istringstream token(temp);
			token >> prodotti.qnt;
			insertUnique(Dispensa, Product(prodotti.code, prodotti.descr, prodotti.qnt));
		}
		dispensa.close();
	}
	else {
		cout << "Unable to open the file...!" << endl;
		exit(-1);
	}
}

void ricettesReadInsert(List<Dish>& Ricette) {
	ifstream ricette("ricette.txt");
	dishes piatti;
	string temp;

	if (ricette.is_open()) {

		while (getline(ricette, temp, ';')) {

			istringstream token2(temp);
			token2 >> piatti.code;
			getline(ricette, piatti.descr, ';');
			getline(ricette, piatti.ingr1_code, ';');
			getline(ricette, temp, ';');
			istringstream token3(temp);
			token3 >> piatti.qnt1;
			getline(ricette, piatti.ingr2_code, ';');
			getline(ricette, temp);
			istringstream token4(temp);
			token4 >> piatti.qnt2;

			insertOrdered(Ricette, Dish(piatti.code, piatti.descr, Product(piatti.ingr1_code, piatti.qnt1), Product(piatti.ingr2_code, piatti.qnt2)));
		}
		ricette.close();
	}
	else {
		cout << "Unable to open the file...!" << endl;
		exit(-1);
	}
}

void cookDish(List<Dish> & Ricette, List<Product> & Dispensa, int dish_to_control) {
	int disponibility = 0;
	int ric_pos = Ricette.currPos();
	int dis_pos = Dispensa.currPos();
	Ricette.setPos(dish_to_control - 1);

	Product ingredient_1 = Ricette.getValue().ingr1_key();
	Product ingredient_2 = Ricette.getValue().ingr2_key();

	for (Dispensa.moveToStart(); Dispensa.currPos() < Dispensa.length(); Dispensa.next())
	{
		if (Dispensa.getValue() == ingredient_1 && Dispensa.getValue().qnt_key() >= ingredient_1.qnt_key()) {
			Product removed = Dispensa.remove();
			Dispensa.insert(removed - ingredient_1);
			disponibility++;
		}
		else if (Dispensa.getValue() == ingredient_2 && Dispensa.getValue().qnt_key() >= ingredient_2.qnt_key()) {
			Product removed = Dispensa.remove();
			Dispensa.insert(removed - ingredient_2);
			disponibility++;
		}
	}

	if (disponibility == 2) cout << "Products were avaiables! Dish cooked!" << endl;
	else cout << "Products were not avaiables! Sorry but dish wasn't cook" << endl;

	Ricette.setPos(ric_pos);
	Dispensa.setPos(dis_pos);
}