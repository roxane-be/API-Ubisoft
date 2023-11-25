#pragma once

class Button;
class UIGame : public Component
{
public:
	UIGame();

	virtual void Init() override;
	virtual void Update(float deltaTime) override;
	virtual void Render() override;



	//Button* buttonQuit;
	//Button* buttonShop;
	//Button* buttonPlay;

private:
	//std::vector<Button> m_buttons;
	//enum eButtons {
	//	PLAY,
	//	SHOP,
	//	QUIT	
	//};

	void PlayGame();
	void ShopWindow();
	void QuitGame();

};

