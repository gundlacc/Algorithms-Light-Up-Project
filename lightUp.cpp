#include <iostream>
#include <vector>

struct LightPair {
	int lightRow;
	int lightColumn;
};

void printRules() {

	std::cout << "Light Up is played on a rectangular grid. The grid has pound cells (#) and blank cells in it." << std::endl;
	std::cout << "The objective is to place light bulbs on the grid so that every blank square is lit. A cell is" << std::endl;
	std::cout << "illuminated by a light bulb if they're in the same row or column, and if there are no pound cells" << std::endl;
	std::cout << "between them. Also, no light bulb may illuminate another light bulb. Some of the black cells have" << std::endl;
	std::cout << "numbers in them. A number in a cell indicates how many light bulbs share an edge with that cell." << std::endl;
	std::cout << std::endl;
	std::cout << "Here is the board you will be making your guesses for. The numbers on the top and left side are" << std::endl;
	std::cout << "your grid numbers for selecting where you want to place your lights." << std::endl;
	std::cout << std::endl;
}

void buildPrintBoard() {

	char lightBoard[8][8];

	lightBoard[0][0] = ' ';

	for (int i = 1; i < 8; i++)
	{
		char aChar = '0' + i;
		lightBoard[i][0] = aChar;
	}

	for (int j = 1; j < 8; j++)
	{
		char aChar = '0' + j;
		lightBoard[0][j] = aChar;
	}

	for (int i = 1; i < 8; i++)
	{
		for (int j = 1; j < 8; j++)
		{
			lightBoard[i][j] = ' ';
		}
	}

	lightBoard[1][2] = '#';
	lightBoard[2][5] = '2';
	lightBoard[2][7] = '#';
	lightBoard[3][2] = '2';
	lightBoard[4][4] = '4';
	lightBoard[5][6] = '2';
	lightBoard[6][1] = '#';
	lightBoard[6][3] = '2';
	lightBoard[7][6] = '#';


	//PRINTING
	for (int i = 0; i < 8; i++) {
		std::cout << "_";
		for (int j = 0; j < 8; j++) {
			std::cout << lightBoard[i][j];
			std::cout << '|' ;
		}
		std::cout << std::endl;
	}

}

bool answerVerification(std::vector<LightPair> user, std::vector<LightPair> key) {
	int numCorrect = 0;

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			if (user[i].lightRow == key[j].lightRow && user[i].lightColumn == key[j].lightColumn) {
				numCorrect++;
				break;
			}
		}
	}

	if (numCorrect == 12) {
		return true;
	}
	else {
		return false;
	}
}

int main() {

	printRules();
	buildPrintBoard();

	int row = 0;
	int column = 0;

	std::vector<LightPair> answerKey{
		{1, 5},
		{2, 2},
		{2, 6},
		{3, 1},
		{3, 4},
		{4, 3},
		{4, 5},
		{5, 4},
		{5, 7},
		{6, 2},
		{6, 6},
		{7, 3}
	};

	std::cout << "Please make a row and then column selection for where you would like to place your lights." << std::endl;
	std::cout << "when you are finised selecting, please enter -1 as your row and column." << std::endl;

	std::vector<LightPair> userEntries;
	while (row != -1) {
		LightPair p;
		std::cout << "Row: ";
		std::cin >> row;	
		std::cout << "Column: ";
		std::cin >> column;
		std::cout << std::endl;
		p.lightRow = row;
		p.lightColumn = column;
		userEntries.push_back(p);
	}
	userEntries.pop_back();

	bool isRight = answerVerification(userEntries, answerKey);

	if (isRight == true) {
		std::cout << "Your answer was correct! Congrats!" << std::endl;
	}
	else if (isRight == false) {
		std::cout << "I'm sorry, your answer was not correct." << std::endl;
	}

	return 0;
}