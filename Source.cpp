#include <iostream>
#include "folder.h"
#include "File.h"
#include <string>

int main() {
	bool menu = true;
	std::string nameLargest;
	std::string newName;
	int LargestFile = 0;
	int choice;
	int FolderChoice;
	std::string newFolderName;
	std::string newFileName;
	int position;
	const int FileMax=10;
	int numberoffiles = 4;
	std::string answer="yes";
	std::string NewFileName;
	std::string fileName;

	Folder rootFolder("Root folder", 2023);
	Folder PC("PC", 2010);

	rootFolder.addFolder("PC");
	rootFolder.addFolder("Users");
	rootFolder.addFolder("Screenshots");
	rootFolder.addFolder("Games");
	rootFolder.addFolder("Music");

	

	rootFolder.printFolders();

	while (menu) {
		std::cout << "Option 1: open folder\n" << "Option 2: change folder name\n" << "Option 3: add file\n" << "Option 4: terminate program.\n";
		std::cout << "For choosing an option, please type in 1,2,3 or 4\n";
		std::cin >> choice;
		
		switch (choice) {
		//////////////////////////////////////////////
		case 1:
			std::cout << "What folder? Please type number\n";
			std::cin >> FolderChoice;
			switch (FolderChoice) {
			case 1: {
				rootFolder.getFolder("PC")->addFile("Settings ", 2010);
				rootFolder.getFolder("PC")->addFile("Disk_C ", 2010);
				rootFolder.getFolder("PC")->addFile("Disk_D ", 2010);
				rootFolder.getFolder("PC")->addFile("User's guideline.pdf", 2009);

				rootFolder.getFolder("PC")->printFiles();
				////////////////////////////////////////////////////////
				std::cout<<"\n"<<"Want to add new file or folder to this folder ? Type yes or no\n";
				std::cin >> answer;
				if (answer=="yes") {
					std::cout << "How many new files? You can max have 10 files in a folder\n";
					int numFiles;
					std::cin >> numFiles;
					if (numFiles>=0 && numFiles < 7) {
						std::cout << "type new name\n";
						for (int j = 0; j < numFiles; j++)
						{
							std::cin >> NewFileName;

							rootFolder.getFolder("PC")->addFile(NewFileName, 2023);
						}

						rootFolder.getFolder("PC")->printFiles();

						/////////////////////////////////////////////////////////////////

						std::cout << "Want to change file name in folder `PC`? Type yes or no\n";
						std::cin >> answer;
						if (answer == "no") {
							std::cout << "Moving on\n";
						}

						else if (answer == "yes") {
							std::cout << "Please enter the name of the file you want to change\n";
							std::cin >> fileName;
							std::cout << "New name: ";
							std::cin >> newFileName;
							PC.getFolder(fileName)->setName(newFileName);
							PC.printFiles();

						}
						else {
							std::cout << "no files matching found";
						}


						/////////////////////////////////////////////////////////
						std::cout << "Want to add new folder into folder `PC` ? Type yes or no\n";
						std::cin >> answer;
						if (answer == "yes") {
							std::cout << "New name: ";
							std::cin >> newFolderName;
							PC.addFolder(newFolderName);
							std::cout << "\n" << "Now folder PC has : \n";
							rootFolder.getFolder("PC")->printFiles();
							PC.printFolders();
							std::cout << "\n";

							std::cout << "Want to add new file/s into folder `" << newFolderName << "` ? Type yes or no\n";
							std::cin >> answer;
							if (answer == "yes") {
								std::cout << "How many new files?\n";
								int numFiles;
								std::cin >> numFiles;
								if (numFiles > 0 && numFiles < 11) {
									std::cout << "type new name\n";
									for (int j = 0; j < numFiles; j++)
									{
										std::cin >> NewFileName;

										PC.getFolder(newFolderName)->addFile(NewFileName, 2023);
									}
									std::cout << "\n"<<"Now `" << newFolderName << "` has these files: \n";
									PC.getFolder(newFolderName)->printFiles();
									std::cout << "\n";
									/////////////////////////////////////////////////////////////////

									std::cout << "Want to change file name in folder `?"<<newFolderName<<"` Type yes or no\n";
									std::cin >> answer;
									if (answer == "no") {
										std::cout << "Moving on\n";
									}

									else if (answer == "yes") {
										for (int i = 0; i < numFiles; i++) {
											fileName=i;
											std::cout << "Please enter the name of the file you want to change\n";
											std::cin >> fileName;
											std::cout << "New name: ";
											std::cin >> newFileName;
											/*files[i].setName(newFileName);
											files[i].printInfo();*/
											PC.getFolder(newFolderName)->printFiles();
											std::cout << "\n";
										}
										

									}
									else {
										std::cout << "no files matching found";
									}

								}
								else {
									std::cout << "More than 10 files not allowed";
								}

								
							}
						}

						

						/*for (int i = 0; i < numFiles; i++) {
							if (LargestFile < rootFolder.getFolder("PC")->getSize()) {
								nameLargest = rootFolder.getFolder("PC")->getName();
								LargestFile = rootFolder.getFolder("PC")->getSize();
							}
						}
				
						std::cout << "Largest file: " << nameLargest << " " << LargestFile << "\n";*/
					}
					else {
						std::cout << "Thats gonna be more than 10 files\n";
					}
					
	
				}
				///////////////////////////////////////////////////////////

				

				break;
			}

			//////////////////////////////////////////////
			case 2: {
				File SecondFolder[2] = {
				  File("Alexander ", 2015),
				  File("Thomas ", 2021),
				};

				for (int i = 0; i < 2; i++) {
					SecondFolder[i].printInfo();
				}

				for (int i = 0; i < 2; i++) {
					if (LargestFile < SecondFolder[i].getSize()) {
						nameLargest = SecondFolder[i].getName();
						LargestFile = SecondFolder[i].getSize();
					}
				}

				std::cout << "Largest file: " << nameLargest << " " << LargestFile << "\n";

				std::cout << "Please choose number of file to change it's name, where first file is 0. If you dont want to change anything enter number 50 \n";
				std::cin >> position;
				
				if (position == 50) {
					std::cout << "Moving on\n";
				}
				else if (position >= 0 && position < 2) {
					std::cout << "New name: \n";
					std::cin >> newFileName;
					SecondFolder[position].setName(newFileName);
					for (int position = 0; position < 2; position++) {
						SecondFolder[position].printInfo();
					}
				}
				else {
					std::cout << "no files matching found";
				}
				break;

			}
			//////////////////////////////////////////////
			case 3: {
				File ThirdFolder[3] = {
				  File("Z brush(1) ", 2018),
				  File("Z brush(2) ", 2019),
				  File("Z brush(3) ", 2019),

				};

				for (int i = 0; i < 3; i++) {
					ThirdFolder[i].printInfo();
				}
				
				for (int i = 0; i < 3; i++) {
					if (LargestFile < ThirdFolder[i].getSize()) {
						nameLargest = ThirdFolder[i].getName();
						LargestFile = ThirdFolder[i].getSize();
					}
				}

				std::cout << "Largest file: " << nameLargest << " " << LargestFile << "\n";

				std::cout << "Please choose number of file to change it's name, where first file is 0. If you dont want to change anything enter number 50 \n";
				std::cin >> position;
				if (position == 50) {
					std::cout << "Moving on\n";
				}
				else if (position >= 0 && position < 3) {
					std::cout << "New name: \n";
					std::cin >> newFileName;
					ThirdFolder[position].setName(newFileName);
					for (int position = 0; position < 3; position++) {
						ThirdFolder[position].printInfo();
					}
				}
				else {
					std::cout << "no files matching found";
				}
				break;
			}

			//////////////////////////////////////////////
			case 4: {
				File FourthFolder[7] = {
				  File("Hollow night ", 2018),
				  File("Life is strange ", 2011),
				  File("Elden Ring ", 2019),
				  File("Little Nightmares ", 2022),
				  File("Zelda ", 2016),
				  File("Asphalt ", 2015),
				  File("Candy Crush", 2018)
				};

				for (int i = 0; i < 7; i++) {
					FourthFolder[i].printInfo();
				}

				for (int i = 0; i < 7; i++) {
					if (LargestFile < FourthFolder[i].getSize()) {
						nameLargest = FourthFolder[i].getName();
						LargestFile = FourthFolder[i].getSize();
					}
				}

				std::cout << "Largest file: " << nameLargest << " " << LargestFile << "\n";
				std::cout << "Please choose number of file to change it's name, where first file is 0. If you dont want to change anything enter number 50 \n";
				std::cin >> position;
				if (position == 50) {
					std::cout << "Moving on\n";
				}
				else if (position >= 0 && position < 7) {
					std::cout << "New name: \n";
					std::cin >> newFileName;
					FourthFolder[position].setName(newFileName);
					for (int position = 0; position < 7; position++) {
						FourthFolder[position].printInfo();
					}
				}
				else {
					std::cout << "no files matching found";
				}
				break;
			}

			//////////////////////////////////////////////
			case 5: {
				File FithFolder[6] = {
				  File("Rock ", 2013),
				  File("Classic ", 2010),
				  File("Jazz ", 2016),
				  File("Folk", 2023),
				  File("Mix", 2017),
				  File("Rap ", 2015),
				};

				for (int i = 0; i < 6; i++) {
					FithFolder[i].printInfo();
				}

				for (int i = 0; i < 6; i++) {
					if (LargestFile < FithFolder[i].getSize()) {
						nameLargest = FithFolder[i].getName();
						LargestFile = FithFolder[i].getSize();
					}
				}

				std::cout << "Largest file: " << nameLargest << " " << LargestFile << "\n";


				std::cout << "Please choose number of file to change it's name, where first file is 0. If you dont want to change anything enter number 50 \n";
				std::cin >> position;
				if (position == 50) {
					std::cout << "Moving on\n";
				}
				else if (position >= 0 && position < 6) {
					std::cout << "New name: \n";
					std::cin >> newFileName;
					FithFolder[position].setName(newFileName);
					for (int position = 0; position < 6; position++) {
						FithFolder[position].printInfo();
					}
				}
				else {
					std::cout<<"no files matching found";
				}
			
				break;
			}

			}
			break;
		case 2: {
			std::cout << "Please enter the name of the folder you want to change\n";
			std::string folderName;
			std::cin >> folderName;
			std::cout << "New name: ";
			std::cin >> newFolderName;
			rootFolder.getFolder(folderName)->setName(newFolderName);
			rootFolder.printFolders();
			break;
		}
			
		case 3:
			std::cout << "Create folder";
			//std::cin >> position;
			//createFolder();
			break;

		case 4:
			std::cout << "you chose to terminate the program. Bye then. \n";
			std::cout << "  ";
			menu = false;
			break;
	
		default:
			std::cout << "no such option\n";
			break;
		}  	
	}
}