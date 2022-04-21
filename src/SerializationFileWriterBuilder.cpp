#include "include/SerializationFileWriterBuilder.h"

void SerializationFileWriterBuilder::openFile(const std::string& pathToFile)
{
	stream.open(pathToFile, std::ios::out);
}

void SerializationFileWriterBuilder::closeFile()
{
	stream.close();
}

std::ofstream& SerializationFileWriterBuilder::operator<<(const std::string& s)
{
	stream << s;
	return stream;
}

std::ofstream& SerializationFileWriterBuilder::operator<<(const char* s)
{
	stream << s;
	return stream;
}

std::ofstream& SerializationFileWriterBuilder::operator<<(const wchar_t* s)
{
	stream << s;
	return stream;
}

