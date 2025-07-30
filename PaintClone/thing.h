#pragma once
#include "SFML/Graphics.hpp"
#include "program.h"
#include <iostream>
#include "utils.h"

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