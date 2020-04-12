#include "Level1Gen.h"
#include "The_Glitch.h"

Level1Gen::Level1Gen() {
	//change numbers to add floors
	roomsBlockNum[0] = 0,
		26, 53, 24, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0;

	roomsDoorNum[0] = 0,
		3, 1, 1, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0;

	for (int i = 0; i < 100; i++) {
		roomsgen[i] = -1;
	}
	//add floor coords to the lists
	room1[0] = Vec3(-2.0f, 0.0f, 0.0f), Vec3(2.0f, 0.0f, 0.0f), Vec3(-2.0f, 2.0f, 0.0f), Vec3(2.0f, 2.0f, 0.0f), Vec3(-2.0f, 4.0f, 0.0f), Vec3(2.0f, 4.0f, 0.0f), Vec3(4.0f, 4.0f, 0.0f), Vec3(6.0f, 4.0f, 0.0f), Vec3(-4.0f, 6.0f, 0.0f), Vec3(-2.0f, 6.0f, 0.0f), Vec3(2.0f, 8.0f, 0.0f), Vec3(4.0f, 8.0f, 0.0f), Vec3(6.0f, 8.0f, 0.0f), Vec3(-4.0f, 10.0f, 0.0f), Vec3(-2.0f, 10.0f, 0.0f), Vec3(2.0f, 10.0f, 0.0f), Vec3(4.0f, 10.0f, 0.0f), Vec3(6.0f, 10.0f, 0.0f), Vec3(-2.0f, 12.0f, 0.0f), Vec3(6.0f, 12.0f, 0.0f), Vec3(-2.0f, 14.0f, 0.0f), Vec3(2.0f, 14.0f, 0.0f), Vec3(6.0f, 14.0f, 0.0f), Vec3(-2.0f, 16.0f, 0.0f), Vec3(0.0f, 16.0f, 0.0f), Vec3(2.0f, 16.0f, 0.0f),
		Vec3(6.0f, 6.0f, 0.0f), Vec3(-4.0f, 8.0f, 0.0f), Vec3(4.0f, 14.0f, 0.0f);//doors positions

	room2[0] = Vec3(-12.0f, 0.0f, 0.0f), Vec3(-10.0f, 0.0f, 0.0f), Vec3(-8.0f, 0.0f, 0.0f), Vec3(-6.0f, 0.0f, 0.0f), Vec3(-4.0f, 0.0f, 0.0f), Vec3(-2.0f, 0.0f, 0.0f), Vec3(2.0f, 0.0f, 0.0f), Vec3(4.0f, 0.0f, 0.0f), Vec3(6.0f, 0.0f, 0.0f), Vec3(8.0f, 0.0f, 0.0f), Vec3(10.0f, 0.0f, 0.0f), Vec3(12.0f, 0.0f, 0.0f), Vec3(-12.0f, 2.0f, 0.0f), Vec3(12.0f, 2.0f, 0.0f), Vec3(-12.0f, 4.0f, 0.0f), Vec3(-4.0f, 4.0f, 0.0f), Vec3(-2.0f, 4.0f, 0.0f), Vec3(0.0f, 4.0f, 0.0f), Vec3(2.0f, 4.0f, 0.0f), Vec3(4.0f, 4.0f, 0.0f), Vec3(12.0f, 4.0f, 0.0f), Vec3(-12.0f, 6.0f, 0.0f), Vec3(-4.0f, 6.0f, 0.0f), Vec3(4.0f, 6.0f, 0.0f), Vec3(12.0f, 6.0f, 0.0f), Vec3(-12.0f, 8.0f, 0.0f), Vec3(4.0f, 8.0f, 0.0f), Vec3(12.0f, 8.0f, 0.0f), Vec3(-12.0f, 10.0f, 0.0f), Vec3(-4.0f, 10.0f, 0.0f), Vec3(4.0f, 10.0f, 0.0f), Vec3(12.0f, 10.0f, 0.0f), Vec3(-12.0f, 12.0f, 0.0f), Vec3(-4.0f, 12.0f, 0.0f), Vec3(-2.0f, 12.0f, 0.0f), Vec3(0.0f, 12.0f, 0.0f), Vec3(2.0f, 12.0f, 0.0f), Vec3(4.0f, 12.0f, 0.0f), Vec3(12.0f, 12.0f, 0.0f), Vec3(-12.0f, 14.0f, 0.0f), Vec3(12.0f, 14.0f, 0.0f), Vec3(-12.0f, 16.0f, 0.0f), Vec3(-10.0f, 16.0f, 0.0f), Vec3(-8.0f, 16.0f, 0.0f), Vec3(-6.0f, 16.0f, 0.0f), Vec3(-4.0f, 16.0f, 0.0f), Vec3(-2.0f, 16.0f, 0.0f), Vec3(2.0f, 16.0f, 0.0f), Vec3(4.0f, 16.0f, 0.0f), Vec3(6.0f, 16.0f, 0.0f), Vec3(8.0f, 16.0f, 0.0f), Vec3(10.0f, 16.0f, 0.0f), Vec3(12.0f, 16.0f, 0.0f),
		Vec3(0.0f, 16.0f, 0.0f);//door position

	room3[0] = Vec3(-2.0f, 0.0f, 0.0f), Vec3(2.0f, 0.0f, 0.0f), Vec3(-2.0f, 2.0f, 0.0f), Vec3(2.0f, 2.0f, 0.0f), Vec3(-2.0f, 4.0f, 0.0f), Vec3(2.0f, 4.0f, 0.0f), Vec3(-2.0f, 6.0f, 0.0f), Vec3(2.0f, 6.0f, 0.0f), Vec3(-2.0f, 8.0f, 0.0f), Vec3(2.0f, 8.0f, 0.0f), Vec3(-2.0f, 10.0f, 0.0f), Vec3(2.0f, 10.0f, 0.0f), Vec3(-2.0f, 12.0f, 0.0f), Vec3(2.0f, 12.0f, 0.0f), Vec3(-2.0f, 14.0f, 0.0f), Vec3(2.0f, 14.0f, 0.0f), Vec3(-2.0f, 16.0f, 0.0f), Vec3(2.0f, 16.0f, 0.0f), Vec3(-2.0f, 18.0f, 0.0f), Vec3(2.0f, 18.0f, 0.0f), Vec3(-2.0f, 20.0f, 0.0f), Vec3(2.0f, 20.0f, 0.0f), Vec3(-2.0f, 22.0f, 0.0f), Vec3(2.0f, 22.0f, 0.0f), 
		Vec3(0.0f, 22.0f, 0.0f);//door position

	/*
		|/|
		| |
		| ~~~~~/|
		|		|
		| |~~~| |
		| |	  | |~~~~~
		| |   |      /
		| |   | |~~~~~
		|       |
		|		|
		|		|
		~~~~/~~~~
	
	
	*/
	room4[0] = Vec3(-8.0f, 0.0f, 0.0f), Vec3(-6.0f, 0.0f, 0.0f), Vec3(-4.0f, 0.0f, 0.0f), Vec3(-2.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, -2.0f), Vec3(2.0f, 0.0f, 0.0f), Vec3(4.0f, 0.0f, 0.0f), Vec3(6.0f, 0.0f, 0.0f),
		Vec3(-8.0f, 2.0f, 0.0f), Vec3(-6.0f, 2.0f, -2.0f), Vec3(-4.0f, 2.0f, -2.0f), Vec3(-2.0f, 2.0f, -2.0f), Vec3(0.0f, 2.0f, -2.0f), Vec3(2.0f, 2.0f, -2.0f), Vec3(4.0f, 2.0f, -2.0f), Vec3(6.0f, 2.0f, -2.0f), Vec3(8.0f, 2.0f, 0.0f),
		Vec3(-8.0f, 4.0f, 0.0f), Vec3(-6.0f, 4.0f, -2.0f), Vec3(-4.0f, 4.0f, -2.0f), Vec3(-2.0f, 4.0f, -2.0f), Vec3(0.0f, 4.0f, -2.0f), Vec3(2.0f, 4.0f, -2.0f), Vec3(4.0f, 4.0f, -2.0f), Vec3(6.0f, 4.0f, -2.0f), Vec3(8.0f, 4.0f, 0.0f),
		Vec3(-8.0f, 6.0f, 0.0f), Vec3(-6.0f, 6.0f, -2.0f), Vec3(-4.0f, 6.0f, -2.0f), Vec3(-2.0f, 6.0f, -2.0f), Vec3(0.0f, 6.0f, -2.0f), Vec3(2.0f, 6.0f, -2.0f), Vec3(4.0f, 6.0f, -2.0f), Vec3(6.0f, 6.0f, -2.0f), Vec3(8.0f, 6.0f, 0.0f),
		Vec3(-8.0f, 8.0f, 0.0f), Vec3(-6.0f, 8.0f, -2.0f), Vec3(-4.0f, 8.0f, 0.0f), Vec3(-2.0f, 8.0f, -2.0f), Vec3(0.0f, 8.0f, -2.0f), Vec3(2.0f, 8.0f, -2.0f), Vec3(4.0f, 8.0f, 0.0f), Vec3(6.0f, 8.0f, -2.0f), Vec3(8.0f, 8.0f, 0.0f), Vec3(10.0f, 8.0f, 0.0f), Vec3(12.0f, 8.0f, 0.0f), Vec3(14.0f, 8.0f, 0.0f), Vec3(16.0f, 8.0f, 0.0f), Vec3(18.0f, 8.0f, 0.0f),
		Vec3(-8.0f, 10.0f, 0.0f), Vec3(-6.0f, 10.0f, -2.0f), Vec3(-4.0f, 10.0f, 0.0f), Vec3(-2.0f, 10.0f, -2.0f), Vec3(0.0f, 10.0f, -2.0f), Vec3(2.0f, 10.0f, -2.0f), Vec3(4.0f, 10.0f, 0.0f), Vec3(6.0f, 10.0f, -2.0f), Vec3(8.0f, 10.0f, 0.0f), Vec3(10.0f, 10.0f, -2.0f), Vec3(12.0f, 10.0f, -2.0f), Vec3(14.0f, 10.0f, -2.0f), Vec3(16.0f, 10.0f, -2.0f), Vec3(18.0f, 10.0f, -2.0f),
		Vec3(-8.0f, 12.0f, 0.0f), Vec3(-6.0f, 12.0f, -2.0f), Vec3(-4.0f, 12.0f, 0.0f), Vec3(-2.0f, 12.0f, -2.0f), Vec3(0.0f, 12.0f, -2.0f), Vec3(2.0f, 12.0f, -2.0f), Vec3(4.0f, 12.0f, 0.0f), Vec3(6.0f, 12.0f, -2.0f), Vec3(8.0f, 12.0f, 0.0f), Vec3(10.0f, 12.0f, 0.0f), Vec3(12.0f, 12.0f, 0.0f), Vec3(14.0f, 12.0f, 0.0f), Vec3(16.0f, 12.0f, 0.0f), Vec3(18.0f, 12.0f, 0.0f),
		Vec3(-8.0f, 14.0f, 0.0f), Vec3(-6.0f, 14.0f, -2.0f);


	curRoom = 0.0f; 

}
Level1Gen::~Level1Gen() {}

