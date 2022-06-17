



void Plansza::GRA(){
    gracze[0].rusz_Gracza(kosc.rzut_Kostka());
    cout << "\n pozycja gracza to pole: " << gracze[0].pobierz_Lokalizacje() << endl;
    cout << "\n kasa gracza to: " << gracze[0].pobierz_Ilosc_Pieniedzy() << endl;
    bankier.daj_pieniadze_graczowi(gracze[0], 3333);
    cout << "\n kasa gracza to: " << gracze[0].pobierz_Ilosc_Pieniedzy() << endl;
}

//Wyświetlanie planszy
void Plansza::displayHorizontal(int firstSpace, int lastSpace, int numPlayers){

	int numSpaces = abs(lastSpace - firstSpace) + 1;

	//first line for all cards
	for(int i = 0; i < numSpaces; i++){
		cout << "----------";
	}
	
	cout << "-" << endl;

	//second line
	for(int i = 0; i < numSpaces; i++){

		Space current;

		if(firstSpace < lastSpace) {
			current = pola[firstSpace + i];
		} else {
			current = pola[firstSpace - i];
		}

		if(current.getType() == "Nieruchomość"){ 
			cout << "|--"; 
			for(int x = 0; x < current.getHouses(); x++){
			    cout << "X";
			}
			for(int x = 0; x < 7-(current.getHouses()); x++){
			    cout << "-";
			} 
		} else {
			cout << "|" << current.getName(0);
		}
	}
	
	cout << "|" << endl;

	//third line
	for(int i = 0; i < numSpaces; i++){

		Space current;

		if(firstSpace < lastSpace) {
			current = pola[firstSpace + i];
		} else {
			current = pola[firstSpace - i];
		}

		if(current.getType() == "Nieruchomość"){ 
			cout << "|" << current.getName(0);
		} else {
			cout << "|" << current.getName(1);
		}
	}
	
	cout << "|" << endl;

	//fourth line
	for(int i = 0; i < numSpaces; i++){

		Space current;

		if(firstSpace < lastSpace) {
			current = pola[firstSpace + i];
		} else {
			current = pola[firstSpace - i];
		}

		if(current.getType() == "Nieruchomość"){ 
			cout << "|" << current.getName(1);
		} else {
			cout << "|" << "         ";
		}
	}
	
	cout << "|" << endl;

	//fifth line

	for(int i = 0; i < numSpaces; i++){

		int counter = 0;		

		if(firstSpace < lastSpace) {

		    cout << "|   ";
		    for(int j = 0; j < numPlayers; j++){
			if((firstSpace + i) == (gracze[j].getLocation())){
				cout << gracze[j].getGamePiece();
				counter++;
			}
		    }	
		    for(int x = 0; x < (6-counter); x++){
		        cout << " ";
		    }	

		} else {

		    cout << "|   ";
		    for(int j = 0; j < numPlayers; j++){
			if((firstSpace - i) == (gracze[j].getLocation())){
				cout << gracze[j].getGamePiece();
				counter++;
			}
		    }	
		    for(int x = 0; x < (6-counter); x++){
		        cout << " ";
		    }	

		}	
	}
	
	cout << "|" << endl;

	//sixth line
	for(int i = 0; i < numSpaces; i++){

		Space current;

		if(firstSpace < lastSpace) {
			current = pola[firstSpace + i];
		} else {
			current = pola[firstSpace - i];
		}

		if(current.getType() == "Nieruchomość"){ 
			cout << "|" << current.getActionText(0);
		} else {
			cout << "|" << current.getActionText(0);
		}
	}
	
	cout << "|" << endl;

	//seventh line
	for(int i = 0; i < numSpaces; i++){

		Space current;

		if(firstSpace < lastSpace) {
			current = pola[firstSpace + i];
		} else {
			current = pola[firstSpace - i];
		}

		if(current.getType() == "Nieruchomość"){ 
			cout << "|" << current.getActionText(1);
		} else {
			cout << "|" << current.getActionText(1);
		}
	}
	
	cout << "|" << endl;
	
	//eighth line
	for(int i = 0; i < numSpaces; i++){
		cout << "----------";
	}
	
	cout << "-" << endl;
}

