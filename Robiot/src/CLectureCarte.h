#ifndef LECTURE_CARTE
#define LECTURE_CARTE

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>



using namespace std;

#pragma once
class CLectureCarte
{
	private:
		vector< vector<char> > carte;

	public: 
	// Constructeur
	CLectureCarte();


	//Destructeur
	~CLectureCarte();

	void AfficheCarte();
	void CreationTableau(int itaille_collonne, int itaille_ligne);


	
};

#endif