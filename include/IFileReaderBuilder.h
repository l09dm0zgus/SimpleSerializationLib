#pragma once
#include<iostream>
class IFileReaderBuilder
{
public:
	virtual void openFile(const std::string& pathToFile) = 0;
	virtual void readFile() = 0;
	virtual void closeFile() = 0;
};