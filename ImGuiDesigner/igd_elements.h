#pragma once
#include <functional>
#include <unordered_map>
#include "igd_window.h"
#include "igd_button.h"
#include "igd_childwindow.h"
#include "igd_text.h"
#include "igd_separator.h"
#include "igd_inputtext.h"
#include "igd_inputfloat.h"
#include "igd_inputint.h"
#include "igd_sliderfloat.h"
#include "igd_sliderint.h"
#include "igd_checkbox.h"
#include "igd_combo.h"
#include "igd_selectable.h"
#include "igd_tabbar.h"
#include "igd_tabitem.h"
#include "igd_texture.h"
#include "igd_table.h"
namespace igd
{
	static inline std::unordered_map<std::string, std::function<ImGuiElement*(ImGuiElement*, nlohmann::json)>> element_load_functions = {
		{igd::Window::json_identifier, igd::Window::load },
		{igd::Button::json_identifier, igd::Button::load },
		{igd::ChildWindow::json_identifier, igd::ChildWindow::load },
		{igd::Text::json_identifier, igd::Text::load },
		{igd::Separator::json_identifier, igd::Separator::load },
		{igd::InputText::json_identifier, igd::InputText::load },
		{igd::InputFloat::json_identifier, igd::InputFloat::load },
		{igd::InputInt::json_identifier, igd::InputInt::load },
		{igd::SliderFloat::json_identifier, igd::SliderFloat::load },
		{igd::SliderInt::json_identifier, igd::SliderInt::load },
		{igd::CheckBox::json_identifier, igd::CheckBox::load},
		{igd::Combo::json_identifier, igd::Combo::load},
		{igd::Selectable::json_identifier, igd::Selectable::load},
		{igd::TabBar::json_identifier, igd::TabBar::load},
		{igd::TabItem::json_identifier, igd::TabItem::load},
		{igd::Texture::json_identifier, igd::Texture::load},
		{igd::Table::json_identifier, igd::Table::load},
	};
}
