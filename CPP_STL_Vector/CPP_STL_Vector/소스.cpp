#include <iostream>
#include <vector>

#define USER_MAX 6

using namespace std;

struct UserInfo
{
	char acUserName[21];
	int Level;
	int Exp;
};

//���� ���� ������ �����ϴ� Ŭ����
//�濡�� �ִ� 6����� ��� �� �� �ִ�.
//�濡 ������ ���� �� ���� ���� ��� �� ����� ������ �ȴ�

class GameRoomUser
{
public:
	GameRoomUser();
	~GameRoomUser();

//�濡�� ���� ����
//���� ������ ������ acMasterUserName�� ���ο� ������ �̸��� ���� �ؾ� �Ѵ�
	bool DelUser(char* pcUserName)
	{
		for (size_t i = 0; i < USER_MAX; i++)
		{
			if (memcmp(pcUserName, Users[i].acUserName, sizeof(pcUserName)) == false)
			{
				Users.erase(Users.begin() + i);
				memcpy(acMasterUserName, Users.begin()->acUserName, sizeof(pcUserName));
			}
		}
	}

	//�濡 ������ ������ ����. ������ true ����
	bool IsEmpty()
	{
		if (Users.empty() == false)
			return false;
		else
			return true;
	}

	//�濡 ������ �� á���� ����, �� á�ٸ� true ����
	bool IsFull()
	{
		if (Users.size() == 6)
			return true;
		else
			return false;
	}

	//Ư�� ������ ����
	UserInfo& GetUserOfName(char* pcName)
	{
		for (size_t i = 0; i < USER_MAX; i++)
		{
			if (memcmp(pcName, Users[i].acUserName, sizeof(pcName)) == false)
			{
				cout << "Name : " << Users[i].acUserName << endl;
				cout << "Level : " << Users[i].Level << endl;
				cout << "Exp : " << Users[i].Exp << endl;
			}
		}
	}

	//������ ���� ����
	UserInfo& GetMasterUser()
	{
		cout << "Name : " << Users.begin()->acUserName << endl;
		cout << "Level : " << Users.begin()->Level << endl;
		cout << "Exp : " << Users.begin()->Exp << endl;
	}

	//���� ���������� �濡 ���� ������ ����
	UserInfo& GetUserOfLastOrder()
	{
		cout << "Name : " << Users.end()->acUserName << endl;
		cout << "Level : " << Users.end()->Level << endl;
		cout << "Exp : " << Users.end()->Exp << endl;
	}

	//Ư�� ������ ���� ������ �i�Ƴ���.
	bool BanUser(int OrderNum)
	{
		cout << "Name : " << Users[OrderNum].acUserName << endl;
		cout << "Level : " << Users[OrderNum].Level << endl;
		cout << "Exp : " << Users[OrderNum].Exp << endl;
	}

	//��� ������ �����Ѵ�.
	void Clear()
	{
		Users.clear();
	}

private:
	vector<UserInfo> Users;
	char acMasterUserName[21]; //������ �̸�
};

GameRoomUser::GameRoomUser()
{
}

GameRoomUser::~GameRoomUser()
{
}

int main()
{
	return 0;
}