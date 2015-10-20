#include "BobNEve.h"

#include "Game.h"

BobNEve::BobNEve()
	: game_(new Game())
{
}

BobNEve::~BobNEve()
{
	delete game_;
}

void BobNEve::Init(){

}

void BobNEve::Launch(){
	
}

void BobNEve::Start(){
	game_->Start();
}