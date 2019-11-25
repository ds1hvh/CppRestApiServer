#include "JsonOBJ.h"
#include<string>
#include<iostream>

JsonOBJ::JsonOBJ()
{
	document.SetObject();
}

void JsonOBJ::add(std::string key)
{
	auto& allocator = document.GetAllocator();
	rapidjson::Value k;
	k.SetString(key.c_str(), key.length(), allocator);
	document.AddMember(k, "", allocator);

}

void JsonOBJ::add(std::string key, std::string value)
{
	auto& allocator = document.GetAllocator();
	rapidjson::Value k, v;

	k.SetString(key.c_str(), key.length(), allocator);
	v.SetString(value.c_str(), value.length(), allocator);
	document.AddMember(k, v, allocator);

}

void JsonOBJ::add(std::string key, Board board)
{
	auto& allocator = document.GetAllocator();
	rapidjson::Value k, v;

	k.SetString(key.c_str(), key.length(), allocator);
	v.SetArray();
	
	int size = board.getSize();
	bool* clearList = board.getClearList();
	for (int i = 0; i < size; i++) 
	{
		v.PushBack(clearList[i], allocator);
	}

	document.AddMember(k, v, allocator);
}


void JsonOBJ::set(std::string key, std::string value)
{
	auto& allocator = document.GetAllocator();
	rapidjson::Value& v = document[key.c_str()];
	v.SetString(value.c_str(), value.length(), allocator);
}

std::string JsonOBJ::getDoc()
{
	rapidjson::StringBuffer buffer;

	buffer.Clear();

	rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
	document.Accept(writer);

	return std::string(buffer.GetString());
}
