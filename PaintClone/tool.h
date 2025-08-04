#pragma once
#include "thing.h"

class Tool : public Thing
{
public:
	virtual void Start() override { }
	virtual void Update() override { }
	virtual void HandleEvent(sf::Event &currentEvent) override { }
	virtual void CleanUp() override { }
	virtual void Draw() override { }

	virtual void Select();
	virtual void Deselect();
	virtual void DrawToCanvas() { }
};