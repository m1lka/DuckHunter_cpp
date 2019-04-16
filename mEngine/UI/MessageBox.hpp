#ifndef _MESSAGEBOX_HPP_
#define _MESSAGEBOX_HPP_

#include <SDL2/SDL.h>
#include <string>

using std::string;

enum DialogResult 
{
	No = 0,
	Yes = 1
};

class MessageBox
{
public:

	static void ShowInfo(string title, string message)
	{
		SDL_MessageBoxButtonData buttons[1];
		buttons[0].buttonid = 0;
		buttons[0].flags = SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT;
		buttons[0].text = "I see\0";
		
		SDL_MessageBoxColorScheme colorScheme = {
			{
				{255, 0,    0},
				{0,   255,  0},
				{255, 255,  0},
				{0,   0,  255},
				{255, 0,  255}
			}
		};
		
		SDL_MessageBoxData msgboxData;
		msgboxData.flags = SDL_MESSAGEBOX_INFORMATION;
		msgboxData.window = nullptr;
		msgboxData.title = title.c_str();
		msgboxData.message = message.c_str();
		msgboxData.numbuttons = 1;
		msgboxData.buttons = buttons;
		msgboxData.colorScheme = &colorScheme;
		
		int buttonid = 0;
		SDL_ShowMessageBox(&msgboxData, &buttonid);
	}
	
	static DialogResult ShowDialog(string title, string message)
	{
		SDL_MessageBoxButtonData buttons[2] = 
		{
			{SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, DialogResult::No, "No"},
			{SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, DialogResult::Yes, "Yes"}
		};
		
		SDL_MessageBoxColorScheme colorScheme = {
			{
				{255, 0,    0},
				{0,   255,  0},
				{255, 255,  0},
				{0,   0,  255},
				{255, 0,  255}
			}
		};
		
		SDL_MessageBoxData msgboxData;
		msgboxData.flags = SDL_MESSAGEBOX_INFORMATION;
		msgboxData.window = nullptr;
		msgboxData.title = title.c_str();
		msgboxData.message = message.c_str();
		msgboxData.numbuttons = 2;
		msgboxData.buttons = buttons;
		msgboxData.colorScheme = &colorScheme;
		
		DialogResult buttonid;
		SDL_ShowMessageBox(&msgboxData, reinterpret_cast<int*>(&buttonid));
		return buttonid;
	}
};

#endif // _MESSAGEBOX_HPP_
