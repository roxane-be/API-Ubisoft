#pragma once

class Button;
class UIGame
{
public:
	UIGame();

	void Init();
	void Update(float deltaTime);
	void Render();

	void PlayGame();
	void ShopWindow();
	void QuitGame();

	Button* buttonQuit;
	Button* buttonShop;
	Button* buttonPlay;



};

