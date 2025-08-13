/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : uiHandler
Description : ngl I never ended up using this and did it all in toolbar for some reason
Author : Maximilian Oscar Jack McCarthy
Mail : maximilian.mccarthy@mds.ac.nz
**************************************************************************/

#pragma once
#include "thing.h"

class UiHandler : public Thing
{
private:
	
public:
	void Start() override;
	void Update(float deltaTime, sf::RenderWindow& window) override;
	void Draw(sf::RenderWindow& window) override
};