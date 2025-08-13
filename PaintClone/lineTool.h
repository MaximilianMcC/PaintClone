/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : lineTool
Description : line tool
Author : Maximilian Oscar Jack McCarthy
Mail : maximilian.mccarthy@mds.ac.nz
**************************************************************************/

#pragma once
#include "tool.h"
#include "shapeTool.h"
#include "slider.h"
#include "toolbar.h"

class LineTool : public ShapeTool
{
private:
	float thickness = 0.1f;
	Slider slider;

	void MakeNewShape();
	void ResizeShape(sf::Vector2f newSize);

public:
	LineTool(std::string displayName, std::string descriptionAndTutorial)
	: ShapeTool(displayName, descriptionAndTutorial) { }

	void Start() override;
	void Update() override;
	void Draw() override;
};