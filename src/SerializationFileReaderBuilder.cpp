
#include "include/SerializationFileReaderBuilder.h"
struct FileContent
{
	std::map<std::string, std::string> keysAndNVP;

}fileContent;

void SerializationFileReaderBuilder::openFile(const std::string& pathToFile)
{
	file.open(pathToFile, std::ios::in);
}

void SerializationFileReaderBuilder::readFile()
{

	while (file.good())
	{
		std::string line;
		file >> line;
		if (line != "")
		{
			std::vector<std::string> splitKeyResult = split(line, "=");
			keysWithNameAndValues[splitKeyResult.at(0)] = splitKeyResult.at(1);
		}
		
	}
	fileContent.keysAndNVP.insert(keysWithNameAndValues.begin(), keysWithNameAndValues.end());
}

void SerializationFileReaderBuilder::closeFile()
{
	file.close();
}

bool isNumber(const std::string& str)
{
	std::size_t charPosition = 0;
	charPosition = str.find_first_not_of(' ');
	if (charPosition == str.size())
	{
		return false;
	}
	if (str[charPosition] == '+' || str[charPosition] == '-') 
	{
		++charPosition; 
	}
	int numberOfDigits, numberOfPoints;
	for (numberOfDigits = 0, numberOfPoints = 0; std::isdigit(str[charPosition]) || str[charPosition] == '.'; charPosition++)
	{
		if (str[charPosition] == '.')
		{
			++numberOfPoints;
		}
		else
		{
			++numberOfDigits;
		}
	}
	if (numberOfPoints > 1 || numberOfDigits < 1)
	{
		return false;
	}

	while (str[charPosition] == ' ') 
	{
		++charPosition;
	}

	return charPosition == str.size();
}

int castStringToIntenger(const std::string& number)
{
	try
	{
		if (!isNumber(number))
		{
			throw "Error::Wrong type.Value isn't integer!";
		}
	}
	catch (const char* errorMessage)
	{
		std::cout << errorMessage << std::endl;
		exit(-1);
	}
	return std::stoi(number);
}

float castStringToFloat(const std::string& number)
{
	try
	{
		if (!isNumber(number))
		{
			throw "Error::Wrong type.Value isn't float!";
		}
	}
	catch (const char* errorMessage)
	{
		std::cout << errorMessage << std::endl;
		exit(-1);
	}
	return std::stof(number);
}

double castStringToDouble(const std::string& number)
{
	try
	{
		if (!isNumber(number))
		{
			throw "Error::Wrong type.Value isn't double!";
		}
	}
	catch (const char* errorMessage)
	{
		std::cout << errorMessage << std::endl;
		exit(-1);
	}
	return std::stod(number);;
}

std::vector<std::string> split(const std::string& s, const std::string& delimiter)
{
	size_t startPosition = 0, endPosition, delimiterLength = delimiter.length();
	std::string token;
	std::vector<std::string> result;
	while ((endPosition = s.find(delimiter, startPosition)) != std::string::npos)
	{
		token = s.substr(startPosition, endPosition - startPosition);
		startPosition = endPosition + delimiterLength;
		result.push_back(token);
	}

	result.push_back(s.substr(startPosition));
	return result;
}
int operator>>(const std::string& keyAndName, int& value)
{
	value = castStringToIntenger(fileContent.keysAndNVP[keyAndName]);
	return value;
}
float operator>>(const std::string& keyAndName, float& value)
{
	value = castStringToFloat(fileContent.keysAndNVP[keyAndName]);
	return value;
}

double operator>>(const std::string& keyAndName, double& value)
{
	value = castStringToDouble(fileContent.keysAndNVP[keyAndName]);
	return value;
}

std::string operator>>(const std::string& keyAndName, std::string& value)
{
	value = fileContent.keysAndNVP[keyAndName];
	return value;
}
	
char* operator>>(const std::string& keyAndName, char* value)
{
	value = (char*)fileContent.keysAndNVP[keyAndName].c_str();
	return value;
}

wchar_t* operator>>(const std::string& keyAndName, wchar_t* value)
{
	size_t stringSize = strlen(fileContent.keysAndNVP[keyAndName].c_str()) + 1;
	size_t outSize;
	mbstowcs_s(&outSize, value, stringSize, fileContent.keysAndNVP[keyAndName].c_str(), stringSize - 1);
	return value;
}
