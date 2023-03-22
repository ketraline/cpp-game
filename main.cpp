#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <string>
using namespace std;

int hp = 20, light = 20, ehp = 35, move, desc;

void lose(){
	cout << "You lose." << endl;
	hp = 20;
	light = 20;
	ehp = 20;
}

void win(){
	cout << "You win." << endl;
	hp = 20;
	light = 20;
	ehp = 20;
}

main(){
	cout << "In the middle of the City, suddenly a huge library rose from out of the ground. Weird creatures started roaming the area, people contorting and changing into hideous monsters. Your name is Roland, and your task is to protect." << endl;
	label:
	cout << "Enemy HP: " << ehp << endl << "Your HP: " << hp << endl << "Light: " << light << endl <<"Type desc and number of the move for extra information." << endl;
	cout << "(1) Attack: Mook Workshop" << endl << "(2) Attack: Wheels Industry" << endl << "(3) Attack: Furioso" << endl << "(4) Describe Attacks" << endl;
	cin >> move; 
	system("cls");
	cout << "Status:" << endl;
	
	if (move == 1){
		cout << "You sliced the enemy with your sword." << endl;
		ehp -= 2;
		if (ehp <= 0)
		{
			win();
			return 0;
		}
		cout << endl << "The enemy attacks with his sword." << endl << endl;
		hp -= 2;
		if (hp <= 0)
		{
			lose();
			return 0;
		}
	}
	
	if (move == 2){
		if (light < 2){
			
		}
		else{
		cout << "You bash your enemy on the head with a giant longsword.";
		ehp -= 4;
		light -= 2;
		if (ehp <= 0)
		{
			win();
			return 0;
		}
		cout << "The enemy used his axe." << endl << endl;
		hp -=2;	
		if (hp <= 0)
		{
			lose();
			return 0;
		}
		if (light <= 0)
		{
			cout << "You're significantly worn out. You can't perform light-based attacks.";
		}
	}
	}
	
	if (move == 3){
		if (light < 10){
				cout << "You gathered all your strength to use all of your weapons in a series of attacks, but instead only managed to barely scratch the enemy with your sword... \n Wait for your light to regenerate.";
		ehp -= 1;
		if (ehp <= 0)
		{
			win();
			return 0;
		}
		cout << endl << "The enemy attacks with sword." << endl << endl;
		hp -= 2;
		if (hp <= 0)
		{
			lose();
			return 0;
		}	
		goto label;
		}
		else{
		cout << "You perform a 10-part attack, using all of your weapons. It wore you out a lot.";
		ehp -= 16;
		light -= 10;
		hp -= 2;
		if (ehp <= 0)
		{
			win();
			return 0;
		}
		if (hp <= 0)
		{
			lose();
			return 0;
		}
		cout << "The enemy used his axe." << endl << endl;
		hp -=2;	
		if (hp <= 0)
		{
			lose();
			return 0;
		}
		if (light <= 0)
		{
			cout << "You're significantly worn out. You can't perform light-based attacks.";
		}
	}
	}
	if (move == 4){
		cout << "Which attack would you like described?";
		cin >> desc;
		if (desc == 1){
		cout << endl << "Attack: Mook Workshop" << endl << "You attack the enemy with your sword." << endl << "Deals 2 HP." << endl << endl;
		goto label;
	}
	
	if (desc == 2){
		cout << endl << "Attack: Wheels Industry" << endl << "You attack the enemy with a longsword." << endl << "Deals 4 HP. Consumes 2 Light." << endl << endl;
		goto label;
	}
	
	if (desc == 3){
		cout << endl << "Attack: Furioso" << endl << "You use all of your weapons to attack in a series." << endl << "Deals 16 HP. Consumes 10 Light." << endl << endl;
		goto label;
	}
	}
	light += 1;
	goto label;
}
