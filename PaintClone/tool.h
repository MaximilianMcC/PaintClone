#pragma once
#include "thing.h"

class Tool : public Thing
{
protected:
	std::string name;
	std::string info;

public:
	Tool(std::string displayName, std::string descriptionAndTutorial);

	virtual void Start() override { }
	virtual void Update() override { }
	virtual void HandleEvent(sf::Event &currentEvent) override { }
	virtual void CleanUp() override { }
	virtual void Draw() override { }

	virtual void Select() { }
	virtual void Deselect() { }
	virtual void DrawToCanvas() { }

	std::string GetName();
	
	std::string GetInfo();
	void SetInfo(std::string newInfo);
};