/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : thing
Description : everything is a thing
Author : Maximilian Oscar Jack McCarthy
Mail : maximilian.mccarthy@mds.ac.nz
**************************************************************************/

#pragma once
#include <iostream>
#include <functional>
#include "SFML/Graphics.hpp"
#include "utils.h"
#include "assetManager.h"
#include "colors.h"



class Thing
{
public:
	virtual void Start() { }
	virtual void Update() { }
	virtual void HandleEvent(sf::Event &currentEvent) { }
	virtual void Draw() { }
	virtual void CleanUp() { }
};

// Just for organisation
class UiElement : public Thing
{
public:
	void Start() override { }
	void Update() override { }
	void HandleEvent(sf::Event &currentEvent) override { }
	void Draw() override { }
	void CleanUp() override { }
};