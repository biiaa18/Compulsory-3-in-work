#pragma once
#include <iostream>



class File
{
private:
	std::string name;
	int size = rand() % 100+1;
	int creationDate;
	int numberOfFiles;
	
	



public:
	File() {
		name = "";
		creationDate = 0;
		numberOfFiles = 0;

		

	}

	
	File(std::string nName, int nCreationDate) {
		name = nName;
		creationDate = nCreationDate;
		numberOfFiles = 0;
	}

	void printInfo() {
		std::cout << "File Name: " << name << "  Size: " << size << "MB" << "  Date: " << creationDate << "\n";
	}

	int getSize() {
		return size;
	}
	
	std::string getName() {
		return name;
	}

	void setName(std::string newFileName) {
		name = newFileName;
	}

	
};
