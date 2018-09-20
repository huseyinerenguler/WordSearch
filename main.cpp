#include <iostream>
#include <string>
#include <fstream> // for read txt files, keyw --> ifstream
#include <sstream> // for convert integer to string, keyw --> ostringstream

#include "LinkedList.h"
#include "BinaryTree.h"


// function prototype
string intToString (int);
void removeSpecials (string*);

using namespace std;
 
 
int main() {
	
	LinkedList<string> list;
	BinaryTree<string> tree;
	
	int totalNumberOfTxtFiles; // 9600
	int numberOfStopWords = 174;
	int completedPercentage = 0;
	
	string searchWord;
	string readWord;
	string stopWords[numberOfStopWords];
	
	string readWordsFileDirectory;
	string stopWordsFileDirectory = "stopwords.txt"; // constant.
	
	ifstream readWordsFile;	
	ifstream stopWordsFile;
		
	
	while(true) {
		
		system("cls");
		
		cout << "In how many files do you want to search? (max:9600): ";
		cin >> totalNumberOfTxtFiles;
				
		if (totalNumberOfTxtFiles < 1) {
			cout << "It must be greater than zero!" << endl;
			cout << "\nDo you want search again (y/n): ";
			string choice; cin >> choice;
			if (!(choice == "y" || choice == "Y"))
				return 0;
			continue;
		}
			
		if (totalNumberOfTxtFiles > 9600)
			totalNumberOfTxtFiles = 9600;
		
		cout << "Enter a word, (use just lowercase and letters): ";
		cin >> searchWord;
		
		removeSpecials(&searchWord);
	
		// stopWords[] okuyup doldurma kýsmý
		stopWordsFile.open(stopWordsFileDirectory.c_str());
		if (stopWordsFile.is_open()) {
			int index = 0;
			while(stopWordsFile >> stopWords[index])
				index++;
		}
		stopWordsFile.close();	
	
		// txt'leri tek tek okuma kýsmý	
	    for (int numberOfTxtFile = 1; numberOfTxtFile <= totalNumberOfTxtFiles; numberOfTxtFile++) {
	    	readWordsFileDirectory = "AllDocs\\" + intToString(numberOfTxtFile) + ".txt";
	    	
	    	// txt'den her kelime okunuyor
		    readWordsFile.open(readWordsFileDirectory.c_str());
			if (readWordsFile.is_open()) {			
		        while (readWordsFile >> readWord) {
		        	
					removeSpecials(&readWord);
					
					if (readWord.length() > 0) {
						int flag = 0;
						
						for (int i = 0; i < numberOfStopWords; i++) {
							if (readWord.compare(stopWords[i]) == 0)
									flag = 1;
						}
						
						if (flag == 0)
							list.insert(readWordsFileDirectory, readWord);
							tree.insert(readWordsFileDirectory, readWord);					
					}	
		        }
		    }
		    readWordsFile.close();
		    

			int tempPercentage = (numberOfTxtFile * 100) / totalNumberOfTxtFiles;
			
			if (completedPercentage != tempPercentage) {
				completedPercentage = tempPercentage;
				
				system("cls");
				cout << "Searching Word: " << searchWord << endl;
				cout << "Progress: " << intToString(completedPercentage) << "% ";
			}
		}
		
		cout << "\n\n---------------------------------" << endl;
		cout << "  Linked List Searching Results" << endl;
		cout << "---------------------------------" << endl;
		list.showSingleWord(searchWord);		
		
		cout << "\n\n---------------------------------" << endl;
		cout << "  Binary Tree Searching Results" << endl;
		cout << "---------------------------------" << endl;
		tree.printListOfFiles(searchWord);
		
		
		cout << "\n\nDo you want search again (y/n): ";
		string choice; cin >> choice;
		if (!(choice == "y" || choice == "Y"))
			return 0;
	}
	
    return 0;
}

string intToString (int number) {
    ostringstream temp;
    temp << number;
    return temp.str();
}

void removeSpecials (string *str) {
	
	int index = 0;
	int len = str->length();
	
	while (index < len) {
	
		char c = (*str)[index];
		
		if (((c>='A')&&(c<='Z')) || ((c>='a')&&(c<='z'))) {
			
			if (((c>='A')&&(c<='Z')))
				(*str)[index] += 32; // make lowercase
			index++;
		}
		
		else {
			str->erase(index);
			len--;
		}	
	}
}
