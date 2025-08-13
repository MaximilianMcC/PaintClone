/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : tool
Description : tool parent
Author : Maximilian Oscar Jack McCarthy
Mail : maximilian.mccarthy@mds.ac.nz
**************************************************************************/

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
	virtual void DrawOnCanvas() { }

	std::string GetName();
	
	std::string GetInfo();
	void SetInfo(std::string newInfo);
};