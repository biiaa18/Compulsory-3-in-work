#pragma once
#include <iostream>
#include "File.h"

const int max_files = 10;
const int max_folders = 5;

class Folder
{
private:
	std::string name;
	int size = rand() % 100+1;
	int creationDate;

	int numberOfFiles;
	int numberOfFolders;

	File files[max_files];
	Folder* folders;

public:
	Folder() {
		name = "";
		creationDate = 0;

		numberOfFiles = 0;
		numberOfFolders = 0;

		folders = NULL;
	}

	Folder(std::string folderName, int folderCreationDate = 2023) {
		name = folderName;
		creationDate = folderCreationDate;

		numberOfFiles = 0;
		numberOfFolders = 0;

		folders = new Folder[max_folders];
	}

	void printInfo() {
		std::cout << "Folder Name: " << name << "  Size : " << size << "MB" << "  Date : " << creationDate << "\n";
	}

	void printFolders() {
		for (int i = 0; i < numberOfFolders; i++) {
			folders[i].printInfo();
		}
	}

	void printFiles() {
		for (int i = 0; i < numberOfFiles; i++) {
			files[i].printInfo();
		}
	}

	void addFile(std::string filename, int date = 2023) {
		if (numberOfFiles < max_files) {
			files[numberOfFiles] = File(filename, date);
			numberOfFiles++;
		}
		else {
			std::cout << "Error: Too many files in folder " << name << std::endl;
		}
	}

	void addFolder(std::string folderName) {
		if (numberOfFolders < max_folders) {
			folders[numberOfFolders] = Folder(folderName, 2023);
			numberOfFolders++;
		}
		else {
			std::cout << "Error: Too many folders in folder " << name << std::endl;
		}
	}

	Folder* getFolder(std::string folderName) {
		for (int i = 0; i < numberOfFolders; i++)
		{
			if (folders[i].getName() == folderName) {
				return &folders[i];
			}
		}

		return NULL;
	}

	std::string getName() {
		return name;
	}

	void setName(std::string newFolderName) {
		 name = newFolderName;
	}	

	int getSize() {
		return size;
	}

	void changeFileName(std::string fileName, std::string newFileName) {
		for (int i = 0; i < numberOfFiles; i++) {
			if (fileName == files[i].getName()) {
				files[i].setName(newFileName);
			}
			
		}
		
	}

	void getLargestFile() {
		int LargestFile=0;
		for (int i = 0; i < numberOfFiles; i++) {
			if (LargestFile < files[i].getSize()) {
				LargestFile = files[i].getSize();
			}
		}
		for (int j = 0; j < numberOfFiles; j++) {
			if (LargestFile == files[j].getSize()) {
				files[j].printInfo();
			}
		}
	}



};

