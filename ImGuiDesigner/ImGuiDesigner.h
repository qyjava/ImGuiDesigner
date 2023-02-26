#pragma once
#include "Workspace.h"
#include "Properties.h"
#include "ToolBar.h"
#include "Notifications.h"
namespace igd
{
	extern Notifications* notifications;
	extern WorkSpace* active_workspace;
	extern std::vector<WorkSpace*> workspaces;
	extern Properties* properties;
	extern Walnut::Application* app;
	extern bool add_workspace;
	extern std::vector<WorkSpace*> delete_workspace;

}