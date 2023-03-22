#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <string>
using namespace std;

int hp = 20, light = 20, ehp = 35;
string move = "";

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
	cout << "(1) Attack: Mook Workshop" << endl << "(2) Attack: Wheels Industry" << endl << "(3) Attack: Furioso" << endl;
	cin >> move;
	system("cls");
	cout << "Status:" << endl;
	
	if (move == "desc 1"){
		cout << "Attack: Mook Workshop" << endl << "You attack the enemy with your sword." << endl << "Deals 2 HP." << endl;
		goto label;
	}
	
	if (move == "desc 2"){
		cout << "Attack: Wheels Industry" << endl << "You attack the enemy with a longsword." << endl << "Deals 4 HP. Consumes 2 Light." << endl;
		goto label;
	}
	
	if (move == "desc 3"){
		cout << "Attack: Furioso" << endl << "You use all of your weapons to attack in a series." << endl << "Deals 16 HP. Consumes 10 Light." << endl;
		goto label;
	}
	
	if (move == "2" && light < 2){
		cout << "You tried using your longsword, but you felt too weak to swing it and it dropped to the floor with a loud thud... \n Wait for your light to regenerate.";
		cout << endl << "The enemy attacks with sword." << endl << endl;
		hp -= 2;
		if (hp <= 0)
		{
			lose();
			return 0;
		}	
		goto label;
	}
	if (move == "3" && light < 10){
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
	
	if (move == "1"){
		cout << "You sliced the enemy with your sword." << endl;
		ehp -= 2;
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
	}
	
	if (move == "2"){
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
	
	if (move == "3"){
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
	light += 1;
	goto label;
}

