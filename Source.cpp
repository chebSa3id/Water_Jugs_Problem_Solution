#include <conio.h>
#include <iostream>
#include <vector>
#include <set>

//assume x=4,y3
using namespace std;


struct node {
	int x, y;
	bool old = 0;
	vector <node*> childs;
};

set<node*> sett;
node* crtnode(int x, int y) {
	node* tmp = new node;
	tmp->x = x;
	tmp->y = y;
	return tmp;
}

void fillx(node* a) {
	a->x = 4;
}
void filly(node* a) {
	a->y = 3;
}
void emptx(node* a) {
	a->x = 0;
}
void empty(node* a) {
	a->y = 0;
}
void xty(node* a) {
	while (a->y < 3 && a->x != 0) {
		a->x -= 1;
		a->y += 1;
	}
}

void ytx(node* a) {
	while (a->x < 4 && a->y != 0) {
		a->y -= 1;
		a->x += 1;
	}
}

bool chkset(node* a) {
	set<node*> ::iterator it;
	node* b;
	for (it = sett.begin(); it != sett.end(); ++it) {
		b = *it;
		if (b->x == a->x && b->y == a->y) {
			return 0;
		}
	}
	return 1;
}

int algo(node* nod, int gx, int gy) {

	if (chkset(nod)) {
		sett.insert(nod);
	}
	else {
		return 0;
	}
	while (!(nod->x == gx && nod->y == gy)) {

		node* tmp = new node;
		tmp->x = nod->x; tmp->y = nod->y;
		fillx(tmp);
		nod->childs.push_back(tmp);
		tmp = new node;
		tmp->x = nod->x; tmp->y = nod->y;
		filly(tmp);

		nod->childs.push_back(tmp);
		tmp = new node;
		tmp->x = nod->x; tmp->y = nod->y;
		emptx(tmp);

		nod->childs.push_back(tmp);
		tmp = new node;
		tmp->x = nod->x; tmp->y = nod->y;
		empty(tmp);

		nod->childs.push_back(tmp);

		tmp = new node;
		tmp->x = nod->x; tmp->y = nod->y;
		xty(tmp);

		nod->childs.push_back(tmp);
		tmp = new node;
		tmp->x = nod->x; tmp->y = nod->y;
		ytx(tmp);
		nod->childs.push_back(tmp);
		return (algo(nod->childs[0], 1, 0) || algo(nod->childs[1], 1, 0) || algo(nod->childs[2], 1, 0) || algo(nod->childs[3], 1, 0) || algo(nod->childs[4], 1, 0) || algo(nod->childs[5], 1, 0));
	}
	return (1);
}

using namespace std;

int main() {
	node* tree = crtnode(0, 0);
	int gx, gy;
	gx = 1, gy = 0;
	int x = algo(tree, gx, gy);
	if (x == 1) {
		cout << "Goal is Reached : " << '(' << gx << ',' << gy << ')' << '\n';
	}
	return 0;
}