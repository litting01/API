#pragma once
#include <Windows.h>
class Mouse
{
	POINT pos;
	bool click = false;
	static Mouse* Instance;
	Mouse();
	~Mouse();
public:
	static void Create() {
		if (Instance == NULL)
			Instance = new Mouse;
	}
	static Mouse* GetInstance() {
		return Instance;
	}
	static void Destroy() {
		if (Instance == NULL)
			return;
		delete Instance;
		Instance = nullptr;
	}
	void SetPos(POINT _pos) {
		pos = _pos;
	}
	void SetPos(LPARAM lParam) {
		pos.x = LOWORD(lParam);
		pos.y = HIWORD(lParam);
	}
	void SetClick(bool _click) {
		click = _click;
	}
	bool GetClick() {
		return click;
	}
	POINT GetPos() {
		return pos;
	}
};