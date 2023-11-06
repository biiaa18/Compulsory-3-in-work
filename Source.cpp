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
	Folder Users("Users", 2010);
	Folder Screenshots("Screenshots", 2010);
	Folder Games("Games", 2010);
	Folder Music("Music", 2010);

	rootFolder.addFolder("PC");
	rootFolder.addFolder("Users");
	rootFolder.addFolder("Screenshots");
	rootFolder.addFolder("Games");
	rootFolder.addFolder("Music");

	

	rootFolder.printFolders();

	while (menu) {
		std::cout << "Option 1: open folder\n" << "Option 2: change folder name\n" << "Option 3: terminate program.\n";
		std::cout << "For choosing an option, please type in 1,2 or 3\n";
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
				std::cout << "\n" << "Want to add new file or folder to this folder ? Type yes or no\n";
				std::cin >> answer;
				if (answer == "yes") {
					std::cout << "How many new files? You can max have 10 files in a folder\n";
					int numFiles;
					std::cin >> numFiles;
					if (numFiles >= 0 && numFiles < 7) {
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
							rootFolder.getFolder("PC")->changeFileName(fileName, newFileName);
							rootFolder.getFolder("PC")->printFiles();

						}
						else {
							std::cout << "wrong input";
						}

						std::cout << "Largest file: ";
						rootFolder.getFolder("PC")->getLargestFile();





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
									std::cout << "\n" << "Now `" << newFolderName << "` has these files: \n";
									PC.getFolder(newFolderName)->printFiles();
									std::cout << "\n";
									/////////////////////////////////////////////////////////////////

									std::cout << "Want to change file name in folder `?" << newFolderName << "` Type yes or no\n";
									std::cin >> answer;
									if (answer == "no") {
										std::cout << "Moving on\n";
									}

									else if (answer == "yes") {

										std::cout << "Please enter the name of the file you want to change\n";
										std::cin >> fileName;
										std::cout << "New name: ";
										std::cin >> newFileName;
										PC.getFolder(newFolderName)->changeFileName(fileName, newFileName);
										PC.getFolder(newFolderName)->printFiles();
										std::cout << "\n";
										break;



									}
									else {
										std::cout << "no files matching found";
									}

									std::cout << "Largest file: ";
									PC.getFolder(newFolderName)->getLargestFile();
								}
								else {
									std::cout << "More than 10 files not allowed";
								}


							}
						}
					}
					else {
						std::cout << "Thats gonna be more than 10 files\n";
					}
				}
				else {
					break;
				}
				///////////////////////////////////////////////////////////



				break;
			}

				  //////////////////////////////////////////////
			case 2: {
				rootFolder.getFolder("Users")->addFile("Alexander ", 2015);
				rootFolder.getFolder("Users")->addFile("Thomas ", 2021);


				rootFolder.getFolder("Users")->printFiles();
				////////////////////////////////////////////////////////
				std::cout << "\n" << "Want to add new file or folder to this folder ? Type yes or no\n";
				std::cin >> answer;
				if (answer == "yes") {
					std::cout << "How many new files? You can max have 10 files in a folder\n";
					int numFiles;
					std::cin >> numFiles;
					if (numFiles >= 0 && numFiles < 9) {
						std::cout << "type new name\n";
						for (int j = 0; j < numFiles; j++)
						{
							std::cin >> NewFileName;

							rootFolder.getFolder("Users")->addFile(NewFileName, 2023);
						}

						rootFolder.getFolder("Users")->printFiles();

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
							rootFolder.getFolder("Users")->changeFileName(fileName, newFileName);
							rootFolder.getFolder("Users")->printFiles();

						}
						else {
							std::cout << "wrong input";
						}

						std::cout << "Largest file: ";
						rootFolder.getFolder("Users")->getLargestFile();





						/////////////////////////////////////////////////////////
						std::cout << "Want to add new folder into folder `Users` ? Type yes or no\n";
						std::cin >> answer;
						if (answer == "yes") {
							std::cout << "New name: ";
							std::cin >> newFolderName;
							Users.addFolder(newFolderName);
							std::cout << "\n" << "Now folder Users has : \n";
							rootFolder.getFolder("Users")->printFiles();
							Users.printFolders();
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

										Users.getFolder(newFolderName)->addFile(NewFileName, 2023);
									}
									std::cout << "\n" << "Now `" << newFolderName << "` has these files: \n";
									Users.getFolder(newFolderName)->printFiles();
									std::cout << "\n";
									/////////////////////////////////////////////////////////////////

									std::cout << "Want to change file name in folder `?" << newFolderName << "` Type yes or no\n";
									std::cin >> answer;
									if (answer == "no") {
										std::cout << "Moving on\n";
									}

									else if (answer == "yes") {

										std::cout << "Please enter the name of the file you want to change\n";
										std::cin >> fileName;
										std::cout << "New name: ";
										std::cin >> newFileName;
										Users.getFolder(newFolderName)->changeFileName(fileName, newFileName);
										Users.getFolder(newFolderName)->printFiles();
										std::cout << "\n";
										break;



									}
									else {
										std::cout << "no files matching found";
									}

									std::cout << "Largest file: ";
									Users.getFolder(newFolderName)->getLargestFile();
								}
								else {
									std::cout << "More than 10 files not allowed";
								}


							}
						}
					}
					else {
						std::cout << "Thats gonna be more than 10 files\n";
					}
				}
				else {
					break;
				}

				break;

			}
				  //////////////////////////////////////////////
			case 3: {

				rootFolder.getFolder("Screenshots")->addFile("Z brush(1) ", 2018);
				rootFolder.getFolder("Screenshots")->addFile("Z brush(2) ", 2019);
				rootFolder.getFolder("Screenshots")->addFile("Z brush(3) ", 2019);

				rootFolder.getFolder("Screenshots")->printFiles();
				////////////////////////////////////////////////////////
				std::cout << "\n" << "Want to add new file or folder to this folder ? Type yes or no\n";
				std::cin >> answer;
				if (answer == "yes") {
					std::cout << "How many new files? You can max have 10 files in a folder\n";
					int numFiles;
					std::cin >> numFiles;
					if (numFiles >= 0 && numFiles < 8) {
						std::cout << "type new name\n";
						for (int j = 0; j < numFiles; j++)
						{
							std::cin >> NewFileName;

							rootFolder.getFolder("Screenshots")->addFile(NewFileName, 2023);
						}

						rootFolder.getFolder("Screenshots")->printFiles();

						/////////////////////////////////////////////////////////////////

						std::cout << "Want to change file name in folder `Screenshots`? Type yes or no\n";
						std::cin >> answer;
						if (answer == "no") {
							std::cout << "Moving on\n";
						}

						else if (answer == "yes") {
							std::cout << "Please enter the name of the file you want to change\n";
							std::cin >> fileName;
							std::cout << "New name: ";
							std::cin >> newFileName;
							rootFolder.getFolder("Screenshots")->changeFileName(fileName, newFileName);
							rootFolder.getFolder("Screenshots")->printFiles();

						}
						else {
							std::cout << "wrong input";
						}

						std::cout << "Largest file: ";
						rootFolder.getFolder("Screenshots")->getLargestFile();





						/////////////////////////////////////////////////////////
						std::cout << "Want to add new folder into folder `Screenshots` ? Type yes or no\n";
						std::cin >> answer;
						if (answer == "yes") {
							std::cout << "New name: ";
							std::cin >> newFolderName;
							Screenshots.addFolder(newFolderName);
							std::cout << "\n" << "Now folder Screenshots has : \n";
							rootFolder.getFolder("Screenshots")->printFiles();
							Screenshots.printFolders();
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

										Screenshots.getFolder(newFolderName)->addFile(NewFileName, 2023);
									}
									std::cout << "\n" << "Now `" << newFolderName << "` has these files: \n";
									Screenshots.getFolder(newFolderName)->printFiles();
									std::cout << "\n";
									/////////////////////////////////////////////////////////////////

									std::cout << "Want to change file name in folder `?" << newFolderName << "` Type yes or no\n";
									std::cin >> answer;
									if (answer == "no") {
										std::cout << "Moving on\n";
									}

									else if (answer == "yes") {

										std::cout << "Please enter the name of the file you want to change\n";
										std::cin >> fileName;
										std::cout << "New name: ";
										std::cin >> newFileName;
										Screenshots.getFolder(newFolderName)->changeFileName(fileName, newFileName);
										Screenshots.getFolder(newFolderName)->printFiles();
										std::cout << "\n";
										break;




									}
									else {
										std::cout << "no files matching found";
									}

									std::cout << "Largest file: ";
									Screenshots.getFolder(newFolderName)->getLargestFile();
								}
								else {
									std::cout << "More than 10 files not allowed";
								}


							}
						}
					}
					else {
						std::cout << "Thats gonna be more than 10 files\n";
					}
				}
				else {
					break;
				}
				///////////////////////////////////////////////////////////



				break;
			}

				  //////////////////////////////////////////////
			case 4: {
				rootFolder.getFolder("Hollow night")->addFile("Z brush(1) ", 2018);
				rootFolder.getFolder("Life is strange")->addFile("Z brush(2) ", 2011);
				rootFolder.getFolder("Elden Ring")->addFile("Z brush(3) ", 2019);
				rootFolder.getFolder("Little Nightmares")->addFile("Z brush(1) ", 2022);
				rootFolder.getFolder("Zelda")->addFile("Z brush(2) ", 2016);
				rootFolder.getFolder("Asphalt")->addFile("Z brush(3) ", 2015);
				rootFolder.getFolder("Candy Crush")->addFile("Z brush(1) ", 2018);

				rootFolder.getFolder("Games")->printFiles();
				////////////////////////////////////////////////////////
				std::cout << "\n" << "Want to add new file or folder to this folder ? Type yes or no\n";
				std::cin >> answer;
				if (answer == "yes") {
					std::cout << "How many new files? You can max have 10 files in a folder\n";
					int numFiles;
					std::cin >> numFiles;
					if (numFiles >= 0 && numFiles < 4) {
						std::cout << "type new name\n";
						for (int j = 0; j < numFiles; j++)
						{
							std::cin >> NewFileName;

							rootFolder.getFolder("Games")->addFile(NewFileName, 2023);
						}

						rootFolder.getFolder("Games")->printFiles();

						/////////////////////////////////////////////////////////////////

						std::cout << "Want to change file name in folder `Games`? Type yes or no\n";
						std::cin >> answer;
						if (answer == "no") {
							std::cout << "Moving on\n";
						}

						else if (answer == "yes") {
							std::cout << "Please enter the name of the file you want to change\n";
							std::cin >> fileName;
							std::cout << "New name: ";
							std::cin >> newFileName;
							rootFolder.getFolder("Games")->changeFileName(fileName, newFileName);
							rootFolder.getFolder("Games")->printFiles();

						}
						else {
							std::cout << "wrong input";
						}

						std::cout << "Largest file: ";
						rootFolder.getFolder("Games")->getLargestFile();





						/////////////////////////////////////////////////////////
						std::cout << "Want to add new folder into folder `Games` ? Type yes or no\n";
						std::cin >> answer;
						if (answer == "yes") {
							std::cout << "New name: ";
							std::cin >> newFolderName;
							Games.addFolder(newFolderName);
							std::cout << "\n" << "Now folder Games has : \n";
							rootFolder.getFolder("Games")->printFiles();
							Games.printFolders();
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

										Games.getFolder(newFolderName)->addFile(NewFileName, 2023);
									}
									std::cout << "\n" << "Now `" << newFolderName << "` has these files: \n";
									Games.getFolder(newFolderName)->printFiles();
									std::cout << "\n";
									/////////////////////////////////////////////////////////////////

									std::cout << "Want to change file name in folder `?" << newFolderName << "` Type yes or no\n";
									std::cin >> answer;
									if (answer == "no") {
										std::cout << "Moving on\n";
									}

									else if (answer == "yes") {

										std::cout << "Please enter the name of the file you want to change\n";
										std::cin >> fileName;
										std::cout << "New name: ";
										std::cin >> newFileName;
										Games.getFolder(newFolderName)->changeFileName(fileName, newFileName);
										Games.getFolder(newFolderName)->printFiles();
										std::cout << "\n";
										break;



									}
									else {
										std::cout << "no files matching found";
									}

									std::cout << "Largest file: ";
									Games.getFolder(newFolderName)->getLargestFile();
								}
								else {
									std::cout << "More than 10 files not allowed";
								}


							}
						}
					}
					else {
						std::cout << "Thats gonna be more than 10 files\n";
					}
				}
				else {
					break;
				}
				///////////////////////////////////////////////////////////



				break;
			}
			case 5: {
				rootFolder.getFolder("Music")->addFile("Rock ", 2015);
				rootFolder.getFolder("Music")->addFile("Jazz ", 2021);


				rootFolder.getFolder("Music")->printFiles();
				////////////////////////////////////////////////////////
				std::cout << "\n" << "Want to add new file or folder to this folder ? Type yes or no\n";
				std::cin >> answer;
				if (answer == "yes") {
					std::cout << "How many new files? You can max have 10 files in a folder\n";
					int numFiles;
					std::cin >> numFiles;
					if (numFiles >= 0 && numFiles < 9) {
						std::cout << "type new name\n";
						for (int j = 0; j < numFiles; j++)
						{
							std::cin >> NewFileName;

							rootFolder.getFolder("Music")->addFile(NewFileName, 2023);
						}

						rootFolder.getFolder("Music")->printFiles();

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
							rootFolder.getFolder("Music")->changeFileName(fileName, newFileName);
							rootFolder.getFolder("Music")->printFiles();

						}
						else {
							std::cout << "wrong input";
						}

						std::cout << "Largest file: ";
						rootFolder.getFolder("Music")->getLargestFile();





						/////////////////////////////////////////////////////////
						std::cout << "Want to add new folder into folder `Music` ? Type yes or no\n";
						std::cin >> answer;
						if (answer == "yes") {
							std::cout << "New name: ";
							std::cin >> newFolderName;
							Music.addFolder(newFolderName);
							std::cout << "\n" << "Now folder Music has : \n";
							rootFolder.getFolder("Music")->printFiles();
							Music.printFolders();
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

										Music.getFolder(newFolderName)->addFile(NewFileName, 2023);
									}
									std::cout << "\n" << "Now `" << newFolderName << "` has these files: \n";
									Music.getFolder(newFolderName)->printFiles();
									std::cout << "\n";
									/////////////////////////////////////////////////////////////////

									std::cout << "Want to change file name in folder `?" << newFolderName << "` Type yes or no\n";
									std::cin >> answer;
									if (answer == "no") {
										std::cout << "Moving on\n";
									}

									else if (answer == "yes") {

										std::cout << "Please enter the name of the file you want to change\n";
										std::cin >> fileName;
										std::cout << "New name: ";
										std::cin >> newFileName;
										Music.getFolder(newFolderName)->changeFileName(fileName, newFileName);
										Music.getFolder(newFolderName)->printFiles();
										std::cout << "\n";
										break;



									}
									else {
										std::cout << "no files matching found";
									}

									std::cout << "Largest file: ";
									Music.getFolder(newFolderName)->getLargestFile();
								}
								else {
									std::cout << "More than 10 files not allowed";
								}


							}
						}
					}
					else {
						std::cout << "Thats gonna be more than 10 files\n";
					}
				}
				else {
					break;
				}
			}
			
				break;
			}

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