int Level1Gen::RoomGenerations() {

	seed = (long)13492;
	ran1idnum = (long)-13492;

#define IA 16807		/// primitive root modulo M31 7^5
#define IM 2147483647	/// One of the Mersenne primes: 2^31-1
#define AM (1.0/IM)
#define IQ 127773
#define IR 2836
#define NTAB 32
#define NDIV (1+(IM-1)/NTAB)
#define EPS 1.2e-7
#define RNMX (1.0-EPS)
	int j;
	long k;
	static long iy = 0;
	static long iv[NTAB];
	float temp;
	if (ran1idnum <= 0 || !iy) {
		if (-(ran1idnum) < 1) ran1idnum = 1;
		else ran1idnum = -(ran1idnum);
		for (j = NTAB + 7; j >= 0; j--) {
			k = (ran1idnum) / IQ;
			ran1idnum = IA * (ran1idnum - k * IQ) - IR * k;
			if (ran1idnum < 0) ran1idnum += IM;
			if (j < NTAB) iv[j] = ran1idnum;
		}
		iy = iv[0];
	}
	k = (ran1idnum) / IQ;
	ran1idnum = IA * (ran1idnum - k * IQ) - IR * k;
	if (ran1idnum < 0) ran1idnum += IM;
	j = iy / NDIV;
	iy = iv[j];
	iv[j] = ran1idnum;
	temp = (float)AM * iy;
	if (temp > RNMX) {
		return RNMX;
	}
	else {
		int tempi = static_cast<int>(((temp) * (99.0 - 0.0) + 0.0));
		for (int i = 0; i < 100; i++) {
			if (tempi == roomsgen[i]) {
				tempi = RoomGenerations();
				i = 0;
			}
		}
		roomsgen[tempi] = tempi;

		return tempi;
	}
#undef IA
#undef IM
#undef AM
#undef IQ
#undef IR
#undef NTAB
#undef NDIV
#undef EPS
#undef RNMX
}

