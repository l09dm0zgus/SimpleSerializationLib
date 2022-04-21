#pragma once
#include<iostream>
class IFileWriterBuilder
{
public:
	virtual void openFile(const std::string &pathToFile) = 0;
	virtual void closeFile() = 0;
};