void Plansza::displayVertical(int firstSpace, int lastSpace, int numPlayers){

	Space current = pola[firstSpace];
	Space current2 = pola[lastSpace];

	//toplines
	if(firstSpace != 19){

		cout << "-----------";

		for(int i = 0; i < 8; i++){
			cout << "          ";
		}

		cout << "         ";
		cout << "-----------" << endl;

	}

	
	
	//first line
	if(current.getType() == "Nieruchomość"){
		cout << "|--"; 
		for(int x = 0; x < current.getHouses(); x++){
			cout << "X";
		}
		for(int x = 0; x < 7-(current.getHouses()); x++){
			cout << "-";
		} 
	} else{
		cout << "|" << current.getName(0);
	}
	
	cout << "|         ";

	for(int i = 0; i < 8; i++) {
		cout << "          ";
	}

	if(current2.getType() == "Nieruchomość"){
		cout << "|--"; 
		for(int x = 0; x < current2.getHouses(); x++){
			cout << "X";
		}
		for(int x = 0; x < 7-(current2.getHouses()); x++){
			cout << "-";
		} 
	} else{
		cout << "|" << current2.getName(0);
	}
	
	cout << "|" << endl;

	//second line

	if(current.getType() == "Nieruchomość"){
		cout << "|" << current.getName(0);
	} else{
		cout << "|" << current.getName(1);
	}
	
	cout << "|         ";

	for(int i = 0; i < 8; i++) {
		cout << "          ";
	}

	if(current2.getType() == "Nieruchomość"){
		cout << "|" << current2.getName(0);
	} else{
		cout << "|" << current2.getName(1);
	}

	cout << "|" << endl;
	
	//third line
	
	if(current.getType() == "Nieruchomość"){
		cout << "|" << current.getName(1);
	} else{
		cout << "|" << "         ";
	}
	
	cout << "|         ";

	for(int i = 0; i < 8; i++) {
		cout << "          ";
	}

	if(current2.getType() == "Nieruchomość"){
		cout << "|" << current2.getName(1);
	} else{
		cout << "|" << "         ";
	}

	cout << "|" << endl;

	//fourth line

	int counter = 0;		

	cout << "|   ";

	for(int j = 0; j < numPlayers; j++){
		if((firstSpace) == (gracze[j].getLocation())){
			cout << gracze[j].getGamePiece();
			counter++;
		}
	}	

	for(int x = 0; x < (6-counter); x++){
		        cout << " ";
	}

	cout << "|         ";	

	for(int z = 0; z < 8; z++){
	    cout << "          ";
	}

	counter = 0;		

	cout << "|   ";
	
	for(int j = 0; j < numPlayers; j++){
		if((lastSpace) == (gracze[j].getLocation())){
			cout << gracze[j].getGamePiece();
			counter++;
		}
	}	

	for(int x = 0; x < (6-counter); x++){
		        cout << " ";
	}	
	
	cout << "|" << endl;

	//fifth line
	
	if(current.getType() == "Nieruchomość"){
		cout << "|" << current.getActionText(0);
	} else{
		cout << "|" << current.getActionText(0);
	}
	
	cout << "|         ";

	for(int i = 0; i < 8; i++) {
		cout << "          ";
	}

	if(current2.getType() == "Nieruchomość"){
		cout << "|" << current2.getActionText(0);
	} else{
		cout << "|" << current2.getActionText(0);
	}
	
	cout << "|" << endl;

	//sixth line
	
	if(current.getType() == "Nieruchomość"){
		cout << "|" << current.getActionText(1);
	} else{
		cout << "|" << current.getActionText(1);
	}
	
	cout << "|         ";

	for(int i = 0; i < 8; i++) {
		cout << "          ";
	}

	if(current2.getType() == "Nieruchomość"){
		cout << "|" << current2.getActionText(1);
	} else{
		cout << "|" << current2.getActionText(1);
	}
	
	cout << "|" << endl;

}





