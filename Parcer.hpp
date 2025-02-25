#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <vector>

#include <sstream>

namespace fs = std::filesystem;

typedef unsigned int ui;

class InfoAboutLayer {
private:
	ui width;
	ui height;
	ui id;
	std::string name;
	std::vector<std::vector<std::string>> map;
public:
	InfoAboutLayer() {}

	InfoAboutLayer( ui widthFromFile, ui heightFromFile, ui idFromFile, std::string nameFromFile ) {
		this->width = widthFromFile;
		this->height = heightFromFile;
		this->id = idFromFile;
		this->name = nameFromFile;
	}

	ui getWidth() const {
		return this->width;
	}

	ui getHeight() const {
		return this->height;
	}

	ui getId() const {
		return this->id;
	}

	std::string getName() const {
		return this->name;
	}

	std::vector<std::vector<std::string>> getMap() const {
		return this->map;
	}

	void addMapLine( std::vector<std::string> line ) {
		this->map.push_back( line );
	}
};

std::string searchingToParse( std::size_t& position, ui& iterator, std::string& line ) {
	bool isSearching = true;
	int counterOfQuotes = 0;

	std::string contentString = "";

	while (isSearching) {
		if (line[iterator] == '"') {
			counterOfQuotes++;
		}
		if (counterOfQuotes == 2) {
			isSearching = false;
		}
		if (line[iterator] != '"') {
			contentString += line[iterator];
		}

		iterator++;
	}

	return contentString;
}

InfoAboutLayer parseInfo( std::string& line ) {
	auto idPosition = line.find( "id" );
	auto namePosition = line.find( "name" );
	auto widthPosition = line.find( "width" );
	auto heightPosition = line.find( "height" );

	ui idIterator = idPosition + 3; // warning C4267: "size_t" in "ui"; 
	ui nameIterator = namePosition + 5; // warning C4267: "size_t" in "ui"; 
	ui widthIterator = widthPosition + 6; // warning C4267: "size_t" in "ui"; 
	ui heightIterator = heightPosition + 7; // warning C4267: "size_t" in "ui"; 

	auto idContentString = searchingToParse( idPosition, idIterator, line );
	auto nameContentString = searchingToParse( namePosition, nameIterator, line );
	auto widthContentString = searchingToParse( widthPosition, widthIterator, line );
	auto heightContentString = searchingToParse( heightPosition, heightIterator, line );

	InfoAboutLayer info( (ui)std::atoi( widthContentString.c_str() ),
		(ui)std::atoi( heightContentString.c_str() ),
		(ui)std::atoi( idContentString.c_str() ),
		nameContentString );

	return info;
}

std::vector<std::string> split( const std::string& s, char delim ) {
	std::vector<std::string> result;
	std::stringstream ss( s );
	std::string item;

	while (std::getline( ss, item, delim )) {
		result.push_back( item );
	}

	return result;
}

void print( const std::vector<std::vector<std::string>>& arr ) {
	for (auto i = 0; i < arr.size(); i++) {
		for (auto k = 0; k < arr[i].size(); k++) {
			std::cout << arr[i][k] << ' ';
		}
		std::cout << std::endl;
	}
}

std::vector<InfoAboutLayer> parcedInfo(const std::string& filename) {
	// When be more locations
	std::string filenamePath = filename;

	std::ifstream in( filenamePath );

	std::string line = "";

	std::vector<InfoAboutLayer> result;

	ui iterator = 0;
	ui maxValueOfIterator = 0;

	ui counter = 0;

	if (in.is_open()) {

		while (std::getline( in, line )) {
			if (line.find( "<layer" ) != std::string::npos) {
				auto info = parseInfo( line );
				result.push_back( info );
				maxValueOfIterator = info.getHeight();
				counter++;
				continue;
			}

			// Maybe here bug
			if (iterator < maxValueOfIterator && line.find( "," ) != std::string::npos) {
				result[counter - 1].addMapLine( split( line, ',' ) );

				iterator++;
			}

			if (iterator == maxValueOfIterator && maxValueOfIterator != 0) {
				iterator = 0;
			}
		}
	}
	else {
		std::cerr << "Problem with open stream.";
	}

	for (int i = 0; i < result.size(); i++) {
		std::cout << "Parsed: " << i + 1 << std::endl;

		std::cout << result[i].getWidth() << std::endl;
		std::cout << result[i].getHeight() << std::endl;
		std::cout << result[i].getId() << std::endl;
		std::cout << result[i].getName() << std::endl;

		print( result[i].getMap() );

		std::cout << std::endl;
	}

	in.close();

	return result;
}