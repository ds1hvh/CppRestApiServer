#include "Json.h"
#include<string>
#include<vector>

Json::Json() {
	init();
}

void Json::init()
{
	document.SetObject();
}

void Json::add(std::string key) 
{
	rapidjson::Document::AllocatorType& allocator = document.GetAllocator();	
	rapidjson::Value k(key.c_str(), document.GetAllocator());
	document.AddMember(k, NULL, allocator);

}

void Json::add(std::string key, std::string value)
{
	rapidjson::Document::AllocatorType& allocator = document.GetAllocator();
	rapidjson::Value k(key.c_str(), document.GetAllocator());
	document.AddMember(k, value, allocator);

}

void Json::add(std::string key, std::vector<std::string> values)
{
	rapidjson::Document::AllocatorType& allocator = document.GetAllocator();
	rapidjson::Value k(key.c_str(), document.GetAllocator());
	rapidjson::Value array(rapidjson::kArrayType);
	
	int size = values.size();
	
	for (int i = 0; i < size; i++) 
	{
		array.PushBack(values.at(i), allocator);
	}

	document.AddMember(k, array, allocator);

}

void Json::add(std::string key, rapidjson::Document docValue)
{

}

void Json::setValue(std::string key, std::string value)
{

}


void Json::setValue(std::string key, std::vector<std::string> values)
{

}

void Json::setValue(std::string key, rapidjson::Document docValue)
{

}

std::string Json::getDoc()
{

}