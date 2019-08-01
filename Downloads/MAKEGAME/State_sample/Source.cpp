
#include <conio.h>
#include <cstdio>
#include <iostream>
#define STATE
#ifdef STATE
using namespace std;
class StateBase
{
public:
	virtual StateBase* GetNextState() = 0;
	virtual    char* ToString() = 0;
};

class Dlock : public StateBase
{
public:
	virtual StateBase* GetNextState();
	virtual    char *ToString() {
		return "=>Door was Locked";
	}
};

class Dunlock : public StateBase
{
public:
	virtual StateBase* GetNextState();
	virtual    char* ToString() {
		return "=>Door was Unlocked";
	}
};

// State night
class Dclose : public StateBase
{
public:
	virtual StateBase* GetNextState();
	virtual    char* ToString() {
		return "=>Door was Closed";
	}
};
class Dopen : public StateBase
{
public:
	virtual StateBase* GetNextState();
	virtual    char* ToString() {
		return "=>Door was Opened";
	}
};


StateBase* Dlock::GetNextState() {

		return new Dunlock();
}

StateBase* Dunlock::GetNextState() {
	int n;
	cout << "Door is Unlock\nChose 1 to LOCK.\nChose 2 to OPEN\n";
	cin >> n;
	if(n==1)
		return new Dlock();
	return new Dopen;
}

StateBase* Dclose::GetNextState() {
	int n;
	cout << "Door is CLOSE\nChose 1 to OPEN.\nChose 2 to LOCK\n";
	cin >> n;
	if (n == 1)
	return new Dopen();
	return new Dlock();
}
StateBase* Dopen::GetNextState() {
	return new Dclose();
}

class Door
{
public:
	Door() {}
	Door(StateBase* pContext) {
		m_pState = pContext;
	}
	~Door() {
		delete m_pState;
	}
	void StateChanged() {
		if (m_pState) {
			StateBase* pState = m_pState->GetNextState();
			delete m_pState;
			m_pState = pState;
		}
	}
	char* GetStatus() {
		return m_pState->ToString();
	}
protected:
	StateBase* m_pState;
};

#endif

void main()
{
#ifdef STATE

	Door objDoor(new Dclose);
	cout << "Begin:\n";
	printf("STATUS: %s !!!\n\n", objDoor.GetStatus());
	cout << "Change:\n";
	objDoor.StateChanged();
	printf("STATUS: %s !!!\n\n", objDoor.GetStatus());
	cout << "Change:\n";
	objDoor.StateChanged();
	printf("STATUS: %s !!!\n\n", objDoor.GetStatus());
	cout << "Change:\n";
	objDoor.StateChanged();
	printf("STATUS: %s !!!\n\n", objDoor.GetStatus());
	cout << "Change:\n";
	objDoor.StateChanged();
	printf("STATUS: %s !!!\n\n", objDoor.GetStatus());
	cout << "Change:\n";
	objDoor.StateChanged();
	printf("STATUS: %s !!!\n\n", objDoor.GetStatus());
	cout << "Change:\n";
	objDoor.StateChanged();
	printf("STATUS: %s !!!\n\n", objDoor.GetStatus());
	cout << "Change:\n";
	objDoor.StateChanged();
	printf("STATUS: %s !!!\n\n", objDoor.GetStatus());

#endif

	system("pause");
}