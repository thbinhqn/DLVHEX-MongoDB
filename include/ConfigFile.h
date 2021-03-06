/* -*- C++ -*- */
/**
 * @file ConfigFile.h
 * @author Chao ZHANG
 * @date 08/22/2014*
 * @brief Header file for ConfigFile
 *
 */
#ifndef _CONFIG_FILE_H
#define _CONFIG_FILE_H

#include <fstream>
#include <iostream>
#include <string>
#include <map>

using namespace std;

class ConfigFile
{
private:
	map<string, string> contents;
	std::string fName;

	void removeComment(string &line) const;

	bool onlyWhitespace(const string &line) const;
	
	bool validLine(const string &line) const;

	void extractKey(string &key, size_t const &sepPos, const string &line) const;
	
	void extractValue(string &value, size_t const &sepPos, const string &line) const;

	void extractContents(const string &line);

	void parseLine(const string &line, size_t const lineNo);

	void ExtractKeys();
	
public:
	ConfigFile(const  string &fName);

	bool keyExists(const  string &key) const;

	string getValueOfKey(const  string &key) const;

};






#endif /* _CONFIG_FILE_H */
