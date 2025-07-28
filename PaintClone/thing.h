#pragma once
#include "SFML/Graphics.hpp"
#include "program.h"
#include <iostream>
#include "utils.h"

class Thing
{
public:
	//? = 0 makes it an abstract method
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void HandleEvent(sf::Event &currentEvent) { }
	virtual void Draw() = 0;
	virtual void CleanUp() { }
};