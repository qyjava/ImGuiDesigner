#include "Settings.h"
#include "ImGuiDesigner.h"
#include "../json/single_include/nlohmann/json.hpp"
#include <fstream>
#include <filesystem>
#include <iostream>
void Settings::save()
{
	std::filesystem::path path = std::filesystem::current_path();
	path.append("settings.igs");
	std::ofstream file;
	file.open(path);
	nlohmann::json main_obj;
	main_obj["bools"]=nlohmann::json::array();
	for (auto& [key, value] : bools)
	{
			nlohmann::json obj;
			obj["key"] = key;
			obj["value"] = value;
			main_obj["bools"].push_back(obj);
	}
	file << main_obj.dump() << std::endl;
	file.close();
}

void Settings::load()
{
	std::filesystem::path path = std::filesystem::current_path();
	path.append("settings.igs");
	std::ifstream i(path);
	try
	{
		nlohmann::json j;
		j = nlohmann::json::parse(i);
		for (auto& obj : j["bools"])
		{
			bools[obj["key"]] = obj["value"];
		}
		i.close();
	}
	catch (nlohmann::json::exception& ex)
	{
		igd::dialogs->GenericNotification("Json Error Loading Settings", ex.what(), "", "Ok", []() {});
		std::cerr << "parse error at byte " << ex.what() << std::endl;
		i.close();
	}
	catch (nlohmann::json::parse_error& ex)
	{
		igd::dialogs->GenericNotification("Json Error Loading Settings", ex.what(), "", "Ok", []() {});
		std::cerr << "parse error at byte " << ex.byte << std::endl << ex.what() << std::endl;
		i.close();
	}
}