void Level1Gen::RoomPlacement(Vec3 d, Vec3 doorPos, WallSegment* wallSegment, Door* doors, int doorNum) {
	float angleD;
	int temp = 0;
	int doorTemp = 0;
	Matrix4 rotation;
	switch (RoomGenerations()) {
	
	case 1:
		//OMNOM feed me 26 Blocks and 3 Doors

	/*
			|~|
			| |/|
			|   |
		   ~| |~~
		   /  |~~
		   ~|	/
			| |~~
			| |
			|/|
	*/

		
		for (int i = 0; i < 100; i++) {
			if (roomsgen[i] == -1) {
			
			}
			else {
				temp += roomsBlockNum[i];
			}
		}
		temp -= roomsBlockNum[1];
		temp++;
		if (d.y == 1.0f) { angleD = 0.0f; }
		else if (d.x == 1.0f) { angleD = 90.0f; }
		else if (d.y == -1.0f) { angleD = 180.0f; }
		else { angleD = 270.0f; }
		rotation = MMath::rotate(angleD, Vec3(0.0f, 0.0f, 1.0f));

		for (int i = 0; i < 25; i++) {
			wallSegment[temp + i].setPos((rotation * room1[i]) + doorPos);
			wallSegment[temp + i].partOfRoom = 1;
		}

		for (int i = 0; i < 100; i++) {
			if (roomsgen[i] == -1) {

			}
			else {
				temp += roomsDoorNum[i];
			}
		}
		temp -= roomsDoorNum[1];
		temp++;

		
		doors[temp].setPos((rotation * room1[26]) + doorPos);
		doors[temp].partOfRoom = 1;
		doors[temp + 1].setPos((rotation * room1[27]) + doorPos);
		doors[temp + 1].partOfRoom = 1;
		doors[temp + 2].setPos((rotation * room1[28]) + doorPos);
		doors[temp + 2].partOfRoom = 1;
		doors[doorNum].partOfRoom = 1;

		doors[temp].direction = rotation * Vec3(0.0f, 1.0f, 0.0f);
		doors[temp + 1].direction = rotation * Vec3(0.0f, -1.0f, 0.0f);
		doors[temp + 2].direction = rotation * Vec3(1.0f, 0.0f, 0.0f);
		doors[doorNum].direction = rotation * Vec3(-1.0f, 0.0f, 0.0f);

		break;

	case 2:
		//OMNOM feed me 53 blocks and 1 door
		/*
			~~~~~|/|~~~~~
			|			|
			|	~~~~~	|
			|	|	|	|
			|		|	|
			|	|   |	|
			|	~~~~~	|
			|			|
			~~~~~|/|~~~~~
		*/

		
		for (int i = 0; i < 100; i++) {
			if (roomsgen[i] == -1) {

			}
			else {
				temp += roomsBlockNum[i];
			}
		}
		temp -= roomsBlockNum[2];
		temp++;
		if (d.y == 1.0f) { angleD = 0.0f; }
		else if (d.x == 1.0f) { angleD = 90.0f; }
		else if (d.y == -1.0f) { angleD = 180.0f; }
		else { angleD = 270.0f; }
		rotation = MMath::rotate(angleD, Vec3(0.0f, 0.0f, 1.0f));

		for (int i = 0; i < 52; i++) {
			wallSegment[temp + i].setPos((rotation * room2[i]) + doorPos);
			wallSegment[temp + i].partOfRoom = 2;
		}

		for (int i = 0; i < 100; i++) {
			if (roomsgen[i] == -1) {

			}
			else {
				temp += roomsDoorNum[i];
			}
		}
		temp -= roomsDoorNum[1];
		temp++;


		doors[temp].setPos((rotation * room2[52]) + doorPos);
		doors[temp].partOfRoom = 2;
		doors[doorNum].partOfRoom = 2;

		doors[temp].direction = rotation * Vec3(1.0f, 0.0f, 0.0f);
		doors[doorNum].direction = rotation * Vec3(-1.0f, 0.0f, 0.0f);
		//doors will have the last of the arrays for room positions and will be in accending y


		break;

	case 3:

		//OMNOM feed me 24 blocks and 1 door
		/*
			|/|
			| |
			| |
			| |
			| |
			| |
			| |
			| |
			| |
			| |
			| |
			|/|
		*/




		
		for (int i = 0; i < 100; i++) {
			if (roomsgen[i] == -1) {

			}
			else {
				temp += roomsBlockNum[i];
			}
		}
		temp -= roomsBlockNum[3];
		temp++;
		if (d.y == 1.0f) { angleD = 0.0f; }
		else if (d.x == 1.0f) { angleD = 90.0f; }
		else if (d.y == -1.0f) { angleD = 180.0f; }
		else { angleD = 270.0f; }
		rotation = MMath::rotate(angleD, Vec3(0.0f, 0.0f, 1.0f));

		for (int i = 0; i < 23; i++) {
			wallSegment[temp + i].setPos((rotation * room3[i]) + doorPos);
			wallSegment[temp + i].partOfRoom = 3;
		}

		for (int i = 0; i < 100; i++) {
			if (roomsgen[i] == -1) {

			}
			else {
				temp += roomsDoorNum[i];
			}
		}
		temp -= roomsDoorNum[1];
		temp++;


		doors[temp].setPos((rotation * room3[24]) + doorPos);
		doors[temp].partOfRoom = 3;
		doors[doorNum].partOfRoom = 3;

		doors[temp].direction = rotation * Vec3(1.0f, 0.0f, 0.0f);
		doors[doorNum].direction = rotation * Vec3(-1.0f, 0.0f, 0.0f);

		break;

	case 4:


		for (int i = 0; i < 100; i++) {
			if (roomsgen[i] == -1) {

			}
			else {
				temp += roomsBlockNum[i];
			}
		}
		temp -= roomsBlockNum[4];
		temp++;
		if (d.y == 1.0f) { angleD = 0.0f; }
		else if (d.x == 1.0f) { angleD = 90.0f; }
		else if (d.y == -1.0f) { angleD = 180.0f; }
		else { angleD = 270.0f; }
		rotation = MMath::rotate(angleD, Vec3(0.0f, 0.0f, 1.0f));

		for (int i = 0; i < 23; i++) {
			wallSegment[temp + i].setPos((rotation * room4[i]) + doorPos);
			wallSegment[temp + i].partOfRoom = 4;
		}

		for (int i = 0; i < 100; i++) {
			if (roomsgen[i] == -1) {

			}
			else {
				temp += roomsDoorNum[i];
			}
		}
		temp -= roomsDoorNum[1];
		temp++;


		doors[temp].setPos((rotation * room4[24]) + doorPos);
		doors[temp].partOfRoom = 4;

		doors[temp].direction = rotation * Vec3(1.0f, 0.0f, 0.0f);
		doors[doorNum].direction = rotation * Vec3(-1.0f, 0.0f, 0.0f);
		//set door pos to rotation * room2[_] + doorPos


		break;

	case 5:

		

		break;

	case 6:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 7:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;


	case 8:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 9:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 10:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 11:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 12:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 13:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 14:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 15:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 16:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;


	case 17:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 18:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 19:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 20:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 21:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 22:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 23:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 24:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 25:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 26:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 27:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 28:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 29:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 30:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 31:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 32:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 33:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 34:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 35:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 36:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 37:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 38:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 39:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 40:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 41:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 42:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 43:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 44:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 45:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 46:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 47:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 48:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 49:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 50:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 51:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 52:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 53:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 54:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 55:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 56:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 57:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 58:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 59:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 60:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 61:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 62:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 63:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 64:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 65:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 66:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 67:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 68:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 69:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 70:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 71:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 72:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 73:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 74:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 75:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 76:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 77:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 78:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 79:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 80:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 81:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 82:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 83:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 84:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 85:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 86:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 87:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 88:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 89:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 90:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 91:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 92:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 93:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 94:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 95:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 96:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 97:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 98:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	case 99:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;

	default:

		if (d.y == 1.0f) {


		}
		if (d.x == 1.0f) {


		}
		if (d.y == -1.0f) {


		}
		if (d.x == -1.0f) {


		}

		break;


	}
}
