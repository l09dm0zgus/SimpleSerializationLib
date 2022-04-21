#pragma once
#include <fstream>
#include "IFileWriterBuilder.h"
#include "Defines.h"

class SerializationFileWriterBuilder : public IFileWriterBuilder
{
	public:
		EXPORT_API void openFile(const std::string& pathToFile) override;
		EXPORT_API void closeFile() override;
		EXPORT_API std::ofstream& operator<<(const std::string& s);
		EXPORT_API std::ofstream& operator<<(const char* s);
		EXPORT_API std::ofstream& operator<<(const wchar_t* s);
	private:
		std::ofstream stream;
};

