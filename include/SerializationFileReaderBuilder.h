#pragma once
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

#include "Defines.h"
#include "IFileReaderBuilder.h"

class SerializationFileReaderBuilder : public IFileReaderBuilder
{
	public:
		EXPORT_API void openFile(const std::string& pathToFile) override;
		EXPORT_API void readFile() override;
		EXPORT_API void closeFile() override;
	private:
		std::map<std::string,std::string> keysWithNameAndValues;
		std::ifstream file;
};

EXPORT_API bool isNumber(const std::string& str);
EXPORT_API int castStringToIntenger(const std::string& number);
EXPORT_API float castStringToFloat(const std::string& number);
EXPORT_API double castStringToDouble(const std::string& number);

EXPORT_API std::vector<std::string> split(const std::string& s, const std::string& delimiter);

EXPORT_API int operator>>(const std::string& keyAndName, int& value);
EXPORT_API float operator>>(const std::string& keyAndName, float& value);
EXPORT_API double operator>>(const std::string& keyAndName, double& value);
EXPORT_API std::string operator>>(const std::string& keyAndName, std::string& value);
EXPORT_API char* operator>>(const std::string& keyAndName, char* value);
EXPORT_API wchar_t* operator>>(const std::string& keyAndName, wchar_t* value);




