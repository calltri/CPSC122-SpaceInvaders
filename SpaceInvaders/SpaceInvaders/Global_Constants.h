#pragma once

#include<iostream>
#include<string>


const bool DEBUG = false;

int const WINDOW_WIDTH = 640;
int const WINDOW_HEIGHT = 800;

const float LASER_WIDTH = WINDOW_WIDTH / 320;
const float LASER_HEIGHT = WINDOW_HEIGHT / 40;
const float LASER_SPEED = WINDOW_HEIGHT / 50 / 2;
//Enemy Basic
const float ENEMY_BASIC_WIDTH = 50;
const float ENEMY_BASIC_HEIGHT = 40;
//Enemy2
const float ENEMY_2_WIDTH = 54;
const float ENEMY_2_HEIGHT = 40;
//Enemy Ship (Boss)
const float ENEMY_SHIP_WIDTH = 85;
const float ENEMY_SHIP_HEIGHT = 40;
//Friendly Ship
const float FRIENDLY_SHIP_WIDTH = 50;
const float FRIENDLY_SHIP_HEIGHT = 60;
//Health Sprite
const float HEALTH_WIDTH = 30;
const float HEALTH_HEIGHT = 27;