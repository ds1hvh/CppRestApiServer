#pragma once

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

class Json {

public :
	
	Json();

	void init();
	
	// Add key or key-value
	void add(std::string key);
	void add(std::string key, std::string value);
	void add(std::string key, std::vector<std::string> values);
	void add(std::string key, rapidjson::Document docValue);

	// Set value
	void setValue(std::string key, std::string value);
	void setValue(std::string key, std::vector<std::string> values);
	void setValue(std::string key, rapidjson::Document docValue);

	std::string getDoc();

protected : 

private :
	rapidjson::Document document;

};